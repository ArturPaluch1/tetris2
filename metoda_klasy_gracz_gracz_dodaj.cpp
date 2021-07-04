#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"
using namespace std;


///////////////////////////////////////////
// funkcja dodawania gracza
int gracz::gracz_dodaj(gracz* zalogowany)
{
	int i = 0;
	char przycisk;
	fstream plik_graczy; //tworzenie zmiennej strumienia dla pliku
	int licznik_id = 1;
	string nick, haslo;
	/////////////////////////////////////////////  nie ma pliku  ////////////////////////////////////////////////////////////
	plik_graczy.open("plik_graczy.bin", ios::in | ios::binary); // otwieranie pliku w trybie binarnym do odczytu
	if (plik_graczy.good() == false) // jeœli plik nie otworzony
	{
		cout << endl << "Podaj swoj nick ";
		cin.sync();
		getline(cin, nick);
		plik_graczy.open("plik_graczy.bin", ios::out | ios::trunc | ios::binary); // otwieranie pliku w trybie binarnym do zapisu (tworzenie pliku)
		cout << endl << "Podaj haslo (maksymalnie 20 znakow)";
		while (i < 20)
		{
			przycisk = _getch();
			if (przycisk == 13) //jeœli pobrano enter
			{
				if (i < 2)
				{
					cout << endl << "Podaj dluzsze haslo!";
					_getch();
					system("cls");
					wyswietl_intro(1);
					return 0; //wracanie do funkcji dodaj¹cej gracza
				}
				else
					break; //has³o przyjête, wychodzi z pêtli
			}

			else
			{
				if (przycisk == 32 || przycisk == 8) // porano spacjê lub backspace
				{
					cout << endl << "Spacje i backspace sa niedozwolone!";
					_getch();
					system("cls");
					wyswietl_intro(1);
					return 0;
				}
				else
				{
					cout << "*";
					haslo = haslo + (char)przycisk; // powiêksza ³añcuch has³a o kolejny znak
					i++;	
				}
			}
		}
		//przypisywanie pobranych zmiennych do obiektu
		zalogowany->nick = nick;
		zalogowany->haslo = haslo;
		zalogowany->zmien_wynik(0);
		// zapis obiektu do pliku
		plik_graczy.write((char*)zalogowany, sizeof(gracz));
		// zamykanie pliku
		plik_graczy.close();
		plik_graczy.clear();
		return 1;
	}
	else//////////////////////////////////  by³ plik  ////////////////////////////////////////////////////////////
	{
		cout << endl <<"Dodawanie gracza"<<endl<< "Podaj swoj nick ";
		cin.sync();
		getline(cin, nick);
		if (gracz_szukaj(nick) == 0)//sprawdzanie  funkcj¹ gracz_szukaj czy szukany nick nie jest juz zajêty. 0-wolny 1-zajêty
		{
			cout << "Podaj haslo (maksymalnie 20 znakow)" << endl;;
			i = 0;
			while (i < 20)
			{
				przycisk = _getch();
				if (przycisk == 13)// enter
				{
					if (i < 2)
					{
						cout << endl << "Podaj dluzsze haslo!";
						_getch();
						system("cls");
						wyswietl_intro(1);
						return 0;
					}
					else
						break;
				}
				else
				{
					if (przycisk == 32 || przycisk == 8) // porano spacjê lub backspace
					{
						cout << endl << "Spacje i backspace sa niedozwolone!";
						_getch();
						system("cls");
						wyswietl_intro(1);
						return 0;
					}
					else
					{
						cout << "*";
						haslo = haslo + przycisk; // powiêksza ³añcuch has³a o kolejny znak
						i++;
						continue;
					}
				}
			}
			plik_graczy.close();
			plik_graczy.clear();
			plik_graczy.open("plik_graczy.bin",  ios::app | ios::binary); //otwarcie pliku do zapisu na koñcu pliku
			zalogowany->nick = nick;
			zalogowany->haslo = haslo;
			zalogowany->zmien_wynik(0);
			plik_graczy.write((char*)zalogowany, sizeof(gracz)); // zapis obiektu do pliku
			system("cls");
			//zamkniêcie pliku
			plik_graczy.close();
			plik_graczy.clear();
			return 1;
		}
		else
		{
			cout << "Taki nick jest juz zajety, podaj inny";
			_getch();
			system("cls");
			wyswietl_intro(1);
			return 0;
		}
	}
	
}
