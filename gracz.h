#pragma once
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>  //wymagana do getch
using namespace std;
class gracz
{
	string nick;
	string haslo;
	int  wynik;
public:
	gracz();
	~gracz();
	int gracz_dodaj(gracz* jakis_gracz);  //funkcja dodawania nowego gracza
	int gracz_szukaj(string szukany_nick);  //funkcja wyszukiwania gracza o danym nicku
	int logowanie(gracz* jakis_gracz);  //funkcja logowania
	int dolaczanie_do_gry(gracz* zalogowany);  //funkcja wyœwietla opcje do zalogowania
	void dodaj_wynik_do_pliku(gracz* jakis_gracz);  //funkcja dodawania wyniku do pliku
	void zmien_wynik(int k);  //funkcja zmienia wynik przy kasowaniu linii o wartoœæ k
	void wyswietl_wyniki(gracz * zalogowany);  //funkcja wyswietla wyniki
	int pobierz_wynik();    //funkcja pobiera wynik gracza
	void ustaw_nick(string);  //funkcja ustawia nick
	void sortuj();   //funkcja sortuje wyniki w pliku
};
