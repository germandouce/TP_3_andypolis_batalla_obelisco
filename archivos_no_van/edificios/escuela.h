#ifndef ESCUELA_H
#define ESCUELA_H

#include "edificio.h"

class Escuela: public Edificio {

private:

public:

    Escuela(int piedra, int madera, int metal, int maximo);

    string obtener_material_brindado();

    void mostrar_mensaje();

};


#endif //ESCUELA_H