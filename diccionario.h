#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "nodo_dict.h"

class Diccionario {
    
    private:
    
    Nodo_dict* origen;

    public:

    //Constructor de dicionario
    Diccionario();

    // PRE: Recibe un edificio
    // POST: Inserta un edificio en el diccionario
    void agregar_edificio(Edificio* edificio);

    // PRE : Recibe un id entre 2 valores limites, si son edificios,
    // entre 1 y 7 si son materiales, entre ??? y ???
    // POST: devuelve true si el id se está en el diccionario
    Edificio* buscar_edificio(int id);

    // PRE: -
    // POST: Borra todos los nodos del diccionario
    void borrar_todo();
    
    private:

    // PRE: Recibe un nodo y el edificio a insertar
    // POST: Ingresa el nodo en su posicion correspondiente
    Nodo_dict* agregar_edificio(Nodo_dict* nodo, Edificio* edificio);
    
    //PRE: Recibe id y un nodo
    //POST: Devuelve true si el id esta en el diccionacio
    Nodo_dict* buscar(Nodo_dict* nodo, int id);

    // PRE: Recibe el nodo
    // POST: Borra los nodos derechos e izquierdos en cuestion
    void borrar_todo(Nodo_dict* nodo);

    //Destructor de diccionario
    ~Diccionario();
};

#endif //DICCIONARIO_H