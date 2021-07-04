#include "tablica.h"
#include <iostream>
#include <cstdlib>
#include "parametry_konkretnych_klockow.h"
#include "funkcje.hpp"
#include "gra.h"
#include "gracz.h"
#include <conio.h>
#include <Windows.h>  //bibl do bufora
#include <cstdlib> //losowosc
#include <time.h>  // wymagana do czasu  
#include <cstring>
#include <string>
using namespace std;
//w pliku są tylko metody obsługujące zmienne. Pozostałe metody są w oddzielnych plikachq

tablica::tablica()//konstruktor
{
	wsk = &tabl[0]; //wskaźnik na zerowy element tablicy
}

tablica::~tablica()//destruktor
{
}
// metoda zwraca element tablicy tabl o podanym w argumencie indeksie
char tablica::pobierz_element(int id)
{
	return tabl[id];
}
// metoda ustawia wartość zmiennej tablicy tabl o podanym indeksie
void tablica::ustaw_element(int id, char zmiana)
{
	tabl[id] = zmiana;
}




