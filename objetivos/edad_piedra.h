#ifndef EDAD_PIEDRA_H_INCLUDED
#define EDAD_PIEDRA_H_INCLUDED

#include "objetivo.h"

class Edad_piedra: public Objetivo {
    public:
    Edad_piedra();
    bool comprobar_requisito();
};

#endif // EDAD_PIEDRA_H_INCLUDED