#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../include/ndxl.h"

// -----------------------------
// Parameters
// -----------------------------
constexpr int    N = 12;     // number of oscillators
constexpr double K = 1.0;    // coupling strength
constexpr double omega = 1.0;    // natural frequency
constexpr double delay = 2.0;    // edge delay
constexpr double dt = 0.05;

// -----------------------------
// Storage
// -----------------------------
NDXLVertex* vertices[N];
std::ofstream ofs;

// -----------------------------
// Kuramoto ODE with delayed, directed coupling
// -----------------------------
void kuramoto_delay(
    NDXLVertex* vert,
    double* dtheta,
    const double* theta,
    double t,
    const void* p
) {
    double sum = 0.0;

    for (NDXLEdge* edge = ndxlGetVertexFirstEdge(vert);
        edge;
        edge = ndxlGetVertexNextEdge(vert, edge))
    {
        // IMPORTANT: delayed neighbour state
        const double* st = ndxlGetVertexNeighbourState(vert, edge);
        if (st)
        {
            sum += (*ndxlGetEdgeState(edge)) * sin(*st - *theta);
        }
    }
    *dtheta = *(const double*)p + sum / N;
}

// -----------------------------
// Network callback: output phases
// -----------------------------
void output_cb(NDXLNetwork* net, const double t, const void* p)
{
    ofs << t;
    for (int i = 0; i < N; i++)
        ofs << "," << *ndxlGetVertexState(vertices[i]);
    ofs << "\n";
}

// -----------------------------
// Main
// -----------------------------
int main(int argc, char** argv)
{
    ndxlInit();
    srand(12345);

    // Create network
    NDXLNetwork* net = ndxlCreateNetwork(0);

    // Create oscillators
    for (int i = 0; i < N; i++)
    {
        double theta0 = 2.0 * M_PI * static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

        vertices[i] = ndxlCreateVertex(
            net,
            &theta0,
            1,
            &omega,
            kuramoto_delay,
            nullptr,
            nullptr
        );
    }

    // Create directed ring with delays
    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;

        double weight = K;

        ndxlCreateEdge(
            vertices[i],    // source
            vertices[j],    // destination
            &weight,        // edge state (coupling)
            1,
            delay,          // <-- EDGE DELAY
            nullptr,
            true,           // <-- DIRECTED EDGE
            nullptr,
            nullptr,
            nullptr
        );
    }

    // Open output
    ofs.open("delayed_directed_kuramoto.csv");
    ofs << "time";
    for (int i = 0; i < N; i++)
        ofs << ",theta" << i;
    ofs << "\n";

    // Simulate
    ndxlNetworkSimulate(
        net,
        5.0,
        dt,
        output_cb
    );

    ofs.close();
    ndxlDestroyNetwork(net);

    ndxlPrintError();
    std::cout << "Simulation complete. Output: delayed_directed_kuramoto.csv\n";
    return 0;
}