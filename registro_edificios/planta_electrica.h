#ifndef PLANTA_ELECTRICA_H
#define PLANTA_ELECTRICA_H

#include "edificio.h"

class Planta_electrica: public Edificio {

private:

public:

    Planta_electrica(int piedra, int madera, int metal, int maximo, int fila, int columna);

    string obtener_material_brindado();

    void mostrar_mensaje();

};

#endif // PLANTA_ELECTRICA_H