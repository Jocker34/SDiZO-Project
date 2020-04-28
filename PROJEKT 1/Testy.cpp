#include "stdafx.h"
#include "Testy.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Czas.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Testy::Testy()
{
}

Testy::~Testy()
{
}


void Testy::testTablicy() {
	srand(time(NULL));
	Czas czas;
	Tablica tablica;
	int wybor = 99;
	int wartosc;
	int pozycja;
	string daneWyjsciowe;
	string daneWejsciowe;
	ofstream plikWyjsciowy;
	ifstream plikWejsciowy;



	while (wybor != 0) {
		cout << "Wybierz funkcjê tablicy:" << endl;
		cout << "    1. Dodaj na poczatek" << endl;
		cout << "    2. Dodaj na koniec" << endl;
		cout << "    3. Dodaj" << endl;
		cout << "    4. Usun pierwszy" << endl;
		cout << "    5. Usun ostatni" << endl;
		cout << "    6. Usun" << endl;
		cout << "    7. Wyszukaj element" << endl;
		cout << "    8. Wydrukuj tablice" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		//Zamknij, je¿eli wybrano 0
		if (wybor == 0) return;

		cout << "Plik zawieraj¹cy dane wejœciowe: ";
		cin >> daneWejsciowe;
		cout << "Plik z wynikami testu: ";
		cin >> daneWyjsciowe;


		//Otwórz pliki
		plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wejœcie/" + daneWejsciowe);
		plikWyjsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wyjœcie/Tablica/" + daneWyjsciowe, fstream::out);
		//Sprawd¿ czy plik jest otwarty poprawnie
		if (plikWejsciowy.is_open()) {
			cout << "Otwarto plik " << daneWejsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
			return;
		}

		if (plikWyjsciowy.is_open()) {
			cout << "Otwarto plik " << daneWyjsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
			return;
		}


		switch (wybor) {
		default:
			cout << "B³êdny wybór!" << endl;
			break;

		case 0:
			return;

		case 1:
			cout << "Testowanie...";

			while (plikWejsciowy.good()) 
			{
				plikWejsciowy >> wartosc;
				czas.czasStart();
				tablica.Dodaj_Na_Pocz¹tek(wartosc);
				czas.czasStop();
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			tablica.Pokaz();

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 2:
			cout << "############################";

			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Dodaj_Na_Koniec(wartosc);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 3:
			cout << "############################";

			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Dodaj(wartosc, rand() % tablica.roz_Tab);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 4:
			cout << "############################";

			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				tablica.Dodaj_Na_Pocz¹tek(wartosc);
			}
			while (tablica.roz_Tab != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Usun_Pierwszy();
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 5:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				tablica.Dodaj_Na_Pocz¹tek(wartosc);
			}
			while (tablica.roz_Tab != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Usun_Ostatni();
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 6:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				tablica.Dodaj_Na_Pocz¹tek(wartosc);
			}
			while (tablica.roz_Tab != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Usun(rand() % tablica.roz_Tab);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 7:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				tablica.Dodaj_Na_Pocz¹tek(wartosc);
			}

			for (int i = 0; i < tablica.roz_Tab; i++) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				tablica.Sprawdz(rand() % 2000000 - 1000000);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
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

void Testy::testListy() {
	srand(time(NULL));
	Czas czas;
	Lista lista;
	int wybor = 99;
	int wartosc;
	int pozycja;
	string daneWyjsciowe;
	string daneWejsciowe;
	ofstream plikWyjsciowy;
	ifstream plikWejsciowy;


	while (wybor != 0) {
		cout << "Wybierz funkcjê listy:" << endl;
		cout << "    1. Dodaj na pocz¹tek" << endl;
		cout << "    2. Dodaj na koniec" << endl;
		cout << "    3. Dodaj gdziekolwiek" << endl;
		cout << "    4. Usuñ pierwszy" << endl;
		cout << "    5. Usuñ ostatni" << endl;
		cout << "    6. Usuñ którykolwiek" << endl;
		cout << "    7. Wyszukaj element" << endl;
		cout << "    8. Wydrukuj listê" << endl;
		cout << "    0. Wyjœcie" << endl << endl;
		cout << "Wybór: ";
		cin >> wybor;

		//Zamknij, je¿eli wybrano 0
		if (wybor == 0) return;

		cout << "Plik zawieraj¹cy dane wejœciowe: ";
		cin >> daneWejsciowe;
		cout << "Plik z wynikami testu: ";
		cin >> daneWyjsciowe;


		//Otwórz pliki
		plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wejœcie/" + daneWejsciowe);
		plikWyjsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wyjœcie/Lista/" + daneWyjsciowe, fstream::out);
		//Sprawd¿ czy plik jest otwarty poprawnie
		if (plikWejsciowy.is_open()) {
			cout << "Otwarto plik " << daneWejsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
			return;
		}

		if (plikWyjsciowy.is_open()) {
			cout << "Otwarto plik " << daneWyjsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
			return;
		}

		switch (wybor) {
		default:
			cout << "B³êdny wybór!" << endl;
			break;

		case 0:
			break;

		case 1:
			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Dodaj_Na_Poczatek(wartosc);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 2:
			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Dodaj_Na_Koniec(wartosc);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 3:
			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;

				if (lista.rozmiar == 0) {
					czas.czasStart();
					lista.Dodaj(wartosc, 0);
					czas.czasStop();
				}
				else {
					czas.czasStart();
					lista.Dodaj(wartosc, 1);
					czas.czasStop();
				}
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 4:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				lista.Dodaj_Na_Poczatek(wartosc);
			}
			while (lista.rozmiar != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Usun_Pierwszy();
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 5:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				lista.Dodaj_Na_Poczatek(wartosc);
			}
			while (lista.rozmiar != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Usun_Ostatni();
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 6:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				lista.Dodaj_Na_Poczatek(wartosc);
			}
			while (lista.rozmiar != 0) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Usun(rand() % lista.rozmiar);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 7:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				lista.Dodaj_Na_Poczatek(wartosc);
			}

			for (int i = 0; i < lista.rozmiar; i++) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				lista.Sprawdz(rand() % 2000000 - 1000000);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
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

void Testy::testKopca() {
	srand(time(NULL));
	Czas czas;
	Kopiec kopiec;
	int wybor = 99;
	int wartosc;
	string daneWyjsciowe;
	string daneWejsciowe;
	ofstream plikWyjsciowy;
	ifstream plikWejsciowy;

	while (wybor != 0) {
		cout << "Wybierz funkcjê Kopca:" << endl;
		cout << "    1. Dodaj" << endl;
		cout << "    2. Usuñ" << endl;
		cout << "    3. Wyszukaj" << endl;
		cout << "    4. Wydrukuj kopiec" << endl;
		cout << "    0. Wyjœcie" << endl << endl;
		cout << "Wybór: ";
		cin >> wybor;

		//Zamknij, je¿eli wybrano 0
		if (wybor == 0) return;

		cout << "Plik zawieraj¹cy dane wejœciowe: ";
		cin >> daneWejsciowe;
		cout << "Plik z wynikami testu: ";
		cin >> daneWyjsciowe;


		//Otwórz pliki
		plikWejsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wejœcie/" + daneWejsciowe);
		plikWyjsciowy.open("C:/Users/Kacper/Desktop/PROJEKTY/SDiZO/PROJEKT 1/Wyjœcie/Kopiec/" + daneWyjsciowe, fstream::out);
		//Sprawd¿ czy plik jest otwarty poprawnie
		if (plikWejsciowy.is_open()) {
			cout << "Otwarto plik " << daneWejsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
			return;
		}

		if (plikWyjsciowy.is_open()) {
			cout << "Otwarto plik " << daneWyjsciowe << endl;
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
			return;
		}

		switch (wybor) {
		default:
			cout << "B³êdny wybór!" << endl;
			break;

		case 0:
			break;

		case 1:
			while (plikWejsciowy.good()) {
				//Wczytaj wartoœæ z pliku
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				kopiec.Dodaj(wartosc);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 2:


			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				kopiec.Usun(wartosc);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
			break;

		case 3:
			//Wype³nij tablicê wartoœciami
			while (plikWejsciowy.good()) {
				plikWejsciowy >> wartosc;
				kopiec.Dodaj(wartosc);
			}

			for (int i = 0; i < kopiec.rozmiar; i++) {
				//Wykonaj funkcjê z pomiarem
				czas.czasStart();
				kopiec.Sprawdz(rand() % 2000000 - 1000000);
				czas.czasStop();
				//Zapisz do pliku wynik pomiaru
				plikWyjsciowy << czas.czasWykonania() << endl;
			}

			//Zamknij oba pliki
			plikWejsciowy.close();
			plikWyjsciowy.close();
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

