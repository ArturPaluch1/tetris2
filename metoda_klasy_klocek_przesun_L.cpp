#include "klocek.h"
#include"tablica.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  jeœli jest wolne miejsce,  metoda aktualizuje zmienne klocka zmniejszaj¹c je o 1. Aktualizuje tablicê o zmienione zmienne klocka
void klocek::przesun_L(tablica *jakas_tablica, klocek* jakis_klocek)
{
	if (
		// sprawdza czy z lewej od klocka jest pusto
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_l(0) - 1) != ' ' ||//pobiera z jakas_tablica element o indeksie  zmiennej l0 obiektu jakis_klocek i sprawdza czy jest ró¿ny od ' '
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_l(1) - 1) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_l(2) - 1) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_l(3) - 1) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_l(4) - 1) != ' '
		)
	{ //nie jest pusto, nic nie robi
	}
	else//jest pusto
	{
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0), ' ');//elementowi o indeksie zmiennej z0 z obiektu jakis_klocek przypisuje ' '  (czyœci tablice z jakis_klocek)
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4), ' ');
		//zmienia zmienne zx w jakis_klocek na o 1 mniejsze
		jakis_klocek->ustaw_z(
			jakis_klocek->pobierz_z(0) - 1,
			jakis_klocek->pobierz_z(1) - 1,
			jakis_klocek->pobierz_z(2) - 1,
			jakis_klocek->pobierz_z(3) - 1,
			jakis_klocek->pobierz_z(4) - 1
		);
		//ustawia w jakas_tablica o indeksach zmiennych zx z jakis_klocek wartoœci zmiennej kolor
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_kolor());
		//zmienia zmienne l w jakis_klocek na o 1 mniejsze
		jakis_klocek->ustaw_l(
			jakis_klocek->pobierz_l(0) - 1,
			jakis_klocek->pobierz_l(1) - 1,
			jakis_klocek->pobierz_l(2) - 1,
			jakis_klocek->pobierz_l(3) - 1,
			jakis_klocek->pobierz_l(4) - 1
		);
		//zmienia zmienne r w jakis_klocek na o 1 mniejsze
		jakis_klocek->ustaw_r(
			jakis_klocek->pobierz_r(0) - 1,
			jakis_klocek->pobierz_r(1) - 1,
			jakis_klocek->pobierz_r(2) - 1,
			jakis_klocek->pobierz_r(3) - 1,
			jakis_klocek->pobierz_r(4) - 1
		);
		//zmienia zmienne n w jakis_klocek na o 1 mniejsze
		jakis_klocek->ustaw_n(
			jakis_klocek->pobierz_n(0) - 1,
			jakis_klocek->pobierz_n(1) - 1,
			jakis_klocek->pobierz_n(2) - 1,
			jakis_klocek->pobierz_n(3) - 1,
			jakis_klocek->pobierz_n(4) - 1
		);
		//zmniejsza zmienn¹ x w jakis_klocek o 1
		jakis_klocek->ustaw_x(jakis_klocek->pobierz_x() - 1);
	}
}