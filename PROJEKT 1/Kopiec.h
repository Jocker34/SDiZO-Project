#pragma once
class Kopiec
{
public:
	Kopiec();
	~Kopiec();

	int *Tab;
	unsigned int rozmiar;

	// OPERACJE
	void Dodaj(int);
	void Usun(int);

	// POMOCNICZE 
	bool Sprawdz(int);
	void Popraw();
	void Pokaz();


};

