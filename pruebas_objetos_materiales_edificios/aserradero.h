#ifndef ASERRADERO_H_INCLUDED
#define ASERRADERO_H_INCLUDED

#include "edificio.h"

class Aserradero: public Edificio {

private:

public:
    
    Aserradero(int piedra, int madera, int metal, int maximo);

    string obtener_nombre();

    int obtener_cantidad_brindada();
    
    int obtener_cantidad();

    void mostrar_mensaje();

};

#endif // ASERRADERO_INCLUDED