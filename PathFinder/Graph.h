#pragma once
#include <vector>
/*
template <typename T>
class Graph {
public:
	virtual void setValue(int u, int v, T& u);
	virtual T& getValue(int u, int v);

	virtual int size(int n);
};*/
struct Node {
	double x, y;

	static double l2(Node& a, Node& b) { return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y); }
};

class Graph {
public:
	Graph() {}
	Graph(int n): g(std::vector<std::vector<std::pair<int,double>>>(n,std::vector<std::pair<int,double>>())){}
	Graph(std::vector<std::vector<std::pair<int, double>>>& g): g(g){}

	int size() { return g.size(); }
	double getValue(int u,int v){
		std::vector<std::pair<int, double>>::iterator it;
		for (it = g[u].begin(); it != g[u].end(); it++)
			if (it->first == v) return it->second; 
		return false;
	}
	std::vector<std::pair<int, double>>& getVector(int u) { return g[u]; }

	void setValue(int u, int v, double val) { 
		std::vector<std::pair<int, double>>::iterator it;
		for (it = g[u].begin(); it != g[u].end(); it++)
			if (it->first == v) {
				it->second = val;
				return;
			}
		g[u].push_back({ v,val });
	}

	void addValue(int u, int v, double val) {
		g[u].push_back({ v,val });
	}
private:
	std::vector<std::vector<std::pair<int, double>>> g;
};