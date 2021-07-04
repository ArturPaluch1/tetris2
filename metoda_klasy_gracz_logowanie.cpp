#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
// funkcja logowania gracza
int gracz::logowanie(gracz* jakis_gracz)
{
	int i = 0;
	char przycisk;
	string haslo, nick;
	while (1)
	{
		cout << endl << "logowanie" << endl << "Podaj nick: ";
		cin.sync();
		getline(cin , nick);
		cout << "Podaj haslo: ";
		while (i < 20)
		{
			przycisk = _getch();
			if (i == 0 && przycisk == 13)
			{
				cout << endl<<"Wpisz haslo";
				_getch();
				return 0;
			}
			else
			{
				if (przycisk == 13)//jesli enter
					break;
				else
				{
					cout << "*";
					haslo = haslo + (char)przycisk; // powiêksza ³añcuch has³a o kolejny znak
					i++;
				}
			}

		}
		fstream plik_graczy; //tworzenie zmiennej strumienia dla pliku
		plik_graczy.open("plik_graczy.bin", ios::in | ios::binary); //otwieranie pliku w trybie bin. do odczytu
		if (plik_graczy.good() == false) //b³¹d odczytu
		{
			cout <<endl<<"Brak graczy. Stworz najpierw gracza.";
			_getch();
			system("cls");
			wyswietl_intro(1);
			return 0;;
		}
		else
		{
			while (!plik_graczy.eof()) //do koñca pliku
			{
					if (nick == jakis_gracz->nick && haslo == jakis_gracz->haslo) //sprawdzanie czy w pliku znajduje siê obiekt o wplisanym nicku i haœle
					{
						jakis_gracz->nick = nick;
						jakis_gracz->haslo = haslo;
						return 1;
						
					}
				plik_graczy.read((char*)jakis_gracz, sizeof(gracz)); //wczytywanie obiektu z pliku
			}
			cout << "Zly nick lub haslo";
			_getch();
			system("cls");
			wyswietl_intro(1);
			//zamykanie pliku
			plik_graczy.close();
			plik_graczy.clear();
			return 0; //wracanie do menu wyboru opcji
		}
	}
}