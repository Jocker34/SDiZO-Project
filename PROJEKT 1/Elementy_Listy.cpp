#include "stdafx.h"
#include "Elementy_Listy.h"


Elementy_Listy::Elementy_Listy()
{
}

Elementy_Listy::~Elementy_Listy()
{
}





Elementy_Listy::Elementy_Listy(int wartosc, Elementy_Listy *nastepny, Elementy_Listy *poprzedni) {

	Elementy_Listy::wartosc = wartosc;
	Elementy_Listy::nastepny = nastepny;
	Elementy_Listy::poprzedni = poprzedni;

}