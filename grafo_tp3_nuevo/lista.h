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

    //pre:
    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_elementos();

    //pre:
    //post: agrega un nuevo elemento a la lista
    void agregar(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y);

    //pre:
    //post:
    void asignar_nodos_adyacentes();


    ~Lista();
};

#endif //LISTA_H

