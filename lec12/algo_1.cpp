#include<iostream>
#include<vector>
#include<set>
#include <algorithm> // Required by find_if() (But not by find() !?)
using namespace std;

void search(vector<int>& v, int x) {
	vector<int>::iterator it = find(v.begin(), v.end(), x);
	if (it != v.end()) {
		cout << "we found " << *it << endl;
	}
}

// generic search and print
template <typename T, typename E>
void genSearchPrint(const T& container, const E& elt) {
	auto it = find(container.begin(), container.end(), elt);
	if (it != container.end()) {
		cout << "we found " << *it << endl;
	}
}

bool odd(int i) { return i % 2; }

int main() {
	vector<int> v{ 11, 22, 33, 77, 44 };
	search(v, 22);
	search(v, 23);
	search(v, 44);

	genSearchPrint(v, 77);
	set<double> ds{ 11.11, 22.22, 44.44, 33.33 };
	genSearchPrint(ds, 22.23);
	genSearchPrint(ds, 22.22);

	vector<int> v2{ 10, 22, 33, 77, 44 };
	auto it = find_if(v2.begin(), v2.end(), odd);
	if (it != v2.end()) {
		cout << "find_if found " << *it << endl;
	}

	return 0;
}