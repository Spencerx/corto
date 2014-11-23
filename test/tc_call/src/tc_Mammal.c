/* tc_Mammal.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "tc_Mammal.h"
#include "tc_call__meta.h"


/* ::tc_call::Mammal::getKind() */
tc_MammalKind tc_Mammal_getKind(tc_Mammal _this) {
/* $begin(::tc_call::Mammal::getKind) */
    return _this->kind;
/* $end */
}

/* ::tc_call::Mammal::getProps(::hyve::lang::uint32 someValue) */
tc_MammalProps tc_Mammal_getProps(tc_Mammal _this, db_uint32 someValue) {
/* $begin(::tc_call::Mammal::getProps) */
    DB_UNUSED(someValue);
    return _this->props;
/* $end */
}

/* ::tc_call::Mammal::getSpeed() */
db_float64 tc_Mammal_getSpeed(tc_Mammal _this) {
/* $begin(::tc_call::Mammal::getSpeed) */

    return _this->props.speed;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::tc_call::Mammal::init(::tc_call::Mammal object) */
db_int16 tc_Mammal_init(tc_Mammal object) {
/* $begin(::tc_call::Mammal::init) */
    tc_Animal(object)->kind = TC_MAMMAL;
    return 0;
/* $end */
}

/* virtual ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
db_bool tc_Mammal_matesWith(tc_Mammal _this, tc_Animal m) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "matesWith(::tc_call::Animal m)");
    }
    db_assert(_methodId, "virtual method 'matesWith(::tc_call::Animal m)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::matesWith(::tc_call::Animal m)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::matesWith(::tc_call::Animal m)'.", db_nameof(_this));
        _result = ((db_bool(*)(tc_Mammal, tc_Animal ))_method->_parent.impl)(_this, m);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, m);
    }
    
    return _result;
}

/* ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
db_bool tc_Mammal_matesWith_v(tc_Mammal _this, tc_Animal m) {
/* $begin(::tc_call::Mammal::matesWith) */
    return _this->kind == tc_Mammal(m)->kind;
/* $end */
}

/* ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
db_void tc_Mammal_setProps(tc_Mammal _this, tc_MammalProps *props) {
/* $begin(::tc_call::Mammal::setProps) */
    _this->props = *props;
/* $end */
}

/* ::tc_call::Mammal::setSpeed(::hyve::lang::float64 speed) */
db_void tc_Mammal_setSpeed(tc_Mammal _this, db_float64 speed) {
/* $begin(::tc_call::Mammal::setSpeed) */
    _this->props.speed = speed;
/* $end */
}
