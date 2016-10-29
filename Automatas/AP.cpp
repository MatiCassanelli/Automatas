#include "stdafx.h"
#include "AP.h"


AP::AP()
{
	//ingreso_alfabeto_repetido();
	//ingreso_estados_repetido();
	//ingresar_elemento_pila_repetido();
	pila.push(simbolo_pila_vacia);
	elementos_en_pila.push_back(simbolo_pila_vacia);

	funcion_transicion();
}

AP::AP(string spv)
{
	//ingreso_alfabeto_repetido();
	//ingreso_estados_repetido();
	//ingresar_elemento_pila_repetido();
	simbolo_pila_vacia = spv;
	pila.push(spv);
	elementos_en_pila.push_back(simbolo_pila_vacia);

	funcion_transicion();
}


AP::~AP()
{
}

void AP::funcion_transicion()
{
	cubo = new Estado**[estados.size()];				//i = estados
	for (int i = 0; i < estados.size(); i++)
	{
		cubo[i] = new Estado*[alfabeto_entrada.size()];	//j= alfabeto entrada
		for (int j = 0; j < alfabeto_entrada.size(); j++)
			cubo[i][j] = new Estado[elementos_en_pila.size()];	//k= elementos en pila
	}

	//rellenar();
}

void AP::rellenar()
{
	string ingreso;
	for (int k = 0; k < elementos_en_pila.size(); k++)
		for (int j = 0; j < estados.size(); j++)
			for (int i = 0; i < alfabeto_entrada.size(); i++)
			{
				cout << "Usted esta en el estado " << estados[j].getNombre() << "en la pila hay "<< elementos_en_pila[k]
					<<"y viene el elemento " <<	alfabeto_entrada[i] << " pasamos al estado: ";
				cin >> ingreso;

				while (buscarEstado(ingreso) == -1)
				{
					cout << "Estado no existente. Ingrese uno nuevamente";
					cin >> ingreso;
				}
				cubo[k][j][i] = estados[buscarEstado(ingreso)];
			}
	
}

void AP::mostrar_tabla_f()
{
}

void AP::comprobar_palabra()
{

}

void AP::ingresar_elemento_pila_repetido()
{
	int aux = 0;
	do
	{
		ingresar_elemento_pila();
		cout << "Ingresar otro elemento de la pila? " << endl << "0 = No" << endl << "1 = Si" << " " << endl;
		cin >> aux;
	} while (aux != 0);
}

void AP::ingresar_elemento_pila()
{
	cout << "Ingrese elemento que almacenara en la pila ";
	fflush(stdout);
	string ingreso;
	cin >> ingreso;

	int i = 0;
	while (buscarAlfabeto(ingreso) == -1)
	{
		cout << "El elemento debe corresponderse con alguno del alfabeto de entrada ";
		cin >> ingreso;
	}	

	if (!elementos_en_pila.empty())
	{
		while (buscar_elemento_pila(ingreso) == -1)
		{
			cout << "El elemento debe corresponderse con alguno de los ingresados en la pila ";
			cin >> ingreso;
		}
	}
	elementos_en_pila.push_back(ingreso);
}

int AP::buscar_elemento_pila(string ingreso)
{
	int i = 0;
	for (int i = 0; i<elementos_en_pila.size(); i++)
	{
		if (elementos_en_pila[i] == ingreso)
			return i;
	}
	return -1;
}

void AP::setEstado(int i, int j, int k, Estado est)
{
	cubo[i][j][k] = est;
}

void AP::setElementos(string singreso)
{
	elementos_en_pila.push_back(singreso);
}

void AP::setEstados(Estado est)
{
	estados.push_back(est);
}

void AP::setAlfabeto(string alf)
{
	alfabeto_entrada.push_back(alf);
}

