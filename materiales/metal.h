#ifndef METAL_H_INCLUDED
#define METAL_H_INCLUDED
#include "material.h"

class Metal : public Material {

private:


public:
    //Constructor de metal con 1 parametro
    //PRE:-
    //POST: Construye un paquete de metales con 1 parametro
    Metal(int cantidad_material);

    //metal saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();

};


#endif // METAL_H_INCLUDED