#ifndef ENERGETICO_H_INCLUDED
#define ENERGETICO_H_INCLUDED

#include "objetivo.h"

class Energetico: public Objetivo {
    public:
    Energetico();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // ENERGETICO_H_INCLUDED