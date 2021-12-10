#ifndef NODO_DICT_H
#define NODO_DICT_H

#include <iostream>
#include "registro_edificios/edificio.h"

class Nodo_dict {
    
    private:

    // ATRIBUTOS.
    
    Edificio* edificio;
    Nodo_dict* izquierdo;
    Nodo_dict* derecho;
    Nodo_dict* padre;
    string clave;

    public:

    // METODOS

    // Constructor con parametros
    Nodo_dict(Edificio* edificio);

    // Constructor sin parametros (por default)
    Nodo_dict();

    // PRE: -
    // POST: Devuelve el edificio
    Edificio* devolver_edificio();

    // PRE: -
    // POST: Devuelve la clave del edificio
    string devolver_clave();

    // PRE: Recibe un edificio
    // POST: coloca el edificio en el nodo
    void colocar_edificio(Edificio* edificio);

    // PRE: Recibe un nodo
    // POST: Coloca el nodo como su padre
    void coloca_nodo_padre(Nodo_dict* padre);
    
    // PRE: Recibe el nodo izquierdo y el nodo padre
    // POST: agrega el nodo de su izquierdo y su antecesor
    void colocar_nodo_izquierdo(Nodo_dict* izquierdo, Nodo_dict* padre);

    // PRE: Recibe el nodo derecho y el nodo padre
    // POST: agrega el nodo de su derecho y su antecesor
    void colocar_nodo_derecho(Nodo_dict* derecho, Nodo_dict* padre);

    // PRE: Recibe un nodo
    // POST: Coloca el nodo a la izquierdo
    void colocar_nodo_izquierdo(Nodo_dict* izquierdo);

    // PRE: Recibe un nodo
    // POST: coloca el nodo a la derecho
    void colocar_nodo_derecho(Nodo_dict* derecho);

    // PRE: -
    // POST: Devuelve el nodo izquierdo
    Nodo_dict* devolver_nodo_izquierdo();

    // PRE: -
    // POST: Devuelve el nodo derecho
    Nodo_dict* devolver_nodo_derecho();

    // PRE: -
    // POST: Devuelve el antecesor
    Nodo_dict* devolver_nodo_padre();

    // PRE: -
    // POST: Devuelve true si es una hoja (el nodo no tiene hijos)
    bool es_hoja();

    // PRE: -
    // POST: Devuelve true si solo tiene hijo derecho
    bool hijo_derecho_unico();

    // PRE: -
    // POST: Devuelve true si solo tiene hijo izquierdo
    bool hijo_izquierdo_unico();

    //Destructor de nodo
    ~Nodo_dict();
};

#endif // NODO_DICT_H