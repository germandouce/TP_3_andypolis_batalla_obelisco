#ifndef COMPRAR_ANDYPOLIS_H_INCLUDED
#define COMPRAR_ANDYPOLIS_H_INCLUDED

#include "objetivo.h"

class Comprar_andypolis: public Objetivo {
    public:
    Comprar_andypolis();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);

    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
    
};

#endif // COMPRAR_ANDYPOLIS_H_INCLUDED