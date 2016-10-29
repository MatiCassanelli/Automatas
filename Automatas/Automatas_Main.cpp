// Automatas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "AFD.h"
#include "AP.h"


int main()
{
	//AFD afd = AFD();
	//afd.mostrar_tabla_f();
	//afd.comprobar_palabra();

	Estado q0, q1, q2, qS;
	AP ap = AP();

	ap.setAlfabeto("a");
	ap.setAlfabeto("b");
	ap.setEstados(q0);
	ap.setEstados(q1);
	ap.setEstados(q2);
	ap.setEstados(qS);
	ap.setElementos("a");


	system("Pause");
	return 0;
}

