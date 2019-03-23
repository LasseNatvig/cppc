// algo_3.cpp
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main() {
	int sum = 0;
	vector<int> v{ 1,1,1,1000 };
	cout << accumulate(v.begin(), v.end(), 3) << endl;
	 
	vector<int> v2{ 2,0,0,3 };
	cout << inner_product(v.begin(), v.end(), v2.begin(), 100);
	cout << endl;

	vector<int> result(v.size());
	partial_sum(v.begin(), v.end(), result.begin());
	for (auto e : result) cout << e << " ";
	cout << endl;

	return 0;
}
