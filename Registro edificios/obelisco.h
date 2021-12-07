#ifndef OBELISCO_H
#define OBELISCO_H

#include "edificio.h"

class Obelisco: public Edificio {

private:

public:

    Obelisco(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y);

    string obtener_material_brindado();

    void mostrar_mensaje();

};

#endif //OBELISCO_H