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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// metoda zliczajaca punkty

void tablica::czy_punkt(tablica *jakas_tablica, klocek *jakis_klocek, gracz* jakis_gracz)
//funkcja sprawdza kolejne z czy są w tej samej linii. Póki są, powtarza dla kolejnych z. Jeśli nie są sprawdza linię dla ostatniego z w tej samej linii
//jeśli linia zapełniona to wywołuje funkcję opóść,która począwszy od najbardziej na prawo elementu od zX aż do początku pola gry nadpisuje kolejne elementy elementami o indeksach i-12
//np  tab[100] nadpisuje elementem tab[88], czyli poziom wyżej, następnie tab[99] elementem  tab[87] itd.
{
	if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(0), jakis_klocek->pobierz_z(1)) == 1)//<< równe sa 01
	{
		if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_z(2)) == 1)  //<< równe sa 012
		{
			if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_z(3)) == 1) //<< równe sa 0123
			{
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 01234
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1) //=1 czyli zapelniony pasek
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(0), jakis_gracz);  // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodać 12
				}
				else  //<< równe sa 0123
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);  //funkcja ma oposcic klocki powyzej. czyli zmieniæ indeksy w tablicy o + (a+b)*12
				}
			}
			else  //<< równe sa 012
			{
				if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
					funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(2), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 34
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
				}
				else  //<< 3 i 4 sa rozne
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
		}
		else  //<< równe sa 01
		{
			if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
				funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(1), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
			if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_z(3)) == 1) //<< równe sa 23
			{
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 234
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< równe sa 23
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
			else  //<< 2 jest rozne
			{
				if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
					funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(2), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 34
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< 3 i 4 sa rozne
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
		}
	}
	else  //<< 0 i 1 sa rozne
	{
		if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(0), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
			funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(0), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
		if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_z(2)) == 1)  //<< równe sa 12
		{
			if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_z(3)) == 1) //<< równe sa 123
			{
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 1234
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)

						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< równe sa 123
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
			else  //<< równe sa 12 
			{
				if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
					funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(2), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 34
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< 3 i 4 rozne
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
		}
		else  //<< 12 sa rozne
		{
			if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
				funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(1), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
			if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_z(3)) == 1) //<< równe sa 23
			{
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 234
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< rowne sa 23. 4 jest rozne
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
			else  //<< 2 jest rozne od 3 obnizanie od 2
			{
				if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_y()) == 1) //=1 czyli zape³niony pasek
					funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(2), jakis_gracz); // funkcja ma oposcic klocki powyzej o 1 nizej czyli do kazdego indeksu (poza zerem) dodaæ 12
				if (sprawdzaj_czy_ta_sama_linia(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_z(4)) == 1) //<< równe sa 34
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
				else  //<< 3 i 4 sa rozne
				{
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_y()) == 1)  //tu sprawdza oba od razu bo zosta³y   tylko 2 poziomy y np kwadrat
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(3), jakis_gracz);
					if (funkcja_sprawdzaj_linie(jakas_tablica, jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_y()) == 1)
						funkcja_oposc(jakas_tablica, jakis_klocek->pobierz_x(), jakis_klocek->pobierz_z(4), jakis_gracz);
				}
			}
		}
	}

}