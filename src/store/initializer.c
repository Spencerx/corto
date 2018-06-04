/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>

static
bool corto_type_is_collection(
    corto_type type)
{
    return !type->reference && type->kind == CORTO_COLLECTION;
}

static
bool corto_type_is_complex(
    corto_type type)
{
    return !type->reference &&
      (type->kind == CORTO_COMPOSITE || type->kind == CORTO_COLLECTION);
}

corto_initializer _corto_initializer_init(
    corto_type type,
    void *ptr)
{
    corto_initializer result = {
        .initializer_type = type,
        .initializer_ptr = ptr,
    };

    return result;
}

void corto_initializer_deinit(
    corto_initializer *this)
{
    while (this->current) {
        corto_initializer_pop(this);
    }
}

static
int16_t corto_scope_cache_member(
    corto_walk_opt *opt,
    corto_value *value,
    void *members)
{
    /* Simply append members for the current type-scope. Nested type-scopes will
     * be collected once the initializer moves to another scope. */
    corto_ll_append(members, value->is.member.member);
    return 0;
}

static
int16_t corto_scope_cache_build(
    corto_initializer *this,
    corto_type type)
{
    /* Initializer order is determined by taking all non-private, non-readonly
     * non-local and non-hidden members. */
    corto_walk_opt opt = {0};

    corto_walk_init(&opt);

    opt.access = CORTO_PRIVATE | CORTO_READONLY | CORTO_HIDDEN | CORTO_LOCAL;
    opt.accessKind = CORTO_NOT;
    opt.aliasAction = CORTO_WALK_ALIAS_FOLLOW;
    opt.optionalAction = CORTO_WALK_OPTIONAL_ALWAYS;
    opt.metaprogram[CORTO_MEMBER] = corto_scope_cache_member;

    /* Collect members in temporary linked list so we have O(1) appends */
    corto_ll members = corto_ll_new();

    /* Walk over metadata */
    corto_try(corto_metawalk(&opt, type, members), NULL);

    this->current->max_index = corto_ll_count(members);
    this->current->cache = corto_calloc(
        sizeof(corto_member) * this->current->max_index);

    /* Store members in contiguous array so we have O(1) read access */
    uint32_t count = 0;
    corto_iter it = corto_ll_iter(members);
    corto_member member = this->current->member;
    while (corto_iter_hasNext(&it)) {
        this->current->cache[count].member = corto_iter_next(&it);

        /* If a member was already set, update index to the current member */
        if (member) {
            if (this->current->cache[count].member == member) {
                this->current->index = count;
            }
        }

        count ++;
    }

    corto_ll_free(members);
    return 0;
error:
    corto_ll_free(members);
    return -1;
}

int16_t corto_initializer_index(
    corto_initializer *this,
    uint32_t index)
{
    if (!this->current) {
        corto_throw("cannot set index, no scope pushed");
        goto error;
    }

    corto_type type = this->current->scope_type;

    if (type->kind == CORTO_COMPOSITE) {
        if (!this->current->cache) {
            corto_try (corto_scope_cache_build(this, type), NULL);
        }

        if (index >= this->current->max_index) {
            corto_throw("index %d exceeds number of members in composite value",
              index);
            goto error;
        }

        this->current->member = this->current->cache[index].member;
        this->current->ptr = CORTO_OFFSET(
            this->current->scope_ptr,
            this->current->member->offset);
    } else {
        if (this->current->index >= corto_collection(type)->max) {
            corto_throw("index %d exceeds maximum collection length", index);
            goto error;
        }
    }

    this->current->index = index;

    return 0;
error:
    return -1;
}

int16_t corto_initializer_next(
    corto_initializer *this)
{
    corto_try(corto_initializer_index(this, this->current->index + 1), NULL);
    return 0;
error:
    return -1;
}

bool corto_initializer_has_next(
    corto_initializer *this)
{
    if (!this->current) {
        return false;
    } else {
        if (!this->current->cache) {
            corto_try(
                corto_scope_cache_build(this, this->current->scope_type), NULL);
        }

        if (this->current->index + 1 >= this->current->max_index) {
            return false;
        } else {
            return true;
        }
    }

error:
    return false;
}

int16_t corto_initializer_field(
    corto_initializer *this,
    const char *field_expr)
{
    if (!this->current) {
        corto_throw("cannot set field, no scope pushed");
        goto error;
    }

    corto_type type = this->current->scope_type;
    if (!type) {
        goto error;
    }

    void *ptr = this->current->scope_ptr;

    corto_field field = {0};

    corto_try(corto_field_lookup(
        field_expr,
        type,
        ptr,
        &field
    ), NULL);

    this->current->ptr = field.ptr;
    this->current->member = field.member;

    if (field.index != -1) {
        this->current->index = field.index;
    }

    return 0;
error:
    return -1;
}

int16_t corto_initializer_push(
    corto_initializer *this,
    bool as_collection)
{
    corto_type cur_type = NULL;
    void *cur_ptr = NULL;
    corto_initializer_scope *scope = NULL;

    if (!this->current) {
        cur_type = this->initializer_type;

        /* Ignore if the type is a reference type for the root scope */
        if (cur_type->kind != CORTO_COMPOSITE &&
            cur_type->kind != CORTO_COLLECTION)
        {
            corto_throw("cannot push scope for non-complex type '%s'", cur_type);
            goto error;
        }
    } else {
        cur_type = corto_initializer_get_type(this);
        if (!corto_type_is_complex(cur_type)) {
            corto_throw("cannot push scope for non-complex type '%s'", cur_type);
            goto error;
        }
    }

    if (as_collection && !corto_type_is_collection(cur_type)) {
        corto_throw("cannot push scope of type '%s' as collection",
            corto_fullpath(NULL, cur_type));
        goto error;
    }

    if (!this->current) {
        scope = &this->root_scope;
        cur_ptr = this->initializer_ptr;
    } else {
        scope = corto_calloc(sizeof(corto_initializer_scope));
        cur_ptr = this->current->ptr;
    }

    scope->scope_type = cur_type;
    scope->scope_ptr = cur_ptr;
    scope->parent = this->current;
    this->current = scope;

    return 0;
error:
    return -1;
}

int16_t corto_initializer_pop(
    corto_initializer *this)
{
    if (this->current) {
        corto_initializer_scope *parent = this->current->parent;
        if (this->current->cache) {
            free(this->current->cache);
        }
        if (this->current->parent) {
            /* The root scope is not separately allocated */
            free(this->current);
        }
        this->current = parent;
    } else {
        corto_throw("cannot pop root scope");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_type corto_initializer_get_type(
    corto_initializer *this)
{
    if (!this->current) {
        return this->initializer_type;
    } else if (this->current->member) {
        return this->current->member->type;
    } else if (this->current->scope_type->kind == CORTO_COLLECTION) {
        return corto_collection(this->current->scope_type)->elementType;
    } else {
        uint32_t index = this->current->index;
        if (!this->current->cache) {
            corto_try(
                corto_initializer_index(this, index), NULL);
        }

        if (this->current->max_index >= index) {
            return this->current->cache[index].member->type;
        } else {
            corto_throw("no value at index %d in scope of type '%s'",
                index, corto_fullpath(NULL, this->current->scope_type));
        }
    }

error:
    return NULL;
}

corto_type corto_initializer_get_scope_type(
    corto_initializer *this)
{
    if (!this->current) {
        return this->initializer_type;
    } else {
        return this->current->scope_type;
    }
}

corto_member corto_initializer_get_member(
    corto_initializer *this)
{
    if (!this->current) {
        corto_throw("cannot obtain member, no scope pushed");
        return NULL;
    } else if (this->current->member) {
        return this->current->member;
    } else if (this->current->scope_type->kind == CORTO_COMPOSITE) {
        uint32_t index = this->current->index;
        if (!this->current->cache) {
            corto_try(
                corto_initializer_index(this, index), NULL);
        }

        if (this->current->max_index >= index) {
            return this->current->cache[index].member;
        } else {
            corto_throw("no value at index %d in scope of type '%s'",
                index, corto_fullpath(NULL, this->current->scope_type));
        }
    } else {
        corto_throw("cannot obtain member, scope is of non-composite type '%s'",
            corto_fullpath(NULL, this->current->scope_type));
    }

error:
    return NULL;
}

int32_t corto_initializer_get_index(
    corto_initializer *this)
{
    if (!this->current) {
        corto_throw("cannot obtain index, no scope pushed");
        return -1;
    } else {
        return this->current->index;
    }
}

void* corto_initializer_get_ptr(
    corto_initializer *this)
{
    if (!this->current) {
        return this->initializer_ptr;
    } else {
        if (this->current->scope_ptr) {
            if (!this->current->ptr) {
                if (this->current->member) {
                    this->current->ptr = CORTO_OFFSET(
                        this->current->scope_ptr,
                        this->current->member->offset);
                } else {
                    corto_field field = {0};

                    /* If a member was selected, the pointer should have been set
                     * with it. So if the pointer isn't set yet, this must be a
                     * collection element. */
                    corto_try( corto_field_lookup_index(
                        this->current->index,
                        corto_collection(this->current->scope_type),
                        this->current->scope_ptr,
                        &field), NULL);

                    /* Assign resolved field pointer */
                    this->current->ptr = field.ptr;
                }
            }

            return this->current->ptr;
        } else {
            return NULL;
        }
    }

error:
    return NULL;
}

uintptr_t corto_initializer_set(
    corto_initializer *this,
    corto_value *value)
{
    corto_type type = corto_initializer_get_type(this);
    void *ptr = corto_initializer_get_ptr(this);

    corto_value field = corto_value_pointer(ptr, type);

    return corto_value_binaryOp(CORTO_ASSIGN, &field, value, NULL);
}

uintptr_t corto_initializer_set_bool(
    corto_initializer *this,
    bool value)
{
    corto_value v = corto_value_bool(value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_char(
    corto_initializer *this,
    char value)
{
    corto_value v = corto_value_char(value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_int(
    corto_initializer *this,
    int64_t value)
{
    corto_value v = corto_value_int(value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_uint(
    corto_initializer *this,
    uint64_t value)
{
    corto_value v = corto_value_uint(value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_float(
    corto_initializer *this,
    double value)
{
    corto_value v = corto_value_float(value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_string(
    corto_initializer *this,
    const char *value)
{
    corto_value v = corto_value_string((char*)value);
    return corto_initializer_set(this, &v);
}

uintptr_t corto_initializer_set_ref(
    corto_initializer *this,
    corto_object value)
{
    corto_value v = corto_value_object((char*)value, NULL);
    return corto_initializer_set(this, &v);
}
