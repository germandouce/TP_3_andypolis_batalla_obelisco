#ifndef PIEDRA_H
#define PIEDRA_H

#include "material.h"


class Piedra: public Material {

private:

public:
    
    Piedra(int cantidad_material);
    
    string obtener_nombre();

    string obtener_diminutivo();

    int obtener_cantidad();

    void saludar();
    
};

#endif // PIEDRA_H