#include "stdafx.h"
#include "Estado_AP.h"


Estado_AP::Estado_AP()
{
}


Estado_AP::~Estado_AP()
{
}

void Estado_AP::setApilado(bool sa)
{
	apilado = sa;
}

bool Estado_AP::getApilado()
{
	return apilado;
}
