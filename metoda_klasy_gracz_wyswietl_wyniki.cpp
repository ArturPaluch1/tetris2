#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja wyœwietlaj¹ca wyniki
void gracz::wyswietl_wyniki(gracz *zalogowany)
{	
	gracz *y;
	y = new gracz;
	fstream plik_wynikow;//zmienna strumienia pliku
	plik_wynikow.open("plik_wynikow.bin", ios::in | ios::binary); //otwieranie pliku binarnego w tryb. do odczytu
	if (plik_wynikow.good() == false)
	{
		cout <<endl<< "Brak pliku z danymi";
		_getch();
		system("cls");
		wyswietl_intro(1);
		//dolaczanie_do_gry(zalogowany);//powrót do menu wyborów
	}

	else
	{
		cout << endl << '\t' << '\t' << '\t' << "NAJLEPSZE 100 WYNIKOW TO :" << endl;
		while (!plik_wynikow.eof()) //do koñca pliku
		{
			
			if (y->wynik != 0)
			{
				cout << endl << '\t' << '\t' << '\t' << y->nick << " - " << y->wynik;
			}
			plik_wynikow.read((char*)y, sizeof(gracz));
			
		}
	}
}