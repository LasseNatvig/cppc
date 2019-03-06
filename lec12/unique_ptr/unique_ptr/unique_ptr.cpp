#include <iostream>
#include <string>
#include <vector>
#include <memory> // needed for unique_ptr
using namespace std;

vector<int>*make_vecOld() {
	vector<int>* p{ new vector<int> };
	p->push_back(3); 
	p->push_back(-2);
	// ... other code, an exception here will give memory leak
	return p;
}

vector<int>*make_vecModern() { /// PPP page 703 - top
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(3);
	p->push_back(-2);
	// ... other code, p will be properly destroyed by destructor if an exception is thrown 
	return p.release();  // returns the pointer
}

unique_ptr<vector<int>> make_vecBetter() { /// PPP page 703 - bottom
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(3);
	p->push_back(-2);
	return p;  // returns unique_ptr
}

int main() {
	vector<int>* ivPtr;
	vector<int>* ivPtr2;
	ivPtr = make_vecOld();
	ivPtr2 = ivPtr;
	delete ivPtr;	
	//delete ivPtr2;  // error, crash, multiple deleted on same pointer

	ivPtr = make_vecModern();
	ivPtr2 = ivPtr;
	delete ivPtr;
	// delete ivPtr2; // will still crash

	unique_ptr<vector<int>> uniPtr = make_vecBetter();
	unique_ptr<vector<int>> uniPtr2;

	//	uniPtr2 = uniPtr;  // error, not allowed, an unique_ptr must be kept UNIQUE!
	uniPtr2 = move(uniPtr); // transfer ownership of unique ptr 
	// value of uniPtr is now unspecified
	auto uPtr = move(uniPtr2);  // 
	// value of uniPtr2 is now unspecified

	// It is always one and only one pointer to the memory, and the
	// unique_ptr will always call delete when it leaves scope

	////... demo forskjell vanlig peker og unique_ptr
	//// create unique ptr using unique_ptr's constructor 
	//unique_ptr<Student> s2{ new Student("lana") };
	////create unique_ptr using make_unique
	//unique_ptr<Student> s1 = make_unique<Student>("daso");
	//
	//// transfer ownership of unique ptr 
	//auto s3 = move(s1);
	//// value of s1 is now unspecified 
}