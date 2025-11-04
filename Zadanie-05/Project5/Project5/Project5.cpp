#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool checkTheSpelling(int option, string stringToCheck) {
	switch (option){
		case 1: {
			for ( char c : stringToCheck ) {
				if (!isdigit(c) && c != '-') {
					return false;
				}
			}
			return true;
			break;
		}
		case 2: {
			for (char c : stringToCheck) {
				if (!isdigit(c) && c != '.' && c != '-') {
					return false;
				}
			}
			return true;
			break;
		}
		case 3: {
			for (char c : stringToCheck) {
				if (!isalpha(c)) {
					return false;
				}
			}
			return true;
			break;
		}
		default: {
			return false;
		}
	}
}

void excercieseOne() {
	int arrayOfInts[10];
	int i = 0;
	string input;
	cout << "Podaj 10 liczb calkowitych: " << endl;
	while (i < 10) {
		cout << "Liczba " << i + 1 << ": "; cin >> input;
		if (!checkTheSpelling(1, input)) {
			cout << "Cos chyba ominales podstawowke. Sprobuj jeszcze raz." << endl;
		}
		else {
			arrayOfInts[i] = stoi(input);
			i++;
		}
	}
	
	cout << "Podales nastepujace liczby: " << endl;
	for (int j = 9; j >= 0; j--) {
		cout << arrayOfInts[j] << " ";
	}
}

int main(){
	excercieseOne();
    return 0;
}
