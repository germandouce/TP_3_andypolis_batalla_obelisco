#ifndef NODO_DICT_H
#define NODO_DICT_H

#include <iostream>
#include <string>

using namespace std;

template <typename Dato>
class Nodo_dict {
    
    private:

    // ATRIBUTOS.
    
    Dato* dato;
    Nodo_dict* izquierdo;
    Nodo_dict* derecho;
    Nodo_dict* padre;
    int id;

    public:

    // METODOS

    // Constructor con parametros
    Nodo_dict(Dato* dato);

    // Constructor sin parametros (por default)
    Nodo_dict();

    // PRE: -
    // POST: Devuelve el dato
    Dato* devolver_dato();

    // PRE: -
    // POST: Devuelve el ID del dato
    int devolver_id();

    // PRE: Recibe un dato
    // POST: coloca el dato en el nodo
    void colocar_dato(Dato* dato);

    // PRE: Recibe un nodo
    // POST: Coloca el nodo como su padre
    void coloca_nodo_padre(Nodo_dict* padre);
    
    // PRE: Recibe el nodo izquierdo y el nodo padre
    // POST: agrega el nodo de su izquierdo y su antecesor
    void colocar_nodo_izquierdo(Nodo_dict* izquierdo, Nodo_dict* padre );

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

template <typename Dato>
Nodo_dict<Dato>::Nodo_dict(Dato* dato){
    
    this -> dato = dato;
    std::cout<<dato;
    std::cout << (*dato)[0];
    this -> id = (int)((*dato)[0]);
    std::cout << id;
    this -> izquierdo = nullptr;
    this -> derecho = nullptr;
    this -> padre = nullptr;

}

template <typename Dato>
Dato* Nodo_dict<Dato>::devolver_dato() {
    return (this -> dato);
}

template <typename Dato>
int Nodo_dict<Dato>::devolver_id() {
    return ( this -> id );
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_dato(Dato* dato) {
    this -> dato = dato;
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_derecho(Nodo_dict* derecho, Nodo_dict* padre) {
    this -> derecho = derecho;
    this -> padre = padre;
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_izquierdo(Nodo_dict* izquierdo, Nodo_dict* padre ) {
    this -> izquierdo = izquierdo;
    this -> padre = padre;
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_derecho(Nodo_dict* derecho) {
    this -> derecho = derecho;
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_izquierdo(Nodo_dict* izquierdo) {
    this -> izquierdo = izquierdo;
}

template <typename Dato>
void Nodo_dict<Dato>::coloca_nodo_padre(Nodo_dict* padre) {
    this -> padre = padre;
}

template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_derecho() {
    return ( this -> derecho );
}

template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_izquierdo() {
    return ( this -> izquierdo );
}

template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_padre(){
    return ( this -> padre );
}

template <typename Dato>
bool Nodo_dict<Dato>::es_hoja() {
    return ( this -> devolver_nodo_derecho() == nullptr && devolver_nodo_izquierdo == nullptr );
}

template <typename Dato>
bool Nodo_dict<Dato>::hijo_derecho_unico() {
    return (this -> devolver_nodo_izquierdo() == nullptr && this -> devolver_nodo_derecho() != nullptr );
}

template <typename Dato>
bool Nodo_dict<Dato>::hijo_izquierdo_unico() {
    return (this -> devolver_nodo_derecho() == nullptr && this -> devolver_nodo_izquierdo() != nullptr );
}

template <typename Dato>
Nodo_dict<Dato>::~Nodo_dict() {

}


#endif // NODO_DICT_H