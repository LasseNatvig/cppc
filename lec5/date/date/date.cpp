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
	// **** Hent inn fra eksamen i fjor

	if (d > 31) {
		//throw "Invalid date passed to constructor"; // works but not recommended
		throw exception("Invalid date passed to constructor"); // gives error message
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

class Date_s { // short for Date_safe
	int year;
	int month;
	int day;
public:
	Date_s(int y, int m, int d);
	void add_day(int n);
	int get_month() { return month; }
	int get_day() { return day; }
	int get_year() { return year; }
};

Date_s::Date_s(int y, int m, int d) : year{ y }, month{ m }, day{ d }
{
	// check that (y, m, d) is a valid date
	// ...
	cout << "checking valid date NOT completely implemented\n";
	// **** Hent inn fra eksamen i fjor
	if (d > 31) {
		//throw "Invalid date passed to constructor";
		throw exception("Invalid date passed to constructor");
	}
	else {
		// is OK
	}
}

void Date_s::add_day(int n) {	// increase the Date by n days
	cout << "add day NOT implemented\n";
}

int main() try {
	// Date my_birthday; // error: no default contructor
	Date today{ 12, 24, 2007 };  // gives run time error (exception)
	Date last{ 2000, 12, 31 }; // OK, recommended style
	Date next = { 2014, 2, 14 }; // OK, slightly verbose
	Date christmas = Date{ 1976, 12, 24 }; // OK, verbose

	Date whatAday(1958, 5, 20); // OK, but now a rather OLD style (C++98) (PPP p. 312)

	// add_day(1); // error, add_day undefined, (what date?)
	last.add_day(2);

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