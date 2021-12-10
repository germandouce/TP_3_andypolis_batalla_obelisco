#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "edificio.h"

class Aserradero: public Edificio {

private:

public:

    Aserradero(int piedra, int madera, int metal, int maximo,  int fila, int columna);

    string obtener_material_brindado();

    void mostrar_mensaje();

};


#endif //ASERRADERO_H