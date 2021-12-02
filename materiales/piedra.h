#ifndef PIEDRA_H
#define PIEDRA_H

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Piedra : public Material {

private:

public:
    //Constructor de piedra con dos parametros
    //PRE:-
    //POST: Construye una piedra con 2 parametros
    Piedra(int cantidad_material);

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // PIEDRA_H_INCLUDED