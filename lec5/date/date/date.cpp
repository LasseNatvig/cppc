// date.cpp
#include "std_lib_facilities.h"

// simplest Date (just data)                                                             d
struct Date {
	int year;  
	int month; 
	int day;
};

int main(){
	Date birthday;	// a Date variable (object)
	birthday.year = 12;
	birthday.month = 30;
	birthday.day = 1950; // oops! (no day 1950 in month 30)
					// later in the program, this day will give a problem
	return 0;
}

