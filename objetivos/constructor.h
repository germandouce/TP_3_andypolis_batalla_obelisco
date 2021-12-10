#ifndef CONSTRUCTOR_H_INCLUDED
#define CONSTRUCTOR_H_INCLUDED

#include "objetivo.h"

class Constructor: public Objetivo {
    public:
    Constructor();
    bool comprobar_requisito (Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // CONSTRUCTOR_H_INCLUDED