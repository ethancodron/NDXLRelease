/*
-- NOTE!!!
-- If you are running this code on Windows using Visual Studio,
-- do NOT run straight from the IDE as it will not work!!
-- This is because the relative working path changes to wherever
-- the source file main.cpp is located, so it will not find the
-- algae distributions file (algae.csv). This code was written
-- under the assumption that the executable outputs to:
--
-- ./bin/x64/Algae.exe
--
-- where "bin" is in the same source directory as a folder called
-- "src" which contains the file "main.cpp". We recommend either
-- changing the relative path in code, OR building the executable
-- with VS, then running it standalone so that the relative path
-- is correct w.r.t. algae.csv.
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "../include/ndxl.h"

const double omega = 2.94 * TWO_PI;
const double delta = 0.81;
const double N_i = 160.0;
const double nu_m = 1.74e-4;
const double theta_0 = 0.05 * TWO_PI;
const double theta_c = 0.45 * TWO_PI;
const double K_N = 350.0;
const double chi = 0.018;
const size_t nu = 4;

NDXLVertex* nutrient;
std::ofstream ofs;
std::vector<long> bins(64, 0);

// Uniform random double generator in the range [low; high)
inline const double randdbl(const double low = 0.0, const double high = 1.0)
{
	srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock().now().time_since_epoch()).count());
	const double range = high - low;
	return low + range * static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
}

// Cell noise
void noise(NDXLVertex* vert, double* c, double t, const void* p)
{
	*c = randdbl(-0.1, 0.1);
}

// Cell evolution
void cell(NDXLVertex* vert, double* dtheta, const double* theta, double t, const void* p)
{
	const double N = *ndxlGetVertexState(nutrient);
	*dtheta = omega * (1.0 - N / (K_N + N)) * (1.0 + 1.0 / (1.0 + exp((*theta - theta_0) / (0.01 * TWO_PI))) - 1.0 / (1.0 + exp((*theta - theta_c) / (0.01 * TWO_PI)))) + omega * N / (K_N + N);
}

// Nutrient evolution
void nutrients(NDXLVertex* vert, double* dN, const double* n, double t, const void* p)
{
	*dN = delta * (*n - N_i) - nu_m * *n / (K_N + *n) * ndxlGetNetworkVertexCount(ndxlGetVertexNetwork(vert));
}

// Network callback
void cb(NDXLNetwork* nwk, const double time, const void* p)
{
	// Write out current cell phases
	const size_t cells = ndxlGetNetworkVertexCount(nwk);
	NDXLVertex** verts = new NDXLVertex*[cells];
	ndxlGetNetworkVertices(nwk, verts);
	ofs << time + 28.8;
	for (size_t i = 0; i < cells; i++)
	{
		const double st = *ndxlGetVertexState(verts[i]);
		const long bin = (long)(10.0 * st);
		bins[(bin > 63 ? 63 : bin)]++;

		// Birth daughter cells at phase 0
		if (st >= TWO_PI)
		{
			const double phase = 0.0;
			ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
			ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
			ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
			ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
			ndxlDestroyVertex(verts[i]);
		}
	}

	// Write out and reset bins
	for (long i = 0; i < 64; i++)
	{
		ofs << ',' << bins[i];
		bins[i] = 0;
	}
	ofs << std::endl;
}

int main(int argc, char** argv)
{
	// Initialise everything
	ndxl::init();
	srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock().now().time_since_epoch()).count());
	ofs = std::ofstream("../../res/dist.csv");
	ofs << "Time";
	NDXLNetwork* nwk = ndxlCreateNetwork(0);

	// Read in starting distribution
	std::ifstream ifs("../../res/algae.csv");
	std::string line;

	// Discard first line (headers)
	std::getline(ifs, line);

	// Parse first bin so that bin widths can be calculated and used for initialisation
	std::getline(ifs, line);
	size_t pos = line.find(',');
	double phase0 = std::stod(line.substr(0, pos));
	long count = std::stol(line.substr(pos + 1));

	// Parse bins and counts
	while (std::getline(ifs, line))
	{
		// Determine upper phase bound
		pos = line.find(',');
		const double phase1 = std::stod(line.substr(0, pos));

		// Create count number of cells in the bin [phase0; phase1)
		for (long i = 0; i < count; i++)
		{
			const double phase = randdbl(phase0, phase1);
			ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
		}

		// Update lower phase bound and cell count
		phase0 = phase1;
		count = std::stol(line.substr(pos + 1));
	}

	// Repeat for final count, then close file
	for (long i = 0; i < count; i++)
	{
		const double phase = randdbl(phase0, TWO_PI);
		ndxlCreateVertex(nwk, &phase, 1, 0, cell, noise, 0);
	}
	ifs.close();

	// Create "nutrients" vertex
	nutrient = ndxlCreateVertex(nwk, &N_i, 1, 0, nutrients, 0, 0);

	// Output bins
	for (long i = 0; i < 64; i++)
		ofs << ",Bin" << (i + 1);
	ofs << std::endl;

	// Simulate network
	ndxlNetworkSimulate(nwk, 3.0, 5e-3, cb);
	ofs.close();

	return 0;
}