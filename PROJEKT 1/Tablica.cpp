#include "stdafx.h"
#include <iostream>
#include "Tablica.h"

using namespace std;


// Konstruktor
Tablica::Tablica()
{
	Tablica::wsk_Head = NULL;
	Tablica::roz_Tab = 0;
}

// Dekonstruktor
Tablica::~Tablica()
{
	if (wsk_Head != NULL)
		delete[]wsk_Head;
}


void Tablica::Dodaj_Na_Pocz¹tek(int wartosc) {

	// PIERWSZY ELEMNT NOWEJ TABLICY TO NOWA WAROTSC
	int *new_wsk_Head = new int[roz_Tab + 1];
	new_wsk_Head[0] = wartosc;


	for (int i = 0; i < roz_Tab; i++)
	{
		new_wsk_Head[i + 1] = wsk_Head[i];
	}

	delete wsk_Head;
	wsk_Head = new_wsk_Head;

	roz_Tab++;
}

void Tablica::Dodaj_Na_Koniec(int wartosc) {

	// DZIALA TAK SAMO JAK POWYZEJ TYLKO ZACZYNA OD KONCA

	// NOWA TABLICA
	int *new_wsk_Head = new int[roz_Tab + 1];
	new_wsk_Head[roz_Tab] = wartosc;


	for (int i = 0; i < roz_Tab; i++) 
	{
		new_wsk_Head[i] = wsk_Head[i];
	}


	delete wsk_Head;
	wsk_Head = new_wsk_Head;
	
	roz_Tab++;
}

void Tablica::Dodaj(int wartosc, int pozycja) {


	// SPRAWDZAMY CZY PODANA POZYCJA ISTNIEJE
	if (pozycja < 0 || pozycja > roz_Tab) 
	{
		cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
	}
	else 
	{

		int *new_wsk_Head = new int[roz_Tab + 1];
		new_wsk_Head[pozycja] = wartosc;

		// PRZEPISUJEMY TABLICE DO PODANEJ POZYCJI
		for (int i = 0; i < pozycja; i++) 
		{
			new_wsk_Head[i] = wsk_Head[i];
		}

		// PRZEPISUJEMY TABLICE PO PODANEJ POZYCJI
		for (int i = pozycja; i < roz_Tab; i++) 
		{
			new_wsk_Head[i + 1] = wsk_Head[i];
		}

		
		delete wsk_Head;
		wsk_Head = new_wsk_Head;

		roz_Tab++;

	}

}


void Tablica::Usun_Ostatni() {
	
	if (roz_Tab > 0) {
		
		int *new_wsk_Head = new int[roz_Tab - 1];

		
		for (int i = 0; i < roz_Tab - 1; i++) 
		{
			new_wsk_Head[i] = wsk_Head[i];
		}


		delete[] wsk_Head;
		wsk_Head = new_wsk_Head;

		roz_Tab--;
	}
	else 
	{
		cout << "W tablicy nie ma ¿adnego elementu!" << endl;
	}

}


void Tablica::Usun_Pierwszy() {


	if (roz_Tab > 0) 
	{
	
		int *new_wsk_Head = new int[roz_Tab - 1];

		for (int i = 0; i < roz_Tab - 1; i++) 
		{
			new_wsk_Head[i] = wsk_Head[i + 1];
		}

		delete[] wsk_Head;
		wsk_Head = new_wsk_Head;

	
		roz_Tab--;
	}
	else 
	{
		cout << "W tablicy nie ma ¿adnego elementu!" << endl;
	}

}

void Tablica::Usun(int pozycja) {


	if (roz_Tab > 0 || pozycja > 0 || pozycja < roz_Tab)
	{

		int *new_wsk_Head = new int[roz_Tab - 1];

		for (int i = 0; i < pozycja; i++) 
		{
			new_wsk_Head[i] = wsk_Head[i];
		}

		for (int i = pozycja; i < roz_Tab - 1; i++) 
		{
			new_wsk_Head[i] = wsk_Head[i + 1];
		}


		delete[] wsk_Head;
		wsk_Head = new_wsk_Head;

		roz_Tab--;
	}
	else
	{
		cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
	}


}

bool Tablica::Sprawdz(int wartosc) 
{

	for (int i = 0; i < roz_Tab; i++) 
	{
		if (wsk_Head[i] == wartosc) {
			cout << "Szukana wartoœæ zajmuje w tablicy pozycjê [" << i << "]" << endl;
			return true;
		}
	}
	cout << "Szukana wartoœæ nie wystêpuje w tablicy" << endl;
	return false;
}

void Tablica::Pokaz() {
	cout << "Aktualny stan tablicy:" << endl;

	if (roz_Tab != NULL) 
	{
		for (int i = 0; i < roz_Tab; i++) 
		{
			cout << "    [" << i << "] " << wsk_Head[i] << endl;
		}
	}
	else {
		cout << "    Tablica nie ma ¿adnych elementów" << endl;
	}
}
