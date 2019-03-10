#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Student {
	string name;
	double grades; 
};

bool betterThan(Student* a, Student* b) {
	return ((a->grades) < (b->grades));
}

void printStudents(vector<Student*> studenter) {
	for (auto stud : studenter) { // note; must use -> operator since we have a vector of pointers, not objects
		cout << stud->name << " har kar.snitt: " << stud->grades << endl;
	}
}

void eraseStudent(Student* sPtr, vector<Student*>& studenter) {
	auto it = studenter.begin(); // it er en iterator, kap. 19
								 // vector.begin() og vector.end() er iteratorer, peker på element i vector-en
								 // *it er elementet i vectoren som iteratoren it peker på
	while (it != studenter.end() && *it != sPtr)
		++it;
	// NOTE: Denne er ikke robust, antar at sPtr er blant studenter, se test nedenfor med s0
	studenter.erase(it);
}

void insertStudent(Student* sPtr, vector<Student*>& studenter) {
	// setter inn på riktig plass så vi slipper å sortere
	auto it = studenter.begin(); // it er en iterator, kap. 19
	while (it != studenter.end() && betterThan(*it, sPtr))
		++it;
	studenter.insert(it, sPtr);
}

int main() {
	setlocale(LC_ALL, "norwegian");
	vector<Student*> applicants;

	Student s1 = { "Per", 3.4 };
	Student s2 = { "Kari", 2.9 };
	Student s3 = { "Ole", 3.2 };
	Student s4 = { "Olga", 3.7 };

	applicants.push_back(&s1);
	applicants.push_back(&s2);
	applicants.push_back(&s3);
	applicants.push_back(&s4);

	cout << endl << "Søkere:\n";
	printStudents(applicants);
	sort(applicants.begin(), applicants.end());
	// denne sorterer bare på verdien til pekeren (dvs. adressen) og det er normalt 
	// noe vi IKKE ønsker å gjøre	
	cout << endl << "Søkere etter første kall på sort:\n";
	printStudents(applicants);

	sort(applicants.begin(), applicants.end(), betterThan);
	cout << endl << "Søkere etter kall på sort med bruk av funksjon bedreEnn:\n";
	// det er et alternativ til å overlagre operator< som vi har lært før
	printStudents(applicants);

	// en student trekker søknaden sin, slette den
	eraseStudent(&s1, applicants);
	cout << endl << "Søkere etter at student s1 (Per) er fjernet\n";
	printStudents(applicants);

	// UNCOMMENT denne blokken for demo av at fjernStudent IKKE er robust
	//// test fjernStudent for en peker som ikke er i vectoren
	//Student s0 = { "Nullen Beskjeden", 5.00 };
	//fjernStudent(&s0, sokere);

	Student s5 = { "JamesBond", 3.68 };
	insertStudent(&s5, applicants);
	cout << endl << "Søkere etter at student s5  er tilført\n";
	printStudents(applicants);
}