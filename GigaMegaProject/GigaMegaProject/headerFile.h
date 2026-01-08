#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

extern double arrayOfTemperatureData[100][2];
extern char arrayOfTemperatureUnits[100][2];
extern int dataCounter;

void clearTheScreenAfterInteraction();
bool checkSpelling(int option, string tmpString);
bool checkTheTemperature(char pickedTemp, double tmpTemp);

double getInputTemperature();
char getInputTemperatureUnit();

double FahrenheitToCelsius(double fahrenheit);
double FahrenheitToKelvin(double fahrenheit);
double CelsiusToFahrenheit(double celsius);
double CelsiusToKelvin(double celsius);
double KelvinToCelsius(double kelvin);
double KelvinToFahrenheit(double kelvin);

int whichHistoryToUse();
void printHistory(bool isDeletingInvolved);
void deleteHistory();
void modifyHistory();
void randomHistoryInsertion();

void printSubMenu(int option, double temperatura);
void printMenu();
