#ifndef LETRADO_H_INCLUDED
#define LETRADO_H_INCLUDED

#include "objetivo.h"

class Letrado: public Objetivo {
    public:
    Letrado();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // LETRADO_H_INCLUDED