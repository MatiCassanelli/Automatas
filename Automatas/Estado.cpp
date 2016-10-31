#include "stdafx.h"
#include "Estado.h"


Estado::Estado(string cnombre, bool cinicial, bool csalida)
{
	nombre = cnombre;
	inicial = cinicial;
	salida = csalida;
}

Estado::Estado()
{
}


Estado::~Estado()
{
}

string Estado::getNombre()
{
	return nombre;
}

void Estado::setNombre(string snombre)
{
	nombre = snombre;
}

bool Estado::esInicial()
{
	return inicial;
}

bool Estado::esFinal()
{
	return salida;
}

void Estado::cambiar_inicial(bool cambio)
{
	inicial = cambio;
}

void Estado::setApilado(int sa)
{
	apilado = sa;
}

int Estado::getApilado()
{
	return apilado;
}

void Estado::setDesplazamiento(int sdes)
{
	desplazamiento = sdes;
}

int Estado::getDesplazamiento()
{
	return desplazamiento;
}

void Estado::setEscribe(string sescribe)
{
	escribe = sescribe;
}

string Estado::getEscribe()
{
	return escribe;
}
