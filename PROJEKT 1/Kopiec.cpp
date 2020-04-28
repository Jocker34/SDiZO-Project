#include "stdafx.h"
#include "Kopiec.h"
#include <iostream>


using namespace std;

Kopiec::Kopiec() {
	Kopiec::Tab = NULL;
	Kopiec::rozmiar = 0;
}

Kopiec::~Kopiec() {

	if (Kopiec::rozmiar > 0) {
		delete[]Tab;
	}

}

void Kopiec::Popraw() {

	int tymczasowa = 0;

	// SORTOWANIE
	for (int i = rozmiar; 0 < i; i--) 
	{
		if (Tab[i - 1] < Tab[i]) 
		{
			tymczasowa = Tab[i - 1];
			Tab[i - 1] = Tab[i];
			Tab[i] = tymczasowa;
		}


	}

}


bool Kopiec::Sprawdz(int wartosc) {


	for (int i = 0; i < rozmiar; i++) 
	{
		if (Tab[i] == wartosc) 
		{
			cout << "Szukana wartoœæ zajmuje w tablicy kopca pozycjê [" << i << "]" << endl;
			return true;
		}
	}

	cout << "Szukana wartoœæ nie wystêpuje w kopcu" << endl;
	return false;

}




void Kopiec::Pokaz() {

	cout << "Aktualny stan kopca:" << endl;
	if (rozmiar > 0) 
	{

		for (int i = 0; i < rozmiar; i++) 
		{
			cout << "    [" << i << "] " << Tab[i] << endl;
		}

	}
	else 
	{
		cout << "    Tablica nie ma ¿adnych elementów" << endl;
	}

}


void Kopiec::Dodaj(int wartosc) {

	// SPRAWDZ CZY ELEMENT SIE POWTORZYL 
	if (!Kopiec::Sprawdz(wartosc)) 
	{

		
		int *newTab = new int[rozmiar + 1];

		for (int i = 0; i < rozmiar; i++) 
		{
			newTab[i] = Tab[i];
		}


		newTab[rozmiar] = wartosc;
		delete[]Tab;
		Tab = newTab;

		Kopiec::Popraw();
		rozmiar++;


	}

}

void Kopiec::Usun(int wartosc) {

	
	 
	// SZUKANIE WARTOSCI
	for (int i = 0; i < rozmiar; i++)
	{

		if (Tab[i] == wartosc)
		{


			int *newTab = new int[rozmiar - 1];

			for (int k = 0; k < i; k++)
			{
				newTab[k] = Tab[k];
			}

			for (int k = i + 1; k < rozmiar; k++)
			{
				newTab[k - 1] = Tab[k];
			}


			delete[]Tab;
			Tab = newTab;
			rozmiar--;

			Kopiec::Popraw();
			return;
		}
	
	}

	
}



