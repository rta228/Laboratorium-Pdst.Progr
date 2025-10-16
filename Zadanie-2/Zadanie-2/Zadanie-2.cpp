// Zadanie-2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// 

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

bool spellingChecker(int pType, string pString) {
    // Typy:
	// 1 - Czy string jest tylko cyferkami
    switch (pType) {
        case 1:
            for (char tmpChar : pString) {
                if (!isdigit(tmpChar)) {
                    return 0;
                }
            }
            break;

        default:
            break;
            
    }
}

void Excercise1(int pOption) {
    switch (pOption) {
        case 1:
			cout << "Wersja 1.0: ";
            for (int i = 0; i < 10; i++) {
                cout << i << " ";
            }
			cout << endl;
			break;

        case 2:
            cout << "Wersja 2.0: ";
            for (int i = 0; i <= 10; i++) {
                cout << i << " ";
            }
            cout << endl;
            break;

        case 3:
            cout << "Wersja 3.0: ";
            for (int i = 5; i <= 7; i++) {
                cout << i << " ";
            }
            cout << endl;

            cout << "Wersja 3.1: ";
            for (int i = 5; i < 7; i++) {
                cout << i << " ";
            }
            cout << endl;
            break;

        case 4:
            cout << "Wersja 4.0: ";
            for (int i = 0; i <= 10; i+=2) {
                cout << i << " ";
            }
            cout << endl;
            break;

        case 5:
            cout << "Wersja 5.0: ";
            for (int i = 10; i >=0; i--) {
                cout << i << " ";
            }
            cout << endl;
            break;

        default:
            break;
    }
}

void Excercise2() {
	float fahr, celsius;
    int start, end, step;

    start = 0;
    end = 200;
	step = 20;

    fahr = start;
    cout << "Fahreheit na Celsjusza #1" << endl;
    while (fahr <= end) {
        celsius = 5 * (fahr - 32) / 9;
        cout << fahr << "\t" << celsius << endl;
        fahr = fahr + step;
	}
}

void Excercise3() {
	float fahr, celsius;
    int start, end, step;
    end = 200;
    step = 20;

    cout << "Fahreheit na Celsjusza #2" << endl;
    for(fahr = 0; fahr <= end; fahr += step) {
        celsius = 5 * (fahr - 32) / 9;
        cout << fahr << "\t" << celsius << endl;
	}
}

// Rip Zadanie 4

void Excercise5() {
    float fahr, celsius;
    int start, end, step;
    end = 200;
    step = 20;

    cout << "Fahreheit na Celsjusza #3" << endl;
    for (fahr = 0; fahr <= end; fahr += step) {
        celsius = 5.0  * (fahr - 32) / 9.0;
        printf("%3.0f \t %6.1f \n", fahr, celsius);
    }
}

void Ezcercise6() {
    int end, step;
	string tmpInput1, tmpInput2;
    while (1) {
		cout << "Podaj prosze!";
		cout << "\nPodaj wartosc koncowa petli: ";
        cin >> tmpInput1;
        cout << "\nPodaj wartosc kroku petli: ";
        cin >> tmpInput2;
        if (spellingChecker(1, tmpInput1) && spellingChecker(1, tmpInput2)) {
			end = stoi(tmpInput1);
			step = stoi(tmpInput2);
            break;
        }
        else {
			cout << "Cosik tu kurcze ten oszukujesz, no chyba ze system szesnatskowy ale ogolnie to cyferki != literki. Sprobuj jeszcze raz!" << endl;
        }
    }
	cout << "Twoja petla: " << endl;
    for (int i = 0; i <= end; i += step) {
		cout << i << " ";
    }
    cout << endl;
}

void Excercise7() {
	int tmpInput;
    for (int i = 0; i < 10; i++) {
        cout << "Podaj liczbe: "; cin >> tmpInput;
        if (tmpInput > 0) {
			cout << tmpInput << endl;
        }
        else {
            cout << endl;
        }
    }
}

void Excercise8() {
	cout << "Juz mi sie nie chce, ale leicmy dalej" << endl;
    for (int i = 0; i <= 100; i += 2) {
		cout << i << " ";
    }
}

void Ezcercise9() {
    int n;
    string tmpInput1;
    while (1) {
        cout << "Podaj liczbe od 1 do 100: ";
        cin >> tmpInput1;
        if (spellingChecker(1, tmpInput1)) {
            n = stoi(tmpInput1);
            break;
        }
        else {
            cout << "Blagam cie no kurde no wpisz wartosc INT!" << endl;
        }
    }
    for (int i = 0; i <= 100; i++) {
        if ( i % n == 0) {
			cout << i << " ";
        }
    }
    cout << endl;
}

void Ezcercise10() {
    int n, countOfSth;
    string tmpInput1;
    while (1) {
        cout << "Podaj liczbe od 1 do 100: ";
        cin >> tmpInput1;
        if (spellingChecker(1, tmpInput1)) {
            n = stoi(tmpInput1);
            break;
        }
        else {
            cout << "Ja nie mam slow, prosze o INT!" << endl;
        }
    }
    countOfSth = 0;
    for (int i = 0; i <= 100; i++) {
        if (i % n == 0) {
            countOfSth++;
        }
    }
    cout << countOfSth << endl;
}

void Ezcercise11() {
    int a, b;
    string tmpInput1, tmpInput2;
    while (1) {
        cout << "Podaj prosze!";
        cout << "\nPodaj liczbe A: ";
        cin >> tmpInput1;
        cout << "\nPodaj licbze B: ";
        cin >> tmpInput2;
        if (spellingChecker(1, tmpInput1) && spellingChecker(1, tmpInput2)) {
            a = stoi(tmpInput1);
            b = stoi(tmpInput2);
            break;
        }
        else {
            cout << "Dobra koniec! Sprobuj jeszcze raz!" << endl;
        }
    }

	int x = min(a, b);
	int y = max(a, b);

	cout << "Liczby podzielne przez 3 z zakresu <" << x << ";" << y << ">: ";
    for (int i = x; i <= y; i++) {
        if ( i % 3 == 0 ) {
			cout << i << " ";
        }
    }
}

void Eakdjfsize12() {
    int n, countOfSth;
    float avgOfSth;
    string tmpInput1;
    while (1) {
        cout << "Podaj liczbe: ";
        cin >> tmpInput1;
        if (spellingChecker(1, tmpInput1)) {
            n = stoi(tmpInput1);
            break;
        }
        else {
            cout << "Tylko INT!" << endl;
        }
    }
    countOfSth = 0;
    for (int i = 0; i < n; i++) {
        countOfSth+=i;
    }
    avgOfSth = countOfSth/n;
    cout << "No masz tutaj srednia: " << countOfSth << endl;
}

void Excercise13() {
	cout << "Licbzy od 0 do 100. ALE NA ODWROT!" << endl;
    for (int i = 100; i >= 0; i--) {
        cout << i <<  " ";
    }
}

void Excercise14() {
    int a, b, c;
    string tmpInput1, tmpInput2, tmpInput3;
    while (1) {
        cout << "Podaj prosze!";
        cout << "\nPodaj liczbe A: ";
        cin >> tmpInput1;
        cout << "\nPodaj licbze B: ";
        cin >> tmpInput2;
        cout << "\nPodaj licbze C: ";
        cin >> tmpInput3;
        if (spellingChecker(1, tmpInput1) && spellingChecker(1, tmpInput2) && spellingChecker(1, tmpInput3)) {
            a = stoi(tmpInput1);
            b = stoi(tmpInput2);
            c = stoi(tmpInput3);
            break;
        }
        else {
            cout << "INT != CHAR" << endl;
        }
    }

	int minFrom3 = min(a, min(b, c));

	cout << "Najmniejsza liczba to: " << minFrom3 << endl;
}


void Ezcercise15() {
    int n, m;
    string tmpInput1, tmpInput2;
    while (1) {
        cout << "Podaj prosze!";
        cout << "\nPodaj ilosc liczb do wylosowania: ";
        cin >> tmpInput1;
        cout << "\nPodaj gorny zakres tych liczb: ";
        cin >> tmpInput2;
        if (spellingChecker(1, tmpInput1) && spellingChecker(1, tmpInput2)) {
            n = stoi(tmpInput1);
            m = stoi(tmpInput2);
            break;
        }
        else {
            cout << ";-;" << endl;
        }
    }
    
    srand(time(NULL));
	cout << "Oto liczby wylosowane: " << endl;
    for (int i = 0; i < n; i++){
		cout << (rand() % m) << " ";
    }
}


void Ezcercise16() {
    int luckyNumber, tmpInt, countOfLN;
    string tmpInput1;
    while (1) {
        cout << "Podaj swoj szczesliwy numerek: ";
        cin >> tmpInput1;
        if (spellingChecker(1, tmpInput1)) {
            luckyNumber = stoi(tmpInput1);
            break;
        }
        else {
            cout << "0_0" << endl;
        }
    }

    srand(time(NULL));
	countOfLN = 0;
    for (int i = 0; i < 10; i++) {
		tmpInt = rand() % 10;
        if (tmpInt == luckyNumber) {
            countOfLN++;
        }
    }
	cout << "Twoj szczesliwy numerek wylosowal sie " << countOfLN << " razy!" << endl;
}

int main(){
	//  Excercise1(1);
    //  Excercise1(2);
    //  Excercise1(3);
    //  Excercise1(4);
    //  Excercise1(5);
    //  Excercise2();
    //  Excercise3();
    //  Excercise5();
    //  Ezcercise6();
    //  Excercise7();
    //  Excercise8();
    //  Ezcercise9();
    //  Ezcercise10();
    //  Ezcercise11();
    //  Eakdjfsize12();
    //  Excercise13();
    //  Excercise14();
    //  Ezcercise15();
    //  Ezcercise16();
    return 0;
}
