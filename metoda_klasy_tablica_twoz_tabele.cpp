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

//metoda tworzy tablicê do gry
void tablica::twoz_tabele()
{
	int y = 0;
	char a = 186; // |
	char b = 205;//  -
	char c = 201; // |
	char d = 187;//  -
	char e = 200; // |
	char f = 188;//  -
	char g = 204; // |
	char h = 185;//  -
				 //przypisywanie  wartoœci w tablicy
	for (y = 12; y<336; y += 12)
	{
		ustaw_element(y, a);// |
	}
	for (y = 23; y<347; y += 12)
	{
		ustaw_element(y, a);// |
	}
	for (y = 1; y<11; y++)
	{
		ustaw_element(y, b);// -
	}
	for (y = 337; y<347; y++)
	{
		ustaw_element(y, b);// -
	}
	ustaw_element(0, c);  // -
	ustaw_element(11, d); // |
	ustaw_element(336, e);  //|
	ustaw_element(347, f);  // -

	ustaw_element(14, 'n');
	ustaw_element(15, 'a');
	ustaw_element(16, 's');
	ustaw_element(17, 't');
	ustaw_element(18, 'e');
	ustaw_element(19, 'p');
	ustaw_element(20, 'n');
	ustaw_element(21, 'y');
	ustaw_element(27, 'k');
	ustaw_element(28, 'l');
	ustaw_element(29, 'o');
	ustaw_element(30, 'c');
	ustaw_element(31, 'e');
	ustaw_element(32, 'k');

	ustaw_element(90, 32);
	ustaw_element(101, 32);
	ustaw_element(88, 32);
	ustaw_element(96, g);	// |
	ustaw_element(107, h);	// -
	for (y = 0; y<348; y++)
	{ //omijaj elementy ju¿ ustawione
		if (pobierz_element(y) == a ||
			pobierz_element(y) == b ||
			pobierz_element(y) == c ||
			pobierz_element(y) == d ||
			pobierz_element(y) == e ||
			pobierz_element(y) == f ||
			pobierz_element(y) == g ||
			pobierz_element(y) == h ||
			pobierz_element(y) == 'n' ||
			pobierz_element(y) == 'a' ||
			pobierz_element(y) == 's' ||
			pobierz_element(y) == 't' ||
			pobierz_element(y) == 'e' ||
			pobierz_element(y) == 'p' ||
			pobierz_element(y) == 'n' ||
			pobierz_element(y) == 'y' ||
			pobierz_element(y) == 'k' ||
			pobierz_element(y) == 'l' ||
			pobierz_element(y) == 'o' ||
			pobierz_element(y) == 'c' ||
			pobierz_element(y) == 'e' ||
			pobierz_element(y) == 'k'
			)
		{
			continue;
		}
		else
		{
			ustaw_element(y, 32); // spacja
		}
	}
}