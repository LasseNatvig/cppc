// Lstring_2.cpp   
#include "std_lib_facilities.h"
int main() {
	//*****************************************************
	// A) Correct use of string
	string str1 = "ABCDEF";  //
	for (unsigned int i = 3; i < str1.size(); ++i) {
		str1[i] = '*';
	}
	cout << "str1: " << str1 << endl;
	// Note, for some strange reason ????????????????????????????????????????????????????????????????????????????????
	// if the test is <= and not < above, the code seems to work well, even though the last '*'
	// is written after the end of the string!
	// TODO - TEORI ???  kan det være at string objekt lagrer lengde i en variabel OG bruker 
	// et tegn ekstra for null-terminering slik at det blir mer robust, og ikke oppdages her,
	// vi har usynlig fått en string med en liten feil, bør kunne oppdages på en lur måte!
	// dette er vel egentlig en svakhet

	//*****************************************************
	// B) This will give run time error
	//string str2 = "ABCDEF"; // as above, but *2 is a bug
	//for (unsigned int i = 3; i <= str2.size() * 2; ++i) {
	//	str2[i] = '*';
	//}
	//cout << "str2: " << str2 << endl;

	//*****************************************************
	// C) Old C-style string, C-string (PPP 27.5), 
	// strlen(s) gives the length of a C-string, correct use
	char str3[] = "ABCDEF";
	for (unsigned int i = 3; i < strlen(str3); ++i) {
		str3[i] = '*';
	}
	cout << "str3: " << str3 << endl;

	//*****************************************************
	// D) Old C-style string, C-string (PPP 27.5), 
	// the <= test below is a bug, writing past the end of the string
	//char str4[] = "ABCDEF";
	//for (unsigned int i = 3; i <= strlen(str4); ++i) {
	//	str4[i] = '*';
	//}
	//cout << "str4: " << str4 << endl;
	// If run (Ctrl-F5): str4 is not printed and keep_window_open does not work, something goes wrong.
	// If run in debugger (F5): Stops and gives error at right point

	//*****************************************************
	// E) Just as case B above but with C-string 
	string str5 = "ABCDEF"; // as above, but *2 is a bug
	for (unsigned int i = 3; i <= str5.size() * 2; ++i) {
		str5[i] = '*';
	}
	cout << "str5: " << str5 << endl;
	// Behaves the same way as case D), long silence, then terminates

	keep_window_open();
	cout << "goodbye";
}