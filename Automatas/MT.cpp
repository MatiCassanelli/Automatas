#include "stdafx.h"
#include "MT.h"


MT::MT()
{
	cabezal = 1;
	alfabeto_entrada.push_back("%");
	ingreso_alfabeto_repetido();
	ingreso_estados_repetido();
	cinta.push_back("%");
	alfabeto_en_cinta.push_back("%");
	ingresar_elemento_cinta_repetido();
	funcion_transicion();
}


MT::~MT()
{
}

void MT::funcion_transicion()
{
	matriz = new Estado*[estados.size()];				//filas
	for (int i = 0; i < estados.size(); i++)
		matriz[i] = new Estado[alfabeto_entrada.size()];	//columnas

	rellenar();
}

void MT::rellenar()
{
	string ingreso_estado, escribir;
	int ingreso_despl;
	for (int j = 0; j < estados.size(); j++)
		for (int i = 0; i < alfabeto_entrada.size(); i++)
		{
			if (estados[j].esFinal() == false)
			{
				cout << "Usted esta en el estado " << estados[j].getNombre() << " y lee el elemento " <<
					alfabeto_entrada[i] << " pasamos al estado: ";
				cin >> ingreso_estado;

				while (buscarEstado(ingreso_estado) == -1)
				{
					cout << "Estado no existente. Ingrese uno nuevamente";
					cin >> ingreso_estado;
				}

				cout << "Que desea escribir en la cinta?" << endl;
				cin >> escribir;

				while (buscar_elemento_cinta(escribir) == -1)
				{
					cout << "Ingrese un elemento valido";
					cin >> escribir;
				}

				cout << "El movimiento es:" << endl << "Derecha--> 1, Izquierda--> -1, Parar--> 0: ";
				cin >> ingreso_despl;

				while (ingreso_despl != -1 && ingreso_despl != 0 && ingreso_despl != 1)
				{
					cout << "Ingrese uno de dichos valores " << endl << "Derecha--> 1, Izquierda--> -1, Parar--> 0: ";
					cin >> ingreso_despl;
				}
			}
			matriz[j][i] = estados[buscarEstado(ingreso_estado)];
			if (estados[j].esFinal() == false)
			{
				matriz[j][i].setEscribe(escribir);
				matriz[j][i].setDesplazamiento(ingreso_despl);
			}
		}
}

void MT::mostrar_tabla_f()
{
}

void MT::comprobar_palabra()
{
	Estado estado_actual = estado_inicial;
	string ingreso;
	cout << "Ingrese la cadena que desea comprobar ";
	cin >> ingreso;

	while (ingreso_palabra_cinta(ingreso) == 0)
	{
		cout << "Cadena incorrecta. Ingrese una nueva: ";
		cin >> ingreso;
	}
	
	int i, j;

	while (estado_actual.esFinal()==false)
	{
		i = buscarEstado(estado_actual.getNombre());
		j = buscarAlfabeto(cinta[cabezal]);
		estado_actual = matriz[i][j];

		cinta[cabezal] = estado_actual.getEscribe();
		cabezal += estado_actual.getDesplazamiento();
	}
	if (cinta[cinta.size() - 1] != "%")
		cinta.push_back("%");
	if (cinta[0] != "%")
		cinta.insert(cinta.begin(), "%");
	for (int m = 0; m < cinta.size(); m++)
		cout<<cinta[m];
	cout << endl;
	cinta.clear();
	cabezal = 0;
}

void MT::ingresar_alfabeto_cinta()
{
	cout << "Ingrese elemento que almacenara en la cinta ";
	fflush(stdout);
	string ingreso;
	cin >> ingreso;

	if (buscar_elemento_cinta(ingreso) == -1)
		alfabeto_en_cinta.push_back(ingreso);
}

int MT::buscar_elemento_cinta(string ingreso)
{
	for (int i = 0; i<alfabeto_en_cinta.size(); i++)
	{
		if (alfabeto_en_cinta[i] == ingreso)
			return i;
	}
	return -1;
}

void MT::ingresar_elemento_cinta_repetido()
{
	int aux = 0;
	do
	{
		ingresar_alfabeto_cinta();
		cout << "Ingresar otro elemento al alfabeto de la cinta? " << endl << "0 = No" << endl << "1 = Si" << " " << endl;
		cin >> aux;
	} while (aux != 0);
}

int MT::ingreso_palabra_cinta(string ingreso)
{
	string parche;
	int B = 0;
	for (int i = 0; i < ingreso.size(); i++)
	{
		parche = ingreso[i];
		if (buscarAlfabeto(parche) != -1)
		{
			cinta.push_back(parche);
			B = 1;
		}
		else
			return 0;

	}
	cinta.push_back("%");
	return B;
}
