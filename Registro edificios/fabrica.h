#ifndef FABRICA_H
#define FABRICA_H

#include "edificio.h"

class Fabrica: public Edificio {

private:

public:

    Fabrica(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y);

    string obtener_material_brindado();

    void mostrar_mensaje();

};

#endif //FABRICA_H