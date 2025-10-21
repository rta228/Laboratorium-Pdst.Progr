#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool CheckTheSpelling(int pType, string pString) {
    switch (pType) {
        case 1: {
            for (char tmpChar : pString) {
                if (!isdigit(tmpChar)) {
                    return false;
                }
            }
			return true;
            break;
		}
        case 2: {
            for (char tmpChar : pString) {
                if (!isdigit(tmpChar) && tmpChar != '.') {
                    return false;
                }
            }
            return true;
            break;
        }
        case 3: {
            for (char tmpChar : pString) {
                if (!isalpha(tmpChar)) {
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

void Excercise1(int pType) {
	string tmpString1, tmpString2;
    int a, b;
	cout << "\nZadanie 1";
    while (1) {
        cout << "\nPodaj liczbe calkowita A: "; cin >> tmpString1;
        cout << "\nPodaj liczbe calkowita B: "; cin >> tmpString2;
        if (!CheckTheSpelling(1, tmpString1) || !CheckTheSpelling(1, tmpString2)) {
            cout << "Cos nie dziala. Podaj liczbe calkowita!\n";
        }
        break;
    }
	a = stoi(tmpString1);
	b = stoi(tmpString2);

    switch (pType) {
        case 1: {
            if (a == b) {
                cout << "Liczby sa rowne!\n";
                break;
            }
            else if (a < b) {
                cout << "Liczba A jest mniejsza od liczby B!\n";
                break;
            }
            else {
                cout << "Liczba A jest wieksza od liczby B!\n";
                break;
            }
        }
        case 2: {
            if (a <= b) {
                if (a == b) {
                    cout << "Liczby sa rowne!\n";
                    break;
                }
                else {
                    cout << "Liczba A jest mniejsza od liczby B!\n";
                    break;
                }
            }
            else {
                cout << "Liczba A jest wieksza od liczby B!\n";
                break;
            }
        }
        default: {
            cout << "Nie ma takiej opcji!\n";
            break;
		}
    }
}

void Excercise3() {
    string tmpString1;
    double r;
    cout << "\nZadanie 2";
    while (1) {
        cout << "\nPodaj wspolczynnik z zakresu 0-1: "; cin >> tmpString1;
        if (!CheckTheSpelling(2, tmpString1)) {
            cout << "Cos nie dziala. Podaj poprawna wartosc!\n";
        }
        break;
    }
    r = stod(tmpString1);
    if ( r >= 0.7 && r <= 1) {
		cout << "Bardzo silna korelacja dodatnia!\n";
    }
    else if ( r >= 0.5) {
        cout << "Silna korelacja dodatnia!\n";
    }
    else if ( r >= 0.3) {
        cout << "Umiarkowana korelacja dodatnia!\n";
    }
    else if (r >= 0.2) {
        cout << "Slaba korelacja dodatnia!\n";
    }
    else if (r >= 0) {
        cout << "Brak korelacji!\n";
    }
    else {
		cout << "Liczba spoza zakresu 0-1!\n";
    }
}

void Excercise4() {
    string tmpString1, tmpString2;
    double a, b;
	char operation;
    while (1) {
        cout << "\nPodaj liczbe zmiennoprzecinkowa A: "; cin >> tmpString1;
        cout << "\nPodaj liczbe zmiennoprzecinkowa B: "; cin >> tmpString2;
        cout << "\nPodaj znak operacji matematycznej (+ - * /): "; cin >> operation;
        if (!CheckTheSpelling(2, tmpString1) || !CheckTheSpelling(2, tmpString2)) {
            cout << "Cos nie dziala. Podaj poprawne wartosci!\n";
        }
        break;
    }
    a = stod(tmpString1);
    b = stod(tmpString2);

    switch (operation) {
        case '+': {
            cout << "Wynik dodawania: " << a + b << "\n";
            break;
		}
        case '-': {
            cout << "Wynik odejmowania: " << a - b << "\n";
            break;
        }
        case '*': {
            cout << "Wynik mnozenia: " << a * b << "\n";
            break;
        }
        case '/': {
            if (b != 0) {
                cout << "Wynik dzielenia: " << a / b << "\n";
                break;
            }
            cout << "Przez zero sie nie dzieli!\n";
        }
        default: {
            cout << "Nasz kalkulator to nie program ktory wszystko liczy tylko 4 dniowy bobas z azji, on takie znaki bedzie mial za tydzien!\n";
        }
    }
}

void Excercise5() {
    int n1 = 0, n2 = 1, n3 = 0, i = 2;
    cout << "Ciąg fibonacciego: \n";
    bool isThisTrue = true;
    while ( isThisTrue == true ) {
        i++;
        n3 = n1 + n2;
        cout << n3 << endl;
        n1 = n2;
        n2 = n3;
    }
}

void Excercise6() {
    char choice;
    while (1) {
		cout << "\n+-------------- Kalkulator --------------+\n";
		cout << "|                1. Start                |\n";
        cout << "|                2. Exit                 |\n";
        cout << "|                3. Clear                |\n";
        cout << "+----------------------------------------+\n";
		cout << "Wybierz opcje: "; cin >> choice;
        switch (choice)
        {
		case '1':
            Excercise4();
            break;
		case '2':
            return;
        case '3':
            system("CLS");
            break;
        default:
			cout << "Nie ma takiej opcji!\n";
            break;
        }
    }
}

void Excercise7() {
	cout << "\nZadanie 7\n";
	int counter = 0;
    while (1) {
        if (counter < 200) {
            if (counter % 2 != 0) {
                cout << counter << " ";
            }
            counter++;
        }
        else {
            break;
        }
    }
}

void Excerices8() {
    string tmpString1;
    int n;
    cout << "\nZadanie 1";
    while (1) {
        cout << "\nPodaj dodatnia liczbe naturalna N: "; cin >> tmpString1;
        if (!CheckTheSpelling(2, tmpString1) && stoi(tmpString1)>0) {
            cout << "Cos nie dziala. Podaj liczbe naturalna i wieksza od 0!\n";
        }
        break;
    }
    n = stoi(tmpString1);
    int i = 2;
    while ( i < sqrt(n) ) {
        if (n % i == 0) {
            cout << "Najmniejszy dzielnik z przedzialu [2-sqrt(n)] liczby " << n << " to " << i << "\n";
            break;
        }
        i++;
    }
}

int main(){
    cout << "+----------------- Witaj W Programie -----------------+\n";
	Excercise1(1);
	Excercise3();
	Excercise4();
	//Excercise5(); // ! Nieskonczona petla !
	Excercise6();
	Excercise7();
	Excerices8();
    cout << "+----------------------- Adios -----------------------+\n";
	return 0;
}
