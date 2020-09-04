#include "Graph.h"
#include "Heap.h"
#include "Dijkstra.h"
#include "A_star.h"
#include "ReadData.h"
#include <iostream>
#include <chrono>


using namespace std::chrono;

static void out(std::vector<int>& v) {
	std::cout << v[0];
	for (int i = 1; i < v.size();i++) {
		std::cout << "," << v[i] ;
	}
}

int main() {

	/*
	std::vector < std::vector<std::pair<int, double>> > g=
	{
		{{1,8},{3,5},{2,2}},
		{{0,8},{3,2},{5,13}},
		{{0,2},{3,2},{4,5}},
		{{0,5},{1,2},{2,2},{4,1},{6,3},{5,6}},
		{{3,1},{2,5},{6,1}},
		{{1,13},{3,6},{6,2},{7,3}},
		{{3,3},{4,1},{5,2},{7,6}},
		{{5,3},{6,6}}
	};

	Graph graph(g);
	Dijkstra::solve(0, 7, graph);
	*/
	
	Graph graph;
	std::vector<Node> nodes;

	read("", graph, nodes);


	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//auto s=Dijkstra::solve(0, 20000, graph);
	auto s = A_star::solve(0, 20000, graph, nodes);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	out(s);
	std::cout << std::endl;
	std::cout << "Time difference = " << (double)std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/10e6 << "[s]" << std::endl;
	getchar();
	
}