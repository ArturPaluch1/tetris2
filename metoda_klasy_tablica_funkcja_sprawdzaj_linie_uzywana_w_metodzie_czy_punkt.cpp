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


/////////////////////////////////// 
// metoda sprawdza czy linia pozioma w tablicy po po³o¿enia klocka jest zape³niona. Zwraca 1 jeœli jest 0 jeœli nie
int tablica::funkcja_sprawdzaj_linie(tablica *jakas_tablica, int z, int y)
{
	int i = 0;
	//jeœli z pobrany z obiektu klocek jest wiêkszy od y+84  (+84 bo y jest liczone od 0 a wy¿ej s¹ jeszcze znaki)
	// s¹ liczone od zera, czyli po lewej krawêdzi tablicy
	//y jest na poziomie najni¿szej czêœci klocka
	if (z>y + 84)
	{
		for (i = y +1 + 84; i<y + 11 + 84; i++)
			// od lewego, górnego rogu tablicy, powiêkszonego o 84 (do poziomu gdzie zaczyna siê operowanie klockeim) +1 bo sprawdzane jest pole gry
			//do +11 bo obszar gry ma 10 pól w poziomie
		{
			if (jakas_tablica->pobierz_element(i) != ' ') //jeœli kratka jest zajêta
			{
				continue;
			}
			else {//kratka by³a pusta, linia nie jest zajêta
				return 0;
			}
		}
		return 1;
	}
	///////////////////////////////////////////////////////
	if (z<y + 84 && (z>y - 12 + 84))
		//z jest o 1 poziom wy¿ej od y 

	{
		for (i = y - 12 + 1 + 84; i<y - 12 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 12 + 84) && (z>(y - 24 + 84)))
	{//z jest o 2 poziomy wy¿ej od y 
		for (i = y - 24 + 1 + 84; i<y - 24 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 24 + 84) && (z>(y - 36 + 84)))
	{//z jest o 3 poziomy wy¿ej od y 
		for (i = y - 36 + 1 + 84; i<y - 36 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
	///////////////////////////////////////////////////////
	if ((z<y - 36 + 84) && (z>(y - 48 + 84)))
	{//z jest o 4 poziomy wy¿ej od y 
		for (i = y - 48 + 1 + 84; i<y - 48 + 11 + 84; i++)
		{
			if (jakas_tablica->pobierz_element(i) != ' ')
			{
				continue;
			}
			else {
				return 0;
			}
			// linia gdzies pusta
		}
		return 1;
		//  linia zapelniona
	}
}