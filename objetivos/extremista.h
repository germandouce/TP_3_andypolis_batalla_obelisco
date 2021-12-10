#ifndef EXTREMISTA_H_INCLUDED
#define EXTREMISTA_H_INCLUDED

#include "objetivo.h"

class Extremista: public Objetivo {
    public:
    Extremista();
    bool comprobar_requisito(int cantidad_bombas_totales);
};

#endif // EXTREMISTA_H_INCLUDED
