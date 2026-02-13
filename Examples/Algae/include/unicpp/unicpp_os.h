//----------------------------------\\
// C/C++ Operating system detection	\\
// Ethan Codron 2025				\\
// GNU GPL-3.0						\\
//----------------------------------\\
// Header file macroising operating	\\
// system functions and providing a	\\
// means to detect the host OS.		\\
//----------------------------------\\

#ifndef _UNICPP_OS_
#define _UNICPP_OS_

#include "unicpp_core.h"

#define UNI_PLATFORM_UNSUPPORTED	-1
#define UNI_PLATFORM_NONE			0
#define UNI_PLATFORM_WIN64			1
#define UNI_PLATFORM_WIN32			2
#define UNI_PLATFORM_MACOS			4
#define UNI_PLATFORM_LINUX64		8
#define UNI_PLATFORM_LINUX32		16
#define UNI_PLATFORM_UNIX64			32
#define UNI_PLATFORM_UNIX32			64

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)	// All (supported) Windows clients define at least one of these macros
	#include <Windows.h>
	
	#if defined(_WIN64)
		#define UNI_PLATFORM		UNI_PLATFORM_WIN64
		#define UNI_PLATFORM_NAME	"Windows x64"
	#else
		#define UNI_PLATFORM		UNI_PLATFORM_WIN32
		#define UNI_PLATFORM_NAME	"Windows x86"
	#endif // defined(_WIN64)
	
	static inline const char uniIsHeapPointer(void* ptr)
	{
		ULONG_PTR stack_low, stack_high;
		GetCurrentThreadStackLimits(&stack_low, &stack_high);
		return (((uintptr_t)ptr < stack_low) || ((uintptr_t)ptr >= stack_high));
	}
#else
	#if defined(__APPLE__)
		#include <pthread.h>
		#include <TargetConditionals.h>

		#if TARGET_OS_MAC
			#define UNI_PLATFORM		UNI_PLATFORM_MACOS
			#define UNI_PLATFORM_NAME	"macOS"
		#else
			#define UNI_PLATFORM		UNI_PLATFORM_UNSUPPORTED
			#define UNI_PLATFORM_NAME	"u/Apple"
		#endif // TARGET_OS_MAC
		
		static inline const char uniIsHeapPointer(void* ptr)
		{
			pthread_t self = pthread_self();
			void* stack_base = pthread_get_stackaddr_np(self);
			size_t stack_size = pthread_get_stacksize_np(self);
			uintptr_t low = (uintptr_t)stack_base - stack_size;
			uintptr_t high = (uintptr_t)stack_base;
			return (((uintptr_t)ptr < low) || ((uintptr_t)ptr >= high));
		}
	#elif defined(__ANDROID__)
		#define UNI_PLATFORM		UNI_PLATFORM_UNSUPPORTED
		#define UNI_PLATFORM_NAME	"Android"

		static inline const char isHeapPointer(void* ptr)
		{
			int dummy;
			uintptr_t mask = 0xFFFFFF0000000000ULL;
			uintptr_t a = (uintptr_t)&dummy & mask;
			uintptr_t b = (uintptr_t)ptr & mask;
			return (a != b);
		}
	#elif defined(__linux__)	// Linux-specific definitions/includes
		#if defined(__x86_64__)
			#define UNI_PLATFORM		UNI_PLATFORM_LINUX64
			#define UNI_PLATFORM_NAME	"Linux64"
		#elif defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__)
			#define UNI_PLATFORM		UNI_PLATFORM_LINUX32
			#define UNI_PLATFORM_NAME	"Linux32"
		#else
			#define UNI_PLATFORM		UNI_PLATFORM_UNSUPPORTED
			#define UNI_PLATFORM_NAME	"u/Linux"
		#endif
		
		#include <pthread.h>
		#include <unistd.h>
		
		static inline const char uniIsHeapPointer(void* ptr)
		{
			pthread_attr_t attr;
			pthread_getattr_np(pthread_self(), &attr);
			void* stack_base;
			size_t stack_size;
			pthread_attr_getstack(&attr, &stack_base, &stack_size);
			pthread_attr_destroy(&attr);
			uintptr_t low = (uintptr_t)stack_base;
			uintptr_t high = low + stack_size;
			return (((uintptr_t)ptr < low) || ((uintptr_t)ptr >= high));
		}
	#elif defined(__unix__)	// Non-linux unix-based operating systems
		#if defined(__x86_64__)
			#define UNI_PLATFORM		UNI_PLATFORM_UNIX64
			#define UNI_PLATFORM_NAME	"Unix64"
		#elif defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__)
			#define UNI_PLATFORM		UNI_PLATFORM_UNIX32
			#define UNI_PLATFORM_NAME	"Unix32"
		#else
			#define UNI_PLATFORM		UNI_PLATFORM_UNSUPPORTED
			#define UNI_PLATFORM_NAME	"u/Unix"
		#endif
		
		#include <pthread.h>
		#include <unistd.h>
		
		static inline const char uniIsHeapPointer(void* ptr)
		{
			pthread_attr_t attr;
			pthread_getattr_np(pthread_self(), &attr);
			void* stack_base;
			size_t stack_size;
			pthread_attr_getstack(&attr, &stack_base, &stack_size);
			pthread_attr_destroy(&attr);
			uintptr_t low = (uintptr_t)stack_base;
			uintptr_t high = low + stack_size;
			return (((uintptr_t)ptr < low) || ((uintptr_t)ptr >= high));
		}
	#else	// Unsupported platform
		#define UNI_PLATFORM		UNI_PLATFORM_NONE
		#define UNI_PLATFORM_NAME	"unsupported"
		
		static inline const char isHeapPointer(void* ptr)
		{
			int dummy;
			uintptr_t mask = 0xFFFFFF0000000000ULL;
			uintptr_t a = (uintptr_t)&dummy & mask;
			uintptr_t b = (uintptr_t)ptr & mask;
			return (a != b);
		}
	#endif // defined(__linux__)
#endif // defined(_WIN32)

#define UNI_ARCHITECTURE	(sizeof(void*) << 3)

static inline const int uniPlatform() { return UNI_PLATFORM; }
static inline const char* const uniOperatingSystem() { return UNI_PLATFORM_NAME; }
static inline const int uniArchitecture() { return UNI_ARCHITECTURE; }

#ifdef __cplusplus
_UNI_BEGIN

inline const int platform() noexcept { return uniPlatform(); }
inline const char* const operating_system() noexcept { return uniOperatingSystem(); }
inline const int architecture() noexcept { return uniArchitecture(); }
inline const char is_heap_pointer(void* _Ptr) noexcept { return uniIsHeapPointer(_Ptr); }

_UNI_END
#endif // __cplusplus

#endif // _UNICPP_OS_