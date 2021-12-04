#ifndef ANDYCOINS_H_INCLUDED
#define ANDYCOINS_H

#include "material.h"

class Andycoins : public Material {

private:

public:
    //Constructor de andycoins con 1 parametros
    //PRE:-
    //POST: Construye un andycoins con 1 parametro
    Andycoins(int cantidad_material);

    //Andycoins saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // ANDYCOINS_H_INCLUDED_INCLUDED