//--------------------------\\
// C/C++ Compiler detection	\\
// Ethan Codron 2025		\\
// GNU GPL-3.0				\\
//--------------------------\\
// Header file macroising	\\
// compiler tokens.			\\
//--------------------------\\

#ifndef _UNICPP_COMPILER_
#define _UNICPP_COMPILER_

#include "unicpp_core.h"

#define UNI_COMPILER_NONE		0
#define UNI_COMPILER_MSVC		1
#define UNI_COMPILER_GCC		2
#define UNI_COMPILER_GPP		4
#define UNI_COMPILER_CLANG		8
#define UNI_COMPILER_MINGW32	16
#define UNI_COMPILER_MINGW64	32

#if defined(_MSC_VER)	// MSVC compiler
	#define _CDECL		__cdecl
	#define _CLRCALL	__clrcall
	#define _FASTCALL	__fastcall
	#define _REGCALL	__regcall
	#define _PASCAL		__pascal
	#define _SAFECALL	__safecall
	#define _STDCALL	__stdcall
	#define _THISCALL	__thiscall
	#define _VECTORCALL	__vectorcall

	#define UNI_COMPILER		UNI_COMPILER_MSVC
	#define UNI_COMPILER_NAME	"MSVC"
	
	#if _MSVC_LANG >= 201703L
		#define _CONSTEXPR constexpr
		#ifndef _NODISCARD
			#define _NODISCARD [[nodiscard]]
		#endif // _NODISCARD
	#else
		#define _CONSTEXPR inline constexpr
		#ifndef _NODISCARD
			#define _NODISCARD
		#endif // _NODISCARD
	#endif // C++17
#else
	#define _CDECL		__attribute__((__cdecl__))
	#define _CLRCALL	__attribute__((__clrcall__))
	#define _FASTCALL	__attribute__((__fastcall__))
	#define _REGCALL	__attribute__((__regcall__))
	#define _PASCAL		__attribute__((__pascal__))
	#define _SAFECALL	__attribute__((__safecall__))
	#define _STDCALL	__attribute__((__stdcall__))
	#define _THISCALL	__attribute__((__thiscall__))
	#define _VECTORCALL	__attribute__((__vectorcall__))

	#if __cplusplus >= 201703L
		#define _CONSTEXPR constexpr
		#ifndef _NODISCARD
			#define _NODISCARD [[nodiscard]]
		#endif // _NODISCARD
	#else
		#define _CONSTEXPR inline constexpr
		#ifndef _NODISCARD
			#define _NODISCARD
		#endif // _NODISCARD
	#endif // C++17

	#if defined(__GNUC__)	// GNU gcc compiler
		#define UNI_COMPILER		UNI_COMPILER_GCC
		#define UNI_COMPILER_NAME	"gcc"
	#elif defined(__GNUG__)	// GNU g++ compiler
		#define UNI_COMPILER		UNI_COMPILER_GPP
		#define UNI_COMPILER_NAME	"g++"
	#elif defined(__clang__)	// clang compiler
		#define UNI_COMPILER		UNI_COMPILER_CLANG
		#define UNI_COMPILER_NAME	"clang"
	#elif defined(__MINGW32__)
		#define UNI_COMPILER		UNI_COMPILER_MINGW32
		#define UNI_COMPILER_NAME	"MinGW 32"
	#elif defined(__MINGW64__)
		#define UNI_COMPILER		UNI_COMPILER_MINGW64
		#define UNI_COMPILER_NAME	"MinGW-w64"
	#else	// Unrecognised compiler
		#define UNI_COMPILER		UNI_COMPILER_NONE
		#define UNI_COMPILER_NAME	"unrecognised"
	#endif // __GNUC__
#endif // _MSVC_LANG

static inline const int uniCompiler() { return UNI_COMPILER; }
static inline const char* const uniCompilerName() { return UNI_COMPILER_NAME; }

#ifdef __cplusplus
_UNI_BEGIN

inline const int compiler() noexcept { return uniCompiler(); }
inline const char* const compiler_name() noexcept { return uniCompilerName(); }

_UNI_END
#endif // __cplusplus

#endif // _UNICPP_COMPILER_