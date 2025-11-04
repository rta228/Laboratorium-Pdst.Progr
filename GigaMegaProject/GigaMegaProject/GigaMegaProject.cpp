#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

bool checkSpelling(int option, string tmpString){
	switch (option) {
		case 1: {
			for (char c : tmpString) {
				if (!isdigit(c)) {
					return false;
				}
			}
			return true;
			break;
		}
		case 2: {
			for (char c : tmpString) {
				if (!isdigit(c) && c != '.') {
					return false;
				}
			}
			break;
		}
		default: {
			return false;
		}
	}
}

bool checkTheTemperature(char pickedTemp, double tmpTemp) {
	switch (pickedTemp) {
		case 'F': {
			if (tmpTemp < -459.67) {
				return false;
			}
			return true;
			break;
		}
		case 'C': {
			if (tmpTemp < -273.15) {
				return false;
			}
			return true;
			break;
		}
		case 'K': {
			if (tmpTemp < 0) {
				return false;
			}
			return true;
			break;
		}
		default: {
			return false;
			break;
		}
	}
}

double getInputTemperature() {
	string tempInput;
	while (1) {
		cout << "Podaj temperature do konwersji: "; cin >> tempInput;
		if (checkSpelling(2, tempInput)) {
			return stod(tempInput);
		}
		else {
			cout << "Niepoprawna wartosc temperatury! Sproboj ponownie." << endl;
		}
	}
}

double FahrenheitToCelsius(double fahrenheit) {
	return (fahrenheit - 32) * 5.0 / 9.0;
}

double FahrenheitToKelvin(double fahrenheit) {
	return (fahrenheit + 459.67) * 5.0 / 9.0;
}

double CelsiusToFahrenheit(double celsius) {
	return (celsius * 9.0 / 5.0) + 32;
}

double CelsiusToKelvin(double celsius) {
	return celsius + 273.15;
}

double KelvinToCelsius(double kelvin) {
	return kelvin - 273.15;
}

double KelvinToFahrenheit(double kelvin) {
	return (kelvin * 9.0 / 5.0) - 459.67;
}


void printSubMenu(int option, double temperatura) {
	bool continueOption = true;
	char optionChar;
	if (option == 1 || option == 2) {
		optionChar = 'F';
	}
	else if (option == 3 || option == 4) {
		optionChar = 'C';
	}
	else if (option == 5 || option == 6) {
		optionChar = 'K';
	}

	if (!checkTheTemperature(optionChar, temperatura)) {
		cout << "Pro Tip: Temperatury maja dolne granice.\nNiestety istnieje cos takiego jak zero absolutne" << endl;
	}
	else {
		switch (option) {
		case 1: {
			cout << "Wybrales opcje 1: Fahrenheity na Celsjusze" << endl;
			cout << "Temperatura w Fahrenheitach: " << temperatura << " F" << endl;
			cout << "Temperatura w Celsjuszach: " << FahrenheitToCelsius(temperatura) << " C" << endl;
			break;
		}case 2: {
			cout << "Wybrales opcje 2: Fahrenheity na Kelviny" << endl;
			cout << "Temperatura w Fahrenheitach: " << temperatura << " F" << endl;
			cout << "Temperatura w Kelvinach: " << FahrenheitToKelvin(temperatura) << " K" << endl;
			break;
		}case 3: {
			cout << "Wybrales opcje 3: Celsjusze na Fahrenheity" << endl;
			cout << "Temperatura w Celsjuszach: " << temperatura << " C" << endl;
			cout << "Temperatura w Fahrenheitach: " << CelsiusToFahrenheit(temperatura) << " F" << endl;
			break;
		}case 4: {
			cout << "Wybrales opcje 4: Celsjusze na Kelviny" << endl;
			cout << "Temperatura w Celsjuszach: " << temperatura << " C" << endl;
			cout << "Temperatura w Kelvinach: " << CelsiusToKelvin(temperatura) << " K" << endl;
			break;
		}case 5: {
			cout << "Wybrales opcje 5: Kelviny na Celsjusze" << endl;
			cout << "Temperatura w Kelvinach: " << temperatura << " K" << endl;
			cout << "Temperatura w Celsjuszach: " << KelvinToCelsius(temperatura) << " C" << endl;
			break;
		}case 6: {
			cout << "Wybrales opcje 6: Kelviny na Fahrenheity" << endl;
			cout << "Temperatura w Kelvinach: " << temperatura << " K" << endl;
			cout << "Temperatura w Fahrenheitach: " << KelvinToFahrenheit(temperatura) << " F" << endl;
			break;
		}default: {
			continueOption = false;
			system("cls");
			break;
		}
		}
		if (continueOption) {
			string tmp;
			cout << "Nacisnij dowolny klawisz, aby kontynuowac..." << endl;
			cin.ignore();
			getline(cin, tmp);
			system("cls");
		}
	}
}

void printMenu() {
	string choice;
	int option;
	double temperature;
	while (1) {
		system("cls");
		cout << "+---------------------------------------------+" << endl;
		cout << "|        Program do zamiany Temperatur        |" << endl;
		cout << "|         1. Fahrenheity na Celsjusze         |" << endl;
		cout << "|         2. Fahrenheity na Kelviny           |" << endl;
		cout << "|         3. Celsjusze na Fahrenheity         |" << endl;
		cout << "|         4. Celsjusze na Kelviny             |" << endl;
		cout << "|         5. Kelviny na Celsjusze             |" << endl;
		cout << "|         6. Kelviny na Fahrenheity           |" << endl;
		cout << "|         7. Zakoncz dzialanie programu       |" << endl;
		cout << "+---------------------------------------------+" << endl;
		cout << "Wybierz opcje (1-7): "; cin >> choice;	
		if (checkSpelling(1, choice)) {
			option = stoi(choice);
			if (option > 6 || option < 1) {
				cout << "Program sie zakonczyl\nDo widzenia!" << endl;
				break;
			}
			temperature = getInputTemperature();
			printSubMenu(option, temperature);
		}
		else {
			cout << "Sproboj jeszcze raz okej" << endl;
		}
	}
}

int main(){
	printMenu();
	return 0;
}
