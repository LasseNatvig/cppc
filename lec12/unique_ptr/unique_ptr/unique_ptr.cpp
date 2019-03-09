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

vector<int> make_vecMove() { /// PPP 19.5.5 
	vector<int> res;
	res.push_back(3);
	res.push_back(-2);
	return res;  // return by move constructor
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

	auto v = make_vecMove();
	for (auto e : v) cout << e << " ";
}