#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#include "edificio.h"

class Mina: public Edificio {

private:

public:
    
    Mina(int piedra, int madera, int metal, int maximo);

    string obtener_nombre();
    
    string obtener_diminutivo();

    int obtener_cantidad_brindada();

    int obtener_cantidad();

    void saludar();

};

#endif //MINA_H_INCLUDED