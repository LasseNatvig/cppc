// Lec1Ex5.cpp      Demonstrates simple use of string
#include "std_lib_facilities.h"
int main() {
	string s1("Hello");
	string s2 = "World";
	string s3 = s1 + " " + s2 + "!";
	cout << "1) " << s3 << endl;

	string s4 = "Strange ";
	s3.insert(6, s4);
	cout << "2) " << s3 << "\n";

	cout << "3) Length of s3 is: " << s3.size() << '\n';

	// access to char

	// substr ...

	keep_window_open();
}