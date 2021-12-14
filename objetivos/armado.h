#ifndef ARMADO_H_INCLUDED
#define ARMADO_H_INCLUDED

#include "objetivo.h"

class Armado: public Objetivo {
    public:
    Armado();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
    
    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
};

#endif // ARMADO_H_INCLUDED

