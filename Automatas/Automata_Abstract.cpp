#include "stdafx.h"
#include "Automata_Abstract.h"
#include <Windows.h>

void Automata_Abstract::ingresar_alfabeto()
{
	cout << "Ingrese elemento componente del alfabeto de entrada ";
	fflush(stdout);
	string ingreso;
	cin >> ingreso;
	if (!alfabeto_entrada.empty())
	{
		while (buscarAlfabeto(ingreso) != -1)
		{
			cout << "Elemento existente. Ingrese uno distinto ";
			cin >> ingreso;
		}
	}
	alfabeto_entrada.push_back(ingreso);
}

void Automata_Abstract::ingresar_estados()
{
	int i = 0;
	Estado estado_ingresado = ingresar_info_estado();

	if (!estados.empty())
	{
		if (estado_ingresado.esInicial() == 1)
		{
			for (int i = 0; i<estados.size(); i++)
			{
				if (estados[i].esInicial())
				{
					cout << "No puede haber dos estados iniciales. Se convirtio el estado actual en uno NO inicial";
					estado_ingresado.cambiar_inicial(false);
				}
			}
		}
	}
	estados.push_back(estado_ingresado);
	if (estado_ingresado.esInicial())
		estado_inicial = estado_ingresado;
}

int Automata_Abstract::buscarAlfabeto(string ingreso)
{
	int i = 0;
	for (; i<alfabeto_entrada.size(); i++)
	{
		if (alfabeto_entrada[i] == ingreso)
			return i;
	}
	return -1;
}

int Automata_Abstract::buscarEstado(string ingreso)
{
	int i = 0;
	for (int i = 0; i<estados.size(); i++)
	{
		if (estados[i].getNombre() == ingreso)
			return i;
	}
	return -1;
}

void Automata_Abstract::ingreso_alfabeto_repetido()
{
	int aux = 0;
	do
	{
		ingresar_alfabeto();
		cout << "Ingresar otro elemento del alfabeto de entrada? " << endl << "0 = No" << endl << "1 = Si" << " " << endl;
		cin >> aux;
	} while (aux != 0);
}

void Automata_Abstract::ingreso_estados_repetido()
{
	int ingreso;
	int aux = existeInicial();
	while (aux == 0)
	{
		do
		{
			ingresar_estados();
			cout << "Ingresar otro estado ? " << endl << "0 = No" << endl << "1 = Si" << " " << endl;
			cin >> ingreso;
			aux = 1;
		} while (ingreso != 0);

		if (existeInicial() == 0)
		{
			cout << "Debe existir un estado inicial obligatoriamente. Debera ingresar todos los estados de nuevo" << endl;
			estados.clear();
			aux = 0;
		}
	}
}

Estado Automata_Abstract::ingresar_info_estado()
{
	bool inicial, salida;
	string nombre;

	cout << "Ingrese nombre del estado ";
	cin >> nombre;
	while (buscarEstado(nombre) != -1)
	{
		cout << "Estado existente. Ingrese uno distinto ";
		cin >> nombre;
	}

	cout << "Estado Inicial?" << endl << "0 = No" << endl << "1 = Si" << " " << endl;
	cin >> inicial;

	cout << "Estado de Salida?" << endl << "0 = No" << endl << "1 = Si" << " " << endl;
	cin >> salida;

	Estado devolver = { nombre, inicial, salida };
	return devolver;
}

int Automata_Abstract::existeInicial()
{
	int B = 0;
	for (int i = 0; i < estados.size(); i++)
	{
		if (estados[i].esInicial())
			B = 1;
	}
	return B;
}

void Automata_Abstract::setLED(char letra)
{
	LPDWORD pto = 0;
	LPOVERLAPPED over = 0;

	HANDLE serialHandle;
	string s = { "COM4" };
	std::wstring stemp = std::wstring(s.begin(), s.end());
	LPCWSTR sw = stemp.c_str();

	serialHandle = CreateFile(sw, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	// Do some basic settings
	DCB serialParams = { 0 };
	serialParams.DCBlength = sizeof(serialParams);

	GetCommState(serialHandle, &serialParams);
	serialParams.BaudRate = 9600;
	serialParams.ByteSize = 8;
	serialParams.StopBits = 1;
	serialParams.Parity = 0;
	SetCommState(serialHandle, &serialParams);

	// Set timeouts
	COMMTIMEOUTS timeout = { 0 };
	timeout.ReadIntervalTimeout = 50;
	timeout.ReadTotalTimeoutConstant = 50;
	timeout.ReadTotalTimeoutMultiplier = 50;
	timeout.WriteTotalTimeoutConstant = 50;
	timeout.WriteTotalTimeoutMultiplier = 10;

	SetCommTimeouts(serialHandle, &timeout);

	if (letra == 'a')
		WriteFile(serialHandle, "a", 1, pto, over);
	else
		WriteFile(serialHandle, "b", 1, pto, over);

	CloseHandle(serialHandle);
}



