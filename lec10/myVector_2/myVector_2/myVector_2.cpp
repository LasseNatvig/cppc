/* myVector_2.cpp, note this is an "empty project" without the PPP scaffolding
  The example shows the early steps towards a proper implementation of vector,
  it builds on myVector_1.cpp. Some codelines are commented only or in more detail 
  in the myVector_1.cpp since we expect the reader to study example by example.
  - the definition of the constructor of myVector is here moved inline 
  - example is used in lecture to demonstrate memory leak, and motivate 
    the concept destructor
*/
#include<iostream>
#include<math.h> //
using namespace std;
class myVector { 
	int sz;	// the number of elements (“the size”)
	double* elem; // pointer to the first element
public:
	myVector(int s) : sz{ s }, 
		elem{ new double[s] }{} // allocate s doubles
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	double get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, double v) { elem[n] = v; }
};

void useVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		v.set(i, static_cast<double>(sqrt(i)));
}
void printVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v.get(i) << " "; 
}
void memoryLeak(int x) {
	myVector v(x);
	useVector(v);
	//... cleanup missing, or not?

}
int main()
try {
	myVector doubleVec(10);
	useVector(doubleVec);
	printVector(doubleVec);
	
	for (int i = 0; i < 1000; i++)
		memoryLeak(1000000);

	cout << "\nType any char + return to quit:";
	char c; cin >> c;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}