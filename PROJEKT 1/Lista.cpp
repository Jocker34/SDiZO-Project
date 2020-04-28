#include "stdafx.h"
#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista()
{
	Lista::pierwszyElement = NULL;
	Lista::aktualnyElement = NULL;
	Lista::ostatniElement = NULL;
	Lista::rozmiar = 0;
}


Lista::~Lista()
{
	for (int i = 0; i < Lista::rozmiar; i++) {

		//Przypisz kolejny element jako aktualny
		aktualnyElement = pierwszyElement->nastepny;
		//Usu� pierwszy element
		delete pierwszyElement;

		pierwszyElement = aktualnyElement;
	}

}


void Lista::Dodaj_Na_Poczatek(int wartosc) {

	//Sprawd�, czy istnieje element pocz�tkowy
	if (pierwszyElement == NULL) {
		//Utw�rz nowy element i ustaw go jako element pocz�tkowy i ko�cowy
		pierwszyElement = new Elementy_Listy(wartosc, NULL, NULL);
		ostatniElement = pierwszyElement;

	}
	else {
		//Ustaw element ktory by� pierwszym jako aktualny
		aktualnyElement = pierwszyElement;
		//Zast�p pierwszy element nowym
		//Ustaw jego warto�� oraz element kolejny na element aktualny (by�y pierwszy)
		pierwszyElement = new Elementy_Listy(wartosc, aktualnyElement, NULL);
		aktualnyElement->poprzedni = pierwszyElement;

	}

	//Zwi�ksz rozmiar listy
	rozmiar++;

}

void Lista::Dodaj_Na_Koniec(int wartosc) {
	//Sprawd�, czy istnieje element pocz�tkowy
	if (pierwszyElement == NULL) {
		//Utw�rz nowy element i ustaw go jako element pocz�tkowy i ko�cowy
		ostatniElement = new Elementy_Listy(wartosc, NULL, NULL);
		pierwszyElement = ostatniElement;

	}
	else {
		//Ustaw element kt�ry by� ostatnim jako aktualny
		aktualnyElement = ostatniElement;
		//Zast�p ostatni element nowym
		//Ustaw jego warto�� oraz element poprzedni na element aktualny (by�y ostatni)
		ostatniElement = new Elementy_Listy(wartosc, NULL, aktualnyElement);
		aktualnyElement->nastepny = ostatniElement;
	}
	//Zwi�ksz rozmiar listy o 1
	rozmiar++;
}

void Lista::Dodaj(int wartosc, int pozycja) {

	//Sprawd� czy w li�cie istnieje pozycja podana przez u�ytkownika
	if (pozycja < 0 || pozycja > rozmiar) {
		cout << "W li�cie nie istnieje pozycja [" << pozycja << "]" << endl;
		return;
	}
	//Sprawd� czy wybrana pozycja jest pierwsz�
	if (pozycja == 0) {
		Lista::Dodaj_Na_Poczatek(wartosc);
		return;
	}

	//Sprawd� czy wybrana pozycja jest ostatni�
	if (pozycja == rozmiar - 1) {
		Dodaj_Na_Koniec(wartosc);
		return;
	}

	//Sprawd� w kt�rej po�owie listy znajduje si� wybrany element
	if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

								 //Przypisz za aktualny element pierwszy
		aktualnyElement = pierwszyElement;

		//Przesu� wszyskie elementy o jeden dalej
		for (int i = 1; i < pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->nastepny;
		}

	}
	else {

		//Przypisz za aktualny element ostatni
		aktualnyElement = ostatniElement;

		//Przesu� wszystkie elementy o jedn� pozycj� wstecz
		for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->poprzedni;
		}

	}

	//Stw�rz nowy element listy z podanymi parametrami
	Elementy_Listy *nowyElementListy = new Elementy_Listy(wartosc, aktualnyElement,
		aktualnyElement->nastepny);

	//przypisz nowy element w odpowiednim miejscu tablicy
	aktualnyElement->nastepny->poprzedni = nowyElementListy;
	aktualnyElement->nastepny = nowyElementListy;

	//Zwi�ksz rozmiar listy
	rozmiar = rozmiar + 1;
}

void Lista::Usun_Pierwszy() {

	if (rozmiar > 0)
	{
		//przypisz drugi element jako aktualny
		aktualnyElement = pierwszyElement->nastepny;

		//Usu� pierwszy element
		delete pierwszyElement;

		//Sprawd�, czy w li�cie s� jeszcze jakie� elementy
		//Je�eli tak, ustaw aktualny element jako pierwszy
		//Je�eli nie, wyzeruj elementy listy
		if (rozmiar > 1) {
			aktualnyElement->poprzedni = NULL;
			pierwszyElement = aktualnyElement;
		}
		else {
			aktualnyElement = NULL;
			pierwszyElement = NULL;
			ostatniElement = NULL;
		}

		//Zmniejsz rozmiar listy
		rozmiar--;
	}
	else
	{
		cout << "Lista jest pusta " << endl;
	}
	}


void Lista::Usun_Ostatni() {

	if (rozmiar > 0)
	{
		//Przypisz przedostani element jako aktualny
		aktualnyElement = ostatniElement->poprzedni;
		//Usu� ostatni element
		delete ostatniElement;

		//Sprawd�, czy w li�cie s� jeszcze jakie� elementy
		//Je�eli tak, ustaw aktualny element jako ostatni
		//Je�eli nie, wyzeruj elementy listy
		if (rozmiar > 1) {
			aktualnyElement->nastepny = NULL;
			ostatniElement = aktualnyElement;
		}
		else {
			aktualnyElement = NULL;
			pierwszyElement = NULL;
			ostatniElement = NULL;
		}

		//Zmniejsz rozmiar listy
		rozmiar--;
	}
	else
	{
		cout << "Lista jest pusta " << endl;
	}
}

void Lista::Usun(int pozycja) {
	if (rozmiar > 0)
	{

		//Sprawd� czy w li�cie istnieje pozycja podana przez u�ytkownika
		if (pozycja < 0 || pozycja > rozmiar) {
			cout << "W li�cie nie istnieje pozycja [" << pozycja << "]" << endl;
			return;
		}
		//Sprawd� czy wybrana pozycja jest pierwsz�
		if (pozycja == 0) {
			Usun_Pierwszy();
			return;
		}

		//Sprawd� czy wybrana pozycja jest ostatni�
		if (pozycja == rozmiar - 1) {
			Usun_Ostatni();
			return;
		}

		//Sprawd� w kt�rej po�owie listy znajduje si� wybrany element
		if (pozycja < rozmiar / 2) {

			//Przypisz za aktualny element pierwszy
			aktualnyElement = pierwszyElement;

			//Przesu� wszyskie elementy o jeden dalej
			for (int i = 1; i < pozycja - 1; ++i) {
				aktualnyElement = aktualnyElement->nastepny;
			}

		}
		else {

			//Przypisz za aktualny element ostatni
			aktualnyElement = ostatniElement;

			//Przesu� wszystkie elementy o jedn� pozycj� wstecz
			for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
				aktualnyElement = aktualnyElement->poprzedni;
			}

		}

		//Stw�rz nowy element listy z podanymi parametrami
		Elementy_Listy *nowyElementListy = aktualnyElement->nastepny;

		//przypisz nowy element w odpowiednim miejscu tablicy
		aktualnyElement->nastepny = nowyElementListy->nastepny;
		aktualnyElement->nastepny->poprzedni = nowyElementListy;

		delete[]nowyElementListy;

		//Zmniejsz rozmiar listy
		rozmiar--;
	}
	else
	{
		cout << "Lista jest pusta " << endl;
	}

}

bool Lista::Sprawdz(int wartosc) {

	//Je�eli lista jest pusta, zwr�� false z automatu
	if (rozmiar == 0) {
		return false;

	}

	//Przypisa pierwszy element jako aktualny
	aktualnyElement = pierwszyElement;

	//Przeszukaj list� pod k�tem warto�ci
	for (int i = 0; i < rozmiar; i++) {
		if (aktualnyElement->wartosc == wartosc) {
			cout << "Szukana warto�� zajmuje w li�cie pozycj� [" << i << "]" << endl;
			return true;
		}

		aktualnyElement = aktualnyElement->nastepny;
	}

	//Je�eli warto�� nie wyst�pi�a w �adnej iteracji listy zwr�� false
	cout << "Szukana warto�� nie wyst�puje w li�cie" << endl;
	return false;
}

void Lista::Pokaz() {

	if (rozmiar > 0)
	{
		//Ustaw jako akutualny element pierwszy element listy
		aktualnyElement = pierwszyElement;

		for (int i = 0; i < rozmiar; i++) {

			cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

			//Przypisz kolejny element listy jako aktualny
			aktualnyElement = aktualnyElement->nastepny;

		}
	}
	else
	{
		cout << "Lista jest pusta " << endl;
	}

}