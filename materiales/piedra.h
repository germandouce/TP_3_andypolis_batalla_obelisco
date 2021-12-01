#ifndef PIEDRA_H_INCLUDED
#define PIEDRA_H_INCLUDED

#include "material.h"

class Piedra : public Material {

private:

public:
    //Constructor de piedra con un parametro
    //PRE:-
    //POST: Construye un paquete de piedras con 1 parametros
    Piedra(int cantidad_material);

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // PIEDRA_H_INCLUDED