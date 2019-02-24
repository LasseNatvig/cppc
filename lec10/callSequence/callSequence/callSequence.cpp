// callSequence.cpp
#include <iostream>
#include<string>
using namespace std;

class Person {
private:
	string name;
public:
	Person(string name) : name{ name } {
		cout << "Person - constructor" << endl;
	}
	Person(const Person& other) {
		name = other.name;
		cout << "Person - copy constructor" << endl;
	}
	~Person() {
		cout << "Person - destructor" << endl;
	}
	Person& operator=(const Person& rhs) {
		this->name = rhs.name;
		cout << "Person - assignment-operator" << endl;
		return *this;
	}
	//Person& operator=(Person rhs) { // with copy-and-swap
	//	swap(name, rhs.name);
	//	cout << "Person - assignment-operator" << endl;
	//	return *this;
	//}
	string get_name() { return name; }
};

class Student : public Person {
private:
	int id;
public:
	Student(string name, int id) : Person{ name }, id{ id } {
		cout << "Student - constructor" << endl;
	}

	Student(const Student& other) : Person{ other } {
		id = other.id;
		cout << "Student - copy constructor" << endl;
	}

	~Student() {
		cout << "Student - destructor" << endl;
	}

	Student& operator=(const Student& rhs) {
		Person::operator=(rhs);  // Note
		this->id = rhs.id;
		cout << "Student - assignment-operator" << endl;
		return *this;
	}
	//Student& operator=(Student rhs) { // with copy-and-swap
	//	Person::operator=(rhs);
	//	swap(id, rhs.id);
	//	cout << "Student - assignment-operator" << endl;
	//	return *this; 
	//}
	string toString() {
		return ("student " + get_name() + " " + to_string(id) + "\n");
	}
};

int main() {
	setlocale(LC_ALL, "Norwegian");
	cout << endl << "Constructs Person objects a og c" << endl;
	Student a{ "a", 100 };
	Student c{ "c", 300 };
	cout << "a: " + a.toString() + "c: " + c.toString();

	cout << endl << "Constructs Person object b with copy constructor" << endl;
	Student b{a};
	cout << "b: " + b.toString();

	cout << endl << "Constructs d, and then assigns d = c" << endl;
	Student d{ "d", 400 };
	d = c;
	cout << "d: " + d.toString();

	cout << endl << "Leaves scope" << endl;
	return 0;
}
