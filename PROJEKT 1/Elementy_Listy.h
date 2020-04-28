#pragma once
class Elementy_Listy
{
public:


	Elementy_Listy *nastepny;
	Elementy_Listy *poprzedni;
	int wartosc;

	Elementy_Listy(int, Elementy_Listy *, Elementy_Listy *);

	Elementy_Listy();
	~Elementy_Listy();
};

