#ifndef PIEDRA_H
#define PIEDRA_H

#include "material.h"

class Piedra: public Material {

private:

public:
    
    Piedra(int cantidad_material);
    
    string obtener_nombre();

    int obtener_cantidad();

    int obtener_cantidad_brindada();

    void mostrar_mensaje();
    
};

#endif // PIEDRA_H