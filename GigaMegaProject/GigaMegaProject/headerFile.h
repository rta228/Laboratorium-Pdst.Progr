#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

double arrayOfTemperatureData[100][2];
char arrayOfTemperatureUnits[100][2];
int dataCounter = 0;

void clearTheScreenAfterInteraction() {
	string tmp;
	cout << "Nacisnij dowolny klawisz, aby kontynuowac..." << endl;
	cin.ignore();
	getline(cin, tmp);
	system("cls");
}

bool checkSpelling(int option, string tmpString) {
	switch (option) {
	case 1: {
		for (char c : tmpString) {
			if (!isdigit(c) && c != '-') {
				return false;
			}
		}
		return true;
		break;
	}
	case 2: {
		for (char c : tmpString) {
			if (!isdigit(c) && c != '-' && c != '.') {
				return false;
			}
		}
		break;
	}case 3: {
		for (char c : tmpString) {
			if (!isdigit(c)) {
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

char getInputTemperatureUnit() {
	string tempUnit;
	while (1) {
		cout << "Podaj jednostke temperatury (C, F, K): "; cin >> tempUnit;
		if (tempUnit == "C" || tempUnit == "F" || tempUnit == "K") {
			return tempUnit[0];
		}
		else {
			cout << "Niepoprawna jednostka temperatury! Sproboj ponownie." << endl;
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

int whichHistoryToUse() {
	string input;
	int option;
	while (1) {
		cout << "Podaj cyfre aby otworzyc historie\n";
		cout << "Jesli chcesz wyswitlic dana konwersje z Jednostki podanej wpisz przypisna do niej cyfre\n";
		cout << "1 - C\n";
		cout << "2 - F\n";
		cout << "3 - K\n";
		cout << "4 - wszystko\n";
		cout << "Wybor: ";
		cin >> input;
		if (checkSpelling(1, input)) {
			option = stoi(input);
			break;
		}
		cout << "Podaj poprawna cyfre!" << endl;
	}
	return option;
}

void printHistory(bool isDeletingInvolved) {
	int option;
	if (isDeletingInvolved) {
		option = 4;
	}
	else {
		option = whichHistoryToUse();
	}
	switch (option){
	case 1:
		cout << "Historia konwersji temperatur (Tylko z C):" << endl;
		for (int i = 0; i < dataCounter; i++) {
			if (arrayOfTemperatureUnits[i][0] == 'C') {
				cout << "Obliczenie nr " << i + 1 << ": " << arrayOfTemperatureData[i][0] << arrayOfTemperatureUnits[i][0] << " -> " << arrayOfTemperatureData[i][1] << arrayOfTemperatureUnits[i][1] << endl;
			}
		}
		break;
	case 2:
		cout << "Historia konwersji temperatur (Tylko z F):" << endl;
		for (int i = 0; i < dataCounter; i++) {
			if (arrayOfTemperatureUnits[i][0] == 'F') {
				cout << "Obliczenie nr " << i + 1 << ": " << arrayOfTemperatureData[i][0] << arrayOfTemperatureUnits[i][0] << " -> " << arrayOfTemperatureData[i][1] << arrayOfTemperatureUnits[i][1] << endl;
			}
		}
		break;
	case 3:
		cout << "Historia konwersji temperatur (Tylko z K):" << endl;
		for (int i = 0; i < dataCounter; i++) {
			if (arrayOfTemperatureUnits[i][0] == 'K') {
				cout << "Obliczenie nr " << i + 1 << ": " << arrayOfTemperatureData[i][0] << arrayOfTemperatureUnits[i][0] << " -> " << arrayOfTemperatureData[i][1] << arrayOfTemperatureUnits[i][1] << endl;
			}
		}
		break;
	case 4:
		cout << "Historia konwersji temperatur:" << endl;
		for (int i = 0; i < dataCounter; i++) {
			cout << "Obliczenie nr " << i + 1 << ": " << arrayOfTemperatureData[i][0] << arrayOfTemperatureUnits[i][0] << " -> " << arrayOfTemperatureData[i][1] << arrayOfTemperatureUnits[i][1] << endl;
		}
		break;
	default:
		cout << "Niepoprawna opcja, wracam do menu glownego." << endl;
		break;
	}
}

void deleteHistory() {
	string indexToDelete;
	int index;
	printHistory(1);
	cout << "Usuwanie historii konwersji temperatur\n";
	while (1) {
		cout << "Podaj indeks do usuniecia (0 - " << dataCounter - 1 << endl;
		cout << "Wybor: ";
		cin >> indexToDelete;
		if (!checkSpelling(1, indexToDelete) && stoi(indexToDelete) >= 0 && stoi(indexToDelete) < dataCounter) {
			index = stoi(indexToDelete);
			break;
		}
		else {
			cout << "Niepoprawny format indeksu!" << endl;
		}
	}
	for (int i = index; i < dataCounter - 1; i++) {
		arrayOfTemperatureData[i][0] = arrayOfTemperatureData[i + 1][0];
		arrayOfTemperatureData[i][1] = arrayOfTemperatureData[i + 1][1];
		arrayOfTemperatureUnits[i][0] = arrayOfTemperatureUnits[i + 1][0];
		arrayOfTemperatureUnits[i][1] = arrayOfTemperatureUnits[i + 1][1];
	}
	dataCounter--;
	cout << "Usunieto wpis o indeksie " << index << endl;
}

void modifyHistory() {
	string indexToModify;
	int index;
	double newInputTemperature;
	char inputTemperatureUnit;
	char outputTemperatureUnit;
	printHistory(1);
	cout << "Modyfikajca historii konwersji temperatur\n";
	while (1) {
		cout << "Podaj indeks do modyfikacji (0 - " << dataCounter - 1 << endl;
		cout << "Wybor: ";
		cin >> indexToModify;
		if (!checkSpelling(1, indexToModify) && stoi(indexToModify) >= 0 && stoi(indexToModify) < dataCounter) {
			index = stoi(indexToModify);
			break;
		}
		else {
			cout << "Niepoprawny format indeksu!" << endl;
		}
	}

	while(1) {
		cout << "Aktualna wartosc rekordu: " << arrayOfTemperatureData[index][0] << " " << arrayOfTemperatureUnits[index][0] << endl;
		newInputTemperature = getInputTemperature();
		inputTemperatureUnit = getInputTemperatureUnit();

		if (checkTheTemperature(inputTemperatureUnit, newInputTemperature)) {
			break;
		}
		else {
			cout << "Podana temperatura jest ponizej zera absolutnego! Sproboj ponownie." << endl;
		}
	}

	while (1) {
		cout << "Podaj na jaka jednostke chcesz zmienic twoja temperature: " << newInputTemperature << " " << inputTemperatureUnit << endl;
		outputTemperatureUnit = getInputTemperatureUnit();
		if (inputTemperatureUnit != outputTemperatureUnit) {
			break;
		}
		else {
			cout << "Jednostka wejsciowa i wyjsciowa nie moga byc takie same! Sproboj ponownie." << endl;
		}
	}

	switch (inputTemperatureUnit) {
		case 'F': {
			if (outputTemperatureUnit == 'C') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = FahrenheitToCelsius(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			else if (outputTemperatureUnit == 'K') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = FahrenheitToKelvin(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			break;
		}
		case 'C': {
			if (outputTemperatureUnit == 'F') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = CelsiusToFahrenheit(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			else if (outputTemperatureUnit == 'K') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = CelsiusToKelvin(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			break;
		}
		case 'K': {
			if (outputTemperatureUnit == 'C') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = KelvinToCelsius(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			else if (outputTemperatureUnit == 'F') {
				arrayOfTemperatureData[index][0] = newInputTemperature;
				arrayOfTemperatureData[index][1] = KelvinToFahrenheit(newInputTemperature);
				arrayOfTemperatureUnits[index][0] = inputTemperatureUnit;
				arrayOfTemperatureUnits[index][1] = outputTemperatureUnit;
			}
			break;
		}
		default: {
			cout << "Niepoprawna jednostka temperatury!" << endl;
			break;
		}
	}
}

void randomHistoryInsertion() {
	string tmp;
	int countOfRndEntries, inputUnit, inputTemp, outputUnit;
	while (1){
		cout << "Ile rekordow wypelnic losowymi przeliczeniami?\nIlosc: "; cin >> tmp;
		if (checkSpelling(3,tmp) && (stoi(tmp)+dataCounter) < 100) {
			countOfRndEntries = stoi(tmp);
			break;
		}
		cout << "Niepoprawna wartosc, pamietaj ze musisz podac INT oraz ze maksymalna ilosc indexow histori to 100! Sproboj ponownie." << endl;
	}
	srand(time(0));
	for (int i = 0; i < countOfRndEntries; i++) {
		inputUnit = rand() % 3;
		do{
			outputUnit = rand() % 3;
		} while (inputUnit == outputUnit);
		switch (inputUnit) {
			case 0: {
				arrayOfTemperatureUnits[dataCounter][0] = 'C';
				inputTemp = rand() % 1000 - 273;
				arrayOfTemperatureData[dataCounter][0] = inputTemp;
				if (outputUnit == 1) {
					arrayOfTemperatureUnits[dataCounter][1] = 'F';
					arrayOfTemperatureData[dataCounter][1] = CelsiusToFahrenheit(inputTemp);
				}
				else {
					arrayOfTemperatureUnits[dataCounter][1] = 'K';
					arrayOfTemperatureData[dataCounter][1] = CelsiusToKelvin(inputTemp);
				}
				break;
			}
			case 1: {
				arrayOfTemperatureUnits[dataCounter][0] = 'F';
				inputTemp = rand() % 1000 - 459;
				arrayOfTemperatureData[dataCounter][0] = inputTemp;
				if (outputUnit == 0) {
					arrayOfTemperatureUnits[dataCounter][1] = 'C';
					arrayOfTemperatureData[dataCounter][1] = FahrenheitToCelsius(inputTemp);
				}
				else {
					arrayOfTemperatureUnits[dataCounter][1] = 'K';
					arrayOfTemperatureData[dataCounter][1] = FahrenheitToKelvin(inputTemp);
				}
				break;
			}
			case 2: {
				arrayOfTemperatureUnits[dataCounter][0] = 'K';
				inputTemp = rand() % 1000;
				arrayOfTemperatureData[dataCounter][0] = inputTemp;
				if (outputUnit == 0) {
					arrayOfTemperatureUnits[dataCounter][1] = 'C';
					arrayOfTemperatureData[dataCounter][1] = KelvinToCelsius(inputTemp);
				}
				else {
					arrayOfTemperatureUnits[dataCounter][1] = 'F';
					arrayOfTemperatureData[dataCounter][1] = KelvinToFahrenheit(inputTemp);
				}
				break;
			}
			default: {
				break;
			}
		}
		dataCounter++;
	}
	cout << "Pomyslnie dodano " << countOfRndEntries << " losowych rekordow do historii!" << endl;
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

	if (!checkTheTemperature(inputChar, temperatura) && option < 7 && option != 10) {
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
			printHistory(0);
			break;
		}case 8: {
			continueOption = false;
			deleteHistory();
			break;
		}case 9: {
			continueOption = false;
			modifyHistory();
			break;
		}case 10: {
			continueOption = false;
			randomHistoryInsertion();
			break;
		}default: {
			continueOption = false;
			system("cls");
			break;
		}
		}
		if (continueOption) {
			if (dataCounter<100) {
				arrayOfTemperatureData[dataCounter][0] = temperatura;
				arrayOfTemperatureData[dataCounter][1] = resultTemp;
				arrayOfTemperatureUnits[dataCounter][0] = inputChar;
				arrayOfTemperatureUnits[dataCounter][1] = outputChar;
				dataCounter++;
			}
			else {
				cout << "Historia konwersji jest pelna! Nie mozna zapisac wiecej danych." << endl;
			}
		}
		clearTheScreenAfterInteraction();
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
		cout << "|         8. Usun element historii            |" << endl;
		cout << "|         9. Modyfikuj element historii       |" << endl;
		cout << "|         10. Losowe konwersje do histori     |" << endl;
		cout << "|         11. Zakoncz dzialanie programu      |" << endl;
		cout << "+---------------------------------------------+" << endl;
		cout << "Wybierz opcje (1-10): "; cin >> choice;
		if (checkSpelling(1, choice)) {
			option = stoi(choice);
			if (option == 11) {
				cout << "Program sie zakonczyl\nDo widzenia!" << endl;
				break;
			}
			else if (option >= 7 && option <= 10) {
				if (dataCounter>0 || option == 10) {
					printSubMenu(option, 0);
				}
				else {
					cout << "Historia konwersji jest pusta! Nie mozna wykonac tej operacji." << endl;
					clearTheScreenAfterInteraction();
				}
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
