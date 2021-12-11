#ifndef EDAD_PIEDRA_H_INCLUDED
#define EDAD_PIEDRA_H_INCLUDED

#include "objetivo.h"

class Edad_piedra: public Objetivo {
    public:
    Edad_piedra();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);

    void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
};

#endif // EDAD_PIEDRA_H_INCLUDED