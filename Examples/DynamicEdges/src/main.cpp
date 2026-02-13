#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../include/ndxl.h"

// -----------------------------
// Parameters
// -----------------------------
constexpr int    N = 10;
constexpr double omega = 1.0;
constexpr double K0 = 0.8;
constexpr double A = 0.6;
constexpr double Omega = 0.4;
constexpr double dt = 0.05;

// -----------------------------
// Globals
// -----------------------------
std::vector<NDXLVertex*> verts;
std::ofstream ofs;

// -----------------------------
// Kuramoto vertex ODE
// -----------------------------
void kuramoto(
    NDXLVertex* vert,
    double* dtheta,
    const double* theta,
    double t,
    const void* p
) {
    double sum = 0.0;

    for (NDXLEdge* e = ndxlGetVertexFirstEdge(vert);
        e;
        e = ndxlGetVertexNextEdge(vert, e))
    {
        const double* st = ndxlGetVertexNeighbourState(vert, e);
        if (st)
            sum += (*ndxlGetEdgeState(e)) * sin(*st - *theta);
    }

    *dtheta = omega + sum;
}

// -----------------------------
// Network callback: update edges + output
// -----------------------------
void network_cb(NDXLNetwork* net, const double t, const void* p)
{
    // ---- Update edge weights ----
    for (int i = 0; i < N; i++)
    {
        // Ring: edge i connects verts[i] -> verts[i+1]
        NDXLEdge* e = ndxlGetVertexFirstEdge(verts[i]);

        double phase = 2.0 * M_PI * i / N;
        double K = K0 + A * sin(Omega * t + phase);

        ndxlSetEdgeState(e, &K);
    }

    // ---- Output ----
    ofs << t;

    // Vertex phases
    for (int i = 0; i < N; i++)
        ofs << "," << *ndxlGetVertexState(verts[i]);

    // Edge weights
    for (int i = 0; i < N; i++)
    {
        NDXLEdge* e = ndxlGetVertexFirstEdge(verts[i]);
        ofs << "," << *ndxlGetEdgeState(e);
    }

    ofs << "\n";
}

// -----------------------------
// Main
// -----------------------------
int main()
{
    ndxlInit();

    NDXLNetwork* net = ndxlCreateNetwork(0);
    verts.resize(N);

    // Create vertices
    for (int i = 0; i < N; i++)
    {
        double theta0 = 2.0 * M_PI * i / N;
        verts[i] = ndxlCreateVertex(net, &theta0, 1, 0, kuramoto, 0, 0);
    }

    // Create ring edges
    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;
        double K = K0;

        ndxlCreateEdge(
            verts[i],
            verts[j],
            &K,
            1,
            0.0,
            0,
            false,
            0,
            0,
            0
        );
    }

    // Output header
    ofs.open("dynamic_edges_full.csv");
    ofs << "time";
    for (int i = 0; i < N; i++)
        ofs << ",theta" << i;
    for (int i = 0; i < N; i++)
        ofs << ",K" << i;
    ofs << "\n";

    // Simulate
    ndxlNetworkSimulate(net, 100.0, dt, network_cb);

    ofs.close();
    ndxlDestroyNetwork(net);

    std::cout << "Simulation complete: dynamic_edges_full.csv\n";
    return 0;
}