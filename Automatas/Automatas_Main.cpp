// Automatas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "AFD.h"
#include "AP.h"
#include "MT.h"


int main()
{

	//AP ap = AP();
	//cout << endl << "Ingrese @ si quiere ingresar otra palabra." << endl << endl;
	//do {
	//	ap.comprobar_palabra();
	//	cout << endl << endl << "Ingrese nueva palabra:" << endl;
	//} while (0 != 1);

	//AFD afd = AFD();
	//afd.mostrar_tabla_f();
	//afd.comprobar_palabra();

	//AP ap = AP();
	//ap.comprobar_palabra();

	MT mt = MT();
	cout << endl << "Ingrese @ si quiere ingresar otra palabra." << endl << endl;
	do {
		mt.comprobar_palabra();
		cout << endl << endl << "Ingrese nueva palabra:" << endl;
	} while (0 != 1);



	system("Pause");
	return 0;
}

