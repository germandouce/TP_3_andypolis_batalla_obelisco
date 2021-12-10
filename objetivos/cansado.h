#ifndef CANSADO_H_INCLUDED
#define CANSADO_H_INCLUDED

#include "objetivo.h"

class Cansado: public Objetivo {
    public:
    Cansado();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // CANSADO_H_INCLUDED