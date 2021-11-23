#ifndef NODO_DICT_H
#define NODO_DICT_H

#include <iostream>

template <typename Dato>
class Nodo_dict {

    private:

    // ATRIBUTOS.
    
    Dato* dato;
    Nodo_dict* izquierda;
    Nodo_dict* derecha;
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
    // POST: agrega el nodo de su izquierda y su antecesor
    void colocar_nodo_izquierdo(Nodo_dict* izquierda, Nodo_dict* padre );

    // PRE: Recibe el nodo derecho y el nodo padre
    // POST: agrega el nodo de su derecha y su antecesor
    void colocar_nodo_derecho(Nodo_dict* derecha, Nodo_dict* padre);

    // PRE: Recibe un nodo
    // POST: Coloca el nodo a la izquierda
    void colocar_nodo_izquierdo(Nodo_dict* izquierda);

    // PRE: Recibe un nodo
    // POST: coloca el nodo a la derecha
    void colocar_nodo_derecho(Nodo_dict* derecha);

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
    
}

template <typename Dato>
Nodo_dict<Dato>::Nodo_dict(){
    
}

template <typename Dato>
Dato* Nodo_dict<Dato>::devolver_dato() {
    
}

template <typename Dato>
int Nodo_dict<Dato>::devolver_id() {
    
}
template <typename Dato>
void Nodo_dict<Dato>::colocar_dato(Dato* dato) {
    
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_derecho(Nodo_dict* derecha, Nodo_dict* padre) {
    
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_izquierdo(Nodo_dict* izquierda, Nodo_dict* padre ) {
    
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_derecho(Nodo_dict* derecha) {
    
}

template <typename Dato>
void Nodo_dict<Dato>::colocar_nodo_izquierdo(Nodo_dict* izquierda) {

}

template <typename Dato>
void Nodo_dict<Dato>::coloca_nodo_padre(Nodo_dict* padre) {
    
}


template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_derecho() {

}

template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_izquierdo() {
    
}

template <typename Dato>
Nodo_dict<Dato>* Nodo_dict<Dato>::devolver_nodo_padre(){
    
}

template <typename Dato>
bool Nodo_dict<Dato>::es_hoja() {

}

template <typename Dato>
bool Nodo_dict<Dato>::hijo_derecho_unico() {

}

template <typename Dato>
bool Nodo_dict<Dato>::hijo_izquierdo_unico() {

}

template <typename Dato>
Nodo_dict<Dato>::~Nodo_dict() {
    
}


#endif // NODO_DICT_H