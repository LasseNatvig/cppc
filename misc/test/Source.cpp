#include "../../std_lib_facilities.h"

int square(int x) {
	return x * x;
}

int max(int a, int b) { 
	if (a<b)
		return b;
	else
		return a;
}

int main() {

}

// call-by-value (send the function a copy of the argument’s value)

//int f(int a) { a = a+1; return a; }
//
////int main()
//{
//	int xx = 0;
//	cout << f(xx) << '\n';	// writes 1
//	cout << xx << '\n'; 	// writes 0; f() doesn’t change xx
//	int yy = 7;
//	cout << f(yy) << '\n';  // writes 8;  f() doesn’t change yy
//	cout << yy << '\n'; 	// writes 7
//}
//
// call-by-reference (pass a reference to the argument)
//int f(int& a) { a = a + 1; return a; }
//
//int main()
//{
//	int xx = 0;
//	cout << f(xx) << '\n'; // writes 1	
//						   // f() changed the value of xx
//	cout << xx << '\n';    // writes 1
//	int yy = 7;
//	cout << f(yy) << '\n'; // writes 8
//						   // f() changes the value of yy
//	cout << yy << '\n';    // writes 8
//}