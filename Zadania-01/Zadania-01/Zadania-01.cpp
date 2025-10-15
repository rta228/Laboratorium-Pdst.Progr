#include <iostream>
#include <string>
using namespace std;

bool SpellChecker(int pCategory , string pString) {
	// Category 1 - only letters
	// Category 2 - only digits
	// Category 3 - digits and +/-
	switch (pCategory){
	case 1:
		for (char tmpChar : pString) {
			if (!isalpha(tmpChar)) {
				return false;
			}
		}
		break;

	case 2:
		for (char tmpChar : pString) {
			if (!isdigit(tmpChar)) {
				return false;
			}
		}
		break;

	case 3:
		for (char tmpChar : pString) {
			if (!isdigit(tmpChar)) {
				if (tmpChar != '-' && tmpChar != '+') {
					return false;
				}
			}
		}
		break;
	default:
		break;
	}
}

void Initials(string pName, string pSurname) {
	cout << "Imie: " << pName << ", Nazwisko: " << pSurname << "\nInicjaly: " << pName[0] <<pSurname[0] << endl;
	// printf("Imie: %s, Nazwisko: %s\nInicjaly: %c%c\n", pName.c_str(), pSurname.c_str(), pName[0], pSurname[0]);
}

/* This is Patric the Star
* Say Hello!
* - Hello! - Patric says
* He is here to stay right here for the rest of the eternity
* This is an infinit damnation but he doesn't mind
* He enjoys being a star
* Be like Patric
		 *
		***
	   *****
*******************
 *****************
  ***************
   *************
	***********
   *************
   *****   *****
	***     ***
	 *       *
*/
void Star() {
	int starHeight = 12;
	int starWidth = 20;
	int starCenter = starWidth / 2;
	bool starToPrint = false;
	int tmpInt = 0;
    for(int i = 0; i < starHeight; i++) {
        for (int j = 0; j < starWidth; j++) {
			starToPrint = false;
			if (i <= 2) {
				if (j >= starCenter - i && j <= starCenter + i) {
					starToPrint = true;
				}
			}
			else if (i <= 7) {
				tmpInt = i - 3;
				for(int k = 0; k <= 8 - tmpInt; k++) {
					//-0 -2 -4 -6
					if (j == starCenter - k || j == starCenter + k) {
						starToPrint = true;
						break;
					}
				}
			}
			else if (i <= 8) {
				tmpInt = i - 5;
				for (int k = 0; k <= 8 - tmpInt; k++) {
					//-4
					if (j == starCenter - k || j == starCenter + k) {
						starToPrint = true;
						break;
					}
				}
			}
			else if (i <= 11) {
				tmpInt = i - 6;
				for (int k = 0; k <= 8 - tmpInt; k++) {
					if (j == starCenter - k || j == starCenter + k) {
						// 3 5 7
						if (j >= starCenter - (i - 8) + 1 && j <= starCenter + (i - 8) - 1) {
							starToPrint = false;
						}
						else {
							starToPrint = true;
						}
						break;
					}
				}
			}
			if (starToPrint) {
				cout << "*";
				//printf("*");
			}
			else {
				cout << " ";
				//printf(" ");
			}
        }
        cout << endl;
	}
}

void PresenceList(int recordsNumber, int pNr[], string pNames[], string pSurnames[]) {
	cout << "+---------------- Lista obecnosci ----------------+\n";
	//printf("+---------------- Lista obecnosci ----------------+\n");
	cout << "NR\tImie\tNazwisko" << endl;
	//printf("NR\tImie\tNazwisko\n");
	for (int i = 0; i < recordsNumber; i++) {
		cout << pNr[i] << "\t" << pNames[i] << "\t" << pSurnames[i] << endl;
		//printf("%d\t%s\t%s\n", pNr[i], pNames[i].c_str(), pSurnames[i].c_str());
	}
	cout << "+-------------------------------------------------+\n";
	//printf("+-------------------------------------------------+\n");
}

float Addition(float a, float b) {
	return a + b;
}

float Multiplication(float a, float b) {
	return a * b;
}

void SimpleCalculus(float a, float b) {
	cout << "Operacje na liczbach: " << a << " i " << b << endl;
	//printf("Operacje na liczbach: %f i %f\n", a, b);
	cout << "Dodawanie: " << Addition(a, b) << endl;
	//printf("Dodawanie: %f\n", Addition(a, b));
	cout << "Mnozenie: " << Multiplication(a, b) << endl;
	//printf("Mnozenie: %f\n", Multiplication(a, b));
}

void TemperatureConversion(float pFahrenheit) {
	float celsius = (pFahrenheit - 32) * 5.0 / 9.0;
	cout << pFahrenheit << " stopni Fahrenheita to:\n " << celsius << " stopni Celsjusza.\n" << (celsius+273.15) << " stopni Kelvina\n" << endl;
	//printf("%f stopni Fahrenheita to:\n %f stopni Celsjusza.\n %f stopni Kelvina\n", pFahrenheit, celsius, (celsius+273.15));
}

int main(){
	// Zadanie 1
	printf("Zadanie 1\n");
	string name, surname;
	while (1) {
		cout << "Podaj imie: ";
		//printf("Podaj imie: ");
		cin >> name;
		//scanf("%s", name);
		cout << "Podaj nazwisko: ";
		//printf("Podaj nazwisko: ");
		cin >> surname;
		//scanf("%s", surname);
		if (SpellChecker(1, name) and SpellChecker(1, surname)) {
			break;
		}
		else {
			cout << "Cosik mi tu szpacisz drogi Panie kolego. \nImiona zwykle nie maja cyferek i znaczkow! \nA nie sadze ze jestes z rodziny krolewskiej. \nSproboj jeszcze raz!" << endl;
			//printf("Cosik mi tu szpacisz drogi Panie kolego. \nImiona zwykle nie maja cyferek i znaczkow! \nA nie sadze ze jestes z rodziny krolewskiej. \nSproboj jeszcze raz!\n");
		}
	}
	Initials(name, surname);

    // Zadanie 2
	printf("\nZadanie 2\n");
    Star();

	// Zadanie 3
	printf("\nZadanie 3\n");
	int tmpCount = 3;
	int tmpNr[3] = { 2, 13, 3813 };
	string tmpNames[3] = { "Roman", "Borbi", "Tony" };
	string tmpSurnames[3] = { "Gejmaniak", "Krętacz", "Beton" };
	PresenceList(tmpCount, tmpNr, tmpNames, tmpSurnames);

	// Zadanie 4
	printf("\nZadanie 4\n");
	int a, b;
	string tmpString1, tmpString2;
	while(1){
		cout << "\nPodaj Liczbe A: ";
		//printf("\nPodaj Liczbe A: ");
		cin >> tmpString1;
		//scanf("%s", tmpString1);
		cout << "\nPodaj Liczbe B:";
		//printf("\nPodaj Liczbe B:");
		cin >> tmpString2;
		//scanf("%s", tmpString2);
		if(SpellChecker(2, tmpString1) and SpellChecker(2, tmpString2)){
			a = stoi(tmpString1);
			b = stoi(tmpString2);
			break;
		}
		else{
			cout << "Wyczuwam tutaj lekki szwindel. \nLiczby nie maja liter i znaczkow! \nSproboj jeszcze raz!" << endl;
			//printf("Wyczuwam tutaj lekki szwindel. \nLiczby nie maja liter i znaczkow! \nSproboj jeszcze raz!\n");
		}
	}
	SimpleCalculus(a, b);

	// Zadanie 5
	printf("\nZadanie 5\n");
	float tmpFahrenheit;
	while (1) {
		cout << "\nPodaj temperature w stopniach Fahrenheita: ";
		//printf("\nPodaj temperature w stopniach Fahrenheita: ");
		cin >> tmpString1;
		//scanf("%s", tmpString1);
		if (SpellChecker(3, tmpString1)) {
			tmpFahrenheit = stof(tmpString1);
			break;
		}
		else {
			cout << "No i znow to przerabiamy kurcze ten. \nLiczby nie maja liter i znaczkow (Oprocz +/-)! \nSproboj jeszcze raz!" << endl;
			//printf("No i znow to przerabiamy kurcze ten. \nLiczby nie maja liter i znaczkow (Oprocz +/-)! \nSproboj jeszcze raz!\n");
		}
	}
	TemperatureConversion(tmpFahrenheit);

    return 0;
}
