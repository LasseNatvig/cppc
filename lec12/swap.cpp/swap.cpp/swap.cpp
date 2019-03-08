#include<iostream>
#include<vector>
using namespace std; 

template<typename T>
void mySwap(T & v1, T & v2) {
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

int main() {
	vector<int> v1{ 11,22,33 };
	vector<int> v2;
	mySwap(v1, v2);
	for (auto e : v1) cout << e << " ";
	cout << endl;
	for (auto e : v2) cout << e << " ";
	return 0;
}