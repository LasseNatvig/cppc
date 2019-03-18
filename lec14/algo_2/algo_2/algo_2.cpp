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

	{// Part 2, copy
		**********vector<int> nums{ 1, 2, 3, 100, 200, 300 };
		for_each(nums.begin(), nums.end(), print);
		cout << '\n';
		for_each(nums.begin(), nums.end(), PrintGE(100));
		cout << '\n';
	}

	{// Part 3, transform
		//**********vector<int> nums{ 1, 2, 3, 100, 200, 300 };
		//for_each(nums.begin(), nums.end(), print);
		//cout << '\n';
		//for_each(nums.begin(), nums.end(), PrintGE(100));
		//cout << '\n';
	}


	{// Part 4, sort
		//**********vector<int> nums{ 1, 2, 3, 100, 200, 300 };
		//for_each(nums.begin(), nums.end(), print);
		//cout << '\n';
		//for_each(nums.begin(), nums.end(), PrintGE(100));
		//cout << '\n';
	}







	return 0;
}