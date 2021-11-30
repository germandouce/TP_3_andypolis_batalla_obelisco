
#ifndef BOMBAS_H
#define BOMBAS_H

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Bombas : public Material {

private:


public:
    //Constructor de piedra con dos parametros
    //PRE:-
    //POST: Construye un paquete de bombas sin parametros
    Bombas();

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // BOMBAS_H