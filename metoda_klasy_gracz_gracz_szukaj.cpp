#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// funkcja wyszukiwania gracza o danym nicku
int gracz::gracz_szukaj(string szukany_nick)
{
	int z = 0;
	fstream plik_graczy;
	gracz *y = new gracz; //obiekt typu gracz
	plik_graczy.open("plik_graczy.bin", ios::in | ios::binary); //otwieranie pliku bin. w trybie do odczytu
	if (plik_graczy.good() == false) //b³¹d odczytu
	{
		cout << "Brak pliku z danymi";
	}
	else
	{
		while (!plik_graczy.eof()) //do koñca pliku
		{
			plik_graczy.read((char*)y, sizeof(gracz)); //pobiera obiekt gracz
			if (y->nick != szukany_nick)//jeœli nick w pliku nie jest taki sam jak nick do wyszukania wraca do pêtli i pobiera nastêpny obiekt
			{
			}
			else
			{
				z = 1;
				break;
			}
		}
		//zamykanie pliku
		plik_graczy.close();
		plik_graczy.clear();
	}
	return z; //zwracanie zmiennej okreœlaj¹cej czy znaleziono czy nie
}