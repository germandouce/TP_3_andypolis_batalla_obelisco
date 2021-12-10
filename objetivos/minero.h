#ifndef MINERO_H_INCLUDED
#define MINERO_H_INCLUDED

#include "objetivo.h"

class Minero: public Objetivo {
    public:
    Minero();
    bool comprobar_requisito(int cantidad_minas, int cantidad_minas_oro);
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios);
};

#endif // MINEROO_H_INCLUDED