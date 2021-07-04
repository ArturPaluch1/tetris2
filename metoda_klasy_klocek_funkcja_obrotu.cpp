#include "klocek.h"
#include"tablica.h"

//////////////////////////////////////////////////////////////////////////
// metoda obraca klockiem i aktualizuje tablicê
klocek klocek::funkcja_obrotu(tablica *jakas_tablica, klocek *klocek_obecny, klocek* tab_klocek[])
{
	char a = 219;//kszta³t klocka

	if (//jeœli zmienna w jakas_tablica o indeksie  zmiennej zX w tablicy klocków (tab_klocek) o indeksie klocek_obecny->zm powiêkszona/zmniejszona o aktualne zmienne x i y obiektu klocek_obecny jest równa ' ' lub wartoœci zmiennej kolor obiektu klocek_obecny
		//(jeœli miejsce w tablicy o indeksie zX klocka na który aktualny klocek ma siê zamieniæ jest pusty lub zajety przez aktualny klocek)
		(jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == ' ' ||
			jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == klocek_obecny->pobierz_kolor())
		&&
		(jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == ' ' ||
			jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == klocek_obecny->pobierz_kolor())
		&&
		(jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == ' ' ||
			jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == klocek_obecny->pobierz_kolor())
		&&
		(jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == ' ' ||
			jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == klocek_obecny->pobierz_kolor())
		&&
		(jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == ' ' ||
			jakas_tablica->pobierz_element(tab_klocek[klocek_obecny->pobierz_zm()]->pobierz_z(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()) == klocek_obecny->pobierz_kolor())
		)
	{
		//zerowanie aktualnego po³o¿enia klocka w tablicy
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(0), ' ');
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(1), ' ');
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(2), ' ');
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(3), ' ');
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(4), ' ');
		//tworzenie kopii klocka na który ma siê zamieniæ klocek obecny
		klocek *tymczasowy = new klocek(*tab_klocek[klocek_obecny->pobierz_zm()]);
		//przypisywanie nowemu klockowi zmiennych x i y klocka obecnego
		tymczasowy->ustaw_x(klocek_obecny->pobierz_x());
		tymczasowy->ustaw_y(klocek_obecny->pobierz_y());
		klocek_obecny = tymczasowy;
		//aktualizacja tablicy. 
		// zmienna elementu tablicy o indeksie zX+y+x jest zamieniana na wartoœæ zmiennej kolor obiektu klocek_obecny
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(0) + klocek_obecny->pobierz_y() + klocek_obecny->pobierz_x(), klocek_obecny->pobierz_kolor());
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(1) + klocek_obecny->pobierz_y() + klocek_obecny->pobierz_x(), klocek_obecny->pobierz_kolor());
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(2) + klocek_obecny->pobierz_y() + klocek_obecny->pobierz_x(), klocek_obecny->pobierz_kolor());
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(3) + klocek_obecny->pobierz_y() + klocek_obecny->pobierz_x(), klocek_obecny->pobierz_kolor());
		jakas_tablica->ustaw_element(klocek_obecny->pobierz_z(4) + klocek_obecny->pobierz_y() + klocek_obecny->pobierz_x(), klocek_obecny->pobierz_kolor());
		//aktualizacja zmiennych z o zmienne x i y
		klocek_obecny->ustaw_z(
			klocek_obecny->pobierz_z(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_z(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_z(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_z(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_z(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()
		);
		//aktualizacja zmiennych n o zmienne x i y
		klocek_obecny->ustaw_n(
			klocek_obecny->pobierz_n(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_n(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_n(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_n(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_n(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()
		);
		//aktualizacja zmiennych l o zmienne x i y
		klocek_obecny->ustaw_l(
			klocek_obecny->pobierz_l(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_l(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_l(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_l(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_l(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()
		);
		//aktualizacja zmiennych r o zmienne x i y
		klocek_obecny->ustaw_r(
			klocek_obecny->pobierz_r(0) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_r(1) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_r(2) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_r(3) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y(),
			klocek_obecny->pobierz_r(4) + klocek_obecny->pobierz_x() + klocek_obecny->pobierz_y()
		); 
	}
	else
	{}
	return *klocek_obecny;
}