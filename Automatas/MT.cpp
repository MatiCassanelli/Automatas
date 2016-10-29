#include "stdafx.h"
#include "MT.h"


MT::MT()
{
	ingreso_alfabeto_repetido();
	ingreso_estados_repetido();
	funcion_transicion();
}


MT::~MT()
{
}

void MT::funcion_transicion()
{
	//cubo = new Estado**[estados.size()];				//eje x
	//for (int i = 0; i < estados.size(); i++)
	//{
	//	cubo[i] = new Estado*[alfabeto_entrada.size()];	//eje y
	//	for (int j = 0; j < alfabeto_entrada.size(); j++)
	//		cubo[i][j] = new Estado[.size()];	//eje z
	//}


	//rellenar();
}

void MT::rellenar()
{
}

void MT::mostrar_tabla_f()
{
}

void MT::comprobar_palabra()
{
}
