#include "../../std_lib_facilities.h"

 //void f(int a, int& r, const int& cr) { 
	//++a; ++r; ++cr; // error: 'cr': you cannot assign to a variable that is const
 //}
void g(int a, int& r, const int& cr) { 
	++a; ++r; int x = cr; ++x; 
}
int main() {
	int x = 0;
	int y = 0;
	int z = 0;
	g(x, y, z);	// x==0; y==1; z==0
	// g(1, 2, 3);	// error: 'void g(int... cannot convert argument 2 from 'int' to 'int &'
	g(1, y, 3);	// ok: since cr is const we can pass “a temporary”
}




//int square(int x) {
//	return x * x;
//}
//
//int max(int a, int b) { 
//	if (a<b)
//		return b;
//	else
//		return a;
//}
//
//int main() {
//
//}

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