

#include "stdafx.h"
#include <iostream>
#include "Testy.h"
#include "Test.h"
#include <string>

using namespace std;

int main()
{
	// OBIEKTY

	Testy testy;
	Test test;
	int wybor = 99;
	string tn = "n";




	// MENU
	while (wybor != 0) {
		cout << "Wybierz " << endl;
		cout << "    1. Tablica " << endl;
		cout << "    2. Lista dwukierunkowa" << endl;
		cout << "    3. Kopiec Binarny" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		if (wybor == 0) return 0;

		cout << "Wielokrotone testy? (t/n): ";
		cin >> tn;

		switch (wybor) {
		default:
			cout << "Blad wybierz jeszcze raz" << endl;
			break;

		case 0:
			break;

		case 1:
			cout << "Tablica..." << endl;
			if (tn == "t") testy.testTablicy();
			else test.Tab_test1();

			break;

		case 2:
			cout << "Lista dwukierunkowa..." << endl;
			if (tn == "t") testy.testListy();
			else test.List_test1();
			break;

		case 3:
			cout << "Kopiec binarny..." << endl;
			if (tn == "t") testy.testKopca();
			else test.Kopiec_test1();
			break;

		

		}
	}
    return 0;
}

