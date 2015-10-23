/*
 * corto_platform.h
 *
 *  Created on: May 22, 2012
 *      Author: sander
 */

#ifndef CORTO_PLATFORM_H_
#define CORTO_PLATFORM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if INTPTR_MAX == INT32_MAX
#define CORTO_CPU_X86
#elif INTPTR_MAX == INT64_MAX
#define CORTO_CPU_X64
#else
#warning "corto is not supported on platforms which are neither 32- nor 64-bit."
#endif

#if defined(WIN32) || defined(WIN64)
#define CORTO_OS_WINDOWS
#elif defined(__linux__)
#define CORTO_OS_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
#define CORTO_OS_OSX
#else
#warning "corto is not supported on non-unix or windows operating systems."
#endif

#ifdef CORTO_CPU_X86
#define CORTO_CPU_STRING "x86"
#else
#define CORTO_CPU_STRING "x64"
#endif

#ifdef CORTO_OS_WINDOWS
#define CORTO_OS_STRING "windows"
#elif defined(CORTO_OS_LINUX)
#define CORTO_OS_STRING "linux"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#elif defined(CORTO_OS_OSX)
#define CORTO_OS_STRING "darwin"
#define CORTO_DLL_CONSTRUCT void __attribute__ ((constructor)) DllMain(void)
#endif

#define CORTO_PLATFORM_STRING CORTO_CPU_STRING "-" CORTO_OS_STRING

#ifdef __cplusplus
}
#endif

#endif /* CORTO_PLATFORM_H_ */
