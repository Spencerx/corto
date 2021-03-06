/* _type.h
 * This file is generated. Do not modify its contents.
 */

#ifndef CORTO_SECURE_TYPE_H
#define CORTO_SECURE_TYPE_H

#include <corto/lang/_type.h>
#ifdef __cplusplus
extern "C" {
#endif

/* -- Type definitions -- */

/* enum corto/secure/accessKind */
typedef enum corto_secure_accessKind {
    CORTO_SECURE_ACCESS_GRANTED = 0,
    CORTO_SECURE_ACCESS_DENIED = 1,
    CORTO_SECURE_ACCESS_UNDEFINED = 2
} corto_secure_accessKind;

/* bitmask corto/secure/actionKind */
typedef uint32_t corto_secure_actionKind;
    #define CORTO_SECURE_ACTION_CREATE (0x1)
    #define CORTO_SECURE_ACTION_READ (0x2)
    #define CORTO_SECURE_ACTION_UPDATE (0x4)
    #define CORTO_SECURE_ACTION_DELETE (0x8)
    #define CORTO_SECURE_ACTION_ANY (0xf)

/* class corto/secure/key */
typedef struct corto_secure_key_s {
    bool enabled;
} *corto_secure_key;

/* class corto/secure/lock */
typedef struct corto_secure_lock_s {
    corto_query query;
    int16_t priority;
} *corto_secure_lock;


#ifdef __cplusplus
}
#endif
#endif

