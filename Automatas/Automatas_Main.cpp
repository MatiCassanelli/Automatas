// Automatas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "AFD.h"
#include "AP.h"
#include "MT.h"
#include <Windows.h>

void setLED(char letra);


int main()
{	
	setLED('a');
	Sleep(1000);
	setLED('b');

	/*AP ap = AP();
	cout << endl << "Ingrese @ si quiere ingresar otra palabra." << endl << endl;
	do {
		ap.comprobar_palabra();
		cout << endl << endl << "Ingrese nueva palabra:" << endl;
	} while (0 != 1);*/

	/*AFD afd = AFD();
	cout << endl << "Ingrese @ si quiere ingresar otra palabra." << endl << endl;
	do {
		afd.mostrar_tabla_f();
		afd.comprobar_palabra();
	}while (0 != 1);
*/

	//MT mt = MT();
	//cout << endl << "Ingrese @ si quiere ingresar otra palabra." << endl << endl;
	//do {
	//	mt.comprobar_palabra();
	//	cout << endl << endl << "Ingrese nueva palabra:" << endl;
	//} while (0 != 1);



	system("Pause");
	return 0;
}

void setLED(char letra)
{
	LPDWORD pto = 0;
	LPOVERLAPPED over = 0;

	HANDLE serialHandle;
	string s = { "COM3" };
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

	if(letra=='a')
		WriteFile(serialHandle, "a", 1, pto, over);
	else
		WriteFile(serialHandle, "b", 1, pto, over);

	CloseHandle(serialHandle);
}
