// map.cpp, from PPP 21.6.1
#include "std_lib_facilities.h"
int main(){
	map<string, int> words;	// keep (word,frequency) pairs
	for (string s; cin >> s; )
		++words[s];	// note: words is subscripted by a string
					// words[s] returns an int&
					// the int values are initialized to 0
//	for (const auto& p : words)
	for (const pair<string,int> & p : words)  // without auto
		cout << p.first << ": " << p.second << "\n";
	return 0;
}