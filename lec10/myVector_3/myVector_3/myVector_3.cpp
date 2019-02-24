/* myVector_3.cpp, note this is an "empty project" without the PPP scaffolding
  The example shows the third step towards a proper implementation of vector,
  it builds on myVector_1 and ...2.cpp.
  - new in this version of myVector is copy constructor, copy assignment operator=,
	and indexing operator [ ]
 */
#include<iostream>
#include<math.h> //
using namespace std;
class myVector {
	int sz;	// the number of elements (“the size”)
	double* elem; // pointer to the first element
public:
	myVector(int s) : sz{ s },
		elem{ new double[s] }{ // allocate s doubles
		for (int i = 0; i < sz; i++) elem[i] = 0.0; // initialize
	}
	myVector(const myVector&);	// copy constructor: defined below
	myVector& operator=(const myVector& arg); // copy assignment: defined below 
	~myVector() { delete[] elem; } // destructor
	int size() const { return sz; }	// the current size
	double get(int n) const { return elem[n]; } // PPP 17.6
	void set(int n, double v) { elem[n] = v; }
};

myVector::myVector(const myVector& arg)
	:sz{ arg.sz },
	elem{ new double[arg.sz] }
{ // allocate space for elements, 
  // then initialize them (by copying)
	for (int i = 0; i < sz; ++i) {
		elem[i] = arg.elem[i];
	}
}

myVector& myVector::operator=(const myVector& arg)
// like copy constructor, but we must deal with old elements
// make a copy of arg then replace the current sz and elem with a’s
{
	double* p = new double[arg.sz];	// allocate new space
	for (int i = 0; i < arg.sz; ++i) p[i] = arg.elem[i]; // copy elements
	delete[] elem;	// deallocate old space
	sz = arg.sz; // set new size
	elem = p; // set new elements
	return *this; //  return a self-reference
}

void useVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		v.set(i, static_cast<double>(sqrt(i)));
}

void printVector(myVector& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v.get(i) << " ";
}

int main()
try {
	myVector doubleVec(10);
	useVector(doubleVec);
	printVector(doubleVec);

	// Test copy constructor
	{
		myVector v(3);
		v.set(2, 2.2);
		myVector v2 = v;  // v2 is constructed as a copy of v
		printVector(v2);
		cout << endl;
	}

	// Test copy assignment
	{
		myVector v(3);
		v.set(2, 2.2);
		myVector v2(4);
		v2 = v;  // v2 already exist, so copy constructor is not used, but assignment operator= is used
		printVector(v2);
		cout << endl;
	}

	cout << "\nType any char + return to quit:";
	char c; cin >> c;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}