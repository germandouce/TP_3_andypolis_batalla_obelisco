#ifndef ARMADO_H_INCLUDED
#define ARMADO_H_INCLUDED

#include "objetivo.h"

class Armado: public Objetivo {
    public:
    Armado();
    bool comprobar_requisito(int cantidad_bombas_actuales);
};

#endif // ARMADO_H_INCLUDED

