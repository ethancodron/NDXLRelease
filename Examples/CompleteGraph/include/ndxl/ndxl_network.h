//----------------------------------\\
// NDXL header for network class	\\
// Ethan Codron 2025				\\
// GNU GPL-3.0						\\
//----------------------------------\\
// Defines a network class to link	\\
// edges and nodes in a graph.		\\
//----------------------------------\\

#ifndef _NDXL_NETWORK_
#define _NDXL_NETWORK_

#include "ndxl_edge.h"

// void NDXLNetworkCallback(NDXLNetwork* _Network, double _Time, const void* _Params)
typedef void(*NDXLNetworkCallback)(NDXLNetwork*, double, const void*);

#ifdef __cplusplus
extern "C" {
#endif

// Constructors and destructor vvvvv

_NDXLIMP_ NDXLNetwork* _CDECL ndxlCreateNetwork(
	_In_ const void* _Params
) _NOEXCEPT;

_NDXLIMP_ void _CDECL ndxlDestroyNetwork(
	_In_ NDXLNetwork* _Network
) _NOEXCEPT;

// ^^^^^ Constructors and destructor | getters vvvvv

_NDXLIMP_ const size_t _CDECL ndxlGetNetworkEdgeCount(
	_In_ NDXLNetwork* _Network
) _NOEXCEPT;

_NDXLIMP_ void _CDECL ndxlGetNetworkEdges(
	_In_ NDXLNetwork* _Network,
	_Out_ _Notnull_ NDXLEdge** _Edges
) _NOEXCEPT;

_NDXLIMP_ const size_t _CDECL ndxlGetNetworkVertexCount(
	_In_ NDXLNetwork* _Network
) _NOEXCEPT;

_NDXLIMP_ void _CDECL ndxlGetNetworkVertices(
	_In_ NDXLNetwork* _Network,
	_Out_ _Notnull_ NDXLVertex** _Vertices
) _NOEXCEPT;

 // ^^^^^ Getters | functions vvvvv

_NDXLIMP_ void _CDECL ndxlNetworkSimulate(
	_In_ NDXLNetwork* _Network,
	_In_ const double _Time,
	_In_ const double _Step,
	_In_ NDXLNetworkCallback _Callback
) _NOEXCEPT;

// ^^^^^ Functions

#ifdef __cplusplus
}
#endif

#endif // _NDXL_NETWORK_