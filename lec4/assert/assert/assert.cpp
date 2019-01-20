#include<iostream>
#include<ctime>
// #define NDEBUG
#include<cassert>
using namespace std;

int getGuess(int min, int max);
//Ber bruker om tall mellom min og max

void printGuess(int guess, int secret, int count);
//Skriver ut informasjon

int main() {
	setlocale(LC_ALL, "Norwegian");  // Makes printing æ, ø, å, Æ, Ø and Å possible
	srand(static_cast<unsigned int>(time(NULL)));
	int secret = (rand() % 10) + 1;
	int guess = 0;
	int count = 0;
	while (guess != secret) {
		guess = getGuess(1, 10);
		count++;
		printGuess(guess, secret, count);
	}
}

void printGuess(int guess, int secret, int count) {
	if (guess > secret) {
		cout << "Tallet er for stort" << endl;
	}
	else if (guess < secret) {
		cout << "Tallet er for lite" << endl;
	}
	else {
		cout << "Du har gjettet riktig (på " << count << " forsøk)" << endl;
	}
}

int getGuess(int min, int max) {
	//Ber bruker om tall mellom min og max
	int temp = 0;
	do {
		cout << "Gjett et tall mellom ";
		cout << min << " og " << max << ": ";
		cin >> temp;
		assert(temp != 0);
	} while (temp < min || temp > max);
	return temp;
}