#ifndef MINA_H
#define MINA_H

#include "edificio.h"

class Mina: public Edificio {

private:


public:

    Mina(int piedra, int madera, int metal, int maximo, int pos_x, int pos_y);

    string obtener_material_brindado();
    
    void mostrar_mensaje();

};

#endif //MINA_H