#ifndef MINA_DE_ORO_H
#define MINA_DE_ORO_H

#include "edificio.h"

class Mina_de_oro: public Edificio {

private:


public:

    Mina_de_oro(int piedra, int madera, int metal, int maximo,  int fila, int columna);

    string obtener_material_brindado();

    void mostrar_mensaje();

};

#endif //MINA_DE_ORO_H