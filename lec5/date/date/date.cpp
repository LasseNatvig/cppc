// date.cpp, inspired by PPP section 9.4
#include "std_lib_facilities.h"

struct Date {
	int year;  
	int month; 
	int day;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d) { // check for valid date and initialize
	// check that (y, m, d) is a valid date
	cout << "checking valid date NOT completely implemented\n";
	if (d > 31) {
		//throw "Invalid date passed to constructor";
		throw exception("Invalid date passed to constructor");
	}
	else {
		year = y;
		month = m;
		day = d;
	}
}
void Date::add_day(int n) {	// increase the Date by n days
	cout << "add day NOT implemented\n";
}
int main() try {
	//Date my_birthday; // error: 
	Date today{ 12, 24, 2007 };
	return 0;
}
catch (exception& e) {
	cerr << e.what(); 
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	return 2;
}