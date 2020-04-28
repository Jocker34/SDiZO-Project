#pragma once

#include "stdafx.h"
#include "Elementy_Listy.h"
#include <iostream>

class Lista
{
public:
	Lista();
	~Lista();

	int rozmiar;


	Elementy_Listy *pierwszyElement;
	Elementy_Listy *ostatniElement;
	Elementy_Listy *aktualnyElement;

	void Dodaj_Na_Poczatek(int wartosc);
	void Dodaj(int wartosc, int pozycja);
	void Dodaj_Na_Koniec(int wartosc);

	void Usun_Pierwszy();
	void Usun_Ostatni();
	void Usun(int);

	bool Sprawdz(int wartosc);
	void Pokaz();
};

