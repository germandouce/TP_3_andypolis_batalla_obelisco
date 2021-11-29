#ifndef NODO_H
#define NODO_H

#include "vertice.h"

class Nodo
{
//ATRIBUTOS
private:
    Vertice* vertice;
    Nodo* adyacente_derecho; 
    Nodo* adyacente_izquierdo; 
    Nodo* adyacente_abajo;     
    Nodo* adyacente_arriba;
    Nodo* siguiente;

//METODOS
public:
    //pre:
    //post: Inicializa el nodo con el vertice y sus vertices adyacentes.
    Nodo(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y);

    //pre:
    //post: Inicializa el nodo adyacente derecho.
    void asignar_derecho(Nodo* vertice_derecho);

    //pre:
    //post: Inicializa el nodo adyacente izquierdo.
    void asignar_izquierdo(Nodo* vertice_izquierdo);
    
    //pre:
    //post: Inicializa el nodo adyacente superior.
    void asignar_arriba(Nodo* vertice_arriba);

    //pre:
    //post: Inicializa el nodo adyacente inferior.
    void asignar_abajo(Nodo* vertice_abajo);

    //pre:
    //post: asigna el siguiente nodo por orden de numero de vertice
    void asignar_siguiente(Nodo* vertice_siguiente);

    //pre:
    //post:
    Nodo* obtener_siguiente();

    //pre:
    //post: Elimina el vertice.
    ~Nodo();
};

#endif // NODO_H