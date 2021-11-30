#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

const int PRIMER_POSICION = 1;
const int PRIMER_FILA = 1;
const int PRIMER_COLUMNA = 1;

const int INFINITO = 99999;

class Lista{

//ATRIBUTOS
private:
    int cantidad_elementos;
    Nodo* primero;
    Nodo* ultimo;

//METODOS
    //pre:
    //post: Inicializa los nodos adyacentes horizontales.
    void asignar_nodos_horizontales(int filas, int columnas, Nodo* nodo);

    //pre:
    //post: Inicializa los nodos adyacentes verticales.
    void asignar_nodos_verticales(int filas, int columnas, Nodo* nodo);

public:
    Lista();

    Lista(int cantidad_elementos, int filas, int columnas);

    //pre:
    //post: Devuelve la cantidad de elementos que tiene la lista.
    int obtener_cantidad_elementos();

    //pre:
    //post: Agrega un nuevo elemento a la lista.
    void agregar(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y);

    //pre: 1 < posicion <= cantidad_elementos. 
    //post: Devolver el nodo que esta n posiciones despues del primero.
    Nodo* devolver_nodo(int posicion);

    //pre:
    //post: Devuelve el siguiente nodo respesto del nodo actual.
    Nodo* devolver_siguiente(Nodo* nodo_actual);


    //pre: deben haber sido cargados los nodos en la lista antes.
    //post: Inicializa todos los nodos adyacentes.
    void asignar_nodos_adyacentes(int filas, int columnas, Nodo* nodo);

    ~Lista();
};

#endif //LISTA_H

