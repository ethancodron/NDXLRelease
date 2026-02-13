//------------------------------\\
// NDXL header for edge class	\\
// Ethan Codron 2025			\\
// GNU GPL-3.0					\\
//------------------------------\\
// Defines an edge class which	\\
// connects two vertices along	\\
// a potentially dynamic link.	\\
//------------------------------\\

#ifndef _NDXL_EDGE_
#define _NDXL_EDGE_

#include "ndxl_vertex.h"

// void NDXLEdgeFunction(NDXLEdge* _Edge, double* _OutState, const double* _InState, double _Time, const void* _Params)
typedef void(*NDXLEdgeFunction)(NDXLEdge*, double*, const double*, double, const void*);

// void NDXLEdgeNoise(NDXLEdge* _Edge, double* _OutNoise, double _Time)
typedef void(*NDXLEdgeNoise)(NDXLEdge*, double*, double);

// void NDXLEdgeCallback(NDXLEdge* _Edge, double* _State, double _Time, const void* _Params)
typedef void(*NDXLEdgeCallback)(NDXLEdge*, double*, double, const void*);

#ifdef __cplusplus
extern "C" {
#endif

// Constructors and destructor vvvvv

_NDXLIMP_ NDXLEdge* _CDECL ndxlCreateEdge(
	_In_ NDXLVertex* _Vert1,
	_In_ NDXLVertex* _Vert2,
	_In_reads_bytes_(_Order * sizeof(double)) const double* _State,
	_In_ const size_t _Order,
	_In_ const double _Delay,
	_In_ const void* _Params,
	_In_ const char _Directed,
	_In_ NDXLEdgeFunction _Func,
	_In_ NDXLEdgeNoise _Noise,
	_In_ NDXLEdgeCallback _Callback
) _NOEXCEPT;

_NDXLIMP_ NDXLEdge* _CDECL ndxlCopyEdge(
	_In_ NDXLEdge* _Edge,
	_In_ NDXLVertex* _Vert1,
	_In_ NDXLVertex* _Vert2,
	_In_ const char _Directed,
	_In_ const char _CopyState0
) _NOEXCEPT;

_NDXLIMP_ void _CDECL ndxlDestroyEdge(
	_In_ NDXLEdge* _Edge
) _NOEXCEPT;

// ^^^^^ Constructors and destructor | getters vvvvv

_NDXLIMP_ const double _CDECL ndxlGetEdgeDelay(
	_In_ NDXLEdge* _Edge
) _NOEXCEPT;

_NDXLIMP_ const double* _CDECL ndxlGetEdgeState(
	_In_ NDXLEdge* _Edge
) _NOEXCEPT;

// ^^^^^ Getters | setters vvvvv

_NDXLIMP_ const int _CDECL ndxlSetEdgeDelay(
	_In_ NDXLEdge* _Edge,
	_In_ const double _Delay
) _NOEXCEPT;

_NDXLIMP_ const int _CDECL ndxlSetEdgeState(
	_In_ NDXLEdge* _Edge,
	_In_ const double* _State
) _NOEXCEPT;

// ^^^^^ Setters

#ifdef __cplusplus
}
#endif

#endif // _NDXL_EDGE_