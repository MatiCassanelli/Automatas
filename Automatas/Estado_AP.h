#pragma once
#include "Estado.h"
class Estado_AP :
	public Estado
{
private:
	bool apilado;
public:
	Estado_AP();
	~Estado_AP();
	void setApilado(bool);
	bool getApilado();
};

