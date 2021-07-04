#include "tablica.h"
#include <iostream>
#include <cstdlib>
#include "parametry_konkretnych_klockow.h"
#include "funkcje.hpp"
#include "gra.h"
#include "gracz.h"
#include <conio.h>
#include <Windows.h>  //bibl do bufora
#include <cstdlib> //losowosc
#include <time.h>  // wymagana do czasu  
#include <cstring>
#include <string>
using namespace std;

//////////////////////////////////////,
// metoda sprawdza czy z1 i z2 podane w argumentach s¹ na tej samej lini. Sprawdzane s¹ 2 kolejne zX
int tablica::sprawdzaj_czy_ta_sama_linia(int z1, int z2)
{
	if (z2 - z1 == 0 || z2 - z1 == 1)// ==0 sa te same  ==1 s¹ od siebie oddalone o 1 czyli w poziomie
	{
		return 1;
	}
	else return 0;
}



