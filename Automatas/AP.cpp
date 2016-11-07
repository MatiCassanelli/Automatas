#include "stdafx.h"
#include "AP.h"


AP::AP()
{
	pila.push(simbolo_pila_vacia);
	elementos_en_pila.push_back(simbolo_pila_vacia);
	ingreso_alfabeto_repetido();
	ingreso_estados_repetido();
	estados.push_back(qe);
	ingresar_elemento_pila_repetido();
	

	funcion_transicion();
}

AP::AP(string spv)
{
	ingreso_alfabeto_repetido();
	ingreso_estados_repetido();
	ingresar_elemento_pila_repetido();
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

	rellenar();
}

void AP::rellenar()
{
	string ingreso;
	int rta;
	//for (int j = 0; j < estados.size(); j++)
	for (int j = 0; j < estados.size() - 1; j++)
		for (int k = 0; k < elementos_en_pila.size(); k++)
			for (int i = 0; i < alfabeto_entrada.size(); i++)
			{
				cout << endl << "Usted esta en el estado " << estados[j].getNombre() << ", en la pila hay " << elementos_en_pila[k]
					<< " y viene el elemento [" << alfabeto_entrada[i] << "] pasamos al estado: ";
				cin >> ingreso;

				while (buscarEstado(ingreso) == -1)
				{
					cout << "Estado no existente. Ingrese uno nuevamente";
					cin >> ingreso;
				}
				cubo[j][i][k] = estados[buscarEstado(ingreso)];

				if (cubo[j][i][k].getNombre() != "qe") {
					cout << endl << "Apilar --> 1, Desapilar --> 2, Nada--> 0: ";
					cin >> rta;

					if (rta == 1)
						cubo[j][i][k].setApilado(1);
					else if (rta == 2)
						cubo[j][i][k].setApilado(2);
				}
				
			}
	int j = estados.size()-1;
	for (int k = 0; k < elementos_en_pila.size(); k++)
		for (int i = 0; i < alfabeto_entrada.size(); i++)
			cubo[j][i][k] = qe;
}

void AP::mostrar_tabla_f()
{
}

void AP::comprobar_palabra()
{
	char ingreso = '5';
	string parche;
	Estado estado_actual = estado_inicial;
	vector <char> palabra;
	while (ingreso != '@')
	{
		int i = 0, j = 0, k = 0;

		ingreso = _getch();
		if (ingreso != '@') {
			parche = ingreso;
			if (buscarAlfabeto(parche) != -1)
				palabra.push_back(ingreso);
			for (int i = 0; i < palabra.size(); i++)
				cout << palabra[i];

			i = buscarEstado(estado_actual.getNombre());
			j = buscarAlfabeto(parche);
			k = buscar_elemento_pila(pila.top());

			if (j == -1)
				cout << endl << "Ingreso un elemento no existente en el alfabeto de entrada" << endl;
			else
			{
				estado_actual = cubo[i][j][k];

				if (estado_actual.getNombre() != "qe")
				{
					if (estado_actual.getApilado() == 1)
					{
						pila.push(parche);
						cout << endl << "Palabra no aceptada en el lenguaje" << endl;
					}
					else if (estado_actual.getApilado() == 2)
					{
						pila.pop();

						if (pila.top() == "#")
						{
							cout << endl << "Palabra aceptada" << endl;	
							//cout << endl << "Palabra aceptada"<<endl;
							setLED('b');
						}
						else
						{
							cout << endl << "Palabra no aceptada en el lenguaje" << endl;
							//cout << endl << "Palabra no aceptada en el lenguaje"<<endl;
							setLED('a');
						}
						cout << endl;
					}
				}
				else
				{
					cout << endl << "Palabra no aceptada en el lenguaje" << endl;
					setLED('a');
					//cout << endl << "Palabra no aceptada en el lenguaje"<<endl;
				}
			}
		}
		else {
			while (pila.top() != "#")
				pila.pop();
		}
	}
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

	if (buscar_elemento_pila(ingreso) == -1)
		elementos_en_pila.push_back(ingreso);

	
}

int AP::buscar_elemento_pila(string ingreso)
{
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

