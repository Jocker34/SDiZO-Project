#pragma once
class Tablica
{
public:

	// ZMIENNE
	int *wsk_Head;
	int roz_Tab;


	//METODY
	Tablica();
	~Tablica();

	void Dodaj_Na_Pocz¹tek(int);
	void Dodaj_Na_Koniec(int wartosc);
	void Dodaj(int wartosc, int pozycja);
	void Usun_Pierwszy();
	void Usun_Ostatni();
	void Usun(int pozycja);
	bool Sprawdz(int wartosc);
	void Pokaz();
};

