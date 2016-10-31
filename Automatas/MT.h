#include "Automata_Abstract.h"


class MT : public Automata_Abstract
{
private:
	Estado **matriz;
	vector<string> cinta;
	vector<string> alfabeto_en_cinta;
	int cabezal;
public:
	MT();
	~MT();
	void funcion_transicion();
	void rellenar();
	void mostrar_tabla_f();
	void comprobar_palabra();
	void ingresar_alfabeto_cinta();
	int buscar_elemento_cinta(string);
	void ingresar_elemento_cinta_repetido();
	int ingreso_palabra_cinta(string);
};

