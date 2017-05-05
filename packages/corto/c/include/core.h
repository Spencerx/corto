/* core.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_CORE__API_H
#define CORTO_CORE__API_H

#include <corto/corto.h>
#include <corto/_project.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /corto/core/application */
CORTO_EXPORT corto_application _corto_applicationCreate(void);
#define corto_applicationCreate() _corto_applicationCreate()
#define corto_applicationCreate_auto(_id) corto_application _id = corto_applicationCreate(); (void)_id
CORTO_EXPORT corto_application _corto_applicationCreateChild(corto_object _parent, corto_string _id);
#define corto_applicationCreateChild(_parent, _id) _corto_applicationCreateChild(_parent, _id)
#define corto_applicationCreateChild_auto(_parent, _id) corto_application _id = corto_applicationCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_applicationUpdate(corto_application _this);
#define corto_applicationUpdate(_this) _corto_applicationUpdate(corto_application(_this))

CORTO_EXPORT corto_application _corto_applicationDeclare(void);
#define corto_applicationDeclare() _corto_applicationDeclare()
#define corto_applicationDeclare_auto(_id) corto_application _id = corto_applicationDeclare(); (void)_id
CORTO_EXPORT corto_application _corto_applicationDeclareChild(corto_object _parent, corto_string _id);
#define corto_applicationDeclareChild(_parent, _id) _corto_applicationDeclareChild(_parent, _id)
#define corto_applicationDeclareChild_auto(_parent, _id) corto_application _id = corto_applicationDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_applicationDefine(corto_application _this);
#define corto_applicationDefine(_this) _corto_applicationDefine(corto_application(_this))
CORTO_EXPORT corto_application _corto_applicationAssign(corto_application _this);
#define corto_application__optional_NotSet NULL
#define corto_application__optional_Set() corto_applicationAssign((corto_application*)corto_calloc(sizeof(corto_application)))
#define corto_application__optional_SetCond(cond) cond ? corto_applicationAssign((corto_application*)corto_calloc(sizeof(corto_application))) : NULL
#define corto_applicationUnset(_this) _this ? corto_ptr_deinit(_this, corto_application_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_applicationAssign(_this) _corto_applicationAssign(_this)
#define corto_applicationSet(_this) _this = _this ? _this : (corto_application*)corto_calloc(sizeof(corto_application)); _corto_applicationAssign(_this)

/* /corto/core/dispatcher */
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreate(void);
#define corto_dispatcherCreate() _corto_dispatcherCreate()
#define corto_dispatcherCreate_auto(_id) corto_dispatcher _id = corto_dispatcherCreate(); (void)_id
CORTO_EXPORT corto_dispatcher _corto_dispatcherCreateChild(corto_object _parent, corto_string _id);
#define corto_dispatcherCreateChild(_parent, _id) _corto_dispatcherCreateChild(_parent, _id)
#define corto_dispatcherCreateChild_auto(_parent, _id) corto_dispatcher _id = corto_dispatcherCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_dispatcherUpdate(corto_dispatcher _this);
#define corto_dispatcherUpdate(_this) _corto_dispatcherUpdate(corto_dispatcher(_this))

CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclare(void);
#define corto_dispatcherDeclare() _corto_dispatcherDeclare()
#define corto_dispatcherDeclare_auto(_id) corto_dispatcher _id = corto_dispatcherDeclare(); (void)_id
CORTO_EXPORT corto_dispatcher _corto_dispatcherDeclareChild(corto_object _parent, corto_string _id);
#define corto_dispatcherDeclareChild(_parent, _id) _corto_dispatcherDeclareChild(_parent, _id)
#define corto_dispatcherDeclareChild_auto(_parent, _id) corto_dispatcher _id = corto_dispatcherDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_dispatcherDefine(corto_dispatcher _this);
#define corto_dispatcherDefine(_this) _corto_dispatcherDefine(corto_dispatcher(_this))
CORTO_EXPORT corto_dispatcher _corto_dispatcherAssign(corto_dispatcher _this);
#define corto_dispatcher__optional_NotSet NULL
#define corto_dispatcher__optional_Set() corto_dispatcherAssign((corto_dispatcher*)corto_calloc(sizeof(corto_dispatcher)))
#define corto_dispatcher__optional_SetCond(cond) cond ? corto_dispatcherAssign((corto_dispatcher*)corto_calloc(sizeof(corto_dispatcher))) : NULL
#define corto_dispatcherUnset(_this) _this ? corto_ptr_deinit(_this, corto_dispatcher_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_dispatcherAssign(_this) _corto_dispatcherAssign(_this)
#define corto_dispatcherSet(_this) _this = _this ? _this : (corto_dispatcher*)corto_calloc(sizeof(corto_dispatcher)); _corto_dispatcherAssign(_this)

/* /corto/core/event */
CORTO_EXPORT corto_event* _corto_eventCreate(uint16_t kind);
#define corto_eventCreate(kind) _corto_eventCreate(kind)
#define corto_eventCreate_auto(_id, kind) corto_event* _id = corto_eventCreate(kind); (void)_id
CORTO_EXPORT corto_event* _corto_eventCreateChild(corto_object _parent, corto_string _id, uint16_t kind);
#define corto_eventCreateChild(_parent, _id, kind) _corto_eventCreateChild(_parent, _id, kind)
#define corto_eventCreateChild_auto(_parent, _id, kind) corto_event* _id = corto_eventCreateChild(_parent, #_id, kind); (void)_id
CORTO_EXPORT corto_int16 _corto_eventUpdate(corto_event* _this, uint16_t kind);
#define corto_eventUpdate(_this, kind) _corto_eventUpdate(corto_event(_this), kind)

CORTO_EXPORT corto_event* _corto_eventDeclare(void);
#define corto_eventDeclare() _corto_eventDeclare()
#define corto_eventDeclare_auto(_id) corto_event* _id = corto_eventDeclare(); (void)_id
CORTO_EXPORT corto_event* _corto_eventDeclareChild(corto_object _parent, corto_string _id);
#define corto_eventDeclareChild(_parent, _id) _corto_eventDeclareChild(_parent, _id)
#define corto_eventDeclareChild_auto(_parent, _id) corto_event* _id = corto_eventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_eventDefine(corto_event* _this, uint16_t kind);
#define corto_eventDefine(_this, kind) _corto_eventDefine(corto_event(_this), kind)
CORTO_EXPORT corto_event* _corto_eventAssign(corto_event* _this, uint16_t kind);
#define corto_event__optional_NotSet NULL
#define corto_event__optional_Set(kind) corto_eventAssign((corto_event*)corto_calloc(sizeof(corto_event)), kind)
#define corto_event__optional_SetCond(cond, kind) cond ? corto_eventAssign((corto_event*)corto_calloc(sizeof(corto_event)), kind) : NULL
#define corto_eventUnset(_this) _this ? corto_ptr_deinit(_this, corto_event_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_eventAssign(_this, kind) _corto_eventAssign(_this, kind)
#define corto_eventSet(_this, kind) _this = _this ? _this : (corto_event*)corto_calloc(sizeof(corto_event)); _corto_eventAssign(_this, kind)

/* /corto/core/eventMask */
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreate(corto_eventMask value);
#define corto_eventMaskCreate(value) _corto_eventMaskCreate(value)
#define corto_eventMaskCreate_auto(_id, value) corto_eventMask* _id = corto_eventMaskCreate(value); (void)_id
CORTO_EXPORT corto_eventMask* _corto_eventMaskCreateChild(corto_object _parent, corto_string _id, corto_eventMask value);
#define corto_eventMaskCreateChild(_parent, _id, value) _corto_eventMaskCreateChild(_parent, _id, value)
#define corto_eventMaskCreateChild_auto(_parent, _id, value) corto_eventMask* _id = corto_eventMaskCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_eventMaskUpdate(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskUpdate(_this, value) _corto_eventMaskUpdate(corto_eventMask(_this), value)

CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclare(void);
#define corto_eventMaskDeclare() _corto_eventMaskDeclare()
#define corto_eventMaskDeclare_auto(_id) corto_eventMask* _id = corto_eventMaskDeclare(); (void)_id
CORTO_EXPORT corto_eventMask* _corto_eventMaskDeclareChild(corto_object _parent, corto_string _id);
#define corto_eventMaskDeclareChild(_parent, _id) _corto_eventMaskDeclareChild(_parent, _id)
#define corto_eventMaskDeclareChild_auto(_parent, _id) corto_eventMask* _id = corto_eventMaskDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_eventMaskDefine(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMaskDefine(_this, value) _corto_eventMaskDefine(corto_eventMask(_this), value)
CORTO_EXPORT corto_eventMask* _corto_eventMaskAssign(corto_eventMask* _this, corto_eventMask value);
#define corto_eventMask__optional_NotSet NULL
#define corto_eventMask__optional_Set(value) corto_eventMaskAssign((corto_eventMask*)corto_calloc(sizeof(corto_eventMask)), value)
#define corto_eventMask__optional_SetCond(cond, value) cond ? corto_eventMaskAssign((corto_eventMask*)corto_calloc(sizeof(corto_eventMask)), value) : NULL
#define corto_eventMaskUnset(_this) _this ? corto_ptr_deinit(_this, corto_eventMask_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_eventMaskAssign(_this, value) _corto_eventMaskAssign(_this, value)
#define corto_eventMaskSet(_this, value) _this = _this ? _this : (corto_eventMask*)corto_calloc(sizeof(corto_eventMask)); _corto_eventMaskAssign(_this, value)

/* /corto/core/frame */
CORTO_EXPORT corto_frame* _corto_frameCreate(corto_frameKind kind, int64_t value);
#define corto_frameCreate(kind, value) _corto_frameCreate(kind, value)
#define corto_frameCreate_auto(_id, kind, value) corto_frame* _id = corto_frameCreate(kind, value); (void)_id
CORTO_EXPORT corto_frame* _corto_frameCreateChild(corto_object _parent, corto_string _id, corto_frameKind kind, int64_t value);
#define corto_frameCreateChild(_parent, _id, kind, value) _corto_frameCreateChild(_parent, _id, kind, value)
#define corto_frameCreateChild_auto(_parent, _id, kind, value) corto_frame* _id = corto_frameCreateChild(_parent, #_id, kind, value); (void)_id
CORTO_EXPORT corto_int16 _corto_frameUpdate(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frameUpdate(_this, kind, value) _corto_frameUpdate(corto_frame(_this), kind, value)

CORTO_EXPORT corto_frame* _corto_frameDeclare(void);
#define corto_frameDeclare() _corto_frameDeclare()
#define corto_frameDeclare_auto(_id) corto_frame* _id = corto_frameDeclare(); (void)_id
CORTO_EXPORT corto_frame* _corto_frameDeclareChild(corto_object _parent, corto_string _id);
#define corto_frameDeclareChild(_parent, _id) _corto_frameDeclareChild(_parent, _id)
#define corto_frameDeclareChild_auto(_parent, _id) corto_frame* _id = corto_frameDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_frameDefine(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frameDefine(_this, kind, value) _corto_frameDefine(corto_frame(_this), kind, value)
CORTO_EXPORT corto_frame* _corto_frameAssign(corto_frame* _this, corto_frameKind kind, int64_t value);
#define corto_frame__optional_NotSet NULL
#define corto_frame__optional_Set(kind, value) corto_frameAssign((corto_frame*)corto_calloc(sizeof(corto_frame)), kind, value)
#define corto_frame__optional_SetCond(cond, kind, value) cond ? corto_frameAssign((corto_frame*)corto_calloc(sizeof(corto_frame)), kind, value) : NULL
#define corto_frameUnset(_this) _this ? corto_ptr_deinit(_this, corto_frame_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_frameAssign(_this, kind, value) _corto_frameAssign(_this, kind, value)
#define corto_frameSet(_this, kind, value) _this = _this ? _this : (corto_frame*)corto_calloc(sizeof(corto_frame)); _corto_frameAssign(_this, kind, value)

/* /corto/core/frameKind */
CORTO_EXPORT corto_frameKind* _corto_frameKindCreate(corto_frameKind value);
#define corto_frameKindCreate(value) _corto_frameKindCreate(value)
#define corto_frameKindCreate_auto(_id, value) corto_frameKind* _id = corto_frameKindCreate(value); (void)_id
CORTO_EXPORT corto_frameKind* _corto_frameKindCreateChild(corto_object _parent, corto_string _id, corto_frameKind value);
#define corto_frameKindCreateChild(_parent, _id, value) _corto_frameKindCreateChild(_parent, _id, value)
#define corto_frameKindCreateChild_auto(_parent, _id, value) corto_frameKind* _id = corto_frameKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_frameKindUpdate(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKindUpdate(_this, value) _corto_frameKindUpdate(corto_frameKind(_this), value)

CORTO_EXPORT corto_frameKind* _corto_frameKindDeclare(void);
#define corto_frameKindDeclare() _corto_frameKindDeclare()
#define corto_frameKindDeclare_auto(_id) corto_frameKind* _id = corto_frameKindDeclare(); (void)_id
CORTO_EXPORT corto_frameKind* _corto_frameKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_frameKindDeclareChild(_parent, _id) _corto_frameKindDeclareChild(_parent, _id)
#define corto_frameKindDeclareChild_auto(_parent, _id) corto_frameKind* _id = corto_frameKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_frameKindDefine(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKindDefine(_this, value) _corto_frameKindDefine(corto_frameKind(_this), value)
CORTO_EXPORT corto_frameKind* _corto_frameKindAssign(corto_frameKind* _this, corto_frameKind value);
#define corto_frameKind__optional_NotSet NULL
#define corto_frameKind__optional_Set(value) corto_frameKindAssign((corto_frameKind*)corto_calloc(sizeof(corto_frameKind)), value)
#define corto_frameKind__optional_SetCond(cond, value) cond ? corto_frameKindAssign((corto_frameKind*)corto_calloc(sizeof(corto_frameKind)), value) : NULL
#define corto_frameKindUnset(_this) _this ? corto_ptr_deinit(_this, corto_frameKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_frameKindAssign(_this, value) _corto_frameKindAssign(_this, value)
#define corto_frameKindSet(_this, value) _this = _this ? _this : (corto_frameKind*)corto_calloc(sizeof(corto_frameKind)); _corto_frameKindAssign(_this, value)

/* /corto/core/handleAction */
CORTO_EXPORT corto_handleAction* _corto_handleActionCreate(corto_object instance, corto_function procedure);
#define corto_handleActionCreate(instance, procedure) _corto_handleActionCreate(instance, corto_function(procedure))
#define corto_handleActionCreate_auto(_id, instance, procedure) corto_handleAction* _id = corto_handleActionCreate(instance, procedure); (void)_id
CORTO_EXPORT corto_handleAction* _corto_handleActionCreateChild(corto_object _parent, corto_string _id, corto_object instance, corto_function procedure);
#define corto_handleActionCreateChild(_parent, _id, instance, procedure) _corto_handleActionCreateChild(_parent, _id, instance, corto_function(procedure))
#define corto_handleActionCreateChild_auto(_parent, _id, instance, procedure) corto_handleAction* _id = corto_handleActionCreateChild(_parent, #_id, instance, procedure); (void)_id
CORTO_EXPORT corto_int16 _corto_handleActionUpdate(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleActionUpdate(_this, instance, procedure) _corto_handleActionUpdate(corto_handleAction(_this), instance, corto_function(procedure))

CORTO_EXPORT corto_handleAction* _corto_handleActionDeclare(void);
#define corto_handleActionDeclare() _corto_handleActionDeclare()
#define corto_handleActionDeclare_auto(_id) corto_handleAction* _id = corto_handleActionDeclare(); (void)_id
CORTO_EXPORT corto_handleAction* _corto_handleActionDeclareChild(corto_object _parent, corto_string _id);
#define corto_handleActionDeclareChild(_parent, _id) _corto_handleActionDeclareChild(_parent, _id)
#define corto_handleActionDeclareChild_auto(_parent, _id) corto_handleAction* _id = corto_handleActionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_handleActionDefine(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleActionDefine(_this, instance, procedure) _corto_handleActionDefine(corto_handleAction(_this), instance, corto_function(procedure))
CORTO_EXPORT corto_handleAction* _corto_handleActionAssign(corto_handleAction* _this, corto_object instance, corto_function procedure);
#define corto_handleAction__optional_NotSet NULL
#define corto_handleAction__optional_Set(instance, procedure) corto_handleActionAssign((corto_handleAction*)corto_calloc(sizeof(corto_handleAction)), instance, procedure)
#define corto_handleAction__optional_SetCond(cond, instance, procedure) cond ? corto_handleActionAssign((corto_handleAction*)corto_calloc(sizeof(corto_handleAction)), instance, procedure) : NULL
#define corto_handleActionUnset(_this) _this ? corto_ptr_deinit(_this, corto_handleAction_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_handleActionAssign(_this, instance, procedure) _corto_handleActionAssign(_this, instance, corto_function(procedure))
#define corto_handleActionSet(_this, instance, procedure) _this = _this ? _this : (corto_handleAction*)corto_calloc(sizeof(corto_handleAction)); _corto_handleActionAssign(_this, instance, corto_function(procedure))

corto_int16 corto_handleActionCall(corto_handleAction *_delegate, corto_event* event);
#define corto_handleActionInitC_auto(d, callback) corto_handleAction d; corto_handleActionInitC(&d, callback)
CORTO_EXPORT corto_int16 corto_handleActionInitC(corto_handleAction *d, corto_void ___ (*callback)(corto_event*));
#define corto_handleActionInitCInstance_auto(d, instance, callback)corto_handleAction d; corto_handleActionInitCInstance(&d, instance, callback)
CORTO_EXPORT corto_int16 corto_handleActionInitCInstance(corto_handleAction *d, corto_object instance, corto_void ___ (*callback)(corto_object, corto_event*));
/* /corto/core/invokeEvent */
CORTO_EXPORT corto_invokeEvent _corto_invokeEventCreate(corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventCreate(mount, instance, function, args) _corto_invokeEventCreate(corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventCreate_auto(_id, mount, instance, function, args) corto_invokeEvent _id = corto_invokeEventCreate(mount, instance, function, args); (void)_id
CORTO_EXPORT corto_invokeEvent _corto_invokeEventCreateChild(corto_object _parent, corto_string _id, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventCreateChild(_parent, _id, mount, instance, function, args) _corto_invokeEventCreateChild(_parent, _id, corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventCreateChild_auto(_parent, _id, mount, instance, function, args) corto_invokeEvent _id = corto_invokeEventCreateChild(_parent, #_id, mount, instance, function, args); (void)_id
CORTO_EXPORT corto_int16 _corto_invokeEventUpdate(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventUpdate(_this, mount, instance, function, args) _corto_invokeEventUpdate(corto_invokeEvent(_this), corto_mount(mount), instance, corto_function(function), args)

CORTO_EXPORT corto_invokeEvent _corto_invokeEventDeclare(void);
#define corto_invokeEventDeclare() _corto_invokeEventDeclare()
#define corto_invokeEventDeclare_auto(_id) corto_invokeEvent _id = corto_invokeEventDeclare(); (void)_id
CORTO_EXPORT corto_invokeEvent _corto_invokeEventDeclareChild(corto_object _parent, corto_string _id);
#define corto_invokeEventDeclareChild(_parent, _id) _corto_invokeEventDeclareChild(_parent, _id)
#define corto_invokeEventDeclareChild_auto(_parent, _id) corto_invokeEvent _id = corto_invokeEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_invokeEventDefine(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEventDefine(_this, mount, instance, function, args) _corto_invokeEventDefine(corto_invokeEvent(_this), corto_mount(mount), instance, corto_function(function), args)
CORTO_EXPORT corto_invokeEvent _corto_invokeEventAssign(corto_invokeEvent _this, corto_mount mount, corto_object instance, corto_function function, uintptr_t args);
#define corto_invokeEvent__optional_NotSet NULL
#define corto_invokeEvent__optional_Set(mount, instance, function, args) corto_invokeEventAssign((corto_invokeEvent*)corto_calloc(sizeof(corto_invokeEvent)), mount, instance, function, args)
#define corto_invokeEvent__optional_SetCond(cond, mount, instance, function, args) cond ? corto_invokeEventAssign((corto_invokeEvent*)corto_calloc(sizeof(corto_invokeEvent)), mount, instance, function, args) : NULL
#define corto_invokeEventUnset(_this) _this ? corto_ptr_deinit(_this, corto_invokeEvent_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_invokeEventAssign(_this, mount, instance, function, args) _corto_invokeEventAssign(_this, corto_mount(mount), instance, corto_function(function), args)
#define corto_invokeEventSet(_this, mount, instance, function, args) _this = _this ? _this : (corto_invokeEvent*)corto_calloc(sizeof(corto_invokeEvent)); _corto_invokeEventAssign(_this, corto_mount(mount), instance, corto_function(function), args)

/* /corto/core/loader */
CORTO_EXPORT corto_loader _corto_loaderCreate(bool autoLoad);
#define corto_loaderCreate(autoLoad) _corto_loaderCreate(autoLoad)
#define corto_loaderCreate_auto(_id, autoLoad) corto_loader _id = corto_loaderCreate(autoLoad); (void)_id
CORTO_EXPORT corto_loader _corto_loaderCreateChild(corto_object _parent, corto_string _id, bool autoLoad);
#define corto_loaderCreateChild(_parent, _id, autoLoad) _corto_loaderCreateChild(_parent, _id, autoLoad)
#define corto_loaderCreateChild_auto(_parent, _id, autoLoad) corto_loader _id = corto_loaderCreateChild(_parent, #_id, autoLoad); (void)_id
CORTO_EXPORT corto_int16 _corto_loaderUpdate(corto_loader _this, bool autoLoad);
#define corto_loaderUpdate(_this, autoLoad) _corto_loaderUpdate(corto_loader(_this), autoLoad)

CORTO_EXPORT corto_loader _corto_loaderDeclare(void);
#define corto_loaderDeclare() _corto_loaderDeclare()
#define corto_loaderDeclare_auto(_id) corto_loader _id = corto_loaderDeclare(); (void)_id
CORTO_EXPORT corto_loader _corto_loaderDeclareChild(corto_object _parent, corto_string _id);
#define corto_loaderDeclareChild(_parent, _id) _corto_loaderDeclareChild(_parent, _id)
#define corto_loaderDeclareChild_auto(_parent, _id) corto_loader _id = corto_loaderDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_loaderDefine(corto_loader _this, bool autoLoad);
#define corto_loaderDefine(_this, autoLoad) _corto_loaderDefine(corto_loader(_this), autoLoad)
CORTO_EXPORT corto_loader _corto_loaderAssign(corto_loader _this, bool autoLoad);
#define corto_loader__optional_NotSet NULL
#define corto_loader__optional_Set(autoLoad) corto_loaderAssign((corto_loader*)corto_calloc(sizeof(corto_loader)), autoLoad)
#define corto_loader__optional_SetCond(cond, autoLoad) cond ? corto_loaderAssign((corto_loader*)corto_calloc(sizeof(corto_loader)), autoLoad) : NULL
#define corto_loaderUnset(_this) _this ? corto_ptr_deinit(_this, corto_loader_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_loaderAssign(_this, autoLoad) _corto_loaderAssign(_this, autoLoad)
#define corto_loaderSet(_this, autoLoad) _this = _this ? _this : (corto_loader*)corto_calloc(sizeof(corto_loader)); _corto_loaderAssign(_this, autoLoad)

/* /corto/core/mount */
CORTO_EXPORT corto_mount _corto_mountCreate(corto_mountKind kind, corto_string parent, corto_string expr, corto_string type, corto_string contentType, corto_string policy);
#define corto_mountCreate(kind, parent, expr, type, contentType, policy) _corto_mountCreate(kind, parent, expr, type, contentType, policy)
#define corto_mountCreate_auto(_id, kind, parent, expr, type, contentType, policy) corto_mount _id = corto_mountCreate(kind, parent, expr, type, contentType, policy); (void)_id
CORTO_EXPORT corto_mount _corto_mountCreateChild(corto_object _parent, corto_string _id, corto_mountKind kind, corto_string parent, corto_string expr, corto_string type, corto_string contentType, corto_string policy);
#define corto_mountCreateChild(_parent, _id, kind, parent, expr, type, contentType, policy) _corto_mountCreateChild(_parent, _id, kind, parent, expr, type, contentType, policy)
#define corto_mountCreateChild_auto(_parent, _id, kind, parent, expr, type, contentType, policy) corto_mount _id = corto_mountCreateChild(_parent, #_id, kind, parent, expr, type, contentType, policy); (void)_id
CORTO_EXPORT corto_int16 _corto_mountUpdate(corto_mount _this, corto_mountKind kind, corto_string parent, corto_string expr, corto_string type, corto_string contentType, corto_string policy);
#define corto_mountUpdate(_this, kind, parent, expr, type, contentType, policy) _corto_mountUpdate(corto_mount(_this), kind, parent, expr, type, contentType, policy)

CORTO_EXPORT corto_mount _corto_mountDeclare(void);
#define corto_mountDeclare() _corto_mountDeclare()
#define corto_mountDeclare_auto(_id) corto_mount _id = corto_mountDeclare(); (void)_id
CORTO_EXPORT corto_mount _corto_mountDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountDeclareChild(_parent, _id) _corto_mountDeclareChild(_parent, _id)
#define corto_mountDeclareChild_auto(_parent, _id) corto_mount _id = corto_mountDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountDefine(corto_mount _this, corto_mountKind kind, corto_string parent, corto_string expr, corto_string type, corto_string contentType, corto_string policy);
#define corto_mountDefine(_this, kind, parent, expr, type, contentType, policy) _corto_mountDefine(corto_mount(_this), kind, parent, expr, type, contentType, policy)
CORTO_EXPORT corto_mount _corto_mountAssign(corto_mount _this, corto_mountKind kind, corto_string parent, corto_string expr, corto_string type, corto_string contentType, corto_string policy);
#define corto_mount__optional_NotSet NULL
#define corto_mount__optional_Set(kind, parent, expr, type, contentType, policy) corto_mountAssign((corto_mount*)corto_calloc(sizeof(corto_mount)), kind, parent, expr, type, contentType, policy)
#define corto_mount__optional_SetCond(cond, kind, parent, expr, type, contentType, policy) cond ? corto_mountAssign((corto_mount*)corto_calloc(sizeof(corto_mount)), kind, parent, expr, type, contentType, policy) : NULL
#define corto_mountUnset(_this) _this ? corto_ptr_deinit(_this, corto_mount_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountAssign(_this, kind, parent, expr, type, contentType, policy) _corto_mountAssign(_this, kind, parent, expr, type, contentType, policy)
#define corto_mountSet(_this, kind, parent, expr, type, contentType, policy) _this = _this ? _this : (corto_mount*)corto_calloc(sizeof(corto_mount)); _corto_mountAssign(_this, kind, parent, expr, type, contentType, policy)

/* /corto/core/mountKind */
CORTO_EXPORT corto_mountKind* _corto_mountKindCreate(corto_mountKind value);
#define corto_mountKindCreate(value) _corto_mountKindCreate(value)
#define corto_mountKindCreate_auto(_id, value) corto_mountKind* _id = corto_mountKindCreate(value); (void)_id
CORTO_EXPORT corto_mountKind* _corto_mountKindCreateChild(corto_object _parent, corto_string _id, corto_mountKind value);
#define corto_mountKindCreateChild(_parent, _id, value) _corto_mountKindCreateChild(_parent, _id, value)
#define corto_mountKindCreateChild_auto(_parent, _id, value) corto_mountKind* _id = corto_mountKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_mountKindUpdate(corto_mountKind* _this, corto_mountKind value);
#define corto_mountKindUpdate(_this, value) _corto_mountKindUpdate(corto_mountKind(_this), value)

CORTO_EXPORT corto_mountKind* _corto_mountKindDeclare(void);
#define corto_mountKindDeclare() _corto_mountKindDeclare()
#define corto_mountKindDeclare_auto(_id) corto_mountKind* _id = corto_mountKindDeclare(); (void)_id
CORTO_EXPORT corto_mountKind* _corto_mountKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountKindDeclareChild(_parent, _id) _corto_mountKindDeclareChild(_parent, _id)
#define corto_mountKindDeclareChild_auto(_parent, _id) corto_mountKind* _id = corto_mountKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountKindDefine(corto_mountKind* _this, corto_mountKind value);
#define corto_mountKindDefine(_this, value) _corto_mountKindDefine(corto_mountKind(_this), value)
CORTO_EXPORT corto_mountKind* _corto_mountKindAssign(corto_mountKind* _this, corto_mountKind value);
#define corto_mountKind__optional_NotSet NULL
#define corto_mountKind__optional_Set(value) corto_mountKindAssign((corto_mountKind*)corto_calloc(sizeof(corto_mountKind)), value)
#define corto_mountKind__optional_SetCond(cond, value) cond ? corto_mountKindAssign((corto_mountKind*)corto_calloc(sizeof(corto_mountKind)), value) : NULL
#define corto_mountKindUnset(_this) _this ? corto_ptr_deinit(_this, corto_mountKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountKindAssign(_this, value) _corto_mountKindAssign(_this, value)
#define corto_mountKindSet(_this, value) _this = _this ? _this : (corto_mountKind*)corto_calloc(sizeof(corto_mountKind)); _corto_mountKindAssign(_this, value)

/* /corto/core/mountPolicy */
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyCreate(double sampleRate);
#define corto_mountPolicyCreate(sampleRate) _corto_mountPolicyCreate(sampleRate)
#define corto_mountPolicyCreate_auto(_id, sampleRate) corto_mountPolicy* _id = corto_mountPolicyCreate(sampleRate); (void)_id
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyCreateChild(corto_object _parent, corto_string _id, double sampleRate);
#define corto_mountPolicyCreateChild(_parent, _id, sampleRate) _corto_mountPolicyCreateChild(_parent, _id, sampleRate)
#define corto_mountPolicyCreateChild_auto(_parent, _id, sampleRate) corto_mountPolicy* _id = corto_mountPolicyCreateChild(_parent, #_id, sampleRate); (void)_id
CORTO_EXPORT corto_int16 _corto_mountPolicyUpdate(corto_mountPolicy* _this, double sampleRate);
#define corto_mountPolicyUpdate(_this, sampleRate) _corto_mountPolicyUpdate(corto_mountPolicy(_this), sampleRate)

CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyDeclare(void);
#define corto_mountPolicyDeclare() _corto_mountPolicyDeclare()
#define corto_mountPolicyDeclare_auto(_id) corto_mountPolicy* _id = corto_mountPolicyDeclare(); (void)_id
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountPolicyDeclareChild(_parent, _id) _corto_mountPolicyDeclareChild(_parent, _id)
#define corto_mountPolicyDeclareChild_auto(_parent, _id) corto_mountPolicy* _id = corto_mountPolicyDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountPolicyDefine(corto_mountPolicy* _this, double sampleRate);
#define corto_mountPolicyDefine(_this, sampleRate) _corto_mountPolicyDefine(corto_mountPolicy(_this), sampleRate)
CORTO_EXPORT corto_mountPolicy* _corto_mountPolicyAssign(corto_mountPolicy* _this, double sampleRate);
#define corto_mountPolicy__optional_NotSet NULL
#define corto_mountPolicy__optional_Set(sampleRate) corto_mountPolicyAssign((corto_mountPolicy*)corto_calloc(sizeof(corto_mountPolicy)), sampleRate)
#define corto_mountPolicy__optional_SetCond(cond, sampleRate) cond ? corto_mountPolicyAssign((corto_mountPolicy*)corto_calloc(sizeof(corto_mountPolicy)), sampleRate) : NULL
#define corto_mountPolicyUnset(_this) _this ? corto_ptr_deinit(_this, corto_mountPolicy_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountPolicyAssign(_this, sampleRate) _corto_mountPolicyAssign(_this, sampleRate)
#define corto_mountPolicySet(_this, sampleRate) _this = _this ? _this : (corto_mountPolicy*)corto_calloc(sizeof(corto_mountPolicy)); _corto_mountPolicyAssign(_this, sampleRate)

/* /corto/core/mountStats */
CORTO_EXPORT corto_mountStats* _corto_mountStatsCreate(uint64_t declares, uint64_t updates, uint64_t deletes);
#define corto_mountStatsCreate(declares, updates, deletes) _corto_mountStatsCreate(declares, updates, deletes)
#define corto_mountStatsCreate_auto(_id, declares, updates, deletes) corto_mountStats* _id = corto_mountStatsCreate(declares, updates, deletes); (void)_id
CORTO_EXPORT corto_mountStats* _corto_mountStatsCreateChild(corto_object _parent, corto_string _id, uint64_t declares, uint64_t updates, uint64_t deletes);
#define corto_mountStatsCreateChild(_parent, _id, declares, updates, deletes) _corto_mountStatsCreateChild(_parent, _id, declares, updates, deletes)
#define corto_mountStatsCreateChild_auto(_parent, _id, declares, updates, deletes) corto_mountStats* _id = corto_mountStatsCreateChild(_parent, #_id, declares, updates, deletes); (void)_id
CORTO_EXPORT corto_int16 _corto_mountStatsUpdate(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes);
#define corto_mountStatsUpdate(_this, declares, updates, deletes) _corto_mountStatsUpdate(corto_mountStats(_this), declares, updates, deletes)

CORTO_EXPORT corto_mountStats* _corto_mountStatsDeclare(void);
#define corto_mountStatsDeclare() _corto_mountStatsDeclare()
#define corto_mountStatsDeclare_auto(_id) corto_mountStats* _id = corto_mountStatsDeclare(); (void)_id
CORTO_EXPORT corto_mountStats* _corto_mountStatsDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountStatsDeclareChild(_parent, _id) _corto_mountStatsDeclareChild(_parent, _id)
#define corto_mountStatsDeclareChild_auto(_parent, _id) corto_mountStats* _id = corto_mountStatsDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountStatsDefine(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes);
#define corto_mountStatsDefine(_this, declares, updates, deletes) _corto_mountStatsDefine(corto_mountStats(_this), declares, updates, deletes)
CORTO_EXPORT corto_mountStats* _corto_mountStatsAssign(corto_mountStats* _this, uint64_t declares, uint64_t updates, uint64_t deletes);
#define corto_mountStats__optional_NotSet NULL
#define corto_mountStats__optional_Set(declares, updates, deletes) corto_mountStatsAssign((corto_mountStats*)corto_calloc(sizeof(corto_mountStats)), declares, updates, deletes)
#define corto_mountStats__optional_SetCond(cond, declares, updates, deletes) cond ? corto_mountStatsAssign((corto_mountStats*)corto_calloc(sizeof(corto_mountStats)), declares, updates, deletes) : NULL
#define corto_mountStatsUnset(_this) _this ? corto_ptr_deinit(_this, corto_mountStats_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountStatsAssign(_this, declares, updates, deletes) _corto_mountStatsAssign(_this, declares, updates, deletes)
#define corto_mountStatsSet(_this, declares, updates, deletes) _this = _this ? _this : (corto_mountStats*)corto_calloc(sizeof(corto_mountStats)); _corto_mountStatsAssign(_this, declares, updates, deletes)

/* /corto/core/mountSubscription */
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionCreate(corto_string parent, corto_string expr, corto_eventMask mask, uint32_t count, uintptr_t userData);
#define corto_mountSubscriptionCreate(parent, expr, mask, count, userData) _corto_mountSubscriptionCreate(parent, expr, mask, count, userData)
#define corto_mountSubscriptionCreate_auto(_id, parent, expr, mask, count, userData) corto_mountSubscription* _id = corto_mountSubscriptionCreate(parent, expr, mask, count, userData); (void)_id
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionCreateChild(corto_object _parent, corto_string _id, corto_string parent, corto_string expr, corto_eventMask mask, uint32_t count, uintptr_t userData);
#define corto_mountSubscriptionCreateChild(_parent, _id, parent, expr, mask, count, userData) _corto_mountSubscriptionCreateChild(_parent, _id, parent, expr, mask, count, userData)
#define corto_mountSubscriptionCreateChild_auto(_parent, _id, parent, expr, mask, count, userData) corto_mountSubscription* _id = corto_mountSubscriptionCreateChild(_parent, #_id, parent, expr, mask, count, userData); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionUpdate(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, uint32_t count, uintptr_t userData);
#define corto_mountSubscriptionUpdate(_this, parent, expr, mask, count, userData) _corto_mountSubscriptionUpdate(corto_mountSubscription(_this), parent, expr, mask, count, userData)

CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionDeclare(void);
#define corto_mountSubscriptionDeclare() _corto_mountSubscriptionDeclare()
#define corto_mountSubscriptionDeclare_auto(_id) corto_mountSubscription* _id = corto_mountSubscriptionDeclare(); (void)_id
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountSubscriptionDeclareChild(_parent, _id) _corto_mountSubscriptionDeclareChild(_parent, _id)
#define corto_mountSubscriptionDeclareChild_auto(_parent, _id) corto_mountSubscription* _id = corto_mountSubscriptionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionDefine(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, uint32_t count, uintptr_t userData);
#define corto_mountSubscriptionDefine(_this, parent, expr, mask, count, userData) _corto_mountSubscriptionDefine(corto_mountSubscription(_this), parent, expr, mask, count, userData)
CORTO_EXPORT corto_mountSubscription* _corto_mountSubscriptionAssign(corto_mountSubscription* _this, corto_string parent, corto_string expr, corto_eventMask mask, uint32_t count, uintptr_t userData);
#define corto_mountSubscription__optional_NotSet NULL
#define corto_mountSubscription__optional_Set(parent, expr, mask, count, userData) corto_mountSubscriptionAssign((corto_mountSubscription*)corto_calloc(sizeof(corto_mountSubscription)), parent, expr, mask, count, userData)
#define corto_mountSubscription__optional_SetCond(cond, parent, expr, mask, count, userData) cond ? corto_mountSubscriptionAssign((corto_mountSubscription*)corto_calloc(sizeof(corto_mountSubscription)), parent, expr, mask, count, userData) : NULL
#define corto_mountSubscriptionUnset(_this) _this ? corto_ptr_deinit(_this, corto_mountSubscription_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountSubscriptionAssign(_this, parent, expr, mask, count, userData) _corto_mountSubscriptionAssign(_this, parent, expr, mask, count, userData)
#define corto_mountSubscriptionSet(_this, parent, expr, mask, count, userData) _this = _this ? _this : (corto_mountSubscription*)corto_calloc(sizeof(corto_mountSubscription)); _corto_mountSubscriptionAssign(_this, parent, expr, mask, count, userData)

/* /corto/core/mountSubscriptionList */
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListCreate(corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListCreate(length, elements) _corto_mountSubscriptionListCreate(length, elements)
#define corto_mountSubscriptionListCreate_auto(_id, length, elements) corto_mountSubscriptionList* _id = corto_mountSubscriptionListCreate(length, elements); (void)_id
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListCreateChild(_parent, _id, length, elements) _corto_mountSubscriptionListCreateChild(_parent, _id, length, elements)
#define corto_mountSubscriptionListCreateChild_auto(_parent, _id, length, elements) corto_mountSubscriptionList* _id = corto_mountSubscriptionListCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListUpdate(_this, length, elements) _corto_mountSubscriptionListUpdate(corto_mountSubscriptionList(_this), length, elements)

CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListDeclare(void);
#define corto_mountSubscriptionListDeclare() _corto_mountSubscriptionListDeclare()
#define corto_mountSubscriptionListDeclare_auto(_id) corto_mountSubscriptionList* _id = corto_mountSubscriptionListDeclare(); (void)_id
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListDeclareChild(corto_object _parent, corto_string _id);
#define corto_mountSubscriptionListDeclareChild(_parent, _id) _corto_mountSubscriptionListDeclareChild(_parent, _id)
#define corto_mountSubscriptionListDeclareChild_auto(_parent, _id) corto_mountSubscriptionList* _id = corto_mountSubscriptionListDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_mountSubscriptionListDefine(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionListDefine(_this, length, elements) _corto_mountSubscriptionListDefine(corto_mountSubscriptionList(_this), length, elements)
CORTO_EXPORT corto_mountSubscriptionList* _corto_mountSubscriptionListAssign(corto_mountSubscriptionList* _this, corto_uint32 length, corto_mountSubscription* elements);
#define corto_mountSubscriptionList__optional_NotSet NULL
#define corto_mountSubscriptionList__optional_Set(length, elements) corto_mountSubscriptionListAssign((corto_mountSubscriptionList*)corto_calloc(sizeof(corto_mountSubscriptionList)), length, elements)
#define corto_mountSubscriptionList__optional_SetCond(cond, length, elements) cond ? corto_mountSubscriptionListAssign((corto_mountSubscriptionList*)corto_calloc(sizeof(corto_mountSubscriptionList)), length, elements) : NULL
#define corto_mountSubscriptionListUnset(_this) _this ? corto_ptr_deinit(_this, corto_mountSubscriptionList_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_mountSubscriptionListAssign(_this, length, elements) _corto_mountSubscriptionListAssign(_this, length, elements)
#define corto_mountSubscriptionListSet(_this, length, elements) _this = _this ? _this : (corto_mountSubscriptionList*)corto_calloc(sizeof(corto_mountSubscriptionList)); _corto_mountSubscriptionListAssign(_this, length, elements)

/* /corto/core/objectIter */
CORTO_EXPORT corto_objectIter* _corto_objectIterCreate(void);
#define corto_objectIterCreate() _corto_objectIterCreate()
#define corto_objectIterCreate_auto(_id) corto_objectIter* _id = corto_objectIterCreate(); (void)_id
CORTO_EXPORT corto_objectIter* _corto_objectIterCreateChild(corto_object _parent, corto_string _id);
#define corto_objectIterCreateChild(_parent, _id) _corto_objectIterCreateChild(_parent, _id)
#define corto_objectIterCreateChild_auto(_parent, _id) corto_objectIter* _id = corto_objectIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectIterUpdate(corto_objectIter* _this);
#define corto_objectIterUpdate(_this) _corto_objectIterUpdate(corto_objectIter(_this))

CORTO_EXPORT corto_objectIter* _corto_objectIterDeclare(void);
#define corto_objectIterDeclare() _corto_objectIterDeclare()
#define corto_objectIterDeclare_auto(_id) corto_objectIter* _id = corto_objectIterDeclare(); (void)_id
CORTO_EXPORT corto_objectIter* _corto_objectIterDeclareChild(corto_object _parent, corto_string _id);
#define corto_objectIterDeclareChild(_parent, _id) _corto_objectIterDeclareChild(_parent, _id)
#define corto_objectIterDeclareChild_auto(_parent, _id) corto_objectIter* _id = corto_objectIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_objectIterDefine(corto_objectIter* _this);
#define corto_objectIterDefine(_this) _corto_objectIterDefine(corto_objectIter(_this))
CORTO_EXPORT corto_objectIter* _corto_objectIterAssign(corto_objectIter* _this);
#define corto_objectIter__optional_NotSet NULL
#define corto_objectIter__optional_Set() corto_objectIterAssign((corto_objectIter*)corto_calloc(sizeof(corto_objectIter)))
#define corto_objectIter__optional_SetCond(cond) cond ? corto_objectIterAssign((corto_objectIter*)corto_calloc(sizeof(corto_objectIter))) : NULL
#define corto_objectIterUnset(_this) _this ? corto_ptr_deinit(_this, corto_objectIter_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_objectIterAssign(_this) _corto_objectIterAssign(_this)
#define corto_objectIterSet(_this) _this = _this ? _this : (corto_objectIter*)corto_calloc(sizeof(corto_objectIter)); _corto_objectIterAssign(_this)

/* /corto/core/observer */
CORTO_EXPORT corto_observer _corto_observerCreate(corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_observerCreate(mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerCreate(mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_observerCreate_auto(_id, mask, observable, instance, dispatcher, type, enabled, _impl) corto_observer _id = corto_observerCreate(mask, observable, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_observer _corto_observerCreateChild(corto_object _parent, corto_string _id, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_observerCreateChild(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerCreateChild(_parent, _id, mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_observerCreateChild_auto(_parent, _id, mask, observable, instance, dispatcher, type, enabled, _impl) corto_observer _id = corto_observerCreateChild(_parent, #_id, mask, observable, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_observerUpdate(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_observerUpdate(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerUpdate(corto_observer(_this), mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)

CORTO_EXPORT corto_observer _corto_observerDeclare(void);
#define corto_observerDeclare() _corto_observerDeclare()
#define corto_observerDeclare_auto(_id) corto_observer _id = corto_observerDeclare(); (void)_id
CORTO_EXPORT corto_observer _corto_observerDeclareChild(corto_object _parent, corto_string _id);
#define corto_observerDeclareChild(_parent, _id) _corto_observerDeclareChild(_parent, _id)
#define corto_observerDeclareChild_auto(_parent, _id) corto_observer _id = corto_observerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_observerDefine(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_observerDefine(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerDefine(corto_observer(_this), mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_observer _corto_observerAssign(corto_observer _this, corto_eventMask mask, corto_object observable, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_observer__optional_NotSet NULL
#define corto_observer__optional_Set(mask, observable, instance, dispatcher, type, enabled, _impl) corto_observerAssign((corto_observer*)corto_calloc(sizeof(corto_observer)), mask, observable, instance, dispatcher, type, enabled, _impl)
#define corto_observer__optional_SetCond(cond, mask, observable, instance, dispatcher, type, enabled, _impl) cond ? corto_observerAssign((corto_observer*)corto_calloc(sizeof(corto_observer)), mask, observable, instance, dispatcher, type, enabled, _impl) : NULL
#define corto_observerUnset(_this) _this ? corto_ptr_deinit(_this, corto_observer_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_observerAssign(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _corto_observerAssign(_this, mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_observerSet(_this, mask, observable, instance, dispatcher, type, enabled, _impl) _this = _this ? _this : (corto_observer*)corto_calloc(sizeof(corto_observer)); _corto_observerAssign(_this, mask, observable, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)

/* /corto/core/observerEvent */
CORTO_EXPORT corto_observerEvent* _corto_observerEventCreate(uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventCreate(kind, observer, instance, source, event, data, thread) _corto_observerEventCreate(kind, corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventCreate_auto(_id, kind, observer, instance, source, event, data, thread) corto_observerEvent* _id = corto_observerEventCreate(kind, observer, instance, source, event, data, thread); (void)_id
CORTO_EXPORT corto_observerEvent* _corto_observerEventCreateChild(corto_object _parent, corto_string _id, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventCreateChild(_parent, _id, kind, observer, instance, source, event, data, thread) _corto_observerEventCreateChild(_parent, _id, kind, corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventCreateChild_auto(_parent, _id, kind, observer, instance, source, event, data, thread) corto_observerEvent* _id = corto_observerEventCreateChild(_parent, #_id, kind, observer, instance, source, event, data, thread); (void)_id
CORTO_EXPORT corto_int16 _corto_observerEventUpdate(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventUpdate(_this, kind, observer, instance, source, event, data, thread) _corto_observerEventUpdate(corto_observerEvent(_this), kind, corto_observer(observer), instance, source, event, data, thread)

CORTO_EXPORT corto_observerEvent* _corto_observerEventDeclare(void);
#define corto_observerEventDeclare() _corto_observerEventDeclare()
#define corto_observerEventDeclare_auto(_id) corto_observerEvent* _id = corto_observerEventDeclare(); (void)_id
CORTO_EXPORT corto_observerEvent* _corto_observerEventDeclareChild(corto_object _parent, corto_string _id);
#define corto_observerEventDeclareChild(_parent, _id) _corto_observerEventDeclareChild(_parent, _id)
#define corto_observerEventDeclareChild_auto(_parent, _id) corto_observerEvent* _id = corto_observerEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_observerEventDefine(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEventDefine(_this, kind, observer, instance, source, event, data, thread) _corto_observerEventDefine(corto_observerEvent(_this), kind, corto_observer(observer), instance, source, event, data, thread)
CORTO_EXPORT corto_observerEvent* _corto_observerEventAssign(corto_observerEvent* _this, uint16_t kind, corto_observer observer, corto_object instance, corto_object source, corto_eventMask event, corto_object data, uintptr_t thread);
#define corto_observerEvent__optional_NotSet NULL
#define corto_observerEvent__optional_Set(kind, observer, instance, source, event, data, thread) corto_observerEventAssign((corto_observerEvent*)corto_calloc(sizeof(corto_observerEvent)), kind, observer, instance, source, event, data, thread)
#define corto_observerEvent__optional_SetCond(cond, kind, observer, instance, source, event, data, thread) cond ? corto_observerEventAssign((corto_observerEvent*)corto_calloc(sizeof(corto_observerEvent)), kind, observer, instance, source, event, data, thread) : NULL
#define corto_observerEventUnset(_this) _this ? corto_ptr_deinit(_this, corto_observerEvent_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_observerEventAssign(_this, kind, observer, instance, source, event, data, thread) _corto_observerEventAssign(_this, kind, corto_observer(observer), instance, source, event, data, thread)
#define corto_observerEventSet(_this, kind, observer, instance, source, event, data, thread) _this = _this ? _this : (corto_observerEvent*)corto_calloc(sizeof(corto_observerEvent)); _corto_observerEventAssign(_this, kind, corto_observer(observer), instance, source, event, data, thread)

/* /corto/core/operatorKind */
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreate(corto_operatorKind value);
#define corto_operatorKindCreate(value) _corto_operatorKindCreate(value)
#define corto_operatorKindCreate_auto(_id, value) corto_operatorKind* _id = corto_operatorKindCreate(value); (void)_id
CORTO_EXPORT corto_operatorKind* _corto_operatorKindCreateChild(corto_object _parent, corto_string _id, corto_operatorKind value);
#define corto_operatorKindCreateChild(_parent, _id, value) _corto_operatorKindCreateChild(_parent, _id, value)
#define corto_operatorKindCreateChild_auto(_parent, _id, value) corto_operatorKind* _id = corto_operatorKindCreateChild(_parent, #_id, value); (void)_id
CORTO_EXPORT corto_int16 _corto_operatorKindUpdate(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindUpdate(_this, value) _corto_operatorKindUpdate(corto_operatorKind(_this), value)

CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclare(void);
#define corto_operatorKindDeclare() _corto_operatorKindDeclare()
#define corto_operatorKindDeclare_auto(_id) corto_operatorKind* _id = corto_operatorKindDeclare(); (void)_id
CORTO_EXPORT corto_operatorKind* _corto_operatorKindDeclareChild(corto_object _parent, corto_string _id);
#define corto_operatorKindDeclareChild(_parent, _id) _corto_operatorKindDeclareChild(_parent, _id)
#define corto_operatorKindDeclareChild_auto(_parent, _id) corto_operatorKind* _id = corto_operatorKindDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_operatorKindDefine(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKindDefine(_this, value) _corto_operatorKindDefine(corto_operatorKind(_this), value)
CORTO_EXPORT corto_operatorKind* _corto_operatorKindAssign(corto_operatorKind* _this, corto_operatorKind value);
#define corto_operatorKind__optional_NotSet NULL
#define corto_operatorKind__optional_Set(value) corto_operatorKindAssign((corto_operatorKind*)corto_calloc(sizeof(corto_operatorKind)), value)
#define corto_operatorKind__optional_SetCond(cond, value) cond ? corto_operatorKindAssign((corto_operatorKind*)corto_calloc(sizeof(corto_operatorKind)), value) : NULL
#define corto_operatorKindUnset(_this) _this ? corto_ptr_deinit(_this, corto_operatorKind_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_operatorKindAssign(_this, value) _corto_operatorKindAssign(_this, value)
#define corto_operatorKindSet(_this, value) _this = _this ? _this : (corto_operatorKind*)corto_calloc(sizeof(corto_operatorKind)); _corto_operatorKindAssign(_this, value)

/* /corto/core/package */
CORTO_EXPORT corto_package _corto_packageCreate(void);
#define corto_packageCreate() _corto_packageCreate()
#define corto_packageCreate_auto(_id) corto_package _id = corto_packageCreate(); (void)_id
CORTO_EXPORT corto_package _corto_packageCreateChild(corto_object _parent, corto_string _id);
#define corto_packageCreateChild(_parent, _id) _corto_packageCreateChild(_parent, _id)
#define corto_packageCreateChild_auto(_parent, _id) corto_package _id = corto_packageCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_packageUpdate(corto_package _this);
#define corto_packageUpdate(_this) _corto_packageUpdate(corto_package(_this))

CORTO_EXPORT corto_package _corto_packageDeclare(void);
#define corto_packageDeclare() _corto_packageDeclare()
#define corto_packageDeclare_auto(_id) corto_package _id = corto_packageDeclare(); (void)_id
CORTO_EXPORT corto_package _corto_packageDeclareChild(corto_object _parent, corto_string _id);
#define corto_packageDeclareChild(_parent, _id) _corto_packageDeclareChild(_parent, _id)
#define corto_packageDeclareChild_auto(_parent, _id) corto_package _id = corto_packageDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_packageDefine(corto_package _this);
#define corto_packageDefine(_this) _corto_packageDefine(corto_package(_this))
CORTO_EXPORT corto_package _corto_packageAssign(corto_package _this);
#define corto_package__optional_NotSet NULL
#define corto_package__optional_Set() corto_packageAssign((corto_package*)corto_calloc(sizeof(corto_package)))
#define corto_package__optional_SetCond(cond) cond ? corto_packageAssign((corto_package*)corto_calloc(sizeof(corto_package))) : NULL
#define corto_packageUnset(_this) _this ? corto_ptr_deinit(_this, corto_package_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_packageAssign(_this) _corto_packageAssign(_this)
#define corto_packageSet(_this) _this = _this ? _this : (corto_package*)corto_calloc(sizeof(corto_package)); _corto_packageAssign(_this)

/* /corto/core/position */
CORTO_EXPORT corto_position* _corto_positionCreate(double latitude, double longitude);
#define corto_positionCreate(latitude, longitude) _corto_positionCreate(latitude, longitude)
#define corto_positionCreate_auto(_id, latitude, longitude) corto_position* _id = corto_positionCreate(latitude, longitude); (void)_id
CORTO_EXPORT corto_position* _corto_positionCreateChild(corto_object _parent, corto_string _id, double latitude, double longitude);
#define corto_positionCreateChild(_parent, _id, latitude, longitude) _corto_positionCreateChild(_parent, _id, latitude, longitude)
#define corto_positionCreateChild_auto(_parent, _id, latitude, longitude) corto_position* _id = corto_positionCreateChild(_parent, #_id, latitude, longitude); (void)_id
CORTO_EXPORT corto_int16 _corto_positionUpdate(corto_position* _this, double latitude, double longitude);
#define corto_positionUpdate(_this, latitude, longitude) _corto_positionUpdate(corto_position(_this), latitude, longitude)

CORTO_EXPORT corto_position* _corto_positionDeclare(void);
#define corto_positionDeclare() _corto_positionDeclare()
#define corto_positionDeclare_auto(_id) corto_position* _id = corto_positionDeclare(); (void)_id
CORTO_EXPORT corto_position* _corto_positionDeclareChild(corto_object _parent, corto_string _id);
#define corto_positionDeclareChild(_parent, _id) _corto_positionDeclareChild(_parent, _id)
#define corto_positionDeclareChild_auto(_parent, _id) corto_position* _id = corto_positionDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_positionDefine(corto_position* _this, double latitude, double longitude);
#define corto_positionDefine(_this, latitude, longitude) _corto_positionDefine(corto_position(_this), latitude, longitude)
CORTO_EXPORT corto_position* _corto_positionAssign(corto_position* _this, double latitude, double longitude);
#define corto_position__optional_NotSet NULL
#define corto_position__optional_Set(latitude, longitude) corto_positionAssign((corto_position*)corto_calloc(sizeof(corto_position)), latitude, longitude)
#define corto_position__optional_SetCond(cond, latitude, longitude) cond ? corto_positionAssign((corto_position*)corto_calloc(sizeof(corto_position)), latitude, longitude) : NULL
#define corto_positionUnset(_this) _this ? corto_ptr_deinit(_this, corto_position_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_positionAssign(_this, latitude, longitude) _corto_positionAssign(_this, latitude, longitude)
#define corto_positionSet(_this, latitude, longitude) _this = _this ? _this : (corto_position*)corto_calloc(sizeof(corto_position)); _corto_positionAssign(_this, latitude, longitude)

/* /corto/core/remote */
CORTO_EXPORT corto_remote _corto_remoteCreate(corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteCreate(returnType, returnsReference, _impl) _corto_remoteCreate(corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteCreate_auto(_id, returnType, returnsReference, _impl) corto_remote _id = corto_remoteCreate(returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_remote _corto_remoteCreateChild(corto_object _parent, corto_string _id, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteCreateChild(_parent, _id, returnType, returnsReference, _impl) _corto_remoteCreateChild(_parent, _id, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteCreateChild_auto(_parent, _id, returnType, returnsReference, _impl) corto_remote _id = corto_remoteCreateChild(_parent, #_id, returnType, returnsReference, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_remoteUpdate(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteUpdate(_this, returnType, returnsReference, _impl) _corto_remoteUpdate(corto_remote(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)

CORTO_EXPORT corto_remote _corto_remoteDeclare(void);
#define corto_remoteDeclare() _corto_remoteDeclare()
#define corto_remoteDeclare_auto(_id) corto_remote _id = corto_remoteDeclare(); (void)_id
CORTO_EXPORT corto_remote _corto_remoteDeclareChild(corto_object _parent, corto_string _id);
#define corto_remoteDeclareChild(_parent, _id) _corto_remoteDeclareChild(_parent, _id)
#define corto_remoteDeclareChild_auto(_parent, _id) corto_remote _id = corto_remoteDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_remoteDefine(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remoteDefine(_this, returnType, returnsReference, _impl) _corto_remoteDefine(corto_remote(_this), corto_type(returnType), returnsReference, (void(*)(void))_impl)
CORTO_EXPORT corto_remote _corto_remoteAssign(corto_remote _this, corto_type returnType, bool returnsReference, void(*_impl)(void));
#define corto_remote__optional_NotSet NULL
#define corto_remote__optional_Set(returnType, returnsReference, _impl) corto_remoteAssign((corto_remote*)corto_calloc(sizeof(corto_remote)), returnType, returnsReference, _impl)
#define corto_remote__optional_SetCond(cond, returnType, returnsReference, _impl) cond ? corto_remoteAssign((corto_remote*)corto_calloc(sizeof(corto_remote)), returnType, returnsReference, _impl) : NULL
#define corto_remoteUnset(_this) _this ? corto_ptr_deinit(_this, corto_remote_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_remoteAssign(_this, returnType, returnsReference, _impl) _corto_remoteAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)
#define corto_remoteSet(_this, returnType, returnsReference, _impl) _this = _this ? _this : (corto_remote*)corto_calloc(sizeof(corto_remote)); _corto_remoteAssign(_this, corto_type(returnType), returnsReference, (void(*)(void))_impl)

/* /corto/core/request */
CORTO_EXPORT corto_request* _corto_requestCreate(corto_string parent, corto_string expr, corto_string type, uint64_t offset, uint64_t limit, bool content, corto_frame* from, corto_frame* to);
#define corto_requestCreate(parent, expr, type, offset, limit, content, from, to) _corto_requestCreate(parent, expr, type, offset, limit, content, from, to)
#define corto_requestCreate_auto(_id, parent, expr, type, offset, limit, content, from, to) corto_request* _id = corto_requestCreate(parent, expr, type, offset, limit, content, from, to); (void)_id
CORTO_EXPORT corto_request* _corto_requestCreateChild(corto_object _parent, corto_string _id, corto_string parent, corto_string expr, corto_string type, uint64_t offset, uint64_t limit, bool content, corto_frame* from, corto_frame* to);
#define corto_requestCreateChild(_parent, _id, parent, expr, type, offset, limit, content, from, to) _corto_requestCreateChild(_parent, _id, parent, expr, type, offset, limit, content, from, to)
#define corto_requestCreateChild_auto(_parent, _id, parent, expr, type, offset, limit, content, from, to) corto_request* _id = corto_requestCreateChild(_parent, #_id, parent, expr, type, offset, limit, content, from, to); (void)_id
CORTO_EXPORT corto_int16 _corto_requestUpdate(corto_request* _this, corto_string parent, corto_string expr, corto_string type, uint64_t offset, uint64_t limit, bool content, corto_frame* from, corto_frame* to);
#define corto_requestUpdate(_this, parent, expr, type, offset, limit, content, from, to) _corto_requestUpdate(corto_request(_this), parent, expr, type, offset, limit, content, from, to)

CORTO_EXPORT corto_request* _corto_requestDeclare(void);
#define corto_requestDeclare() _corto_requestDeclare()
#define corto_requestDeclare_auto(_id) corto_request* _id = corto_requestDeclare(); (void)_id
CORTO_EXPORT corto_request* _corto_requestDeclareChild(corto_object _parent, corto_string _id);
#define corto_requestDeclareChild(_parent, _id) _corto_requestDeclareChild(_parent, _id)
#define corto_requestDeclareChild_auto(_parent, _id) corto_request* _id = corto_requestDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_requestDefine(corto_request* _this, corto_string parent, corto_string expr, corto_string type, uint64_t offset, uint64_t limit, bool content, corto_frame* from, corto_frame* to);
#define corto_requestDefine(_this, parent, expr, type, offset, limit, content, from, to) _corto_requestDefine(corto_request(_this), parent, expr, type, offset, limit, content, from, to)
CORTO_EXPORT corto_request* _corto_requestAssign(corto_request* _this, corto_string parent, corto_string expr, corto_string type, uint64_t offset, uint64_t limit, bool content, corto_frame* from, corto_frame* to);
#define corto_request__optional_NotSet NULL
#define corto_request__optional_Set(parent, expr, type, offset, limit, content, from, to) corto_requestAssign((corto_request*)corto_calloc(sizeof(corto_request)), parent, expr, type, offset, limit, content, from, to)
#define corto_request__optional_SetCond(cond, parent, expr, type, offset, limit, content, from, to) cond ? corto_requestAssign((corto_request*)corto_calloc(sizeof(corto_request)), parent, expr, type, offset, limit, content, from, to) : NULL
#define corto_requestUnset(_this) _this ? corto_ptr_deinit(_this, corto_request_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_requestAssign(_this, parent, expr, type, offset, limit, content, from, to) _corto_requestAssign(_this, parent, expr, type, offset, limit, content, from, to)
#define corto_requestSet(_this, parent, expr, type, offset, limit, content, from, to) _this = _this ? _this : (corto_request*)corto_calloc(sizeof(corto_request)); _corto_requestAssign(_this, parent, expr, type, offset, limit, content, from, to)

/* /corto/core/result */
CORTO_EXPORT corto_result* _corto_resultCreate(corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, bool leaf);
#define corto_resultCreate(id, name, parent, type, value, leaf) _corto_resultCreate(id, name, parent, type, value, leaf)
#define corto_resultCreate_auto(_id, id, name, parent, type, value, leaf) corto_result* _id = corto_resultCreate(id, name, parent, type, value, leaf); (void)_id
CORTO_EXPORT corto_result* _corto_resultCreateChild(corto_object _parent, corto_string _id, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, bool leaf);
#define corto_resultCreateChild(_parent, _id, id, name, parent, type, value, leaf) _corto_resultCreateChild(_parent, _id, id, name, parent, type, value, leaf)
#define corto_resultCreateChild_auto(_parent, _id, id, name, parent, type, value, leaf) corto_result* _id = corto_resultCreateChild(_parent, #_id, id, name, parent, type, value, leaf); (void)_id
CORTO_EXPORT corto_int16 _corto_resultUpdate(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, bool leaf);
#define corto_resultUpdate(_this, id, name, parent, type, value, leaf) _corto_resultUpdate(corto_result(_this), id, name, parent, type, value, leaf)

CORTO_EXPORT corto_result* _corto_resultDeclare(void);
#define corto_resultDeclare() _corto_resultDeclare()
#define corto_resultDeclare_auto(_id) corto_result* _id = corto_resultDeclare(); (void)_id
CORTO_EXPORT corto_result* _corto_resultDeclareChild(corto_object _parent, corto_string _id);
#define corto_resultDeclareChild(_parent, _id) _corto_resultDeclareChild(_parent, _id)
#define corto_resultDeclareChild_auto(_parent, _id) corto_result* _id = corto_resultDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultDefine(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, bool leaf);
#define corto_resultDefine(_this, id, name, parent, type, value, leaf) _corto_resultDefine(corto_result(_this), id, name, parent, type, value, leaf)
CORTO_EXPORT corto_result* _corto_resultAssign(corto_result* _this, corto_string id, corto_string name, corto_string parent, corto_string type, uintptr_t value, bool leaf);
#define corto_result__optional_NotSet NULL
#define corto_result__optional_Set(id, name, parent, type, value, leaf) corto_resultAssign((corto_result*)corto_calloc(sizeof(corto_result)), id, name, parent, type, value, leaf)
#define corto_result__optional_SetCond(cond, id, name, parent, type, value, leaf) cond ? corto_resultAssign((corto_result*)corto_calloc(sizeof(corto_result)), id, name, parent, type, value, leaf) : NULL
#define corto_resultUnset(_this) _this ? corto_ptr_deinit(_this, corto_result_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_resultAssign(_this, id, name, parent, type, value, leaf) _corto_resultAssign(_this, id, name, parent, type, value, leaf)
#define corto_resultSet(_this, id, name, parent, type, value, leaf) _this = _this ? _this : (corto_result*)corto_calloc(sizeof(corto_result)); _corto_resultAssign(_this, id, name, parent, type, value, leaf)

/* /corto/core/resultIter */
CORTO_EXPORT corto_resultIter* _corto_resultIterCreate(void);
#define corto_resultIterCreate() _corto_resultIterCreate()
#define corto_resultIterCreate_auto(_id) corto_resultIter* _id = corto_resultIterCreate(); (void)_id
CORTO_EXPORT corto_resultIter* _corto_resultIterCreateChild(corto_object _parent, corto_string _id);
#define corto_resultIterCreateChild(_parent, _id) _corto_resultIterCreateChild(_parent, _id)
#define corto_resultIterCreateChild_auto(_parent, _id) corto_resultIter* _id = corto_resultIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultIterUpdate(corto_resultIter* _this);
#define corto_resultIterUpdate(_this) _corto_resultIterUpdate(corto_resultIter(_this))

CORTO_EXPORT corto_resultIter* _corto_resultIterDeclare(void);
#define corto_resultIterDeclare() _corto_resultIterDeclare()
#define corto_resultIterDeclare_auto(_id) corto_resultIter* _id = corto_resultIterDeclare(); (void)_id
CORTO_EXPORT corto_resultIter* _corto_resultIterDeclareChild(corto_object _parent, corto_string _id);
#define corto_resultIterDeclareChild(_parent, _id) _corto_resultIterDeclareChild(_parent, _id)
#define corto_resultIterDeclareChild_auto(_parent, _id) corto_resultIter* _id = corto_resultIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultIterDefine(corto_resultIter* _this);
#define corto_resultIterDefine(_this) _corto_resultIterDefine(corto_resultIter(_this))
CORTO_EXPORT corto_resultIter* _corto_resultIterAssign(corto_resultIter* _this);
#define corto_resultIter__optional_NotSet NULL
#define corto_resultIter__optional_Set() corto_resultIterAssign((corto_resultIter*)corto_calloc(sizeof(corto_resultIter)))
#define corto_resultIter__optional_SetCond(cond) cond ? corto_resultIterAssign((corto_resultIter*)corto_calloc(sizeof(corto_resultIter))) : NULL
#define corto_resultIterUnset(_this) _this ? corto_ptr_deinit(_this, corto_resultIter_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_resultIterAssign(_this) _corto_resultIterAssign(_this)
#define corto_resultIterSet(_this) _this = _this ? _this : (corto_resultIter*)corto_calloc(sizeof(corto_resultIter)); _corto_resultIterAssign(_this)

/* /corto/core/resultList */
CORTO_EXPORT corto_resultList* _corto_resultListCreate(corto_uint32 length, corto_result* elements);
#define corto_resultListCreate(length, elements) _corto_resultListCreate(length, elements)
#define corto_resultListCreate_auto(_id, length, elements) corto_resultList* _id = corto_resultListCreate(length, elements); (void)_id
CORTO_EXPORT corto_resultList* _corto_resultListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_result* elements);
#define corto_resultListCreateChild(_parent, _id, length, elements) _corto_resultListCreateChild(_parent, _id, length, elements)
#define corto_resultListCreateChild_auto(_parent, _id, length, elements) corto_resultList* _id = corto_resultListCreateChild(_parent, #_id, length, elements); (void)_id
CORTO_EXPORT corto_int16 _corto_resultListUpdate(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListUpdate(_this, length, elements) _corto_resultListUpdate(corto_resultList(_this), length, elements)

CORTO_EXPORT corto_resultList* _corto_resultListDeclare(void);
#define corto_resultListDeclare() _corto_resultListDeclare()
#define corto_resultListDeclare_auto(_id) corto_resultList* _id = corto_resultListDeclare(); (void)_id
CORTO_EXPORT corto_resultList* _corto_resultListDeclareChild(corto_object _parent, corto_string _id);
#define corto_resultListDeclareChild(_parent, _id) _corto_resultListDeclareChild(_parent, _id)
#define corto_resultListDeclareChild_auto(_parent, _id) corto_resultList* _id = corto_resultListDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_resultListDefine(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultListDefine(_this, length, elements) _corto_resultListDefine(corto_resultList(_this), length, elements)
CORTO_EXPORT corto_resultList* _corto_resultListAssign(corto_resultList* _this, corto_uint32 length, corto_result* elements);
#define corto_resultList__optional_NotSet NULL
#define corto_resultList__optional_Set(length, elements) corto_resultListAssign((corto_resultList*)corto_calloc(sizeof(corto_resultList)), length, elements)
#define corto_resultList__optional_SetCond(cond, length, elements) cond ? corto_resultListAssign((corto_resultList*)corto_calloc(sizeof(corto_resultList)), length, elements) : NULL
#define corto_resultListUnset(_this) _this ? corto_ptr_deinit(_this, corto_resultList_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_resultListAssign(_this, length, elements) _corto_resultListAssign(_this, length, elements)
#define corto_resultListSet(_this, length, elements) _this = _this ? _this : (corto_resultList*)corto_calloc(sizeof(corto_resultList)); _corto_resultListAssign(_this, length, elements)

/* /corto/core/route */
CORTO_EXPORT corto_route _corto_routeCreate(corto_string pattern, void(*_impl)(void));
#define corto_routeCreate(pattern, _impl) _corto_routeCreate(pattern, (void(*)(void))_impl)
#define corto_routeCreate_auto(_id, pattern, _impl) corto_route _id = corto_routeCreate(pattern, _impl); (void)_id
CORTO_EXPORT corto_route _corto_routeCreateChild(corto_object _parent, corto_string _id, corto_string pattern, void(*_impl)(void));
#define corto_routeCreateChild(_parent, _id, pattern, _impl) _corto_routeCreateChild(_parent, _id, pattern, (void(*)(void))_impl)
#define corto_routeCreateChild_auto(_parent, _id, pattern, _impl) corto_route _id = corto_routeCreateChild(_parent, #_id, pattern, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_routeUpdate(corto_route _this, corto_string pattern, void(*_impl)(void));
#define corto_routeUpdate(_this, pattern, _impl) _corto_routeUpdate(corto_route(_this), pattern, (void(*)(void))_impl)

CORTO_EXPORT corto_route _corto_routeDeclare(void);
#define corto_routeDeclare() _corto_routeDeclare()
#define corto_routeDeclare_auto(_id) corto_route _id = corto_routeDeclare(); (void)_id
CORTO_EXPORT corto_route _corto_routeDeclareChild(corto_object _parent, corto_string _id);
#define corto_routeDeclareChild(_parent, _id) _corto_routeDeclareChild(_parent, _id)
#define corto_routeDeclareChild_auto(_parent, _id) corto_route _id = corto_routeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routeDefine(corto_route _this, corto_string pattern, void(*_impl)(void));
#define corto_routeDefine(_this, pattern, _impl) _corto_routeDefine(corto_route(_this), pattern, (void(*)(void))_impl)
CORTO_EXPORT corto_route _corto_routeAssign(corto_route _this, corto_string pattern, void(*_impl)(void));
#define corto_route__optional_NotSet NULL
#define corto_route__optional_Set(pattern, _impl) corto_routeAssign((corto_route*)corto_calloc(sizeof(corto_route)), pattern, _impl)
#define corto_route__optional_SetCond(cond, pattern, _impl) cond ? corto_routeAssign((corto_route*)corto_calloc(sizeof(corto_route)), pattern, _impl) : NULL
#define corto_routeUnset(_this) _this ? corto_ptr_deinit(_this, corto_route_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_routeAssign(_this, pattern, _impl) _corto_routeAssign(_this, pattern, (void(*)(void))_impl)
#define corto_routeSet(_this, pattern, _impl) _this = _this ? _this : (corto_route*)corto_calloc(sizeof(corto_route)); _corto_routeAssign(_this, pattern, (void(*)(void))_impl)

/* /corto/core/router */
CORTO_EXPORT corto_router _corto_routerCreate(corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator);
#define corto_routerCreate(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerCreate(corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerCreate_auto(_id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_router _id = corto_routerCreate(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator); (void)_id
CORTO_EXPORT corto_router _corto_routerCreateChild(corto_object _parent, corto_string _id, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator);
#define corto_routerCreateChild(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerCreateChild(_parent, _id, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerCreateChild_auto(_parent, _id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_router _id = corto_routerCreateChild(_parent, #_id, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator); (void)_id
CORTO_EXPORT corto_int16 _corto_routerUpdate(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator);
#define corto_routerUpdate(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerUpdate(corto_router(_this), corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)

CORTO_EXPORT corto_router _corto_routerDeclare(void);
#define corto_routerDeclare() _corto_routerDeclare()
#define corto_routerDeclare_auto(_id) corto_router _id = corto_routerDeclare(); (void)_id
CORTO_EXPORT corto_router _corto_routerDeclareChild(corto_object _parent, corto_string _id);
#define corto_routerDeclareChild(_parent, _id) _corto_routerDeclareChild(_parent, _id)
#define corto_routerDeclareChild_auto(_parent, _id) corto_router _id = corto_routerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routerDefine(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator);
#define corto_routerDefine(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerDefine(corto_router(_this), corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
CORTO_EXPORT corto_router _corto_routerAssign(corto_router _this, corto_type returnType, corto_type paramType, corto_string paramName, corto_type routerDataType, corto_string routerDataName, corto_string elementSeparator);
#define corto_router__optional_NotSet NULL
#define corto_router__optional_Set(returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) corto_routerAssign((corto_router*)corto_calloc(sizeof(corto_router)), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator)
#define corto_router__optional_SetCond(cond, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) cond ? corto_routerAssign((corto_router*)corto_calloc(sizeof(corto_router)), returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) : NULL
#define corto_routerUnset(_this) _this ? corto_ptr_deinit(_this, corto_router_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_routerAssign(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _corto_routerAssign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)
#define corto_routerSet(_this, returnType, paramType, paramName, routerDataType, routerDataName, elementSeparator) _this = _this ? _this : (corto_router*)corto_calloc(sizeof(corto_router)); _corto_routerAssign(_this, corto_type(returnType), corto_type(paramType), paramName, corto_type(routerDataType), routerDataName, elementSeparator)

/* /corto/core/routerimpl */
CORTO_EXPORT corto_routerimpl _corto_routerimplCreate(corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplCreate(base, baseAccess, implements) _corto_routerimplCreate(corto_interface(base), baseAccess, implements)
#define corto_routerimplCreate_auto(_id, base, baseAccess, implements) corto_routerimpl _id = corto_routerimplCreate(base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_routerimpl _corto_routerimplCreateChild(corto_object _parent, corto_string _id, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplCreateChild(_parent, _id, base, baseAccess, implements) _corto_routerimplCreateChild(_parent, _id, corto_interface(base), baseAccess, implements)
#define corto_routerimplCreateChild_auto(_parent, _id, base, baseAccess, implements) corto_routerimpl _id = corto_routerimplCreateChild(_parent, #_id, base, baseAccess, implements); (void)_id
CORTO_EXPORT corto_int16 _corto_routerimplUpdate(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplUpdate(_this, base, baseAccess, implements) _corto_routerimplUpdate(corto_routerimpl(_this), corto_interface(base), baseAccess, implements)

CORTO_EXPORT corto_routerimpl _corto_routerimplDeclare(void);
#define corto_routerimplDeclare() _corto_routerimplDeclare()
#define corto_routerimplDeclare_auto(_id) corto_routerimpl _id = corto_routerimplDeclare(); (void)_id
CORTO_EXPORT corto_routerimpl _corto_routerimplDeclareChild(corto_object _parent, corto_string _id);
#define corto_routerimplDeclareChild(_parent, _id) _corto_routerimplDeclareChild(_parent, _id)
#define corto_routerimplDeclareChild_auto(_parent, _id) corto_routerimpl _id = corto_routerimplDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_routerimplDefine(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimplDefine(_this, base, baseAccess, implements) _corto_routerimplDefine(corto_routerimpl(_this), corto_interface(base), baseAccess, implements)
CORTO_EXPORT corto_routerimpl _corto_routerimplAssign(corto_routerimpl _this, corto_interface base, corto_modifier baseAccess, corto_interfaceseq implements);
#define corto_routerimpl__optional_NotSet NULL
#define corto_routerimpl__optional_Set(base, baseAccess, implements) corto_routerimplAssign((corto_routerimpl*)corto_calloc(sizeof(corto_routerimpl)), base, baseAccess, implements)
#define corto_routerimpl__optional_SetCond(cond, base, baseAccess, implements) cond ? corto_routerimplAssign((corto_routerimpl*)corto_calloc(sizeof(corto_routerimpl)), base, baseAccess, implements) : NULL
#define corto_routerimplUnset(_this) _this ? corto_ptr_deinit(_this, corto_routerimpl_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_routerimplAssign(_this, base, baseAccess, implements) _corto_routerimplAssign(_this, corto_interface(base), baseAccess, implements)
#define corto_routerimplSet(_this, base, baseAccess, implements) _this = _this ? _this : (corto_routerimpl*)corto_calloc(sizeof(corto_routerimpl)); _corto_routerimplAssign(_this, corto_interface(base), baseAccess, implements)

/* /corto/core/sample */
CORTO_EXPORT corto_sample* _corto_sampleCreate(corto_time* timestamp, uintptr_t value);
#define corto_sampleCreate(timestamp, value) _corto_sampleCreate(timestamp, value)
#define corto_sampleCreate_auto(_id, timestamp, value) corto_sample* _id = corto_sampleCreate(timestamp, value); (void)_id
CORTO_EXPORT corto_sample* _corto_sampleCreateChild(corto_object _parent, corto_string _id, corto_time* timestamp, uintptr_t value);
#define corto_sampleCreateChild(_parent, _id, timestamp, value) _corto_sampleCreateChild(_parent, _id, timestamp, value)
#define corto_sampleCreateChild_auto(_parent, _id, timestamp, value) corto_sample* _id = corto_sampleCreateChild(_parent, #_id, timestamp, value); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleUpdate(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sampleUpdate(_this, timestamp, value) _corto_sampleUpdate(corto_sample(_this), timestamp, value)

CORTO_EXPORT corto_sample* _corto_sampleDeclare(void);
#define corto_sampleDeclare() _corto_sampleDeclare()
#define corto_sampleDeclare_auto(_id) corto_sample* _id = corto_sampleDeclare(); (void)_id
CORTO_EXPORT corto_sample* _corto_sampleDeclareChild(corto_object _parent, corto_string _id);
#define corto_sampleDeclareChild(_parent, _id) _corto_sampleDeclareChild(_parent, _id)
#define corto_sampleDeclareChild_auto(_parent, _id) corto_sample* _id = corto_sampleDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleDefine(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sampleDefine(_this, timestamp, value) _corto_sampleDefine(corto_sample(_this), timestamp, value)
CORTO_EXPORT corto_sample* _corto_sampleAssign(corto_sample* _this, corto_time* timestamp, uintptr_t value);
#define corto_sample__optional_NotSet NULL
#define corto_sample__optional_Set(timestamp, value) corto_sampleAssign((corto_sample*)corto_calloc(sizeof(corto_sample)), timestamp, value)
#define corto_sample__optional_SetCond(cond, timestamp, value) cond ? corto_sampleAssign((corto_sample*)corto_calloc(sizeof(corto_sample)), timestamp, value) : NULL
#define corto_sampleUnset(_this) _this ? corto_ptr_deinit(_this, corto_sample_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_sampleAssign(_this, timestamp, value) _corto_sampleAssign(_this, timestamp, value)
#define corto_sampleSet(_this, timestamp, value) _this = _this ? _this : (corto_sample*)corto_calloc(sizeof(corto_sample)); _corto_sampleAssign(_this, timestamp, value)

/* /corto/core/sampleIter */
CORTO_EXPORT corto_sampleIter* _corto_sampleIterCreate(void);
#define corto_sampleIterCreate() _corto_sampleIterCreate()
#define corto_sampleIterCreate_auto(_id) corto_sampleIter* _id = corto_sampleIterCreate(); (void)_id
CORTO_EXPORT corto_sampleIter* _corto_sampleIterCreateChild(corto_object _parent, corto_string _id);
#define corto_sampleIterCreateChild(_parent, _id) _corto_sampleIterCreateChild(_parent, _id)
#define corto_sampleIterCreateChild_auto(_parent, _id) corto_sampleIter* _id = corto_sampleIterCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleIterUpdate(corto_sampleIter* _this);
#define corto_sampleIterUpdate(_this) _corto_sampleIterUpdate(corto_sampleIter(_this))

CORTO_EXPORT corto_sampleIter* _corto_sampleIterDeclare(void);
#define corto_sampleIterDeclare() _corto_sampleIterDeclare()
#define corto_sampleIterDeclare_auto(_id) corto_sampleIter* _id = corto_sampleIterDeclare(); (void)_id
CORTO_EXPORT corto_sampleIter* _corto_sampleIterDeclareChild(corto_object _parent, corto_string _id);
#define corto_sampleIterDeclareChild(_parent, _id) _corto_sampleIterDeclareChild(_parent, _id)
#define corto_sampleIterDeclareChild_auto(_parent, _id) corto_sampleIter* _id = corto_sampleIterDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_sampleIterDefine(corto_sampleIter* _this);
#define corto_sampleIterDefine(_this) _corto_sampleIterDefine(corto_sampleIter(_this))
CORTO_EXPORT corto_sampleIter* _corto_sampleIterAssign(corto_sampleIter* _this);
#define corto_sampleIter__optional_NotSet NULL
#define corto_sampleIter__optional_Set() corto_sampleIterAssign((corto_sampleIter*)corto_calloc(sizeof(corto_sampleIter)))
#define corto_sampleIter__optional_SetCond(cond) cond ? corto_sampleIterAssign((corto_sampleIter*)corto_calloc(sizeof(corto_sampleIter))) : NULL
#define corto_sampleIterUnset(_this) _this ? corto_ptr_deinit(_this, corto_sampleIter_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_sampleIterAssign(_this) _corto_sampleIterAssign(_this)
#define corto_sampleIterSet(_this) _this = _this ? _this : (corto_sampleIter*)corto_calloc(sizeof(corto_sampleIter)); _corto_sampleIterAssign(_this)

/* /corto/core/stager */
CORTO_EXPORT corto_stager _corto_stagerCreate(void);
#define corto_stagerCreate() _corto_stagerCreate()
#define corto_stagerCreate_auto(_id) corto_stager _id = corto_stagerCreate(); (void)_id
CORTO_EXPORT corto_stager _corto_stagerCreateChild(corto_object _parent, corto_string _id);
#define corto_stagerCreateChild(_parent, _id) _corto_stagerCreateChild(_parent, _id)
#define corto_stagerCreateChild_auto(_parent, _id) corto_stager _id = corto_stagerCreateChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stagerUpdate(corto_stager _this);
#define corto_stagerUpdate(_this) _corto_stagerUpdate(corto_stager(_this))

CORTO_EXPORT corto_stager _corto_stagerDeclare(void);
#define corto_stagerDeclare() _corto_stagerDeclare()
#define corto_stagerDeclare_auto(_id) corto_stager _id = corto_stagerDeclare(); (void)_id
CORTO_EXPORT corto_stager _corto_stagerDeclareChild(corto_object _parent, corto_string _id);
#define corto_stagerDeclareChild(_parent, _id) _corto_stagerDeclareChild(_parent, _id)
#define corto_stagerDeclareChild_auto(_parent, _id) corto_stager _id = corto_stagerDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_stagerDefine(corto_stager _this);
#define corto_stagerDefine(_this) _corto_stagerDefine(corto_stager(_this))
CORTO_EXPORT corto_stager _corto_stagerAssign(corto_stager _this);
#define corto_stager__optional_NotSet NULL
#define corto_stager__optional_Set() corto_stagerAssign((corto_stager*)corto_calloc(sizeof(corto_stager)))
#define corto_stager__optional_SetCond(cond) cond ? corto_stagerAssign((corto_stager*)corto_calloc(sizeof(corto_stager))) : NULL
#define corto_stagerUnset(_this) _this ? corto_ptr_deinit(_this, corto_stager_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_stagerAssign(_this) _corto_stagerAssign(_this)
#define corto_stagerSet(_this) _this = _this ? _this : (corto_stager*)corto_calloc(sizeof(corto_stager)); _corto_stagerAssign(_this)

/* /corto/core/subscriber */
CORTO_EXPORT corto_subscriber _corto_subscriberCreate(corto_eventMask mask, corto_string parent, corto_string expr, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_subscriberCreate(mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _corto_subscriberCreate(mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_subscriberCreate_auto(_id, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) corto_subscriber _id = corto_subscriberCreate(mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_subscriber _corto_subscriberCreateChild(corto_object _parent, corto_string _id, corto_eventMask mask, corto_string parent, corto_string expr, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_subscriberCreateChild(_parent, _id, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _corto_subscriberCreateChild(_parent, _id, mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_subscriberCreateChild_auto(_parent, _id, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) corto_subscriber _id = corto_subscriberCreateChild(_parent, #_id, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberUpdate(corto_subscriber _this, corto_eventMask mask, corto_string parent, corto_string expr, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_subscriberUpdate(_this, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _corto_subscriberUpdate(corto_subscriber(_this), mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)

CORTO_EXPORT corto_subscriber _corto_subscriberDeclare(void);
#define corto_subscriberDeclare() _corto_subscriberDeclare()
#define corto_subscriberDeclare_auto(_id) corto_subscriber _id = corto_subscriberDeclare(); (void)_id
CORTO_EXPORT corto_subscriber _corto_subscriberDeclareChild(corto_object _parent, corto_string _id);
#define corto_subscriberDeclareChild(_parent, _id) _corto_subscriberDeclareChild(_parent, _id)
#define corto_subscriberDeclareChild_auto(_parent, _id) corto_subscriber _id = corto_subscriberDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberDefine(corto_subscriber _this, corto_eventMask mask, corto_string parent, corto_string expr, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_subscriberDefine(_this, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _corto_subscriberDefine(corto_subscriber(_this), mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
CORTO_EXPORT corto_subscriber _corto_subscriberAssign(corto_subscriber _this, corto_eventMask mask, corto_string parent, corto_string expr, corto_string contentType, corto_object instance, corto_dispatcher dispatcher, corto_string type, bool enabled, void(*_impl)(void));
#define corto_subscriber__optional_NotSet NULL
#define corto_subscriber__optional_Set(mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) corto_subscriberAssign((corto_subscriber*)corto_calloc(sizeof(corto_subscriber)), mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl)
#define corto_subscriber__optional_SetCond(cond, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) cond ? corto_subscriberAssign((corto_subscriber*)corto_calloc(sizeof(corto_subscriber)), mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) : NULL
#define corto_subscriberUnset(_this) _this ? corto_ptr_deinit(_this, corto_subscriber_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_subscriberAssign(_this, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _corto_subscriberAssign(_this, mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)
#define corto_subscriberSet(_this, mask, parent, expr, contentType, instance, dispatcher, type, enabled, _impl) _this = _this ? _this : (corto_subscriber*)corto_calloc(sizeof(corto_subscriber)); _corto_subscriberAssign(_this, mask, parent, expr, contentType, instance, corto_dispatcher(dispatcher), type, enabled, (void(*)(void))_impl)

/* /corto/core/subscriberEvent */
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventCreate(uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventCreate(kind, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventCreate(kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventCreate_auto(_id, kind, subscriber, instance, source, event, data, contentTypeHandle) corto_subscriberEvent* _id = corto_subscriberEventCreate(kind, subscriber, instance, source, event, data, contentTypeHandle); (void)_id
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventCreateChild(corto_object _parent, corto_string _id, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventCreateChild(_parent, _id, kind, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventCreateChild(_parent, _id, kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventCreateChild_auto(_parent, _id, kind, subscriber, instance, source, event, data, contentTypeHandle) corto_subscriberEvent* _id = corto_subscriberEventCreateChild(_parent, #_id, kind, subscriber, instance, source, event, data, contentTypeHandle); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventUpdate(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventUpdate(_this, kind, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventUpdate(corto_subscriberEvent(_this), kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)

CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventDeclare(void);
#define corto_subscriberEventDeclare() _corto_subscriberEventDeclare()
#define corto_subscriberEventDeclare_auto(_id) corto_subscriberEvent* _id = corto_subscriberEventDeclare(); (void)_id
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventDeclareChild(corto_object _parent, corto_string _id);
#define corto_subscriberEventDeclareChild(_parent, _id) _corto_subscriberEventDeclareChild(_parent, _id)
#define corto_subscriberEventDeclareChild_auto(_parent, _id) corto_subscriberEvent* _id = corto_subscriberEventDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_subscriberEventDefine(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEventDefine(_this, kind, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventDefine(corto_subscriberEvent(_this), kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
CORTO_EXPORT corto_subscriberEvent* _corto_subscriberEventAssign(corto_subscriberEvent* _this, uint16_t kind, corto_subscriber subscriber, corto_object instance, corto_object source, corto_eventMask event, corto_result* data, uintptr_t contentTypeHandle);
#define corto_subscriberEvent__optional_NotSet NULL
#define corto_subscriberEvent__optional_Set(kind, subscriber, instance, source, event, data, contentTypeHandle) corto_subscriberEventAssign((corto_subscriberEvent*)corto_calloc(sizeof(corto_subscriberEvent)), kind, subscriber, instance, source, event, data, contentTypeHandle)
#define corto_subscriberEvent__optional_SetCond(cond, kind, subscriber, instance, source, event, data, contentTypeHandle) cond ? corto_subscriberEventAssign((corto_subscriberEvent*)corto_calloc(sizeof(corto_subscriberEvent)), kind, subscriber, instance, source, event, data, contentTypeHandle) : NULL
#define corto_subscriberEventUnset(_this) _this ? corto_ptr_deinit(_this, corto_subscriberEvent_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_subscriberEventAssign(_this, kind, subscriber, instance, source, event, data, contentTypeHandle) _corto_subscriberEventAssign(_this, kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)
#define corto_subscriberEventSet(_this, kind, subscriber, instance, source, event, data, contentTypeHandle) _this = _this ? _this : (corto_subscriberEvent*)corto_calloc(sizeof(corto_subscriberEvent)); _corto_subscriberEventAssign(_this, kind, corto_subscriber(subscriber), instance, source, event, data, contentTypeHandle)

/* /corto/core/time */
CORTO_EXPORT corto_time* _corto_timeCreate(int32_t sec, uint32_t nanosec);
#define corto_timeCreate(sec, nanosec) _corto_timeCreate(sec, nanosec)
#define corto_timeCreate_auto(_id, sec, nanosec) corto_time* _id = corto_timeCreate(sec, nanosec); (void)_id
CORTO_EXPORT corto_time* _corto_timeCreateChild(corto_object _parent, corto_string _id, int32_t sec, uint32_t nanosec);
#define corto_timeCreateChild(_parent, _id, sec, nanosec) _corto_timeCreateChild(_parent, _id, sec, nanosec)
#define corto_timeCreateChild_auto(_parent, _id, sec, nanosec) corto_time* _id = corto_timeCreateChild(_parent, #_id, sec, nanosec); (void)_id
CORTO_EXPORT corto_int16 _corto_timeUpdate(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_timeUpdate(_this, sec, nanosec) _corto_timeUpdate(corto_time(_this), sec, nanosec)

CORTO_EXPORT corto_time* _corto_timeDeclare(void);
#define corto_timeDeclare() _corto_timeDeclare()
#define corto_timeDeclare_auto(_id) corto_time* _id = corto_timeDeclare(); (void)_id
CORTO_EXPORT corto_time* _corto_timeDeclareChild(corto_object _parent, corto_string _id);
#define corto_timeDeclareChild(_parent, _id) _corto_timeDeclareChild(_parent, _id)
#define corto_timeDeclareChild_auto(_parent, _id) corto_time* _id = corto_timeDeclareChild(_parent, #_id); (void)_id
CORTO_EXPORT corto_int16 _corto_timeDefine(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_timeDefine(_this, sec, nanosec) _corto_timeDefine(corto_time(_this), sec, nanosec)
CORTO_EXPORT corto_time* _corto_timeAssign(corto_time* _this, int32_t sec, uint32_t nanosec);
#define corto_time__optional_NotSet NULL
#define corto_time__optional_Set(sec, nanosec) corto_timeAssign((corto_time*)corto_calloc(sizeof(corto_time)), sec, nanosec)
#define corto_time__optional_SetCond(cond, sec, nanosec) cond ? corto_timeAssign((corto_time*)corto_calloc(sizeof(corto_time)), sec, nanosec) : NULL
#define corto_timeUnset(_this) _this ? corto_ptr_deinit(_this, corto_time_o) : 0; corto_dealloc(_this); _this = NULL;
#define corto_timeAssign(_this, sec, nanosec) _corto_timeAssign(_this, sec, nanosec)
#define corto_timeSet(_this, sec, nanosec) _this = _this ? _this : (corto_time*)corto_calloc(sizeof(corto_time)); _corto_timeAssign(_this, sec, nanosec)


#ifdef __cplusplus
}
#endif
#endif

