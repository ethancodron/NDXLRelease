//----------------------------------------------\\
// C/C++ common macros and type identification	\\
// Ethan Codron 2025							\\
// GNU GPL-3.0									\\
//----------------------------------------------\\
// Header file providing a primitive means of	\\
// passing type information to C functions that	\\
// can operate on "generic" types (void*).		\\
//----------------------------------------------\\

#ifndef _UNICPP_CORE_
#define _UNICPP_CORE_

#include <math.h>
#include <stdint.h>

// General definitions vvvvv

#define _UNI_BEGIN	namespace uni {
#define _UNI_END	}
#define _UNI		::uni::

#ifdef __cplusplus
	#define _OPT(v)		= v
	#define _NOEXCEPT	noexcept
#else
	#define _OPT(v)
	#define _NOEXCEPT
#endif // __cplusplus

#define BIT(x) ((unsigned long long)(1) << (x))

// ^^^^^ General definitions | type checking vvvvv

#define UNI_DOUBLE		'd'
#define UNI_FLOAT		'f'
#define UNI_ULLONG		'U'
#define UNI_LLONG		'L'
#define UNI_ULONG		'u'
#define UNI_LONG		'l'
#define UNI_UINT		'I'
#define UNI_INT			'i'
#define UNI_USHORT		'S'
#define UNI_SHORT		's'
#define UNI_UBYTE		'B'
#define UNI_BYTE		'b'
#define UNI_COMPLEX		'Z'
#define UNI_COMPLEXF	'z'
#define UNI_UNDEF		'#'

#ifdef __cplusplus
_UNI_BEGIN

template <typename _Ty>
inline constexpr char get_typeid() { return UNI_UNDEF; }
template<> inline constexpr char get_typeid<double>() { return UNI_DOUBLE; }
template<> inline constexpr char get_typeid<float>() { return UNI_FLOAT; }
template<> inline constexpr char get_typeid<unsigned long long>() { return UNI_ULLONG; }
template<> inline constexpr char get_typeid<long long>() { return UNI_LLONG; }
template<> inline constexpr char get_typeid<unsigned long>() { return UNI_ULONG; }
template<> inline constexpr char get_typeid<long>() { return UNI_LONG; }
template<> inline constexpr char get_typeid<unsigned int>() { return (sizeof(unsigned int) == 8 ? UNI_ULLONG : sizeof(unsigned int) == 4 ? UNI_ULONG : sizeof(unsigned int) == 2 ? UNI_USHORT : sizeof(unsigned int) == 1 ? UNI_UBYTE : UNI_UINT); }
template<> inline constexpr char get_typeid<int>() { return (sizeof(int) == 8 ? UNI_LLONG : sizeof(int) == 4 ? UNI_LONG : sizeof(int) == 2 ? UNI_SHORT : sizeof(int) == 1 ? UNI_UBYTE : UNI_INT); }
template<> inline constexpr char get_typeid<unsigned short>() { return UNI_USHORT; }
template<> inline constexpr char get_typeid<short>() { return UNI_SHORT; }
template<> inline constexpr char get_typeid<unsigned char>() { return UNI_UBYTE; }
template<> inline constexpr char get_typeid<char>() { return UNI_BYTE; }

_UNI_END
#endif // __cplusplus

// ^^^^^ Type checking

#endif // _UNICPP_CORE_