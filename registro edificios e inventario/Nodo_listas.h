#ifndef REGISTRO_EDIFICIOS_NODO_LISTAS_H
#define REGISTRO_EDIFICIOS_NODO_LISTAS_H
#include "Edificio.h"

class Nodo_Reg_ed {
//Atributos
private:
    Edificio* edificio;
    Nodo_Reg_ed* siguiente;

//Metodos
public:
    //constructor
    Nodo_Reg_ed();

    //PRE:
    //POS: devuelve datos del edificio que apunta.
    Edificio * obtener_edificio();

    //PRE:
    //POS: devuelve nodo que le sigue en posicion en el registro al actual.
    Nodo_Reg_ed* obtener_siguiente();

    //pre:
    //post: cambia al nodo que le sigue en posicion en el registro al actual.
    void cambiar_siguiente(Nodo_Reg_ed* puntero);

};


#endif //REGISTRO_EDIFICIOS_NODO_LISTAS_H
