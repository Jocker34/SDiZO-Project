#include "stdafx.h"
#include "Test.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Czas.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


Test::Test()
{
}

Test::~Test()
{
}

	void Test::Tab_test1() {

	Czas czas;
	Tablica tablica;
	int wybor = 99;
	int wartosc;
	int pozycja;
	string daneWejsciowe;
	ifstream plikWejsciowy;

	cout << "Plik zawieraj�cy dane wej�ciowe: ";
	cin >> daneWejsciowe;

	//Otw�rz pliki
	plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wej�cie/" + daneWejsciowe);
	//Sprawd� czy plik jest otwarty poprawnie
	if (plikWejsciowy.is_open()) {
		cout << "Otwarto plik " << daneWejsciowe << endl;
	}
	else {
		cout << "Nie uda�o si� otworzy� pliku wej�ciowego!" << endl;
		return;
	}


	while (plikWejsciowy.good()) {
		plikWejsciowy >> wartosc;
		tablica.Dodaj_Na_Pocz�tek(wartosc);
	}

	while (wybor != 0) {
		cout << "Wybierz funkcj� tablicy:" << endl;
		cout << "    1. Dodaj na poczatek" << endl;
		cout << "    2. Dodaj na koniec" << endl;
		cout << "    3. Dodaj " << endl;
		cout << "    4. Usun pierwszy" << endl;
		cout << "    5. Usun ostatni" << endl;
		cout << "    6. Usun " << endl;
		cout << "    7. Wyszukaj " << endl;
		cout << "    8. Pokaz tablice" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		


			switch (wybor) {
			default:
				cout << "B��dny wyb�r!" << endl;
				break;

			case 0:
				break;

			case 1:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				czas.czasStart();
				tablica.Dodaj_Na_Pocz�tek(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 2:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				czas.czasStart();
				tablica.Dodaj_Na_Koniec(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 3:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				cout << "Podaj pozycje: ";
				cin >> pozycja;
				czas.czasStart();
				tablica.Dodaj(wartosc, pozycja);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 4:
				czas.czasStart();
				tablica.Usun_Pierwszy();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 5:
				czas.czasStart();
				tablica.Usun_Ostatni();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 6:
				cout << "Podaj pozycje: ";
				cin >> pozycja;
				czas.czasStart();
				tablica.Usun(pozycja);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 7:
				cout << "Podaj wartosc: ";
				cin >> wartosc;
				czas.czasStart();
				tablica.Sprawdz(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 8:
				czas.czasStart();
				tablica.Pokaz();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;
			}

		}
	}

	void Test::List_test1()
	{

		Czas czas;
		Lista lista;
		int wybor = 99;
		int wartosc;
		int pozycja;
		string daneWejsciowe;
		ifstream plikWejsciowy;

		cout << "Plik zawieraj�cy dane wej�ciowe: ";
		cin >> daneWejsciowe;

		//Otw�rz pliki
		plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wej�cie/" + daneWejsciowe);
		//Sprawd� czy plik jest otwarty poprawnie
		if (plikWejsciowy.is_open()) {
			cout << "Otwarto plik " << daneWejsciowe << endl;
		}
		else {
			cout << "Nie uda�o si� otworzy� pliku wej�ciowego!" << endl;
			return;
		}


		while (plikWejsciowy.good()) {
			plikWejsciowy >> wartosc;
			lista.Dodaj_Na_Poczatek(wartosc);
		}


		while (wybor != 0) {
			cout << "Wybierz funkcj� listy:" << endl;
			cout << "    1. Dodaj na pocz�tek" << endl;
			cout << "    2. Dodaj na koniec" << endl;
			cout << "    3. Dodaj gdziekolwiek" << endl;
			cout << "    4. Usu� pierwszy" << endl;
			cout << "    5. Usu� ostatni" << endl;
			cout << "    6. Usu� kt�rykolwiek" << endl;
			cout << "    7. Wyszukaj element" << endl;
			cout << "    8. Wydrukuj list�" << endl;
			cout << "    0. Wyj�cie" << endl << endl;
			cout << "Wyb�r: ";
			cin >> wybor;
			switch (wybor) {
			default:
				cout << "B��dny wyb�r!" << endl;
				break;

			case 0:
				break;

			case 1:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				lista.Dodaj_Na_Poczatek(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 2:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				lista.Dodaj_Na_Koniec(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 3:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				cout << "Podaj pozycj�: ";
				cin >> pozycja;
				czas.czasStart();
				lista.Dodaj(wartosc, pozycja);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 4:
				czas.czasStart();
				lista.Usun_Pierwszy();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 5:
				czas.czasStart();
				lista.Usun_Ostatni();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 6:
				cout << "Podaj pozycj�: ";
				cin >> pozycja;
				czas.czasStart();
				lista.Usun(pozycja);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 7:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				lista.Sprawdz(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 8:
				czas.czasStart();
				lista.Pokaz();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			}

		}
	}

	void Test::Kopiec_test1() {
		Czas czas;
		Kopiec kopiec;
		int wybor = 99;
		int wartosc;
		string daneWejsciowe;
		ifstream plikWejsciowy;

		cout << "Plik zawieraj�cy dane wej�ciowe: ";
		cin >> daneWejsciowe;

		//Otw�rz pliki
		plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wej�cie/" + daneWejsciowe);
		//Sprawd� czy plik jest otwarty poprawnie
		if (plikWejsciowy.is_open()) {
			cout << "Otwarto plik " << daneWejsciowe << endl;
		}
		else {
			cout << "Nie uda�o si� otworzy� pliku wej�ciowego!" << endl;
			return;
		}


		while (plikWejsciowy.good()) {
			plikWejsciowy >> wartosc;
			kopiec.Dodaj(wartosc);
		}

		while (wybor != 0) {
			cout << "Wybierz funkcj� Kopca:" << endl;
			cout << "    1. Dodaj" << endl;
			cout << "    2. Usu�" << endl;
			cout << "    3. Wyszukaj" << endl;
			cout << "    4. Wydrukuj kopiec" << endl;
			cout << "    0. Wyj�cie" << endl << endl;
			cout << "Wyb�r: ";
			cin >> wybor;
			switch (wybor) {
			default:
				cout << "B��dny wyb�r!" << endl;
				break;

			case 0:
				break;

			case 1:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				kopiec.Dodaj(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 2:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				kopiec.Usun(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 3:
				cout << "Podaj warto��: ";
				cin >> wartosc;
				czas.czasStart();
				kopiec.Sprawdz(wartosc);
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;

			case 4:
				czas.czasStart();
				kopiec.Pokaz();
				czas.czasStop();
				cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
				break;
			}

		}
	}

