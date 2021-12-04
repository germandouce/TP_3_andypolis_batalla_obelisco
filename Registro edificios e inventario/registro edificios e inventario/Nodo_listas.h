#ifndef REGISTRO_EDIFICIOS_NODO_LISTAS_H
#define REGISTRO_EDIFICIOS_NODO_LISTAS_H
#include "Edificio.h"

class Nodo_l{
//Atributos
private:
    Edificio* edificio;
    Nodo_l* siguiente;

//Metodos
public:
    //constructor
    Nodo_l();

    //PRE:
    //POS: devuelve datos del edificio que apunta.
    Edificio * obtener_edificio();

    //PRE:
    //POS: devuelve nodo que le sigue en posicion en el registro al actual.
    Nodo_l* obtener_siguiente();

    //pre:
    //post: cambia al nodo que le sigue en posicion en el registro al actual.
    void cambiar_siguiente(Nodo_l* puntero);

};


#endif //REGISTRO_EDIFICIOS_NODO_LISTAS_H
