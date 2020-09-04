#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
#include "Graph.h"

static void read(std::string path, Graph& g, std::vector<Node>& n) {
	std::ifstream f1,f2;
	f1.open(path + "cal.cnode.txt");
	f2.open(path + "cal.cedge.txt");

	std::string s;
	while (std::getline(f1,s)) {
		std::istringstream iss(s);
		std::string s1;
		std::getline(iss, s1, ' ');
		std::getline(iss, s1, ' ');
		Node node;
		node.x=stod(s1);
		std::getline(iss, s1, ' ');
		node.y = stod(s1);

		n.push_back(node);
	}

	g = Graph(n.size());
	while (std::getline(f2, s)) {
		std::istringstream iss(s);
		std::string s1;
		std::getline(iss, s1, ' ');
		std::getline(iss, s1, ' ');
		int u = stoi(s1);
		std::getline(iss, s1, ' ');
		int v = stoi(s1);
		std::getline(iss, s1, ' ');
		double val = stod(s1);
		g.addValue(u, v, val);
		g.addValue(v, u, val);
	}

}