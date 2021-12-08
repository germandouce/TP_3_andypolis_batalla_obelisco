#ifndef MINA_ORO_H
#define MINA_ORO_H

#include "edificio.h"

class Mina_oro: public Edificio {

private:


public:

    Mina_oro(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y);

    string obtener_material_brindado();

    void mostrar_mensaje();

};

#endif //MINA_ORO_H