/* ic_function.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::function::construct() */
corto_int16 _ic_function_construct(ic_function this) {
/* $begin(::corto::ic::function::construct) */
    ic_node(this)->kind = IC_FUNCTION;
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::function::str(string in) */
corto_string _ic_function_str(ic_function this, corto_string in) {
/* $begin(::corto::ic::function::str) */
    corto_id id;
    in = strappend(in, "\n%%function %s", corto_fullname(this->function, id));
    return in;
/* $end */
}
