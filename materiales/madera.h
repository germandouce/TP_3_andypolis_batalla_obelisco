#ifndef MADERA_H_INCLDUED
#define MADERA_H_INCLUDED

#include "material.h"

class Madera : public Material {

private:

public:
    //Constructor de madera con 1 parametro
    //PRE:-
    //POST: Construye un paquete de maderas con 1 parametros
    Madera(int cantidad_material);

    //Madera saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // MADERA_H_INCLUDED