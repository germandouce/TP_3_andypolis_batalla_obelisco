#ifndef COMPRAR_ANDYPOLIS_H_INCLUDED
#define COMPRAR_ANDYPOLIS_H_INCLUDED

#include "objetivo.h"

class Comprar_andypolis: public Objetivo {
    public:
    Comprar_andypolis();
    bool comprobar_requisito();
};

#endif // COMPRAR_ANDYPOLIS_H_INCLUDED