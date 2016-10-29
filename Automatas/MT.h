#include "Automata_Abstract.h"


class MT : public Automata_Abstract
{
private:
	Estado ***cubo;
	char cabezal;
public:
	MT();
	~MT();
	void funcion_transicion();
	void rellenar();
	void mostrar_tabla_f();
	void comprobar_palabra();
};

