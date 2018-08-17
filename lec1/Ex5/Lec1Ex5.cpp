// Lec1Ex5.cpp      Demonstrates simple use of string
#include "std_lib_facilities.h"
int main() {
	vector<int> numbers{ -3, 3, 5, 8888 };

	cout << "The numbers *****************' CHANGE ALL CODE HERE ****** are:\n";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << endl;
	}

	keep_window_open();
}