#pragma once
#include <string>
using namespace std;

class Estado
{
private:
	bool inicial = false;
	bool salida = false;
	string nombre;
	int apilado = 0;	//va al estado de AP
	int desplazamiento;	//va al estado de MT
	string escribe;		//va al estado de MT

public:
	Estado(string,bool,bool);
	Estado();
	~Estado();
	string getNombre();
	void setNombre(string);
	bool esInicial();
	bool esFinal();
	void cambiar_inicial(bool);
	void setApilado(int);			//va al estado de AP
	int getApilado();				//va al estado de AP
	void setDesplazamiento(int);	//va al estado de MT
	int getDesplazamiento();		//va al estado de MT
	void setEscribe(string);		//va al estado de MT
	string getEscribe();			//va al estado de MT



};

