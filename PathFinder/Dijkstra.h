#pragma once
#include "Graph.h"

class Dijkstra
{
public:
	static std::vector<int> solve(int u,int v,Graph& g){
		int n = g.size();
		std::vector<std::pair<int, double>> temp(n, { -1,9999999 }); // { Preced, Value }
		std::vector<bool> used(n, false);

		double distance = 0;
		int actual_node = u;
		used[u] = true;

		for (int i = 0; i < n; i++) {
			std::vector<std::pair<int, double>>& vec=g.getVector(actual_node);
			
			for (int j = 0; j < vec.size(); j++) {
				int node = vec[j].first;
				if (!used[node]) {
					if (distance + vec[j].second < temp[node].second) {
						temp[node] = { actual_node,distance + vec[j].second };
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

