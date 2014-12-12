#include <string.h>
#include <stdio.h>

#include "hyve.h"
#include "json.h"
#include "tc_jsonser__api.h"
#include "tc_jsonser__meta.h"
#include "tc_jsonser__type.h"


#define _test_scope(object, expected) \
{\
   db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, FALSE, TRUE};\
   db_serialize(&serializer, tc_jsonser_##object##_o, &userData);\
   if (strcmp(userData.buffer, "{\"scope\":"expected"}")) {\
       result = -1;\
       fprintf(\
           stderr,\
           "tc_jsonser_number: FAIL: expected %s, serialized %s\n",\
           "{\"scope\":"expected"}", userData.buffer);\
   }\
}

db_int16 test_scope(void) {
    db_int16 result = 0;

    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    _test_scope(namesp, 
        "[{\"name\":\"a\","
            "\"type\":\"::hyve::lang::int16\",\""
            "states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\",\""
            "childCount\":0},"
        "{\"name\":\"b\",\""
            "type\":\"::hyve::lang::string\","
            "\"states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\","
            "\"childCount\":0}]"
    );

    return result;
}

#undef _test_scope
