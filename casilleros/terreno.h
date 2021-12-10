#ifndef TERRENO_H
#define TERRENO_H

#include "casillero_construible.h"

class Terreno: public Casillero_construible {

    public:

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Terreno según los valores ingresados.
    Terreno(int fila, int columna);

    // Destructor.
	//pre: -uctor.
	//pre: -
	//post: -
	~Terreno();
};

#endif // TERRENO_H