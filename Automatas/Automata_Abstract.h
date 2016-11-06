#pragma once
#include "Estado.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <Windows.h>

class Automata_Abstract
{
protected:
	vector<Estado> estados;
	vector<string> alfabeto_entrada;
	Estado estado_inicial;
	Estado estado_actual;

public:
	virtual void funcion_transicion() = 0;	//implementar en todas
	virtual void rellenar() = 0;	//implementar en todas
	virtual void mostrar_tabla_f() = 0;		//implementar en todas
	void ingresar_alfabeto();	//implementada aca
	void ingresar_estados();	//implementada aca
	virtual void comprobar_palabra() = 0;	//implementar en todas 
	int buscarAlfabeto(string);	//implementada aca
	int buscarEstado(string);	//implementada aca
	void ingreso_alfabeto_repetido();	//implementada aca
	void ingreso_estados_repetido();	//implementada aca
	Estado ingresar_info_estado();	//implementada aca
	int existeInicial();	//implementado aca
};
