#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

double arrayOfTemperatureData[100][2];
char arrayOfTemperatureUnits[100][2];
int dataCounter = 0;

bool checkSpelling(int option, string tmpString) {
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
	char inputChar, outputChar;
	double resultTemp = 0;
	if (option == 1 || option == 2) {
		inputChar = 'F';
	}
	else if (option == 3 || option == 4) {
		inputChar = 'C';
	}
	else if (option == 5 || option == 6) {
		inputChar = 'K';
	}
	else {
		inputChar = ' ';
	}

	if (!checkTheTemperature(inputChar, temperatura) && option != 7) {
		cout << "Pro Tip: Temperatury maja dolne granice.\nNiestety istnieje cos takiego jak zero absolutne" << endl;
	}
	else {
		switch (option) {
		case 1: {
			outputChar = 'C';
			resultTemp = FahrenheitToCelsius(temperatura);
			cout << "Wybrales opcje 1: Fahrenheity na Celsjusze" << endl;
			cout << "Temperatura w Fahrenheitach: " << temperatura << " F" << endl;
			cout << "Temperatura w Celsjuszach: " << FahrenheitToCelsius(temperatura) << " C" << endl;
			break;
		}case 2: {
			outputChar = 'K';
			resultTemp = FahrenheitToKelvin(temperatura);
			cout << "Wybrales opcje 2: Fahrenheity na Kelviny" << endl;
			cout << "Temperatura w Fahrenheitach: " << temperatura << " F" << endl;
			cout << "Temperatura w Kelvinach: " << FahrenheitToKelvin(temperatura) << " K" << endl;
			break;
		}case 3: {
			outputChar = 'F';
			resultTemp = CelsiusToFahrenheit(temperatura);
			cout << "Wybrales opcje 3: Celsjusze na Fahrenheity" << endl;
			cout << "Temperatura w Celsjuszach: " << temperatura << " C" << endl;
			cout << "Temperatura w Fahrenheitach: " << CelsiusToFahrenheit(temperatura) << " F" << endl;
			break;
		}case 4: {
			outputChar = 'K';
			resultTemp = CelsiusToKelvin(temperatura);
			cout << "Wybrales opcje 4: Celsjusze na Kelviny" << endl;
			cout << "Temperatura w Celsjuszach: " << temperatura << " C" << endl;
			cout << "Temperatura w Kelvinach: " << CelsiusToKelvin(temperatura) << " K" << endl;
			break;
		}case 5: {
			outputChar = 'C';
			resultTemp = KelvinToCelsius(temperatura);
			cout << "Wybrales opcje 5: Kelviny na Celsjusze" << endl;
			cout << "Temperatura w Kelvinach: " << temperatura << " K" << endl;
			cout << "Temperatura w Celsjuszach: " << KelvinToCelsius(temperatura) << " C" << endl;
			break;
		}case 6: {
			outputChar = 'F';
			resultTemp = KelvinToFahrenheit(temperatura);
			cout << "Wybrales opcje 6: Kelviny na Fahrenheity" << endl;
			cout << "Temperatura w Kelvinach: " << temperatura << " K" << endl;
			cout << "Temperatura w Fahrenheitach: " << KelvinToFahrenheit(temperatura) << " F" << endl;
			break;
		}case 7: {
			continueOption = false;
			cout << "Historia konwersji temperatur:" << endl;
			for (int i = 0; i < dataCounter; i++) {
				cout << "Obliczenie nr " << i + 1 << ": " << arrayOfTemperatureData[i][0] << arrayOfTemperatureUnits[i][0] << " -> " << arrayOfTemperatureData[i][1] << arrayOfTemperatureUnits[i][1] << endl;
			}
			break;
		}default: {
			continueOption = false;
			system("cls");
			break;
		}
		}
		if (continueOption) {
			arrayOfTemperatureData[dataCounter][0] = temperatura;
			arrayOfTemperatureData[dataCounter][1] = resultTemp;
			arrayOfTemperatureUnits[dataCounter][0] = inputChar;
			arrayOfTemperatureUnits[dataCounter][1] = outputChar;
			dataCounter++;
		}
		string tmp;
		cout << "Nacisnij dowolny klawisz, aby kontynuowac..." << endl;
		cin.ignore();
		getline(cin, tmp);
		system("cls");
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
		cout << "|         7. Pokaz historie konwersji         |" << endl;
		cout << "|         8. Zakoncz dzialanie programu       |" << endl;
		cout << "+---------------------------------------------+" << endl;
		cout << "Wybierz opcje (1-8): "; cin >> choice;
		if (checkSpelling(1, choice)) {
			option = stoi(choice);
			if (option > 7 || option < 1) {
				cout << "Program sie zakonczyl\nDo widzenia!" << endl;
				break;
			}
			else if (option == 7) {
				printSubMenu(option, 0);
			}
			else {
				temperature = getInputTemperature();
				printSubMenu(option, temperature);
			}
		}
		else {
			cout << "Sproboj jeszcze raz okej" << endl;
		}
	}
}
