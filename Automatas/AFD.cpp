#include "stdafx.h"
#include "AFD.h"


AFD::AFD()
{
	ingreso_alfabeto_repetido();
	ingreso_estados_repetido();
	funcion_transicion();
}

AFD::~AFD()
{
}

void AFD::funcion_transicion()
{
	matriz = new Estado*[estados.size()];				//filas
	for (int i = 0; i < estados.size(); i++)
		matriz[i] = new Estado[alfabeto_entrada.size()];	//columnas

	rellenar();
}

void AFD::rellenar()
{
	string ingreso;
	for (int j = 0; j < estados.size(); j++)
		for (int i = 0; i < alfabeto_entrada.size(); i++)
		{
			cout << "Usted esta en el estado " << estados[j].getNombre() << " y viene el elemento " <<
				alfabeto_entrada[i] << " pasamos al estado: ";
			cin >> ingreso;

			while (buscarEstado(ingreso) == -1)
			{
				cout << "Estado no existente. Ingrese uno nuevamente";
				cin >> ingreso;
			}
			matriz[j][i] = estados[buscarEstado(ingreso)];
		}
}

void AFD::mostrar_tabla_f()
{
	for (int i = 0; i < estados.size(); i++)	//filas			
	{
		if (i == 0) {
			cout << '\t';
			for (int k = 0; k < alfabeto_entrada.size(); k++)
				cout << alfabeto_entrada[k] << '\t';
			cout << endl;
		}
		for (int j = 0; j < alfabeto_entrada.size(); j++)	//columnas
		{
			if (j == 0)
			{
				if (estados[i].esInicial())
					cout << "->";
				else
					cout << "  ";

				cout << estados[i].getNombre();
				if (estados[i].esFinal())
					cout << '*';
				cout << '\t';
			}
			cout << matriz[i][j].getNombre() << "\t";
		}
		cout << endl;
	}
}

void AFD::comprobar_palabra()
{
	char ingreso = '5';
	string parche;
	Estado estado_actual = estado_inicial;
	vector <char> palabra;
	while (ingreso != '@')
	{
		int i = 0, j = 0;

		for (int i = 0; i < palabra.size(); i++)
			cout << palabra[i];

		ingreso = _getch();
		parche = ingreso;
		if (buscarAlfabeto(parche) != -1)
			palabra.push_back(ingreso);

		i = buscarAlfabeto(parche);
		j = buscarEstado(estado_actual.getNombre());

		if (i == -1)
			if (ingreso != '@')
				cout << endl << "Ingreso un elemento no existente en el alfabeto de entrada" << endl;
			else
				cout <<endl<<endl;
		else
		{
			estado_actual = matriz[j][i];

			if (estado_actual.esFinal())
				setLED('b');
				//cout << endl << "Ingreso una palabra existente en el lenguaje " << endl;
			else
				setLED('a');
				//cout << endl << "Ingreso una palabra NO existente en el lenguaje " << endl;
			cout << endl;
		}
	}
}

