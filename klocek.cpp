#include "klocek.h"
#include"tablica.h"

//W pliku s¹ tylko konstruktory i metody do operacji na zmiennych klasy. Pozosta³e metody s¹ w oddzielnych plikach

klocek::klocek(): y(0), x(0)//lista inicjalizacyjna
{}
klocek::klocek(const klocek&kopia) //konstruktor kopiuj¹cy
{
	y = kopia.y;
	x = kopia.x;
	zm = kopia.zm;

	id = kopia.id;
	z0 = kopia.z0;
	z1 = kopia.z1;
	z2 = kopia.z2;
	z3 = kopia.z3;
	z4 = kopia.z4;

	n0 = kopia.n0;
	n1 = kopia.n1;
	n2 = kopia.n2;
	n3 = kopia.n3;
	n4 = kopia.n4;

	l0 = kopia.l0;
	l1 = kopia.l1;
	l2 = kopia.l2;
	l3 = kopia.l3;
	l4 = kopia.l4;

	r0 = kopia.r0;
	r1 = kopia.r1;
	r2 = kopia.r2;
	r3 = kopia.r3;
	r4 = kopia.r4;
	kolor = kopia.kolor;
}

klocek::~klocek() //destruktor 
{

}
//metoda ustawia zmienn¹ z klocka. W argumentach przyjmuje wartoœci kolejnych z0-z4
void klocek::ustaw_z(int u0, int u1, int u2, int u3, int u4)
{
	z0 = u0;
	z1 = u1;
	z2 = u2;
	z3 = u3;
	z4 = u4;
}
//metoda zwraca wartoœæ zx ( x podany w argumencie)
int klocek::pobierz_z(int ktory)
{
	switch (ktory)
	{
	case 0:return z0;
		break;
	case 1:return z1;
		break;
	case 2:return z2;
		break;
	case 3:return z3;
		break;
	case 4:return z4;
		break;
	}
}
//metoda ustawia zmienn¹ n klocka. W argumentach przyjmuje wartoœci kolejnych n0-n4
void klocek::ustaw_n(int u0, int u1, int u2, int u3, int u4)
{
	n0 = u0;
	n1 = u1;
	n2 = u2;
	n3 = u3;
	n4 = u4;
}
int pobierz_n(int);//metoda zwraca wartoœæ nx ( x podany w argumencie)
int klocek::pobierz_n(int ktory)
{
	switch (ktory)
	{
	case 0:return n0;
		break;
	case 1:return n1;
		break;
	case 2:return n2;
		break;
	case 3:return n3;
		break;
	case 4:return n4;
		break;
	}
}
//metoda ustawia zmienn¹ l klocka. W argumentach przyjmuje wartoœci kolejnych l0-l4
void klocek::ustaw_l(int u0, int u1, int u2, int u3, int u4)
{
	l0 = u0;
	l1 = u1;
	l2 = u2;
	l3 = u3;
	l4 = u4;
}
//metoda zwraca wartoœæ lx ( x podany w argumencie)
int klocek::pobierz_l(int ktory)
{
	switch (ktory)
	{
	case 0:return l0;
		break;
	case 1:return l1;
		break;
	case 2:return l2;
		break;
	case 3:return l3;
		break;
	case 4:return l4;
		break;
	}
}
//metoda ustawia zmienn¹ r klocka. W argumentach przyjmuje wartoœci kolejnych r0-r4
void klocek::ustaw_r(int u0, int u1, int u2, int u3, int u4)
{
	r0 = u0;
	r1 = u1;
	r2 = u2;
	r3 = u3;
	r4 = u4;
}
//metoda zwraca wartoœæ rx ( x podany w argumencie)
int klocek::pobierz_r(int ktory)
{
	switch (ktory)
	{
	case 0:return r0;
		break;
	case 1:return r1;
		break;
	case 2:return r2;
		break;
	case 3:return r3;
		break;
	case 4:return r4;
		break;
	default :
		system("cls");
		cout << "zly parametr";
		_getch();
		break;
	}
}
//metoda ustawia zmienn¹ x klocka o podanej w argumencie wartoœci
void klocek::ustaw_x(int u)
{
	x = u;
}
//metoda zwraca wartoœæ zmiennej x
int klocek::pobierz_x()
{
	return x;
}
//metoda ustawia zmienn¹ y klocka o podanej w argumencie wartoœci
void klocek::ustaw_y(int u)
{
	y = u;
}
//metoda zwraca wartoœæ zmiennej y
int klocek::pobierz_y()
{
	return y;
}
//metoda zwraca wartoœæ zmiennej kolor
int klocek::pobierz_kolor()
{
	return kolor;
}
//metoda zwraca wartoœæ zmiennej zm
int klocek::pobierz_zm()
{
	return zm;
}









