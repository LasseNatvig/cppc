#include "std_lib_facilities.h"




//int main() {
//	//cout << dec << 1234 << "\t(decimal)\n"
//	//	 << hex << 1234 << "\t(hexadecimal)\n"
//	//	 << oct << 1234 << "\t(octal)\n";
//	//// The '\t' character is “tabulator” 
//
//	cout << 1234.56789 << "\t\t(defaultfloat)\n"
//		 << fixed << 1234.56789 << "\t(fixed)\n"
//		 << scientific << 1234.56789 << "\t(scientific)\n";
//
//
//}


//struct Date {
//	int day, month, year;
//};
//istream& operator>>(istream& is, Date& dd)
//// Read date in format: ( year , month , day )
//{
//	int y, d, m;
//	char ch1, ch2, ch3, ch4;
//	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
//	if (!is) return is;	// we didn’t get our values, so just leave
//	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {	// oops: format error
//		is.clear(ios_base::failbit); // something wrong: set state to fail()
//		return is; // and leave
//	}
//	dd = Date{ y,m,d };	// update dd
//	return is;			// and leave with is in the good() state
//}
//
//ostream& operator<< (ostream& os, const Date& d) {
//	return os << '(' << d.year
//		<< ',' << d.month
//		<< ',' << d.day << ')';
//}
//
//int main() {
//	cout << "Please enter input file name: ";
//	string iname;
//	cin >> iname;
//	ifstream ist{ iname }; // ifstream is an “input stream from a file”
//				// defining an ifstream with a name iname
//				// opens the file of that name for reading
//	if (!ist) error("can’t open input file ", iname);
//
//	cout << "Please enter name of output file: ";
//	string oname;
//	cin >> oname;
//	ofstream ofs{ oname }; // ofstream is an “output stream to a file”
//					// defining an ofstream with a name oname
//					// opens the file with that name for writing
//	if (!ofs) error("can’t open output file ", oname);
//
//
//	struct Reading { // a temperature reading
//		int hour;	// hour after midnight [0:23]
//		double temperature;
//	};
//
//	vector<Reading> temps;	// create a vector to store the readings
//
//	int hour;
//	double temperature;
//	while (ist >> hour >> temperature) { // read
//		if (hour < 0 || 23 < hour)
//			error("hour out of range");	// check
//		temps.push_back(Reading{ hour,temperature }); // store
//	}
//
//
//}
//
////
////class X {
//public:
//	int m;	  // data member
//	int mf(int v) { // function member
//		int old = m;
//		m = v;
//		return old;
//	}
//};
//
//int x;	// global variable – avoid those where you can
//int y;	// another global variable
//
//int f() {
//	int x;	// local variable (Note – now there are two x’s)
//	x = 7;	// local x, not the global x
//	{
//		int x = y;	// another local x, initialized by the global y
//					// (Now there are three x’s)
//		++x;		// increment the local x in this scope
//	}
//	return x;
//}
//// avoid such complicated nesting and hiding: keep it simple!
//
//
//void func(int& x) {
//	x++;
//}
//
//
//enum class Month {
//	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
//};
//Month operator++(Month& m) {	// prefix increment operator
//	// “wrap around”:
//	m = (m == Month::dec) ? Month::jan : Month(static_cast<int>(m) + 1);
//	return m;
//}

//class Year { // year in [min:max) range
//	static constexpr int min = 1800;
//	static constexpr int max = 2200;
//public:
//	class Invalid { };
//	Year(int x) : y{ x } {
//		if (x < min || max <= x) {
//			throw Invalid{};
//		}
//	}
//	int year() { return y; }
//private:
//	int y;
//};




//int main() try {
//
//	ostream os;
//
//	Year{ 1814 };
//	Year{ 1750 };
//}
//catch (exception& e) {	// out_of_range exceptions
//	cerr << "Exception caught:" << e.what() << endl;
//}
//catch (...) {		// all other exceptions
//	cerr << "oops ... some exception\n";
//}


	//Month m = Month::nov;
	//++m;	// m becomes dec
	//++m;	// m becomes jan


	//int a = 0;
	//// int& b = 0;  // error, does not compile 
	//int b = 0;
	//func(a);
	//// func(b&); // error, does not compile 
	//cout << "a = " << a << endl;


	//cout << endl;

	//// if without else, and difference from python
	//{
	//	int a = 2;
	//	if (a == 2)
	//		cout << 2 << endl;
	//		cout << 3 << endl; // Don't do this!!!
	//	a = 4;
	//	if (a == 2)
	//		cout << 2 << endl;
	//		cout << 3 << endl; // is printed !
	//	cout << "end\n";
	//}




	//X var;			// var is a variable of type X 
	//var.m = 7;		// access var’s data member m
	//int x = var.mf(9); // call var’s member function mf()


	//{ // Plain enum-test
	//	enum TitleColor { red, green };	// a “plain” enum { } doesn’t define a scope
	//	int title_color = red;			// red is available here
	//	enum CanvasColor { white, red, blue, purple };	// error: red defined twice
	//	int canvas_color = red;
	//}


	//{ // Scoped enum-test
	//	enum class TitleColor { red, green };
	//	// int title_color = TitleColor::red; // gives error, not allowed	
	//	TitleColor title_color = TitleColor::red;

	//	enum class CanvasColor { white, red, blue, purple };
	//	CanvasColor canvas_color = CanvasColor::red;
	//	cout << "If you really need the int value ";
	//	cout << static_cast<int>(CanvasColor::blue);
	//}

	//cout << "";





//int main()
//try {
//	// …
//}
//catch (out_of_range) {	// out_of_range exceptions
//	cerr << "oops – some vector index out of range\n";
//}
//catch (...) {		// all other exceptions
//	cerr << "oops – some exception\n";
//}
//


//int main() {
	//char c = 'x';
	//bool found = false;
	//string str = "ABCDdefg";
	//for (int i = 0; i < str.length(); ++i) {
	//	if (str[i] == c) {
	//		found = true;
	//		break;
	//	}
	//}


	//char c = 'y';
	//int i1 = c;
	//int i2 = 'y';
	//cout << (c - 1) << ' ' << (c + 1) << endl;
	//char c1 = c - 1;
	//char c2 = i2 + 1;
	//cout << c1 << ' ' << c2 << endl;
	//c2 = toupper(c2);
	//cout << c1 - 'a' << ' ' << c2 << endl;

	//cout << "fin";

	//_setmode(_fileno(stdout), _O_U16TEXT);
	////char c = 'x';
	////int i1 = c;
	////int i2 = 'x';
 //
	//wcout << L"Spade: \x2660\n" << endl;
	//wcout << L"Club: \x2663\n" << endl;
	//wcout << L"Heart: \x2665\n" << endl;
	//wcout << L"Diamond: \x2666\n" << endl;

	//keep_window_open();
//}


 //void f(int a, int& r, const int& cr) { 
	//++a; ++r; ++cr; // error: 'cr': you cannot assign to a variable that is const
 //}
//void g(int a, int& r, const int& cr) { 
//	++a; ++r; int x = cr; ++x; 
//}
//int main() {
//	int x = 0;
//	int y = 0;
//	int z = 0;
//	g(x, y, z);	// x==0; y==1; z==0
//	// g(1, 2, 3);	// error: 'void g(int... cannot convert argument 2 from 'int' to 'int &'
//	g(1, y, 3);	// ok: since cr is const we can pass “a temporary”
//}

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