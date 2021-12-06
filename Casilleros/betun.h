#ifndef BETUN_H
#define BETUN_H

#include "casillero_transitable.h"

class Betun: public Casillero_transitable {

    public:

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Betun según los valores ingresados.
    Betun(int fila, int columna);

    // Destructor.
	//pre: -
	//post: -
	~Betun();
};

#endif // BETUN_H