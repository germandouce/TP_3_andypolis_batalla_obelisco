#ifndef EDAD_PIEDRA_H_INCLUDED
#define EDAD_PIEDRA_H_INCLUDED

#include "objetivo.h"

class Edad_piedra: public Objetivo {
    public:
    Edad_piedra();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // EDAD_PIEDRA_H_INCLUDED