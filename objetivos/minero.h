#ifndef MINERO_H_INCLUDED
#define MINERO_H_INCLUDED

#include "objetivo.h"

class Minero: public Objetivo {
    public:
    
    Minero();
    
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
    
    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios,
    Diccionario *diccionario, int energia);

};

#endif // MINEROO_H_INCLUDED