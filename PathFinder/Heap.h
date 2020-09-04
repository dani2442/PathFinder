#pragma once
#include <iostream>

class Heap {
public:
	Heap(int size): n(size),v(size,9999999999999),idx(size,-1) { }

	double getValue(int index) { return v[index]; }
	void setValue(int index,double val) { v[index] = val; }

	void add(int index, double val){
		int i = temp;
		while (i!=0 && val<v[idx[(i-1)/2]]) {
			idx[i] = idx[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		v[index] = val;
		idx[i] = index;
		temp++;
	}
	double get_min() { return idx[0]; }
	void del_min(){
		int i = 0;
		temp--;
		while (2 * i + 1 < temp) {
			if (2 * i + 2 == temp) {
				if (v[idx[temp]] > v[idx[2 * i + 1]]) {
					idx[i] = idx[2 * i + 1];
					idx[2 * i + 1] = idx[temp];
				}
				else {
					idx[i] = idx[temp];
				}
				i = 2 * i + 1;
				return;
			}
			else {
				if (v[idx[2 * i + 1]] > v[idx[2 * i + 2]]) {
					idx[i] = idx[2 * i + 2];
					i = 2 * i + 2;
				}
				else {
					idx[i] = idx[2 * i + 1];
					i = 2 * i + 1;
				}
			}
		}
		idx[i] = idx[temp];
		
	}

	void debug_print() {
		int c = 0;
		while (true) {
			for (int i = 0; i < pow(2, c); i++) {
				if (i + (int)pow(2, c) - 1 >= temp) {
					std::cout << std::endl; return;
				}
				std::cout << v[idx[(int)pow(2, c) + i - 1]] << " ";
			}
			std::cout << std::endl;
			c++;
		}
	}

private:
	int get_parent(int i) { return int((n - 1) / 2); }
	int get_child(int i) { return 2 * i + 1; }

	int temp=0;
	int n;
	std::vector<int> idx;
	std::vector<double> v;
};