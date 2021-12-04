#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "casillero_transitable.h"

typedef Casillero_transitable* Dato;

class Nodo {
//Atributos
private:
    Dato dato;
    Nodo* siguiente;

//Metodos
public:
    //Internamente es todo estatico. El puntero es al siguiente sola//
    //
    //constructor
    //PRE:Hago que el dato apunte a si mismo (un numero un char un estudiante)
    //y dejo el siguiente en nulo
    //POS:
    Nodo(Dato d);

    //PRE:Cambio el dato en una 
    //
    //POS:
    void cambiar_dato(Dato d);

    //PRE:Recibe un puntero a nodo.
    //POS: Cambio la direccion a la que apunta el nodo al que 
    //le aplico el metodo por el nodo que le paso por parametro. 
    //Es decir coloca, hace apuntar al nodo en el que estoy parado 
    //this->nodo a el nodo que paso por parametro 
    //nuevo nodo.(prox nodo pn)
    //nodo -> cambiar_siguiente(nodo_2) hago apuntar a nodo
    //a nodo 2
    void cambiar_siguiente(Nodo* pn);

    //PRE:
    //POS:Devuelve el dato en si.
    Dato obtener_dato();

    //PRE:
    //POS:Devolvera un puntero al siguiente, es decir un puntero al sig nodo     
    Nodo* obtener_siguiente();
};


#endif // NODO_H_INCLUDED
