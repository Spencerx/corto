/* ic_variable.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::variable::construct() */
corto_int16 _ic_variable_construct(ic_variable this) {
/* $begin(::corto::ic::variable::construct) */
    ic_storage(this)->kind = IC_VARIABLE;
    return ic_storage_construct(ic_storage(this));
/* $end */
}
