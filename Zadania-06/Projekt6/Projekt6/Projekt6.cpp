#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool checkTheSpelling(int type, string valueToCheck) {
	switch (type){
	case 1:
		for(char c : valueToCheck){
			if(!isdigit(c) && c != '-') {
				return false;
			}
		}
		return true;
	case 2:
		for (char c : valueToCheck) {
			if (!isdigit(c) && c != '-' && c != '.') {
				return false;
			}
		}
		return true;
	default:
		return false;
	}
}

int a = 20;
int b = 10;

int sumOf(int pA, int pB) {
	return pA + pB;
}

int tab[10];
int rozmiar = 10;

void showTab() {
	cout << "Zawartosc tablicy:\n";
	for (int i = 0; i < rozmiar; i++) {
		cout << tab[i] << " ";
	}
	cout << "\n";
}

void insertIntoTab() {
	string input;
	cout << "Wpisywanie do tablicy:\n";
    for (int i = 0; i < rozmiar; i++) {
        while (1) {
			cout << "Podaj liczbe calkowita nr " << i + 1 << ": ";
            cin >> input;
			if (checkTheSpelling(2, input)) {
				tab[i] = stoi(input);
				break;
			}
			cout << "Blad! Sprobuj ponownie.\n";
        }
    }
}

void moveTheTab(int index) {
	for (int i = index; i < rozmiar; i++) {
		tab[i] = tab[i + 1];
	}
	rozmiar-=1;
}

void usun() {
	string input;
	cout << "Usuwanie z tablicy:\n";
	while (1) {
		cout << "Podaj indeks do usuniecia (0-" << rozmiar - 1 << "): ";
		cin >> input;
		if (checkTheSpelling(1, input)) {
			int index = stoi(input);
			if (index >= 0 && index < rozmiar) {
				moveTheTab(index);
				showTab();
				break;
			}
			else {
				cout << "Indeks poza zakresem!\n";
			}
		}
		cout << "Blad! Sprobuj ponownie.\n";
	}
}

float TEMP1[10];
float TEMP2[10];
int INDEKS = 0;

float przelicz(float tempToChange) {
	return tempToChange + 273.15;
}

void zapisz(float tempFromUser, float tempConverted) {
	if (INDEKS < 10 && INDEKS >= 0) {
		TEMP1[INDEKS] = tempFromUser;
		TEMP2[INDEKS] = tempConverted;
	}
	else {
		cout << "Tablica pelna, KONIEC MIEJSCA!\nPrzeliczenie nie zostalo wykonane!\n";
	}
}

void wyswietl() {
	for (int i = 0; i < INDEKS; i++) {
		cout << "Indeks TEMP "<< i <<", Temperatura " << TEMP1[i] << " C to " << TEMP2[i] << " K\n";
	}
}

int main(){
    cout << "Oto suma globalna: " << sumOf(a, b) << "!\n";

    int a = 2;
	int b = 1;

    cout << "Oto suma lokalna: " << sumOf(a,b) << "!\n";

	insertIntoTab();
	showTab();
	usun();

	cout << "Przeliczanie temperatur C na K:\n";
	while (1) {
		string input;
		cout << "Podaj temperature w C do przeliczenia (lub wpisz 'exit' aby zakonczyc): ";
		cin >> input;
		if (input == "exit") {
			break;
		}
		if (checkTheSpelling(2, input)) {
			float tempC = stof(input);
			float tempK = przelicz(tempC);
			zapisz(tempC, tempK);
			INDEKS++;
		}
		else {
			cout << "Blad! Sprobuj ponownie.\n";
		}
		wyswietl();
	}
	return 0;
}
