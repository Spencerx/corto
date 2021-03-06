/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
int16_t test_AutoResumeSinkMount_construct(
    test_AutoResumeSinkMount this)
{
    /* Backwards compatibility patch for mount member */
    corto_subscriber s = corto_subscriber(this);
    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_set_str(&corto_subscriber(this)->query.type, this->type);
    corto_string type = this->type ? this->type : "int32";

    corto_mount_set_format(this, "text/corto");

    corto_mount(this)->ownership = CORTO_LOCAL_SOURCE;
    corto_observer(this)->mask = CORTO_ON_TREE;

    // First tier
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "x",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "y",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "z",
        NULL,
        ".",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Second tier
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "a",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "b",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "c",
        NULL,
        "x",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Third tier
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "k",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "l",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "m",
        NULL,
        "x/a",
        type,
        (corto_word)this->value,
        FALSE
    );

    // Fourth tier
    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "n",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "o",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    corto_record__assign(
        corto_recordList__append_alloc(this->items),
        "p",
        NULL,
        "x/a/k",
        type,
        (corto_word)this->value,
        FALSE
    );

    return corto_mount_construct(this);
}

/* Custom release function */
static void test_SinkMount_iterRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_recordList__clear(data->list);
    corto_ll_free(data->list);
    corto_ll_iterRelease(iter);
}

corto_recordIter test_AutoResumeSinkMount_on_query(
    test_AutoResumeSinkMount this,
    corto_query *query)
{
    corto_iter iter = corto_ll_iter(this->items);
    corto_ll data = corto_ll_new();

    /* Filter items by parent */
    corto_recordIter__foreach(iter, e) {
        if (!fnmatch(query->from, e.parent, 0)) {
            if (!fnmatch(query->select, e.id, 0)) {
                corto_record__assign(
                    corto_recordList__append_alloc(data),
                    e.id,
                    e.id,
                    e.parent,
                    e.type,
                    e.value,
                    e.flags
                );
            }

        }

    }

    /* Create persistent iterator */
    corto_iter result = corto_ll_iterAlloc(data);
    /* Overwrite release so that list is cleaned up after select is done */
    result.release = test_SinkMount_iterRelease;
    /* Return persistent iterator to request */
    return result;
}

uintptr_t test_AutoResumeSinkMount_on_subscribe(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{

    /* Result is set to either this or 'expr' depending on the content of expr.
     * This allows the testcase to test both cases where on_subscribe returns the
     * same value of ctx, as well as cases where it doesn't */
    corto_word result = (corto_word)this;

    if (query->select[0] != '*') {
        result = rand();
    }

    corto_queryList__append(
      this->subscribes,
      query
    );

    return result;
}

void test_AutoResumeSinkMount_on_unsubscribe(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{
    if (query->select[0] == '*') {
        test_assert(ctx == (corto_word)this);
    }

    corto_queryList__append(
      this->unsubscribes,
      query
    );
}

uintptr_t test_AutoResumeSinkMount_on_mount(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{
    /* Result is set to either this or 'expr' depending on the content of expr.
     * This allows the testcase to test both cases where on_mount returns the
     * same value of ctx, as well as cases where it doesn't */
    corto_word result = (corto_word)this;

    if (query->select[0] != '*') {
        result = rand();
    }

    corto_queryList__append(
      this->mounts,
      query
    );

    return result;
}

void test_AutoResumeSinkMount_on_unmount(
    test_AutoResumeSinkMount this,
    corto_query *query,
    uintptr_t ctx)
{
    if (query->select[0] == '*') {
        test_assert(ctx == (corto_word)this);
    }

    corto_queryList__append(
      this->unmounts,
      query
    );
}
