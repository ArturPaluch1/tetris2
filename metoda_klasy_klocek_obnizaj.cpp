#include "klocek.h"
#include"tablica.h"
# include "gra.h"
//////////////////////////////////////////////////////////////////////////////////////////
// metoda obni¿aj¹ca pozycjê klocka w tablicy. U¿ywana tylko przy obni¿aniu co 250 ms
int klocek::obnizaj(tablica *jakas_tablica, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[], int u)
{
	int i;
	if (//jeœli najni¿sze czêœci klocka powiêkszone o 12, czyli jeœli poziom ni¿ej NIE jest pusto
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(0) + 12) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(1) + 12) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(2) + 12) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(3) + 12) != ' ' ||
		jakas_tablica->pobierz_element(jakis_klocek->pobierz_n(4) + 12) != ' '
		)
	{ //sprawdza czy nast¹pi³ koniec gry. Jeœli nie, sprawdza czydodaæ punkt. Wychodzi z funkcji
		for (i = 97; i < 107; i++) //górna granica gdzie gra siê nie koñczy
		{
			if (jakas_tablica->pobierz_element(i) != ' ')//jeœli element tablicy o indeksie i jest zajêty
			{
				system("cls");
				wyswietl_intro(1);
				cout <<endl<< '\t' << '\t' << '\t' << "koniec gry" << endl;
				cout << '\t' << '\t' << '\t' << "Twoj wynik to: " << zalogowany->pobierz_wynik()<<endl;

				return 2;
			}
		}
		jakas_tablica->czy_punkt(jakas_tablica, jakis_klocek, zalogowany); //sprawdza czy dodaæ punkt graczowi
		return 1;
	}
	else  //poni¿ej klocka jest puste miejsce
	{
		//zerowanie aktualnej pozycji klocka w tablicy
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3), ' ');
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4), ' ');

		// zamienia parametry klocka w klasie o +12 = 1 poziom ni¿ej
		jakis_klocek->ustaw_z(
			jakis_klocek->pobierz_z(0) + 12,
			jakis_klocek->pobierz_z(1) + 12,
			jakis_klocek->pobierz_z(2) + 12,
			jakis_klocek->pobierz_z(3) + 12,
			jakis_klocek->pobierz_z(4) + 12);

		//zapisuje w tablicy o indeksach zX zmienn¹ kolor klocka o nowych parametrach
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(0), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(1), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(2), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(3), jakis_klocek->pobierz_kolor());
		jakas_tablica->ustaw_element(jakis_klocek->pobierz_z(4), jakis_klocek->pobierz_kolor());
		// zamienienia parametry njani¿szych czêœci klocka o +12
		jakis_klocek->ustaw_n(
			jakis_klocek->pobierz_n(0) + 12,
			jakis_klocek->pobierz_n(1) + 12,
			jakis_klocek->pobierz_n(2) + 12,
			jakis_klocek->pobierz_n(3) + 12,
			jakis_klocek->pobierz_n(4) + 12
		);

		// zamienienia parametry lewych czêœci klocka o +12
		jakis_klocek->ustaw_l(
			jakis_klocek->pobierz_l(0) + 12,
			jakis_klocek->pobierz_l(1) + 12,
			jakis_klocek->pobierz_l(2) + 12,
			jakis_klocek->pobierz_l(3) + 12,
			jakis_klocek->pobierz_l(4) + 12
		);

		// zamienienia parametry prawych czêœci klocka o +12
		jakis_klocek->ustaw_r(
			jakis_klocek->pobierz_r(0) + 12,
			jakis_klocek->pobierz_r(1) + 12,
			jakis_klocek->pobierz_r(2) + 12,
			jakis_klocek->pobierz_r(3) + 12,
			jakis_klocek->pobierz_r(4) + 12);
		// zamienienia parametr y klocka o +12
		jakis_klocek->ustaw_y(jakis_klocek->pobierz_y() + 12);

		// jeœli ta linia pusta to znaczy ¿e ca³y klocek wszed³ do tebeli i mo¿na wyswietliæ nastêpny klocek
		// Chodzi o wyœwietlanie klocka "NASTEPNY KLOCEK"
		for (i = 87; i < 93; i++)
		{
			if (jakas_tablica->pobierz_element(i) == ' ')
			{
				if (i == 92)//jeœli dosz³o do koñca
				{
					
					if (u == 997)//jeœli tablica klocków sie skoñczy³a nastêpny "NEXT" klocek bêdzie z indeksem 0
					{
						//przypisywanie do jakas_tablica o indeksie zX obiektu z tablicy tab_klocek o indeksie u zwiêkszonym o 1 (czyli nastêpnym do wyœwietlenia) wartoœci kolor
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[0]]->pobierz_z(0), tab_klocek[tablica_wylosowanych[0]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[0]]->pobierz_z(1), tab_klocek[tablica_wylosowanych[0]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[0]]->pobierz_z(2), tab_klocek[tablica_wylosowanych[0]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[0]]->pobierz_z(3), tab_klocek[tablica_wylosowanych[0]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[0]]->pobierz_z(4), tab_klocek[tablica_wylosowanych[0]]->pobierz_kolor());
					}
					else
					{
						//przypisywanie do jakas_tablica o indeksie zX obiektu z tablicy tab_klocek o indeksie u zwiêkszonym o 1 (czyli nastêpnym do wyœwietlenia) wartoœci kolor
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_z(0), tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_z(1), tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_z(2), tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_z(3), tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_kolor());
						jakas_tablica->ustaw_element(tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_z(4), tab_klocek[tablica_wylosowanych[u + 1]]->pobierz_kolor());
					}		
				}
				else
					continue;
			}
			else break;
		}
		return 0;
	}
}