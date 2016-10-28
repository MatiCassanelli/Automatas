#pragma once
#include "Automata_Abstract.h"
#include <stack>

class AP : public Automata_Abstract
{
private:
	char elemento_tope;
	char simbolo_pila_vacia;
	stack <char> pila;
public:
	AP();
	AP(char);
	~AP();
	void crear_tabla_f();
	void rellenar();
	void mostrar_tabla_f();
	void comprobar_palabra();
};

