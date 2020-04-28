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
		//Usuñ pierwszy element
		delete pierwszyElement;

		pierwszyElement = aktualnyElement;
	}

}


void Lista::Dodaj_Na_Poczatek(int wartosc) {

	//SprawdŸ, czy istnieje element pocz¹tkowy
	if (pierwszyElement == NULL) {
		//Utwórz nowy element i ustaw go jako element pocz¹tkowy i koñcowy
		pierwszyElement = new Elementy_Listy(wartosc, NULL, NULL);
		ostatniElement = pierwszyElement;

	}
	else {
		//Ustaw element ktory by³ pierwszym jako aktualny
		aktualnyElement = pierwszyElement;
		//Zast¹p pierwszy element nowym
		//Ustaw jego wartoœæ oraz element kolejny na element aktualny (by³y pierwszy)
		pierwszyElement = new Elementy_Listy(wartosc, aktualnyElement, NULL);
		aktualnyElement->poprzedni = pierwszyElement;

	}

	//Zwiêksz rozmiar listy
	rozmiar++;

}

void Lista::Dodaj_Na_Koniec(int wartosc) {
	//SprawdŸ, czy istnieje element pocz¹tkowy
	if (pierwszyElement == NULL) {
		//Utwórz nowy element i ustaw go jako element pocz¹tkowy i koñcowy
		ostatniElement = new Elementy_Listy(wartosc, NULL, NULL);
		pierwszyElement = ostatniElement;

	}
	else {
		//Ustaw element który by³ ostatnim jako aktualny
		aktualnyElement = ostatniElement;
		//Zast¹p ostatni element nowym
		//Ustaw jego wartoœæ oraz element poprzedni na element aktualny (by³y ostatni)
		ostatniElement = new Elementy_Listy(wartosc, NULL, aktualnyElement);
		aktualnyElement->nastepny = ostatniElement;
	}
	//Zwiêksz rozmiar listy o 1
	rozmiar++;
}

void Lista::Dodaj(int wartosc, int pozycja) {

	//SprawdŸ czy w liœcie istnieje pozycja podana przez u¿ytkownika
	if (pozycja < 0 || pozycja > rozmiar) {
		cout << "W liœcie nie istnieje pozycja [" << pozycja << "]" << endl;
		return;
	}
	//SprawdŸ czy wybrana pozycja jest pierwsz¹
	if (pozycja == 0) {
		Lista::Dodaj_Na_Poczatek(wartosc);
		return;
	}

	//SprawdŸ czy wybrana pozycja jest ostatni¹
	if (pozycja == rozmiar - 1) {
		Dodaj_Na_Koniec(wartosc);
		return;
	}

	//SprawdŸ w której po³owie listy znajduje siê wybrany element
	if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

								 //Przypisz za aktualny element pierwszy
		aktualnyElement = pierwszyElement;

		//Przesuñ wszyskie elementy o jeden dalej
		for (int i = 1; i < pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->nastepny;
		}

	}
	else {

		//Przypisz za aktualny element ostatni
		aktualnyElement = ostatniElement;

		//Przesuñ wszystkie elementy o jedn¹ pozycjê wstecz
		for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
			aktualnyElement = aktualnyElement->poprzedni;
		}

	}

	//Stwórz nowy element listy z podanymi parametrami
	Elementy_Listy *nowyElementListy = new Elementy_Listy(wartosc, aktualnyElement,
		aktualnyElement->nastepny);

	//przypisz nowy element w odpowiednim miejscu tablicy
	aktualnyElement->nastepny->poprzedni = nowyElementListy;
	aktualnyElement->nastepny = nowyElementListy;

	//Zwiêksz rozmiar listy
	rozmiar = rozmiar + 1;
}

void Lista::Usun_Pierwszy() {

	if (rozmiar > 0)
	{
		//przypisz drugi element jako aktualny
		aktualnyElement = pierwszyElement->nastepny;

		//Usuñ pierwszy element
		delete pierwszyElement;

		//SprawdŸ, czy w liœcie s¹ jeszcze jakieœ elementy
		//Je¿eli tak, ustaw aktualny element jako pierwszy
		//Je¿eli nie, wyzeruj elementy listy
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
		//Usuñ ostatni element
		delete ostatniElement;

		//SprawdŸ, czy w liœcie s¹ jeszcze jakieœ elementy
		//Je¿eli tak, ustaw aktualny element jako ostatni
		//Je¿eli nie, wyzeruj elementy listy
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

		//SprawdŸ czy w liœcie istnieje pozycja podana przez u¿ytkownika
		if (pozycja < 0 || pozycja > rozmiar) {
			cout << "W liœcie nie istnieje pozycja [" << pozycja << "]" << endl;
			return;
		}
		//SprawdŸ czy wybrana pozycja jest pierwsz¹
		if (pozycja == 0) {
			Usun_Pierwszy();
			return;
		}

		//SprawdŸ czy wybrana pozycja jest ostatni¹
		if (pozycja == rozmiar - 1) {
			Usun_Ostatni();
			return;
		}

		//SprawdŸ w której po³owie listy znajduje siê wybrany element
		if (pozycja < rozmiar / 2) {

			//Przypisz za aktualny element pierwszy
			aktualnyElement = pierwszyElement;

			//Przesuñ wszyskie elementy o jeden dalej
			for (int i = 1; i < pozycja - 1; ++i) {
				aktualnyElement = aktualnyElement->nastepny;
			}

		}
		else {

			//Przypisz za aktualny element ostatni
			aktualnyElement = ostatniElement;

			//Przesuñ wszystkie elementy o jedn¹ pozycjê wstecz
			for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
				aktualnyElement = aktualnyElement->poprzedni;
			}

		}

		//Stwórz nowy element listy z podanymi parametrami
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

	//Je¿eli lista jest pusta, zwróæ false z automatu
	if (rozmiar == 0) {
		return false;

	}

	//Przypisa pierwszy element jako aktualny
	aktualnyElement = pierwszyElement;

	//Przeszukaj listê pod k¹tem wartoœci
	for (int i = 0; i < rozmiar; i++) {
		if (aktualnyElement->wartosc == wartosc) {
			cout << "Szukana wartoœæ zajmuje w liœcie pozycjê [" << i << "]" << endl;
			return true;
		}

		aktualnyElement = aktualnyElement->nastepny;
	}

	//Je¿eli wartoœæ nie wyst¹pi³a w ¿adnej iteracji listy zwróæ false
	cout << "Szukana wartoœæ nie wystêpuje w liœcie" << endl;
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