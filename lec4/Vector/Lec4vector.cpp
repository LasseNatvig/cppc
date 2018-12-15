/* Lec4vector.cpp
(See also Lec1Ex4.cpp)
*** This file demonstrates:
- generating random numbers with rand() and srand()
- (Three ways to loop, repetition from Lec1Ex4)
- out of range error
- exceptions try catch
*/

#include "../../std_lib_facilities.h"  // If this is not used, include the three statements below
//#include <iostream>
//#include <vector>
//using namespace std;

int main() {
	constexpr int N = 10;
	vector<int> nums{}; // initially empty

	// Generating random numbers with rand() and srand()
	// see https://en.cppreference.com/w/cpp/numeric/random/srand
	// see also Exercise 3

	srand(7); // 7 is just an arbitrary seed value. Try another number and see the difference 
	for (unsigned int i = 0; i < N; i++) {
		nums.push_back(rand());
	}

	// Three ways to loop through those numbers
	// 1) The traditional for loop:
	// for (unsigned int i = 0; i < N; i++) {
	for (int i = 0; i < N; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	// 2) range for 
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;

	// 3) range for with auto
	for (auto n : nums) {
		cout << n << " ";
	}
	cout << endl;

	// Out of range error:
	// Assume that we somewhere in the code do not remember 
	// if N is the number of elements in the vector (true)
	// or the last index in the vector (false). We try the last option:

	//// 4) Traditional for loop with range error
	//for (unsigned int i = 0; i <= N; i++) {
	//	cout << nums[i] << " ";
	//}
	//cout << endl;

	// 5) Traditional for loop with range error, try - catch demo, PPP page 149
	//try {
	//	for (unsigned int i = 0; i <= N; i++) {
	//		cout << nums[i] << " ";
	//	}
	//	cout << endl;
	//}
	//catch (out_of_range) {
	//	cerr << "Oops! Range error\n";
	//	return 1;
	//}
	//catch (...) {
	//	cerr << "Unknown exception\n";
	//	return 2;
	//}

	//cout << endl;

	// 6) Traditional for loop with range error, try - catch demo, PPP page 149
	try {
		for (unsigned int i = 0; i <= N; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	catch (exception& e) {
		cerr << "Exception: " << e.what() << "\n";
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception\n";
		return 2;
	}




	//// 6) as above but with try-catch, PPP 5.6 and 5.6.2
	//try {

	//	// TEST Bjarne error(s) og error(s1, s2);

	//	error("Test-error");

	//	for (unsigned int i = 0; i <= N; i++) {
	//		cout << nums[i] << " ";
	//	}
	//	cout << endl;
	//}
	//catch (out_of_range) {
	//	cerr << "Range error\n";
	//	throw(runtime_error("range-error*****"));
	//	//keep_window_open();
	//	return 1;
	//}
	//catch (runtime_error) {
	//	cerr << "runtime error\n";
	//	throw(runtime_error("runtime-error*****"));
	//	keep_window_open();
	//	return 1;
	//}
	//catch (...) {
	//	cerr << "Exception: something went wrong\n";
	//	keep_window_open();
	//	return 2;
	//}

	//int i = 10;
	//cout << i / 0;

	//***************************** hjalp ikke

	//catch (out_of_range) {
	//	throw(runtime_error("range error"));
	//	//cerr << "Range error\n";
	//	//keep_window_open();

}