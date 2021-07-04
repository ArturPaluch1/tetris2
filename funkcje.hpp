
#pragma once
#include <iostream>
#include <cstdlib>
#include "parametry_konkretnych_klockow.h"
#include "gracz.h"
#include <conio.h>
#include<Windows.h>  //bibl do bufora
#include <cstdlib> //losowosc
#include <time.h>  // wymagana do czasu
#include "tablica.h"

//funkcja modyfikuje parametr ile, czyli iloœæ powtórzeñ czekania (sekund/1000)sekundy, czyli sekund milisekund
int czekaj(double sekund, int&ile);
//funkcja obs³uguje klocek w odpowiedzi na naciœniêcie klawisza
void funkcja_obslugi_klawiatury(int &id, char &ruch, tablica *jakas_tablica, klocek *jakis_klocek, klocek* tablica_klocek[], gracz * zalogowany, int tablica_wylosowanych[], int u);
//funkcja losuje id kolejnych klocków do wyœwietlenia
void losuj(int tablica_wylosowanych[]);
void kasowanie_wskaznikow();


