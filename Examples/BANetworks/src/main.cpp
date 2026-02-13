#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/ndxl.h"

// Create storage for the vertices, evaluation times, and order parameter
std::vector<NDXLVertex*> vertices;
std::vector<double> times, op;

// C-style function to generate random numbers in the range [low, high)
const double randdbl(const double low, const double high)
{
	return low + (high - low) * ((double)rand() / (double)RAND_MAX);
}

// Vertex evolution function
void kuramoto(NDXLVertex* vert, double* du, const double* u, double t, const void* p)
{
	double sum = 0.0;
	for (NDXLEdge* edge = ndxlGetVertexFirstEdge(vert); edge; edge = ndxlGetVertexNextEdge(vert, edge))
	{
		const double* st = ndxlGetVertexNeighbourState(vert, edge);
		if (st)
			sum += *ndxlGetEdgeState(edge) * sin(*st - *u);
	}
	*du = *(double*)p + sum / ndxlGetVertexConnectivity(vert);
}

// Split string based on delimiter
std::vector<std::string> split(const std::string& str, const char delimiter = ',')
{
	std::vector<std::string> outv;
	std::string s = str;
	while (s.length())
	{
		const size_t pos = s.find(delimiter);
		if (pos == std::string::npos)
		{
			outv.push_back(s);
			s.erase(0, s.length());
		}
		else
		{
			outv.push_back(s.substr(0, pos));
			s.erase(0, pos + 1);
		}
	}
	return outv;
}

// Network callback to reset state of first and last oscillators to 0
void network_cb(NDXLNetwork* nwk, const double t, const void* p)
{
	const std::size_t N = ndxlGetNetworkVertexCount(nwk);
	if (t == 10.0)
	{
		double null_state = 0.0;
		ndxlSetVertexState(vertices[0], &null_state);
		ndxlSetVertexState(vertices[N - 1], &null_state);
	}

	// Calculate order parameter
	double outer_sum = 0.0;
	for (long i = 0; i < N; i++)
	{
		double inner_sum = 0.0;
		for (long j = 0; j < N; j++)
			inner_sum += std::cos(*ndxlGetVertexState(vertices[j]) - *ndxlGetVertexState(vertices[i]));
		outer_sum += inner_sum;
	}
	times.push_back(t);
	op.push_back(std::sqrt(outer_sum) / N);
}

void run_sim(const long N)
{
	// Open file, prepare network variables
	const long K = (long)(0.4 * N);
	std::ifstream ifs("../../res/networks/BA_n" + std::to_string(N) + "_k" + std::to_string(K) + ".csv");
	NDXLNetwork* network = ndxlCreateNetwork(0);
	vertices = std::vector<NDXLVertex*>(N);
	times.clear();
	op.clear();
	std::vector<std::vector<std::string>> lines(N);

	// Read file, create vertices
	for (long i = 0; i < N; i++)
	{
		std::string line;
		std::getline(ifs, line);
		lines[i] = split(line);
		const double theta = std::stod(lines[i][N]);
		const double omega = std::stod(lines[i][N + 1]);
		vertices[i] = ndxlCreateVertex(network, &theta, 1, &omega, kuramoto, 0, 0);
	}
	ifs.close();

	// Create edges
	const double weight = 1.0;
	for (long i = 0; i < N; i++)
		for (long j = i; j < N; j++)
			if (lines[i][j] == "1")
				ndxlCreateEdge(vertices[i], vertices[j], &weight, 1, 0, 0, false, 0, 0, 0);

	// Simulate network
	ndxlNetworkSimulate(network, 25.0, 0.1, network_cb);

	// Write order parameter results to file
	std::ofstream ofs("../../res/results/BA_n" + std::to_string(N) + "_k" + std::to_string(K) + ".csv");
	for (std::size_t i = 0; i < times.size(); i++)
		ofs << times[i] << "," << op[i] << std::endl;
	ofs.close();
}

int main(int argc, char** argv)
{
	ndxlInit();
	for (long n = 10; n <= 100; n += 15)
		run_sim(n);
	return 0;
}