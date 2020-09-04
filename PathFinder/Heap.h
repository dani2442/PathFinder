#pragma once

struct Data {
	int index;
	double value;
};

class Heap {
public:
	Heap(int size): n(size){
		v = new Data[size];
		for (int i = 0; i < n; i++) {
			v[i] = { -1,999999999};
		}
	}
	~Heap() { delete[] v; }

	void add(Data& d){
		int i = temp;
		while (d.value<v[(i-1)/2].value) {
			v[i] = v[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		v[i] = d;
		temp++;
	}
	Data& get_min() { return v[0]; }
	void del_min(){
		int i = 0;
		while (2 * i + 1 <= temp) {
			if (2 * i + 1 == temp) {
				v[i] = v[2 * i + 1];
			}
			else {
				if (v[2 * i + 1].value > v[2 * i + 2].value) {
					v[i] = v[2 * i + 2];
					i = 2 * i + 2;
				}
				else {
					v[i] = v[2 * i + 1];
					i = 2 * i + 1;
				}
			}
		}
		temp--;
	}

	int size() { return this->n; }

private:
	int get_parent(int i) { return int((n - 1) / 2); }
	int get_child(int i) { return 2 * i + 1; }

	int temp=0;
	int n;
	Data* v;
};