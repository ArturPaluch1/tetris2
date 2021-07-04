#pragma once
#include "tablica.h"
#include "gracz.h"
//deklaracje  klas, ¿eby mo¿na ich by³o uzywaæ w przyjaŸniach
class tablica;
class	S_poziomo;
class	S_pionowo;
class	palka_poziomo;
class	palka_pionowo;
class	kwadrat;
class	piramida_up;
class	piramida_down;
class	piramida_right;
class	piramida_left;
class	L_left;
class	L_right;
class	L_down;
class	L_up;
class	Odwr_L_up;
class	Odwr_L_left;
class	Odwr_L_right;
class	Odwr_L_down;
class	Z_poziomo;
class	Z_pionowo;

class klocek
:public tablica
{
private:
	int y; //pionowa zmienna po³o¿enia klocka(co obni¿enie zwiêksza siê o 12, czyli d³ugoœæ tablicy w poziomie)
		   // s¹ liczone od zera, czyli po lewej krawêdzi tablicy
		   //y jest na poziomie najni¿szej czêœci klocka
	int x; //pozioma zmienna po³o¿enia klocka(zmienia siê o -1/+1 w zaleznoœci od naciœniêcia strza³ki lewo/prawo)
	int zm; // zmienna okreœla id klocka na który klocek ma siê zamieniæ po naciœniêciu strza³ki w górê
	int id; // numer identyfikacyjny klocka
	//zmienne okreœlaj¹ce uk³ad klocka w tablicy 
	//z0 najwy¿ej i najbardziej w lweo, z1 kolejny w prawo, lub jeœli nie ma to pierwszy 1 poziom ni¿ej najbardziej po lewej
	//kolejne analogicznie. Jeœli klocek ma mniej pól ni¿ jest zmiennych, to brakuj¹ce maj¹ t¹ sam¹ wartoœæ co ostatnia istniej¹ca
	int z0;
	int z1;
	int z2;
	int z3;
	int z4;
	//zmienne dolnych pól klocka. 
	//n0 - pierwsza zmienna z* od lewej, która nie ma pod sob¹ innej czêœci klocka. 
	//n1 - kolejna w prawo zmienna z* która nie ma pod sob¹ innej czêœci klocka
	//Jeœli klocek ma mniej pól ni¿ jest zmiennych, to brakuj¹ce maj¹ t¹ sam¹ wartoœæ co ostatnia istniej¹ca
	int n0;
	int n1;
	int n2;
	int n3;
	int n4;
	//zmienne okreœlaj¹ce skrajnie lewe czêœci klocka.
	//l0- z* skrajne z lewej i najwy¿ej
	//l4- z* skrajne z lewej i najni¿ej
	int l0;
	int l1;
	int l2;
	int l3;
	int l4;
	//zmienne okreœlaj¹ce skrajnie prawe czêœci klocka.
	//r0- z* skrajne z prawe i najwy¿ej
	//r4- z* skrajne z prawe i najni¿ej
	int r0;
	int r1;
	int r2;
	int r3;
	int r4;
	//zmienna okresla kolor klocka
	char kolor;
	//przyjaŸnie klasy klocek
	friend class	S_poziomo;
	friend class	S_pionowo;
	friend class	palka_poziomo;
	friend class	palka_pionowo;
	friend class	kwadrat;
	friend class	piramida_up;
	friend class	piramida_down;
	friend class	piramida_right;
	friend class	piramida_left;
	friend class	L_left;
	friend class	L_right;
	friend class	L_down;
	friend class	L_up;
	friend class	Odwr_L_up;
	friend class	Odwr_L_left;
	friend class	Odwr_L_right;
	friend class	Odwr_L_down;
	friend class	Z_poziomo;
	friend class	Z_pionowo;
public:
	klocek();
	klocek(const klocek&kopia); //konstruktor kopiuj¹cy deklaracja
	~klocek(); //destruktor deklaracja
	void ustaw_z(int, int, int, int, int);//metoda ustawia zmienn¹ z klocka. W argumentach przyjmuje wartoœci kolejnych z0-z4
	int pobierz_z(int);//metoda zwraca wartoœæ zx ( x podany w argumencie)
	void ustaw_n(int, int, int, int, int);//metoda ustawia zmienn¹ n klocka. W argumentach przyjmuje wartoœci kolejnych n0-n4
	int pobierz_n(int);//metoda zwraca wartoœæ nx ( x podany w argumencie)
	void ustaw_l(int, int, int, int, int);//metoda ustawia zmienn¹ l klocka. W argumentach przyjmuje wartoœci kolejnych l0-l4
	int pobierz_l(int);//metoda zwraca wartoœæ lx ( x podany w argumencie)
	void ustaw_r(int, int, int, int, int);//metoda ustawia zmienn¹ r klocka. W argumentach przyjmuje wartoœci kolejnych r0-r4
	int pobierz_r(int);//metoda zwraca wartoœæ rx ( x podany w argumencie)
	void ustaw_x(int);//metoda ustawia zmienn¹ x klocka o podanej w argumencie wartoœci
	int pobierz_x();//metoda zwraca wartoœæ zmiennej x
	void ustaw_y(int);//metoda ustawia zmienn¹ z klocka o podanej w argumencie wartoœci
	int pobierz_y();//metoda zwraca wartoœæ zmiennej y
	int pobierz_kolor();//metoda zwraca wartoœæ zmiennej kolor
	int pobierz_zm();//metoda zwraca wartoœæ zmiennej zm
	void przesun_L(tablica *tab, klocek* jakis_klocek); //  jeœli jest wolne miejsce, metoda aktualizuje zmienne klocka zmniejszaj¹c je o 1. Aktualizuje tablicê o zmienione zmienne klocka
	void przesun_P(tablica *tab, klocek* jakis_klocek);//  jeœli jest wolne miejsce, metoda aktualizuje zmienne klocka zwiekszajac je o 1. Aktualizuje tablicê o zmienione zmienne klocka
	klocek funkcja_obrotu(tablica *jakas_tablica, klocek *klocek_obecny, klocek* tablica_klocek[]); //metoda obraca klockiem i aktualizuje tablicê
	int obnizaj(tablica *tab, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[], int u); // metoda obni¿aj¹ca pozycjê klocka w tablicy. U¿ywana tylko przy obni¿aniu co 250 ms
	int obnizaj_do_konca(tablica *jakas_tablica, klocek* jakis_klocek, klocek* tab_klocek[], gracz* zalogowany, int tablica_wylosowanych[]);//metoda obni¿a klocek najni¿ej jak siê da
};