/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

corto_recordList test_Select_collect(
    const char *scope,
    const char *expr,
    uint64_t offset,
    uint64_t limit)
{
    corto_select__fluent r = corto_select(expr).from(scope);

    if (offset || limit) {
        r.limit(limit);
        r.offset(offset);
    }

    corto_iter iter;
    corto_int16 ret = r.iter(&iter);
    if (ret) goto error;
    corto_ll result = corto_ll_new();
    while (corto_iter_hasNext(&iter)) {
        corto_record *item = corto_iter_next(&iter);
        corto_record *listItem = corto_alloc(sizeof(corto_record));
        listItem->parent = corto_strdup(item->parent);
        listItem->name = corto_strdup(item->name);
        listItem->type = corto_strdup(item->type);
        corto_ll_append(result, listItem);
    }

    return result;
error:
    return NULL;
}

bool test_Select_hasObject(
    corto_recordlist items,
    const char *parent,
    const char *name,
    const char *type)
{

    corto_iter iter = corto_ll_iter(items);
    while (corto_iter_hasNext(&iter)) {
        corto_record *item = corto_iter_next(&iter);
        if (!strcmp(item->parent, parent)) {
            if (!strcmp(item->name, name)) {
                if (!strcmp(item->type, type)) {
                    return TRUE;
                } else {
                    corto_throw("type does not match (%s vs %s)", item->type, type);
                }

            } else {
                corto_throw("name does not match (%s vs %s)", item->name, name);
            }

        } else {
            corto_throw("parent does not match (%s vs %s)", item->parent, parent);
        }

        /* This prevents the API from complaining about unhandled errors */
        corto_lasterr();
    }

    return FALSE;
}

void test_Select_setup(
    test_Select this)
{
    corto_object a = corto_void__create(root_o, "a");
    corto_void__create(a, "b");
    corto_object c = corto_void__create(a, "c");

    /* Create in separate scope, to avoid contamination of root & keep test case
     * clean. */
    corto_void__create(a, "abc"); /* For matching filters */
    corto_void__create(a, "abd"); /* For wildcard testing */
    corto_void__create(a, "abdc"); /* For asterisk testing */
    corto_void__create(a, "Abab"); /* For caps testing */
    corto_void__create(a, "ab_ab"); /* Testing underscores */
    corto_void__create(a, "ab01234567890"); /* Testing numbers */
    corto_void__create(root_o, "korto"); /* For testing wildcard */
    corto_void__create(root_o, "karto"); /* For testing asterisk */

    /* Objects to test trees */
    corto_object _1 = corto_void__create(c, "b");
    corto_object _2 = corto_void__create(c, "c");
    corto_object _3 = corto_void__create(c, "abc"); /* For matching filters */
    corto_object _4 = corto_void__create(c, "abd"); /* For wildcard testing */
    corto_object _5 = corto_void__create(c, "abdc"); /* For asterisk testing */
    corto_object _6 = corto_void__create(c, "Abab"); /* For caps testing */
    corto_object _7 = corto_void__create(c, "ab_ab"); /* Testing underscores */
    corto_object _8 = corto_void__create(c, "ab01234567890"); /* Testing numbers */

    /* Add one more level of nesting */
    corto_void__create(_1, "abcdef");
    corto_void__create(_2, "abcdef");
    corto_void__create(_3, "abcdef");
    corto_void__create(_4, "abcdef");
    corto_void__create(_5, "abcdef");
    corto_void__create(_6, "abcdef");
    corto_void__create(_7, "abcdef");
    corto_void__create(_8, "abcdef");

    corto_enable_load(FALSE);
}

void test_Select_tc_selectDeleteCurrent(
    test_Select this)
{
    corto_int16 ret = 0;
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab_ab");

    ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab_ab");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectDeleteFirst(
    test_Select this)
{
    corto_int16 ret = 0;
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab01234567890");

    ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab01234567890");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectDeleteNext(
    test_Select this)
{
    corto_int16 ret = 0;
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab_ab");

    ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab_ab");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectDeleteParent(
    test_Select this)
{
    corto_int16 ret = 0;
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a");

    ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a");
    test_assert(check == NULL);

    test_assert(!corto_iter_hasNext(&iter));

    corto_release(o);
}

void test_Select_tc_selectDeletePrevious(
    test_Select this)
{
    corto_int16 ret = 0;
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab01234567890");

    ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab01234567890");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectEmptyParentAst(
    test_Select this)
{
    corto_iter it;
    corto_record *r;
    corto_int16 ret = corto_select("*").from("").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "config");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "corto");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "package");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "data");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "home");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "karto");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "korto");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it));
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "test");
    test_assertstr(r->parent, "");
    test_assertstr(r->type, "package");

    test_assert(!corto_iter_hasNext(&it));

}

void test_Select_tc_selectEmptyParentString(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("", "corto", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "", "corto", "package"));
}

void test_Select_tc_selectEmptyQueryString(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", "", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, ".", "", "package"));
}

void test_Select_tc_selectEmptyStrings(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("", "", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "", "", "package"));
}

void test_Select_tc_selectFilterAsterisk(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "*rto", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 3);

    test_assert(test_Select_hasObject(results, "", "corto", "package"));
    test_assert(test_Select_hasObject(results, "", "karto", "void"));
    test_assert(test_Select_hasObject(results, "", "korto", "void"));

}

void test_Select_tc_selectFilterWildcard(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "?orto", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 2);

    test_assert(test_Select_hasObject(results, "", "corto", "package"));
    test_assert(test_Select_hasObject(results, "", "korto", "void"));

}

void test_Select_tc_selectFromCorto(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/corto", "//lang", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, ".", "lang", "package"));

}

void test_Select_tc_selectFromLangParent(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", "/corto/lang/compositeKind/DELEGATE", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "corto/lang/compositeKind", "DELEGATE", "constant"));

}

void test_Select_tc_selectFromNull(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "//lang", 0, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/corto", "lang", "package"));

}

void test_Select_tc_selectFromRoot(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", "//lang", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "corto", "lang", "package"));

}

void test_Select_tc_selectFromRootEmpty(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", "", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

}

void test_Select_tc_selectFromRootNull(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", NULL, 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

}

void test_Select_tc_selectFromRootThis(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/", ".", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

}

void test_Select_tc_selectIdentifier(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect(NULL, "a", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, ""));
    (test_assertstr(item->name, "a"));
    (test_assertstr(item->type, "void"));

    corto_release(a);

}

void test_Select_tc_selectIdentifierCaps(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ABC", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));

}

void test_Select_tc_selectInvertCase(
    test_Select this)
{
    corto_iter it;
    corto_int16 ret = corto_select("ABC").from("/a").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_record *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "abc");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "void");

    test_assert(!corto_iter_hasNext(&it));


}

void test_Select_tc_selectInvertCaseFilter(
    test_Select this)
{
    corto_iter it;
    corto_int16 ret = corto_select("ABA?").from("/a").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_record *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "Abab");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "void");

    test_assert(!corto_iter_hasNext(&it));

}

void test_Select_tc_selectInvertCaseScope(
    test_Select this)
{
    corto_iter it;
    corto_int16 ret = corto_select("abc").from("/A").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_record *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "abc");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "void");

    test_assert(!corto_iter_hasNext(&it));

}

void test_Select_tc_selectLimitOvershootScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 0, 10);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 8);

    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectLimitOvershootTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*", 0, 30);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 24);

    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));

}

void test_Select_tc_selectLimitScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 0, 4);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 4);

    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectLimitTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*", 0, 20);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 20);

    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(!test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(!test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(!test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(!test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));

}

void test_Select_tc_selectNumeric(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab01234567890", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

}

void test_Select_tc_selectObject(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "corto", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "", "corto", "package"));

}

void test_Select_tc_selectObjectParentScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("corto", "lang/word", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "lang", "word", "binary"));
}

void test_Select_tc_selectObjectParentTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("corto", "//word", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "lang", "word", "binary"));
}

void test_Select_tc_selectObjectPrefixScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "/corto", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "", "corto", "package"));
}

void test_Select_tc_selectObjectPrefixTrailingScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "/corto/", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 5);

    test_assert(test_Select_hasObject(results, "/corto", "lang", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "vstore", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "native", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "secure", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "test", "package"));

}

void test_Select_tc_selectObjectScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "/corto/lang/word", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/corto/lang", "word", "binary"));
}

void test_Select_tc_selectObjectTrailingScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "corto/", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 5);

    test_assert(test_Select_hasObject(results, "/corto", "lang", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "vstore", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "native", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "secure", "package"));
    test_assert(test_Select_hasObject(results, "/corto", "test", "package"));

}

void test_Select_tc_selectObjectTrailingTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//", 0, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 24);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));

}

void test_Select_tc_selectObjectTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "//word", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/corto/lang", "word", "binary"));
}

void test_Select_tc_selectOffsetLargerThanLimit(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 4, 2);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 2);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectOffsetLimit(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 2, 4);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 4);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectOffsetLimitFilter(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "//delegate*", 0, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 3);

}

void test_Select_tc_selectOffsetLimitOvershootScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 2, 8);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 6);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectOffsetLimitOvershootTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*", 6, 20);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 18);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));

}

void test_Select_tc_selectOffsetScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 2, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 6);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectOffsetTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*", 6, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 18);

    test_assert(!test_Select_hasObject(results, "/a", "ab01234567890", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(!test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));

}

void test_Select_tc_selectOrder(
    test_Select this)
{
    corto_record *item;
    corto_iter iter;

    corto_int16 ret = corto_select("a//*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab_ab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "Abab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abd"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abdc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "b"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "c"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab_ab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "Abab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abd"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abdc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "b"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "c"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    test_assert(!corto_iter_hasNext(&iter));

}

void test_Select_tc_selectParent(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect("/a", "..", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, ".."));
    (test_assertstr(item->name, ""));
    (test_assertstr(item->type, "package"));

    corto_release(a);

}

void test_Select_tc_selectParentNoSlash(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("corto", "lang", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, ".", "lang", "package"));

}

void test_Select_tc_selectParentWithSink(
    test_Select this)
{
    corto_iter it;
    corto_int16 ret = corto_select("..").from("/corto").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_record *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "");
    test_assertstr(r->parent, "..");
    test_assert(!corto_iter_hasNext(&it));

}

void test_Select_tc_selectScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 8);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

}

void test_Select_tc_selectScopedIdentifier(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    results = test_Select_collect(NULL, "a/b", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, "/a"));
    (test_assertstr(item->name, "b"));
    (test_assertstr(item->type, "void"));

}

void test_Select_tc_selectScopedParent(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    results = test_Select_collect(NULL, "a/..", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, ""));
    (test_assertstr(item->name, ""));
    (test_assertstr(item->type, "package"));

}

void test_Select_tc_selectScopedThis(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    results = test_Select_collect(NULL, "a/.", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, ""));
    (test_assertstr(item->name, "a"));
    (test_assertstr(item->type, "void"));

}

void test_Select_tc_selectScopeWithAsterisk(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/*", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 8);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

}

void test_Select_tc_selectScopeWithAsteriskFilter(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab*", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 6);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

}

void test_Select_tc_selectScopeWithWildcard(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/?", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 2);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));

}

void test_Select_tc_selectScopeWithWildcardFilter(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab?", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 2);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));

}

void test_Select_tc_selectSeparator(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/abc,a/abd", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 2);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));


}

void test_Select_tc_selectThis(
    test_Select this)
{
    corto_ll results = NULL;
    corto_record *item;

    corto_object a = corto_resolve(NULL, "a");
    test_assert(a != NULL);

    results = test_Select_collect("/a", ".", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    item = corto_ll_get(results, 0);
    test_assert(item != NULL);
    (test_assertstr(item->parent, ".."));
    (test_assertstr(item->name, "a"));
    (test_assertstr(item->type, "void"));

    corto_release(a);

}

void test_Select_tc_selectTree(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//*", 0, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 24);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));

}

void test_Select_tc_selectTreeDeleteCurrent(
    test_Select this)
{
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab_ab");

    corto_int16 ret = corto_select("a//*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab_ab");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectTreeDeleteFirst(
    test_Select this)
{
    corto_record *item;
    corto_iter iter;
    corto_object o = corto_resolve(NULL, "a/ab01234567890");

    corto_int16 ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab01234567890");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectTreeDeleteGrandparent(
    test_Select this)
{
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a");

    corto_int16 ret = corto_select("a//*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab_ab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "Abab"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abd"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abdc"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "b"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "c"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    test_assert(item != NULL);
    (test_assertstr(item->name, "abcdef"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a");
    test_assert(check == NULL);

    test_assert(!corto_iter_hasNext(&iter));

    corto_release(o);

}

void test_Select_tc_selectTreeDeleteNext(
    test_Select this)
{
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab_ab");

    corto_int16 ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab_ab");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectTreeDeleteParent(
    test_Select this)
{
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a");

    corto_int16 ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a");
    test_assert(check == NULL);

    test_assert(!corto_iter_hasNext(&iter));

    corto_release(o);

}

void test_Select_tc_selectTreeDeletePrevious(
    test_Select this)
{
    corto_iter iter;
    corto_record *item;
    corto_object o = corto_resolve(NULL, "a/ab01234567890");

    corto_int16 ret = corto_select("a/*").iter( &iter );
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab01234567890"));

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "ab_ab"));

    corto_delete(o);
    corto_object check = corto_resolve(NULL, "a/ab01234567890");
    test_assert(check == NULL);

    test_assert(corto_iter_hasNext(&iter));
    item = corto_iter_next(&iter);
    (test_assertstr(item->name, "Abab"));

    corto_iter_release(&iter);

    corto_release(o);

}

void test_Select_tc_selectTreeFromScope(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect("/a", "//", 0, 0);
    test_assert(results != NULL);

    test_assertint(corto_ll_count(results), 24);

    test_assert(test_Select_hasObject(results, ".", "b", "void"));
    test_assert(test_Select_hasObject(results, ".", "c", "void"));
    test_assert(test_Select_hasObject(results, ".", "abc", "void"));
    test_assert(test_Select_hasObject(results, ".", "abd", "void"));
    test_assert(test_Select_hasObject(results, ".", "abdc", "void"));
    test_assert(test_Select_hasObject(results, ".", "Abab", "void"));
    test_assert(test_Select_hasObject(results, ".", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, ".", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "c", "b", "void"));
    test_assert(test_Select_hasObject(results, "c", "c", "void"));
    test_assert(test_Select_hasObject(results, "c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "c/ab01234567890", "abcdef", "void"));

}

void test_Select_tc_selectTreeWithAsteriskFilter(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//ab*", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 20);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abdc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "Abab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab_ab", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "ab01234567890", "void"));

    test_assert(test_Select_hasObject(results, "/a/c/b", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/c", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abd", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/abdc", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/Abab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab_ab", "abcdef", "void"));
    test_assert(test_Select_hasObject(results, "/a/c/ab01234567890", "abcdef", "void"));

}

void test_Select_tc_selectTreeWithWildcard(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//?", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 4);

    test_assert(test_Select_hasObject(results, "/a", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a", "c", "void"));

    test_assert(test_Select_hasObject(results, "/a/c", "b", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "c", "void"));

}

void test_Select_tc_selectTreeWithWildcardFilter(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a//ab?", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 4);

    test_assert(test_Select_hasObject(results, "/a", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a", "abd", "void"));

    test_assert(test_Select_hasObject(results, "/a/c", "abc", "void"));
    test_assert(test_Select_hasObject(results, "/a/c", "abd", "void"));

}

void test_Select_tc_selectUnderscore(
    test_Select this)
{
    corto_ll results = NULL;

    results = test_Select_collect(NULL, "a/ab_ab", 0, 0);
    test_assert(results != NULL);
    test_assertint(corto_ll_count(results), 1);

    test_assert(test_Select_hasObject(results, "/a", "ab_ab", "void"));

}

void test_Select_tc_selectFromPartialMatchedElement(
    test_Select this)
{
    corto_object a = corto_create(root_o, "data/hello/a", corto_void_o);
    test_assert(a != NULL);
    corto_object b = corto_create(root_o, "data/helloworld/b", corto_void_o);
    test_assert(b != NULL);

    corto_iter it;
    test_assert(corto_select("*").from("data/hello").iter(&it) == 0);

    test_assert(corto_iter_hasNext(&it));
    corto_record *r = corto_iter_next(&it);
    test_assertstr(r->id, "a");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "void");

    test_assert(!corto_iter_hasNext(&it));
}

void test_Select_tc_selectIdUnknown(
    test_Select this)
{
    corto_object hello = corto_create(root_o, "foo/bar/hello", corto_void_o);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_void_o);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("bar").from("foo").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it) == 0);
    test_assert(corto_delete(hello) == 0);
}

void test_Select_tc_selectThisUnknown(
    test_Select this)
{
    corto_object bar = corto_create(root_o, "foo/bar", corto_void_o);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_void_o);

    corto_object foo = corto_parentof(bar);
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_unknown_o);
    test_assert(corto_countof(foo) == 1);

    corto_iter it;
    int16_t ret = corto_select(".").from("foo").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it) == 0);
    test_assert(corto_delete(bar) == 0);
}

void test_Select_tc_selectScopeUnknown(
    test_Select this)
{
    corto_object hello = corto_create(root_o, "data/bar/hello", corto_void_o);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_void_o);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("/").from("data").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it) == 0);
    test_assert(corto_delete(hello) == 0);
}

void test_Select_tc_selectTreeUnknown(
    test_Select this)
{
    corto_object world = corto_create(root_o, "data/bar/hello/world", corto_void_o);
    test_assert(world != NULL);
    test_assert(corto_typeof(world) == corto_void_o);

    corto_object hello = corto_parentof(world);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_unknown_o);
    test_assert(corto_countof(hello) == 1);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("//").from("data").iter(&it);
    test_assert(ret == 0);

    test_assert(corto_iter_hasNext(&it) == 1);
    corto_record *r = corto_iter_next(&it);
    test_assertstr(r->id, "world");
    test_assertstr(r->parent, "bar/hello");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it) == 0);
    test_assert(corto_delete(world) == 0);
}

void test_Select_tc_selectIdYieldUnknown(
    test_Select this)
{
    corto_object hello = corto_create(root_o, "foo/bar/hello", corto_void_o);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_void_o);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("bar").from("foo").yield_unknown().iter(&it);
    test_assert(ret == 0);

    corto_record *r;
    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "bar");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "unknown");
    test_assert(corto_iter_hasNext(&it) == 0);

    test_assert(corto_delete(hello) == 0);
}

void test_Select_tc_selectScopeYieldUnknown(
    test_Select this)
{
    corto_object hello = corto_create(root_o, "data/bar/hello", corto_void_o);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_void_o);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("/").from("data").yield_unknown().iter(&it);
    test_assert(ret == 0);

    corto_record *r;
    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "bar");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "unknown");
    test_assert(corto_iter_hasNext(&it) == 0);

    test_assert(corto_delete(hello) == 0);
}

void test_Select_tc_selectThisYieldUnknown(
    test_Select this)
{
    corto_object bar = corto_create(root_o, "foo/bar", corto_void_o);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_void_o);

    corto_object foo = corto_parentof(bar);
    test_assert(foo != NULL);
    test_assert(corto_typeof(foo) == corto_unknown_o);
    test_assert(corto_countof(foo) == 1);

    corto_iter it;
    int16_t ret = corto_select(".").from("foo").yield_unknown().iter(&it);
    test_assert(ret == 0);

    corto_record *r;
    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "foo");
    test_assertstr(r->parent, "..");
    test_assertstr(r->type, "unknown");
    test_assert(corto_iter_hasNext(&it) == 0);

    test_assert(corto_delete(bar) == 0);
}

void test_Select_tc_selectTreeYieldUnknown(
    test_Select this)
{
    corto_object world = corto_create(root_o, "data/bar/hello/world", corto_void_o);
    test_assert(world != NULL);
    test_assert(corto_typeof(world) == corto_void_o);

    corto_object hello = corto_parentof(world);
    test_assert(hello != NULL);
    test_assert(corto_typeof(hello) == corto_unknown_o);
    test_assert(corto_countof(hello) == 1);

    corto_object bar = corto_parentof(hello);
    test_assert(bar != NULL);
    test_assert(corto_typeof(bar) == corto_unknown_o);
    test_assert(corto_countof(bar) == 1);

    corto_iter it;
    int16_t ret = corto_select("//").from("data").yield_unknown().iter(&it);
    test_assert(ret == 0);

    corto_record *r;
    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "bar");
    test_assertstr(r->parent, ".");
    test_assertstr(r->type, "unknown");

    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "hello");
    test_assertstr(r->parent, "bar");
    test_assertstr(r->type, "unknown");

    test_assert(corto_iter_hasNext(&it) != 0);
    r = corto_iter_next(&it);
    test_assertstr(r->id, "world");
    test_assertstr(r->parent, "bar/hello");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it) == 0);
    test_assert(corto_delete(world) == 0);
}

void test_Select_tc_selectUnmatchingObjectAfterUnknown(
    test_Select this)
{
    /* Create unknown object 'foo' and void `foo/bar` */
    corto_create(root_o, "data/foo/bar", corto_void_o);

    /* Create select query that first finds foo and then foo/bar with a filter
     * that should exclude foo/bar */
    corto_iter it;
    int16_t ret = corto_select("//foo").from("/data").iter(&it);
    test_assert(ret == 0);

    /* 'foo' should not be returned because it is unknown. foo/bar should not be
     * returned because the filter doesn't match. */
    test_assert(corto_iter_hasNext(&it) == 0);

    /* This test failed because the unknown object would set a HIDDEN flag on
     * the internal corto_result used by the corto_select iterator. This flag
     * was not cleaned up before a check took place that ensured that
     * corto_select would always evaluate HIDDEN objects in case of a recursive
     * query, to see if the hidden object has any children. This bypasses all
     * filters, and thus foo/bar shows up, even though it doesn't match the id
     * expression. At a later point, the flag is set to the correct value, which
     * is why the object isn't actually hidden from the application. */
}

void test_Select_tc_selectChildAfterUnmatchingUnknownParent(
    test_Select this)
{
    /* Create unknown object 'foo' and void `foo/bar` */
    corto_create(root_o, "data/foo/bar", corto_void_o);

    /* Create select query that doesn't match data/foo but does match foo/bar */
    corto_iter it;
    int16_t ret = corto_select("//bar").from("/data").iter(&it);
    test_assert(ret == 0);

    /* 'foo' should not be returned because it is unknown. foo/bar should be
     * returned because the filter matches. */
    test_assert(corto_iter_hasNext(&it) != 0);
    corto_record *r = corto_iter_next(&it);
    test_assert(r != NULL);
    test_assertstr(r->id, "bar");
    test_assertstr(r->parent, "foo");
    test_assertstr(r->type, "void");

    test_assert(corto_iter_hasNext(&it) == 0);
}

void test_Select_teardown(
    test_Select this)
{
    /* Insert implementation */
}
