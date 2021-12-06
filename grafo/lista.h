#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"



class Lista{

//ATRIBUTOS
private:
    int cantidad_elementos;
    Nodo* primero;
    Nodo* ultimo;


//METODOS

public:
    Lista();

    void agregar_vertices(int cantidad_elementos, int cantidad_filas, int cantidad_columnas);

    //pre:
    //post: Devuelve la cantidad de elementos que tiene la lista.
    int obtener_cantidad_elementos();

    //pre:
    //post: Agrega un nuevo elemento a la lista.
    void agregar(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna);

    void agregar(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna, Nodo* nodo_original);

    void agregar_fifo(Nodo* nodo_original);

    void agregar(Nodo* nuevo_nodo);

    //pre: 1 < posicion <= cantidad_elementos. 
    //post: Devolver el nodo que esta n posiciones despues del primero.
    Nodo* devolver_nodo(int posicion);

    //pre:
    //post: Devuelve el siguiente nodo respesto del nodo actual.
    Nodo* devolver_siguiente(Nodo* nodo_actual);

    void mostrar();

    void eliminar_nodo();

    ~Lista();
};

#endif //LISTA_H

