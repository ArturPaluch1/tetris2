#include "gracz.h"
#include <fstream>
#include <stdio.h>
#include<cstring>
#include <string>
#include <iostream>
#include <cstdlib>
#include "gra.h"

using namespace std;
//w pliku s¹ tylko lista inicjalizacyjna i metody obs³ugi zmiennych klasy. Reszta metod w oddzielnych plikach
gracz::gracz() :nick(""), haslo(""), wynik(0)// lista inicjalizacyjna
{}
gracz::~gracz() //destruktor
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// funkcja ustawiaj¹ca zmienn¹ wynik
void gracz::zmien_wynik(int k)
{	
k==0?wynik=0:wynik=wynik+k;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funkcja pobiera wynik gracza
int gracz::pobierz_wynik()
{
	return wynik;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gracz::ustaw_nick(string twoj_nick)
{
	nick = twoj_nick;
}

