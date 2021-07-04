#pragma once
#pragma once
#include "tablica.h"
#include "klocek.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
  ////////////////////////////////////////////////////////////////
 //               budowa klocków                               //
////////////////////////////////////////////////////////////////
/*
z0-z4 - pozycje domyyœlne konkretnego klocka (max 5 pól). z0 najbardziej po lewej i najwy¿ej. z4 najbardziej na prawo i na dole. Jeœli klocek zajmuje mniej ni¿ 5 pól, kolejne zmienne maj¹ wartoœæ tak¹ sam¹ co ostatnia.
l0-l4 - najbardziej skrajne pola po lewej stronie klocka. Jeœli pola skrajne skoñczy³y siê np na l2 to zmienne l3,l4 maj¹ t¹ sam¹ wartoœæ co ostatnia skrajna. Tak samo przy prawych skrajnych i dolnych.
r0-r4 - najbardziej skrajne pola po prawej stronie klocka.
n0-n4 - najbardziej skrajne pola na dole klocka.
id - id klocka
zm - id klocka, na który ma siê zamieniæ po naciœniêciu strza³ki w górê (o ile spe³ni warunki).
x - zmienna pozioma po³o¿enia klocka. Przy ka¿dym ruchu pawo-lewo zwiêksza/zmniejsza siê o 1. Bazowo 0.
y - zmienna pionowa po³o¿enia klocka. Przy obni¿aniu zwiêksza siê o 12, a przy likwidowaniu klocka wraca do bazowej wartoœci 84.
*/////////////////////////////////////////////////////////////////

class palka_poziomo
	:public klocek  //dziedziczenie publiczne klasy klocek
{
public:
	palka_poziomo(); //konstruktor
};

class palka_pionowo
	:public klocek
{
public:
	palka_pionowo();
};

class kwadrat
	:public klocek
{
public:
	kwadrat();
};

class piramida_up
	:public klocek
{
	friend class klocek;
public:
	piramida_up();
};

class piramida_down
	:public klocek
{
public:
	piramida_down();
};

class piramida_right
	:public klocek
{
public:
	piramida_right();
};

class piramida_left
	:public klocek
{
public:
	piramida_left();
};

class L_left
	:public klocek
{
public:
	L_left();
};

class L_right
	:public klocek
{
public:
	L_right();
};

class L_down
	:public klocek
{
public:
	L_down();
};

class L_up
	:public klocek
{
public:
	L_up();
};

class Odwr_L_up
	:public klocek
{
public:
	Odwr_L_up();
};

class Odwr_L_left
	:public klocek
{
public:
	Odwr_L_left();
};

class Odwr_L_right
	:public klocek
{
public:
	Odwr_L_right();
};

class Odwr_L_down
	:public klocek
{
public:
	Odwr_L_down();
};

class Z_poziomo
	:public klocek
{
public:
	Z_poziomo();
};

class Z_pionowo
	:public klocek
{
public:
	Z_pionowo();
};

class S_poziomo
	:public klocek
{
public:
	S_poziomo();
};

class S_pionowo
	:public klocek
{
public:
	S_pionowo();
};










