#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;

////////////////////////////////////////////////////////////////
//funkcja dodaj¹ca wynik do pliku
void gracz::dodaj_wynik_do_pliku(gracz* jakis_gracz)
{
	fstream plik_wynikow;//zmienna strumienia pliku
		plik_wynikow.open("plik_wynikow.bin", ios::app | ios::binary);//otwieranie pliku binarnego w trybie do zapisu na koñcu pliku
		if (plik_wynikow.good() == false)
		{
			cout <<endl<< "brakuje pliku";
			_getch();
			exit(0);
		}
		else
		{
			plik_wynikow.write((char*)jakis_gracz, sizeof(gracz));//zapis obiektu do pliku
			plik_wynikow.clear();
			plik_wynikow.close(); //zamykanie pliku
			jakis_gracz->sortuj();//wywo³anie funkcji sortuj¹cej wyniki
			jakis_gracz->zmien_wynik(0);

		}
	

	
	
}