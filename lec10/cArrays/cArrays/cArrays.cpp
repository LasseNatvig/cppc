// cArrays.cpp
// - demonstrates 1D and 2D C-arrays
#include <iostream>
using namespace std;

constexpr int sizeA = 5;
constexpr int sizeB = 10;

int globalA[sizeA]; // global array. MAYBE initialized to zeros, but do not trust it

void normalAccessGlobalArray() { /* Demonstrates access to a global array. It is known everywhere in your
	program so you do not need to pass it as parameter. HOWEVER, always try to avoid global variables! */

	// traditional:
	for (int i = 0; i < sizeA; i++) {
		cout << globalA[i] << " ";
	}
	cout << endl; // range for:
	for (int i : globalA) {
		cout << i << " ";
	}
	cout << endl; // with auto:
	for (auto element : globalA) {
		cout << element << " ";
	}
	cout << endl;
}

void localArray(int n) {
	int localInts[5]; // local array, is NOT initialized
	for (int i : localInts) {
		cout << i << " ";
	}
	cout << endl;
	char localChars[4]; // local array, is NOT initialized
	for (auto c : localChars) {
		cout << c << " ";
	}
	// double localDoubles[n]; // error, array size not a constant
}

void outOfRangeAccess() {
	cout << "Dangerous out of range read: " << globalA[-10] << " "
		<< globalA[2000] << endl;
	cout << "Even worse: ";
	globalA[-10] = 8888; globalA[2000] = 9999;
	cout << "Dangerous out of range read: " << globalA[-10] << " "
		<< globalA[2000] << endl;
}

void testArrays() {
	normalAccessGlobalArray();
	localArray(5);
	// ...
	//outOfRangeAccess();
}




int main() try {
	testArrays();
	cout << "\nType any char + return to quit:";
	char c; cin >> c;
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "error: unknown exception";
	return -2;
}