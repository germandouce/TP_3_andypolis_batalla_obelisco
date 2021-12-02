#ifndef BOMBAS_H_INCLUDED
#define BOMBAS_H_INCLUDED

#include "material.h"

class Bombas : public Material {

private:


public:
    //Constructor de bombas con 1 parametros
    //PRE:-
    //POST: Construye un paquete de bombas con 1 parametro
    Bombas(int cantidad_material);

    //Bombas saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // BOMBAS_H_INCLUDED