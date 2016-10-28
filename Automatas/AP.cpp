#include "stdafx.h"
#include "AP.h"


AP::AP()
{
	pila.push(simbolo_pila_vacia);
}

AP::AP(char spv)
{
	simbolo_pila_vacia = spv;
	pila.push(spv);
}


AP::~AP()
{
}

void AP::crear_tabla_f()
{
}

void AP::rellenar()
{
}

void AP::mostrar_tabla_f()
{
}

void AP::comprobar_palabra()
{
}

