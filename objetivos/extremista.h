#ifndef EXTREMISTA_H_INCLUDED
#define EXTREMISTA_H_INCLUDED

#include "objetivo.h"

class Extremista: public Objetivo {
    public:
    Extremista();
    bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia);
};

#endif // EXTREMISTA_H_INCLUDED
