// Lec2Ex3.cpp      Demonstrates ....
#include "../../std_lib_facilities.h"

const int maxNum = 5000000;

vector<int> generateVector(unsigned int n) {
	vector<int> temp;
	for (unsigned int i = 0; i < n; i++) {
		temp.push_back(randint(maxNum));
	}
	return temp;
}

void searchVectorCopy(vector<int> v, int num) { // copy by value
	for (unsigned int i = 0; i < v.size(); ++i) {
		if (v[i] == num)
			cout << "Num: " << num << "found at index " << i << endl;
	}
	cout << endl;
}

void searchVectorRef(vector<int> v_r, int num) { // copy by value
	for (unsigned int i = 0; i < v_r.size(); ++i) {
		if (v_r[i] == num)
			cout << "Num: " << num << "found at index " << i << endl;
	}
	cout << endl;
}

void searchVectorConstRef(const vector<int>& v_cr, int num) { // copy by value
	for (unsigned int i = 0; i < v_cr.size(); ++i) {
		if (v_cr[i] == num)
			cout << "Num: " << num << "found at index " << i << endl;
	}
	cout << endl;
}

int main() {
	vector<int> V = generateVector(10000000);
	searchVectorCopy(V, 9999);	
	searchVectorRef(V, 9999);	
	searchVectorConstRef(V, 9999);
}
