
#include <iostream>
#include <cstdlib>
#include "parametry_konkretnych_klockow.h"
#include "funkcje.hpp"
#include "gra.h"
#include "gracz.h"
#include <conio.h>
#include<Windows.h>  //bibl do bufora
#include <cstdlib> //losowosc
#include <time.h>  // wymagana do czasu  
#include <cstring>
#include <string>


tablica* tab;
int * tab_wynikow;
string*  tab_nickow;
string*  tab_hasel;

using namespace std;
//funkcja modyfikuje parametr ile, czyli iloœæ powtórzeñ czekania (sekund/1000)sekundy, czyli sekund milisekund
int czekaj(double sekund, int &ile)
{

	clock_t koniec = clock() + sekund * CLOCKS_PER_SEC / 1000;
	for (1; clock() < koniec; ) {}
	ile++;
	return ile;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja obs³uguje klocek w odpowiedzi na naciœniêcie klawisza
void funkcja_obslugi_klawiatury(int &id, char &ruch, tablica *jakas_tablica, klocek *jakis_klocek, klocek* tablica_klocek[], gracz * zalogowany, int tablica_wylosowanych[], int u)
{
	switch (ruch)
	{
	case 72://strza³ka w górê
		*jakis_klocek = jakis_klocek->funkcja_obrotu(jakas_tablica, jakis_klocek, tablica_klocek);
		break;
	case 75://strza³ka w lewo
		jakis_klocek->przesun_L(jakas_tablica, jakis_klocek);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		break;
	case 77://strza³ka w prawo
		jakis_klocek->przesun_P(jakas_tablica, jakis_klocek);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		break;
	case 'q':
		system("cls"); //czysci ekran
		kasowanie_wskaznikow();
		wyswietl_intro(1); //wyswietla intro 1- szybko
		cout << endl << endl << '\t' << "Program sponsorowal \"" << "Bar Burka\"" << "- Najlepszy kebab na Slasku!";
		_getch();
		exit(0);
	
	default: break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja losuje id kolejnych klocków do wyœwietlenia
void losuj(int tablica_wylosowanych[])
{
	srand(time(NULL));
	for (int i = 0; i < 999; i++) //losuje 1000 cyfr
	{
		tablica_wylosowanych[i] = rand() % 7;  //wpisuje do tablicy losowe cyfry z zakresu 0-6
	}
}


void kasowanie_wskaznikow()
{
	delete tab;
	delete[] tab_wynikow;
	delete[] tab_hasel;
	delete[] tab_nickow;
}










