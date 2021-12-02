
#ifndef MADERA_H
#define MADERA_H

#include <iostream>
#include <string>
#include "material.h"

using namespace std;

class Andycoins : public Material {

private:

public:
    //Constructor de piedra con dos parametros
    //PRE:-
    //POST: Construye un andycoin con 2 parametros
    Andycoins();

    //Piedra saluda
    //PRE:-
    //POST: Saluda describiendose
    void saludar();


};


#endif // MADERA_H_INCLUDED