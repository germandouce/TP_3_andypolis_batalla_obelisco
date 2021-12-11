#ifndef CANSADO_H_INCLUDED
#define CANSADO_H_INCLUDED

#include "objetivo.h"

class Cansado: public Objetivo {
    public:
    Cansado();
    
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
    
    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
};

#endif // CANSADO_H_INCLUDED