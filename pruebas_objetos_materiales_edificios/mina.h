#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#include "edificio.h"

class Mina: public Edificio {

private:

public:
    
    Mina(int piedra, int madera, int metal, int maximo);

    string obtener_nombre();

    int obtener_cantidad_brindada();

    void mostrar_mensaje();

};

#endif //MINA_H_INCLUDED