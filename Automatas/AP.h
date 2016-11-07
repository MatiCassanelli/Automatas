#pragma once
#include "Automata_Abstract.h"
#include "Estado_AP.h"
#include <stack>

class AP : public Automata_Abstract
{
private:
	string simbolo_pila_vacia = "#";
	string lamda = "l";
	stack <string> pila;
	vector<string> elementos_en_pila;
	Estado ***cubo;
	Estado qe = Estado("qe", false, false);
public:
	AP();
	AP(string);
	~AP();
	void funcion_transicion();
	void rellenar();
	void mostrar_tabla_f();
	void comprobar_palabra();
	void ingresar_elemento_pila_repetido();
	void ingresar_elemento_pila();
	int buscar_elemento_pila(string);
};

