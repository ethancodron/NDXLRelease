//--------------------------------------------------\\
// NDXL header containing core functions and macros	\\
// Ethan Codron 2025								\\
// GNU GPL-3.0										\\
//--------------------------------------------------\\
// Header file containing all core definitions and	\\
// and macros used throughout the API. Macroises	\\
// commonly used tokens/keywords to be platform-	\\
// independent.										\\
//--------------------------------------------------\\

#ifndef _NDXLCORE_
#define _NDXLCORE_

#include "unicpp/unicpp.h"

typedef struct NDXLVertex NDXLVertex;
typedef struct NDXLEdge NDXLEdge;
typedef struct NDXLNetwork NDXLNetwork;

// General definitions vvvvv

#define _NDXL_BEGIN	namespace ndxl {
#define _NDXL_END	}
#define _NDXL		::ndxl::

// ^^^^^ General definitions | import identification vvvvv

#ifdef NDXL_STATIC
	#define _NDXLIMP_
#else
	#ifdef _MSC_VER
		#define _NDXLIMP_ __declspec(dllimport)
	#else
		#define _NDXLIMP_
	#endif // _MSC_VER
#endif // NDXL_STATIC

// ^^^^^ Import identification | error handling vvvvv

#define NDXL_OK				0 // No error occured
#define NDXL_ERR			1 // An error was raised, use ndxlGetErrorMsg() to see details

#define NDXL_VALUE_ERR		-1 // Invalid value e.g., negative vertex order, or nonpositive count in vectorised functions like dtPowv
#define NDXL_TYPE_ERR		-2 // Invalid/unsupported datatype provided to function e.g., trying to call dtCosv on an array of networks
#define NDXL_ARG_ERR		-3 // Invalid argument e.g., ln(0) or asin(4)

// ^^^^^ Error handling

#ifdef __cplusplus
extern "C" {
#endif

_NDXLIMP_ const int _CDECL ndxlGetLastErrorCode() _NOEXCEPT;
_NDXLIMP_ const char* const _CDECL ndxlGetLastErrorMsg() _NOEXCEPT;
_NDXLIMP_ void _CDECL ndxlPrintError() _NOEXCEPT;
_NDXLIMP_ void _CDECL ndxlRaiseError(_In_ const int _Code, _In_z_ const char* const _Msg) _NOEXCEPT;
_NDXLIMP_ const int _CDECL ndxlInit() _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
_NDXL_BEGIN

class vertex;
class edge;
class network;

inline const bool get_last_error_code() noexcept { return ndxlGetLastErrorCode(); }
inline const char* const get_last_error_msg() noexcept { return ndxlGetLastErrorMsg(); }
inline void print_error() noexcept { ndxlPrintError(); }
inline void raise_error(const int _Code, const char* const _Msg) noexcept { ndxlRaiseError(_Code, _Msg); }
inline const int init() noexcept { return ndxlInit(); }

_NDXL_END
#endif // __cplusplus

#endif // _NDXLCORE_