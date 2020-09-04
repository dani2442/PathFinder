#pragma once
#include "Graph.h"
#include "Heap.h"

class A_star
{
public:
	static std::vector<int> solve(int u,int v,Graph& g,std::vector<Node>& nodes){
		int n = g.size();
		Heap temp(n);
		std::vector<int> preced(n, -1);
		std::vector<bool> used(n, false);

		double distance = Node::l2(nodes[u],nodes[v]);
		int actual_node = u;
		used[u] = true;

		for (int i = 0; i < n; i++) {
			std::vector<std::pair<int, double>>& vec=g.getVector(actual_node);
			
			for (int j = 0; j < vec.size(); j++) {
				int node = vec[j].first;
				if (!used[node]) {
					double cost = distance + vec[j].second+Node::l2(nodes[node],nodes[v]) - Node::l2(nodes[actual_node], nodes[v]);
					if (cost < temp.getValue(node)) {
						temp.add(node, cost);
						preced[node]=actual_node;
					}
				}
			}

			int min = temp.get_min();
			temp.del_min();

			if (min == v) {
				break;
			}

			used[min] = true;
			distance = temp.getValue(min);
			actual_node = min;
		}

		std::vector<int> r;
		int k = v;
		while (true) {
			if(k==u){
				r.push_back(u);
				std::reverse(r.begin(), r.end());
				return r;
			}
			else if (preced[k]== -1) return {};
			else {
				r.push_back(k);
				k=preced[k];
			}
		}
	}
};

/*
#pragma once
#include "Graph.h"

class A_star
{
public:
	static std::vector<int> solve(int u,int v,Graph& g,std::vector<Node>& nodes){
		int n = g.size();
		std::vector<std::pair<int, double>> temp(n, { -1,999999999 }); // { Preced, Value }
		std::vector<bool> used(n, false);

		double distance = Node::l2(nodes[u],nodes[v]);
		int actual_node = u;
		used[u] = true;

		for (int i = 0; i < n; i++) {
			std::vector<std::pair<int, double>>& vec=g.getVector(actual_node);
			
			for (int j = 0; j < vec.size(); j++) {
				int node = vec[j].first;
				if (!used[node]) {
					double cost = distance + vec[j].second+Node::l2(nodes[node],nodes[v]) - Node::l2(nodes[actual_node], nodes[v]);
					if (cost < temp[node].second) {
						temp[node] = { actual_node,cost };
					}
				}
			}

			int min = 0;double min_distance = 999999999;
			for (int j = 0; j < temp.size(); j++) {
				if (!used[j] && temp[j].second<min_distance) {
					min_distance = temp[j].second;
					min = j;
				}
			}

			if (min == v) {
				break;
			}

			used[min] = true;
			distance = min_distance;
			actual_node = min;
		}

		std::vector<int> r;
		int k = v;
		while (true) {
			if(k==u){
				r.push_back(u);
				std::reverse(r.begin(), r.end());
				return r;
			}
			else if (temp[k].first == -1) return {};
			else {
				r.push_back(k);
				k=temp[k].first;
			}
		}
	}
};
*/