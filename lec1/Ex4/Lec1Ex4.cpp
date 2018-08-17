// Lec1Ex4.cpp
#include "std_lib_facilities.h"
int main() {
	vector<int> numbers{ -3, 3, 5, 8888 };

	cout << "The numbers are:\n";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << endl;
	}

	keep_window_open();
}