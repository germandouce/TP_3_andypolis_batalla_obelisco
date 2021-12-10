#ifndef MUELLE_H
#define MUELLE_H

#include "casillero_transitable.h"

class Muelle: public Casillero_transitable {

    public:

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Muelle según los valores ingresados.
    Muelle(int fila, int columna);

    // Destructor.
	//pre: -
	//post: -
	~Muelle();
};

#endif // MUELLE_H