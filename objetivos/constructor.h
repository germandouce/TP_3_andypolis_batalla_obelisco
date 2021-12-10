#ifndef CONSTRUCTOR_H_INCLUDED
#define CONSTRUCTOR_H_INCLUDED

#include "objetivo.h"

class Constructor: public Objetivo {
    public:
    Constructor();
    bool comprobar_requisito (int cant_edificios_distintos_construida);
};

#endif // CONSTRUCTOR_H_INCLUDED