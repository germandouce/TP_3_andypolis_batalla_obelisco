#ifndef REGISTRO_EDIFICIOS_NODO_REGISTRO_H
#define REGISTRO_EDIFICIOS_NODO_REGISTRO_H
#include "edificio.h"

class Nodo_R{
//Atributos
private:
    Edificio* edificio;
    Nodo_R* siguiente;

//Metodos
public:
    //constructor
    Nodo_R();

    Nodo_R(Edificio*edificio);

    //PRE:
    //POS: devuelve datos del edificio que apunta.
    Edificio * obtener_edificio();

    //PRE:
    //POS: devuelve nodo que le sigue en posicion en el registro al actual.
    Nodo_R* obtener_siguiente();

    //pre:
    //post: cambia al nodo que le sigue en posicion en el registro al actual.
    void cambiar_siguiente(Nodo_R* puntero);

};


#endif //REGISTRO_EDIFICIOS_NODO_REGISTRO_H
