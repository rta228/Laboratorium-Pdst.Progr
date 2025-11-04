#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool checkSpelling(int type, string tmpString) {
    switch (type) {
		// 1 - only letters
		// 2 - only digits
        case 1:
            for (char c : tmpString) {
                if (!isalpha(c)) {
                    return false;
                }
            }
			return true;
		case 2:
            for (char c : tmpString) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            return true;
        default:
            return false;
    }
}

class ExcerciseOne {
    int numberA, numberB;

public:
    void setNumbers(int pNumberA, int pNumberB) {
        numberA = pNumberA;
        numberB = pNumberB;
    }

    void isGreater(int a, int b);

    int returnGreater(int a, int b);

    void display() {
        isGreater(numberA, numberB);
	}
};

void ExcerciseOne::isGreater(int a, int b) {
    int greater = returnGreater(a, b);
    cout << "Wieksza liczba to: " << greater << endl;
}

int ExcerciseOne::returnGreater(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void insertTwoNumbers(ExcerciseOne& obj) {
    int a, b;
    string tmpStringA, tmpStringB;
    while (1) {
        cout << "\nPodaj liczbe a: ";
        cin >> tmpStringA;
        cout << "\nPodaj liczbe b: ";
        cin >> tmpStringB;
        if (checkSpelling(2, tmpStringA) && checkSpelling(2, tmpStringB)) {
            a = stoi(tmpStringA);
            b = stoi(tmpStringB);
            break;
        }
        cout << "Blad! Podaj liczby ponownie.\n";
    }
    obj.setNumbers(a, b);
}

class ExcerciseTwo {
    int numberN;

    public: 
        void setNumbers(int pNumberN) {
            numberN = pNumberN;
		}

        void printDividers(unsigned int n);

        void display() {
            printDividers(numberN);
		}
};

void ExcerciseTwo::printDividers(unsigned int n) {
    cout << "Dzielniki liczby " << n << ": " << endl;
    for (unsigned int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void insertOneNumber(ExcerciseTwo& obj) {
    unsigned int n;
    string tmpStringN;
    while (1) {
        cout << "\nPodaj liczbe n: ";
        cin >> tmpStringN;
        if (checkSpelling(2, tmpStringN) && stoi(tmpStringN) > 0) {
            n = stoi(tmpStringN);
            break;
        }
        cout << "Bliat! Podaj liczbe calkowita dodtania ponownie.\n";
    }
    obj.setNumbers(n);
}

class ExcerciseThree {
	double numberA, numberB;
	int operationType;

    public:
        void setValues(double pNumberA, double pNumberB, int pOperationType) {
            numberA = pNumberA;
            numberB = pNumberB;
            operationType = pOperationType;
        }
        void insertThreeNumber();

        void display();
        void logicalProgramOfCalculus();

        double sumOfNumbers(double a, double b);
        double differenceOfNumbers(double a, double b);
        double productOfNumbers(double a, double b);
        double quotientOfNumbers(double a, double b);

};

void ExcerciseThree::insertThreeNumber() {
    double a, b, type;
    string tmpStringA, tmpStringB, tmpStringType;
    while (1) {
        cout << "\nPodaj liczbe a: ";
        cin >> tmpStringA;
        cout << "\nPodaj liczbe b: ";
        cin >> tmpStringB;
        cout << "\nPodaj typ operacji\nDostepne operacje\n1 - Dodawanie\n2 - Odejmowanie\n3 - Mnozenie\n4 - Dzielenie\nTwoj wybor: ";
        cin >> tmpStringType;
        if (checkSpelling(2, tmpStringA) || tmpStringA == "." && checkSpelling(2, tmpStringB) || tmpStringB == "." && checkSpelling(2, tmpStringA)) {
            a = stoi(tmpStringA);
            b = stoi(tmpStringB);
            type = stoi(tmpStringType);
            break;
        }
        cout << "Bliat! Sprawdz co zle napisales i sproboj ponownie.\n";
    }
    setValues(a, b, type);
}

double ExcerciseThree::sumOfNumbers(double a, double b) {
    return a + b;
}

double ExcerciseThree::differenceOfNumbers(double a, double b) {
    return a - b;
}

double ExcerciseThree::productOfNumbers(double a, double b) {
    return a * b;
}

double ExcerciseThree::quotientOfNumbers(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Dzielenie przez zero jest zbyt trudne zeby taki maly komputer jak ja to ogarnal Sory ;-;!" << endl;
        return NAN;
    }
}

void ExcerciseThree::logicalProgramOfCalculus() {
    insertThreeNumber();
    switch (operationType) {
    case 1:
        cout << "Suma: " << sumOfNumbers(numberA, numberB) << endl;
        break;
    case 2:
        cout << "Roznica: " << differenceOfNumbers(numberA, numberB) << endl;
        break;
    case 3:
        cout << "Iloczyn: " << productOfNumbers(numberA, numberB) << endl;
        break;
    case 4:
        cout << "Iloraz: " << quotientOfNumbers(numberA, numberB) << endl;
        break;
    default:
        cout << "Nieprawidlowy typ operacji." << endl;
    }
}

void ExcerciseThree::display() {
    int choice;
    while (1) {
        choice = 0;
        cout << "+----------------------------------------------------------------+\n";
        cout << "|                      KALKULATOR 3000 v1.0                      |\n";
        cout << "|                         Opcja 1 - Start                        |\n";
        cout << "|                         Opcja 2 - Czysc                        |\n";
        cout << "|                         Opcja 3 - Koniec                       |\n";
        cout << "+----------------------------------------------------------------+\n";
        cout << "Wybierz opcje: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                logicalProgramOfCalculus();
                break;
            }
            case 2: {
                numberA = 0;
                numberB = 0;
                operationType = 0;
                system("cls||clear");
                break;
            }
            case 3: {
                cout << "Koniec programu. Do zobaczenia!" << endl;
                return;
            }
            default: {
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                break;
            }
        }
    }
}

class ExcerciseFour {
    int numberA, numberB;

    public:
        void setNumbers(int pNumberA, int pNumberB) {
            numberA = pNumberA;
            numberB = pNumberB;
        }

        int powerValue(int a, int b);

        void display();
};

int ExcerciseFour::powerValue(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void ExcerciseFour::display() {
    cout << "Wynik potegowania: " << powerValue(numberA, numberB) << endl;
}

void insertTwoNumbers(ExcerciseFour& obj) {
    unsigned int a, b;
    string tmpStringA, tmpStringB;
    while (1) {
        cout << "\nPodaj liczbe a: ";
        cin >> tmpStringA;
        cout << "\nPodaj liczbe b: ";
        cin >> tmpStringB;
        if (checkSpelling(2, tmpStringA) && stoi(tmpStringA) > 0 && checkSpelling(2, tmpStringB) && stoi(tmpStringB) > 0) {
            a = stoi(tmpStringA);
            b = stoi(tmpStringB);
            break;
        }
        cout << "Blad! Podaj liczby dodatnie ponownie.\n";
    }
    obj.setNumbers(a, b);
}

class ExcerciseFive {
    int numberN;

public:
    void setNumbers(int pNumberN) {
        numberN = pNumberN;
    }

    int returnSilnia(unsigned int n);

    void display();
};

int ExcerciseFive::returnSilnia(unsigned int n) {
    for (unsigned int i = 1; i <= n; i++) {
        n *= i;
    }
    return n;
}

void ExcerciseFive::display() {
    cout << "Silnia liczby " << numberN << " wynosi: " << returnSilnia(numberN) << endl;
}

void insertOneNumber(ExcerciseFive& obj) {
    unsigned int n;
    string tmpStringN;
    while (1) {
        cout << "\nPodaj liczbe n: ";
        cin >> tmpStringN;
        if (checkSpelling(2, tmpStringN) && stoi(tmpStringN) > 0) {
            n = stoi(tmpStringN);
            break;
        }
        cout << "Bliat! Podaj liczbe calkowita dodtania ponownie.\n";
    }
    obj.setNumbers(n);
}


class ExcerciseSix {
    int numberN;

public:
    void setNumbers(int pNumberN) {
        numberN = pNumberN;
    }

    int returnPowerOf2(int type, unsigned int n);

    void display();
};

int ExcerciseSix::returnPowerOf2(int type, unsigned int n) {
    switch(type) {
        case 1: {
            return pow(2, n);
        }
            
        case 2: {
            int result = 1;
            for (unsigned int i = 1; i < n; i++) {
                result = result * 2;
            }
            return result;
        }
            
        default: {
            cout << "Nieprawidlowy typ obliczen" << endl;
            return NAN;
        }
	}
    
}

void ExcerciseSix::display() {
    cout << numberN << "-ta potega liczby 2: " << returnPowerOf2(2, numberN) << endl;
}

void insertOneNumber(ExcerciseSix& obj) {
    unsigned int n;
    string tmpStringN;
    while (1) {
        cout << "\nPodaj liczbe n: ";
        cin >> tmpStringN;
        if (checkSpelling(2, tmpStringN) && stoi(tmpStringN) > 0) {
            n = stoi(tmpStringN);
            break;
        }
        cout << "Bliat! Podaj liczbe calkowita dodtania ponownie.\n";
    }
    obj.setNumbers(n);
}

int main(){
    /*
        Moze ma Pani pomysl jak by dalo sie zoptymalizowac i zunifikowac funkcje insertXNumbers?
        Pewnie nie uzywajac obiektow by bylo to lepsze ale chcailem takie podstawy tego sobie przypomniec
    */

    //ExcerciseOne ExcerciseOneObj1;
    //insertTwoNumbers(ExcerciseOneObj1);
	//ExcerciseOneObj1.display();

	//ExcerciseTwo ExcerciseTwoObj1;
	//insertOneNumber(ExcerciseTwoObj1);
    //ExcerciseTwoObj1.display();

	ExcerciseThree ExcerciseThreeObj1;
	ExcerciseThreeObj1.display();

	//ExcerciseFour ExcerciseFourObj1;
	//insertTwoNumbers(ExcerciseFourObj1);
    //ExcerciseFourObj1.display();

	//ExcerciseFive ExcerciseFiveObj1;
	//insertOneNumber(ExcerciseFiveObj1);
	//ExcerciseFiveObj1.display();

	//ExcerciseSix ExcerciseSixObj1;
	//insertOneNumber(ExcerciseSixObj1);
	//ExcerciseSixObj1.display();

	return 0;
}