#ifndef CAMINO_H
#define CAMINO_H

#include "casillero_transitable.h"

class Camino: public Casillero_transitable {

    public:

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Camino según los valores ingresados.
    Camino(int fila, int columna);

    // Destructor.
	//pre: -
	//post: -
	~Camino();
};

#endif // CAMINO_H