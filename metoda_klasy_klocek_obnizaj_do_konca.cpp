#include "klocek.h"
#include"tablica.h"
# include "gra.h"
////////////////////////////////////////////////////////////////////////////////////
// metoda obni¿a klocek najni¿ej jak siê da
//metoda zlicza iloœæ poziomów w których pod klockeim jest pusto, nastêpnie aktualizuje tablicê
int klocek::obnizaj_do_konca(tablica *jakas_tablica, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[])
{
	int i;
	int r = 12;// zmienna zlicza iloœæ wolnych poziomów

			   //zerowanie aktualnej pozycji klocka w tablicy
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0), ' ');
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1), ' ');
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2), ' ');
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3), ' ');
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4), ' ');
	//dopóki poni¿ej jest wolne miejsce zwiêkszaj r
	while (jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(0) + r) == ' ' &&
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(1) + r) == ' '  &&
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(2) + r) == ' ' &&
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(3) + r) == ' ' &&
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(4) + r) == ' ')
	{
		r = r + 12;
		continue;
	}
	r = r - 12;
	//aktualizowanie  zmiennych w tablicy powiêkszonych o r
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0) + r, jakis_klocek->pobierz_kolor());
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1) + r, jakis_klocek->pobierz_kolor());
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2) + r, jakis_klocek->pobierz_kolor());
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3) + r, jakis_klocek->pobierz_kolor());
	jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4) + r, jakis_klocek->pobierz_kolor());
	//aktualizowanie  zmiennych klocka o r
	jakis_klocek->ustaw_n(
		jakis_klocek->pobierz_n(0) + r,
		jakis_klocek->pobierz_n(1) + r,
		jakis_klocek->pobierz_n(2) + r,
		jakis_klocek->pobierz_n(3) + r,
		jakis_klocek->pobierz_n(4) + r
	);

	jakis_klocek->ustaw_z(
		jakis_klocek->pobierz_z(0) + r,
		jakis_klocek->pobierz_z(1) + r,
		jakis_klocek->pobierz_z(2) + r,
		jakis_klocek->pobierz_z(3) + r,
		jakis_klocek->pobierz_z(4) + r);
	jakis_klocek->ustaw_y(jakis_klocek->pobierz_y() + r);

	for (i = 97; i < 107; i++) //sprawdzanie linii do której jest kontynuowana gra
	{
		if (jakas_tablica->pobierz_element(i) != ' ') //jeœli zajête
		{
			system("cls");
			wyswietl_intro(1);
			cout << endl<<'\t' << '\t' << '\t' << "koniec gry" << endl;
			cout << '\t' << '\t' << '\t' << "Twoj wynik to: " << zalogowany->pobierz_wynik()<<endl;
	//		zalogowany->dodaj_wynik_do_pliku(zalogowany);
			return 2;	
		}
		else
		{	
		}
	}
	// klocek nie wyszed³ poza dozwolony obszar. Sprawdzanie czy dodaæ punkt
	jakas_tablica->czy_punkt(jakas_tablica, jakis_klocek, zalogowany);
	return 1;
	}
	
	
