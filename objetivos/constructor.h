#ifndef CONSTRUCTOR_H_INCLUDED
#define CONSTRUCTOR_H_INCLUDED

#include "objetivo.h"

class Constructor: public Objetivo {
    public:
    Constructor();
    
    bool comprobar_requisito (Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);

    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
};

#endif // CONSTRUCTOR_H_INCLUDED