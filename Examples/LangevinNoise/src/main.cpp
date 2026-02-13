#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <chrono>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../include/ndxl.h"

// -----------------------------
// Physical parameters
// -----------------------------
constexpr double gamma_ = 1.0;     // Friction
constexpr double omega0 = 1.0;     // Trap frequency
constexpr double kBT = 1.0;     // Thermal energy
constexpr double mass = 1.0;
constexpr double dt = 0.01;

// -----------------------------
// Gaussian RNG
// -----------------------------
double gaussian()
{
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);
    return std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
}

// -----------------------------
// Noise function
// -----------------------------
void langevin_noise(
    NDXLVertex* vert,
    double* noise,
    double time,
    const void* params
) {
    noise[0] = 0.0;
    noise[1] = std::sqrt(2.0 * gamma_ * kBT / mass * dt) * gaussian();
}

// -----------------------------
// Deterministic ODE
// -----------------------------
void langevin_ode(
    NDXLVertex* vert,
    double* du,
    const double* u,
    double time,
    const void* params
) {
    const double x = u[0];
    const double v = u[1];

    du[0] = v;
    du[1] = -gamma_ * v - omega0 * omega0 * x;
}

// -----------------------------
// Output callback
// -----------------------------
std::ofstream ofs;
NDXLVertex* particle = nullptr;

void output_cb(
    NDXLNetwork* net,
    double time,
    const void* params
) {
    const double* st = ndxlGetVertexState(particle);
    ofs << time << "," << st[0] << "," << st[1] << "\n";
}

// -----------------------------
// Main
// -----------------------------
int main(int argc, char** argv)
{
    ndxlInit();

    srand(
        (unsigned)std::chrono::high_resolution_clock::now()
        .time_since_epoch().count()
    );

    // Create network
    NDXLNetwork* net = ndxlCreateNetwork(0);

    // Initial state
    double state[2] = { 0.0, 0.0 };

    // Create particle
    particle = ndxlCreateVertex(
        net,
        state,
        2,
        nullptr,
        langevin_ode,
        langevin_noise,
        nullptr
    );

    // Output
    ofs.open("langevin.csv");
    ofs << "time,x,v\n";

    // Simulate
    ndxlNetworkSimulate(
        net,
        100.0,
        dt,
        output_cb
    );

    ofs.close();
    ndxlDestroyNetwork(net);

    std::cout << "Simulation complete. Output written to langevin.csv\n";
    return 0;
}