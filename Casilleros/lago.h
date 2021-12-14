#ifndef LAGO_H
#define LAGO_H

#include "casillero_inaccesible.h"

class Lago: public Casillero_inaccesible {

    public:

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Lago según los valores ingresados.
    Lago(int fila, int columna);

    // Destructor.
	//pre: -
	//post: -
	~Lago();
};

#endif // LAGO_H