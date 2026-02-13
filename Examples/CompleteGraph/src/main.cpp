#include <stdlib.h> // We will need this for random numbers

#include "../include/ndxl.h"

// Declare number of vertices
#define N 1000

/* We will first create a space for our vertices to exist,
so that we can reference them later */
NDXLVertex* vertices[N];

// We will simulate our graph with first order Kuramoto oscillators
// The natural frequency will be provided via the extra parameter list
// We will assume no noise, and no edge delay
void kuramoto(
	NDXLVertex* vertex,
	double* dtheta,
	const double* theta,
	const double time,
	const void* params
) {
	// We will first calculate the summation term in the Kuramoto model
	double sum = 0.0;
	/* Loop through all edges of the current vertex so that we can access
	its neighbours */
	NDXLEdge* edge = ndxlGetVertexFirstEdge(vertex);
	for (; edge; edge = ndxlGetVertexNextEdge(vertex, edge))
	{
		/*
		We want to query the state (theta) of the neighbour along
		the given edge. We do it this way for two reasons:
		First, "edge" contains other information we need, such as
		the edge weight.
		Second, if our edges had a nonzero time delay,
		ndxlGetVertexNeighbourState would return zero, indicating
		the information has not yet travelled along the edge to
		"vertex".
		Note also we can dereference the pointers since we know our
		24
		state vectors only have one element (phase and edge weight,
		respectively).
		*/
		const double* st = ndxlGetVertexNeighbourState(vertex, edge);
		if (st)
			sum += *ndxlGetEdgeState(edge) * sin(*st - *theta);
	}
	*dtheta = *(double*)params + sum / N;
}

int main(int argc, char** argv)
{
	// Remember to ALWAYS call this function FIRST !!!
	ndxlInit();

	/* Start by creating a host network and seeding
	the random number generator (RNG) */
	NDXLNetwork* network = ndxlCreateNetwork();
	srand(314159);

	// We can then add our 1000 vertices
	for (int i = 0; i < N; i++)
	{
		// Random natural frequency between 0.9 and 1.1 Hz
		double omega = (double)rand() * 0.2 / (double)RAND_MAX + 0.9;

		// Random initial phase between -pi and pi
		double state = (double)rand() * 6.28319 / (double)RAND_MAX - 3.14159;

		// Create vertex
		vertices[i] = ndxlCreateVertex(
			network,	// Host network
			&state,		// Address of state vector
			1,			// No. elements in state
			&omega,		// Extra parameters
			kuramoto,	// ODE to follow
			0,			// No noise function
			0			// No callback function
		);
	}

	// Now to add the edges in a complete configuration
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			// Random edge weight between 0.8 and 1.2
			double state = (double)rand() * 0.4 / (double)RAND_MAX + 0.8;

			// Create edge
			ndxlCreateEdge(
				vertices[i],	// Source vertex
				vertices[j],	// Destination vertex
				&state,			// Address of state vector
				1,				// No. elements in state
				0,				// No delay
				0,				// No extra parameters
				false,			// Edge is not directed
				0,				// No ODE to follow
				0,				// No noise function
				0				// no callback function
			);
		}
	}

	// Simulate the network
	ndxlNetworkSimulate(
		network, // Which network to simulate
		50.0, // How long to simulate the network for
		0.1, // Time step size
		0 // No network callback function
	);

	/* Since we called ndxlInit() at the top, it is not strictly
	necessary to explicitly destroy any objects we created. If
	you want, however, you can do so by using the destructors: */
	ndxlDestroyNetwork(network);
	return 0;
}