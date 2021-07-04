#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"


using namespace std;
int zalogowany_1_inaczej0;
//////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja menu wyboru opcji
int gracz::dolaczanie_do_gry(gracz * gracz_zalogowany)
{
	while (1)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //czyszczenie bufora klawiatury

		char wybor;
		cout << endl << " N - nowy gracz" << '\t' << " L - logowanie" << '\t' << " H - highscores" << '\t' << " Q - wyjscie" << '\t' << endl;
		cout << endl << '\t' << "Podczas gry poruszasz sie strzalkami <- -> ";
		cout << endl << '\t' << "obnizasz strzalka w dol, a obracasz strzalka w gore" << endl;
		wybor = _getch();
		switch (wybor)
		{
		case 'n':zalogowany_1_inaczej0 = gracz_zalogowany->gracz_dodaj(gracz_zalogowany); //dodawanie nowego gracza
			if (zalogowany_1_inaczej0 == 1) //jeœli nick nie pusty rozpoczyna grê
			{
				return 1;
			}
			else
			{
				system("cls");
				wyswietl_intro(1);
				return 0;
			}
		case 'l':
			zalogowany_1_inaczej0 = gracz_zalogowany->logowanie(gracz_zalogowany); //logowanie do gry
			if (zalogowany_1_inaczej0 == 1) //jeœli nick nie pusty rozpoczyna grê
			{
				return 1;		
			}
			else
			{
				system("cls");
				wyswietl_intro(1);
				return 0;// ponowna próba logowania	
			}
		case'h':
			wyswietl_wyniki(gracz_zalogowany);//wyœwietlanie wyników
			_getch();
			system("cls");
			wyswietl_intro(1);
			return  0;//powrót do menu wyborów
		case 'q':
			system("cls");
			kasowanie_wskaznikow();
			wyswietl_intro(1);
			cout << endl << endl << '\t' << "Program sponsorowal \"" << "Bar Burka\"" << "- Najlepszy kebab na Slasku!";
			_getch();
			exit(0); //wyjœcie z programu
		default:
			cout << endl << "Zly klawisz";
			_getch();
			system("cls");
			wyswietl_intro(1);
			return 0;//dolaczanie_do_gry(zalogowany);//powrót do menu wyborów
		}
		
	}
	

}