
#include <iostream>
#include <stdio.h>
#include "gra.h"
#include <time.h>  // wymagana do czasu
#include <conio.h>  //wymagana do getch
#include "parametry_konkretnych_klockow.h"
#include "funkcje.hpp"
#include "tablica.h"
#include "intro.h"
#include "gracz.h"
#include <cstdlib> //losowosc
#include<Windows.h>  //bibl do bufora
using namespace std;
int rozpocznij = 0;  //0 utrzymuje w pêtli menu, 1 rozpoczyna i utrzymuje pêtlê gry, 2 dodaje wynik do pliku

void gra()
{
	gracz* zalogowany = new gracz;
	while (1)
	{


		char ruch; //zmienna przechowuje naciœniêty przycisk
		int u = 0; // numer indeksu tablicy wylosowanych
		int tablica_wylosowanych[999]; // tablica z id kolejnych klocków do wyœwietlenia. 
		losuj(tablica_wylosowanych);  // wype³nianie tablicy cyfr losowych
		tablica* tab; tab = new tablica;  // tworzenie obiektu tablicy
		tab->twoz_tabele();

		////////////////////////////////////////////////////////////////////////////
		// tworzenie obiektów konkretnych klocków
		S_poziomo* temp_S_poziomo; temp_S_poziomo = new S_poziomo;
		S_pionowo* temp_S_pionowo; temp_S_pionowo = new S_pionowo;
		palka_poziomo* temp_palka_poziomo; temp_palka_poziomo = new palka_poziomo;
		palka_pionowo* temp_palka_pionowo; temp_palka_pionowo = new palka_pionowo;
		kwadrat* temp_kwadrat; temp_kwadrat = new kwadrat;
		piramida_up* temp_piramida_up; temp_piramida_up = new piramida_up;
		piramida_down* temp_piramida_down; temp_piramida_down = new piramida_down;
		piramida_right* temp_piramida_right; temp_piramida_right = new piramida_right;
		piramida_left* temp_piramida_left; temp_piramida_left = new piramida_left;
		L_left* temp_L_left; temp_L_left = new L_left;
		L_right* temp_L_right; temp_L_right = new L_right;
		L_down* temp_L_down; temp_L_down = new L_down;
		L_up* temp_L_up; temp_L_up = new L_up;
		Odwr_L_up* temp_Odwr_L_up; temp_Odwr_L_up = new Odwr_L_up;
		Odwr_L_left* temp_Odwr_L_left; temp_Odwr_L_left = new Odwr_L_left;
		Odwr_L_right* temp_Odwr_L_right; temp_Odwr_L_right = new Odwr_L_right;
		Odwr_L_down* temp_Odwr_L_down; temp_Odwr_L_down = new Odwr_L_down;
		Z_poziomo* temp_Z_poziomo; temp_Z_poziomo = new Z_poziomo;
		Z_pionowo* temp_Z_pionowo; temp_Z_pionowo = new Z_pionowo;
		////////////////////////////////////////////////////////////////////////////////////////////////////

		klocek* tab_klocek[19] //tablica obiektów klasy klocek. Liczby w komentarzu to id klocka. 
			= {
			temp_palka_pionowo,//0
			temp_kwadrat,//1
			temp_piramida_right,//2
			temp_L_right,//3
			temp_Odwr_L_right,//4
			temp_Z_pionowo,//5
			temp_S_pionowo,//6
			temp_palka_poziomo,//7
			temp_piramida_up,//8
			temp_piramida_down,//9
			temp_piramida_left,//10
			temp_L_left,//11
			temp_L_down,//12
			temp_L_up,//13
			temp_Odwr_L_up,//14
			temp_Odwr_L_left,//15
			temp_Odwr_L_down,//16
			temp_Z_poziomo,//17
			temp_S_poziomo// 18
		};

		////////////////////////////////////////////////////////////////////////////////////////////////////	

		rozpocznij = zalogowany->dolaczanie_do_gry(zalogowany); //proba zmiany rozpocznij, ¿eby wyœæ z pêtli i zacz¹æ grê

		while (1)
		{
			if (rozpocznij == 1)
			{
				int ile = 0; //zmienna do zmiany szybkoœci opuszczania klocków
				int wynik_obnizania;
				klocek* temp = new klocek(*tab_klocek[tablica_wylosowanych[u]]); //uruchomienie konstruktora kopiuj¹cego. Tworzenie  kopii obiektu z tablicy tab_klocek o indeksie wartoœci zmiennej tablicy_wylosowanych o indeksie u.
				while (1)
				{
					ile = czekaj(50, ile);  //oczekiwanie 50 ms.
					if (ile == 5)// jeœli odczekano 5* 50 ms
					{
						ile = 0; //zerowanie licnzika
						wynik_obnizania = temp->obnizaj(tab, temp, tab_klocek, zalogowany, tablica_wylosowanych, u);

						if (wynik_obnizania == 0) //uruchomienie funkcji obni¿aj¹cej klocek o 1 liniê
						{
							tab->wyswietlaj(); //wyœwietlanie tablicy

							continue;
						}
						else
						{
							if (wynik_obnizania == 1)
							{
								tab->wyswietlaj(); //wyœwietlanie tablicy
								break;
							}
							else  //=2
							{
								//	zalogowany->dodaj_wynik_do_pliku(zalogowany);
								rozpocznij = 2;
								break;
								
							}

						}
					}
					else
					{
						if (_kbhit() == 1) //jeœli naciœniêty klawisz
						{
							ruch = _getch(); //pobierz znak z bufora
							FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //czyœci bufor
							if (ruch == 80) //jeœli strza³ka w dó³              
							{
								if (temp->obnizaj_do_konca(tab, temp, tab_klocek, zalogowany, tablica_wylosowanych) == 1)
									//klocek zosta³ obni¿ony do koñca, a gracz zdoby³ punkt. A gracz nei zakoñczy³ gry
								{
									tab->wyswietlaj(); //wyœwietlanie tablicy
									break;//po break zwiêkszany jest u.

								}
								else//klocek opuszczony do koñca, ale gracz zakoñczy³ grê
								{
									rozpocznij = 2;
												
									break;
								}
							}
							else
							{
								funkcja_obslugi_klawiatury(u, ruch, tab, temp, tab_klocek, zalogowany, tablica_wylosowanych, u); // uruchamianie funkcji obs³uguj¹cej przyciski
								tab->wyswietlaj();//wyœwietlanie tablicy



							}
						}
					}

				}
				if (u == 997)//jeœli koniec tablicy wylosowanych indeks siê zeruje i tablica wylosowanych jest przeszukiwana od nowa
					u = 0;
				else
					u++;

			}
			else
			{
				break;
			}
			

			if (rozpocznij == 2)
			{
				zalogowany->dodaj_wynik_do_pliku(zalogowany);
				rozpocznij = 0;
				break;

			}
			else
			{
				continue;
			}

		}



	}




}



