#ifndef MINA_H
#define MINA_H

#include "../edificio.h"

class Mina: public Edificio {

private:


public:

    Mina(int piedra, int madera, int metal, int maximo);

    int obtener_cantidad_brindada();

    string obtener_elemento_brindado();
    
    void mostrar_mensaje();

};

#endif