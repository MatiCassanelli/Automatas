#include "Automata_Abstract.h"

class AFD : public Automata_Abstract
{
private:
	Estado **matriz;
public:
	AFD();
	~AFD();
	void funcion_transicion();
	void rellenar();
	void mostrar_tabla_f();
	void comprobar_palabra();
};

