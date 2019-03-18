// algo_2.cpp
// Inspired by https://en.cppreference.com/w/cpp/algorithm/for_each

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct PrintGE {// Greater or Equal
	PrintGE(int v) : value{ v } { }
	int value;
	bool operator()(int x) {
		if (x >= value) {
			cout << " " << x;
			return true;
		}
		else return false;
	}
};

void print(const int& n) {
	cout << " " << n;
}

int main() {
	{// Part 1, for_each
		vector<int> nums{ 1, 2, 3, 100, 200, 300 };
		for_each(nums.begin(), nums.end(), print);
		cout << '\n';
		for_each(nums.begin(), nums.end(), PrintGE(100));
		cout << '\n';
	}
	cout << endl;

	{// Part 2, unique_copy
		vector<int> v{ 1, 2, 2, 3, 2, 2, 4, 4, 4, -7, 8};
		vector<int> v2(v.size()); // Reserve sufficient space in destination
		unique_copy(v.begin(), v.end(), v2.begin());
		for_each(v2.begin(), v2.end(), print);
		cout << '\n';
	}
	cout << endl;

	{// Part 3, merge
		vector<int> v1{ 1, 2, 3, 100, 200, 300 };
		vector<int> v2{ 3, 4, 5, 6, 800, 10000 }; 
		vector<int> dest(v1.size() + v2.size());
		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());
		for_each(dest.begin(), dest.end(), print);
		cout << '\n';	
	}

	{// Part 4, transform
	 
	}


	{// Part 5, sort
		// maybe in a separate file
	}



	return 0;
}