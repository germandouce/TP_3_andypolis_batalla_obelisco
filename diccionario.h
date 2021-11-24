#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include "nodo_dict.h"

template <typename Dato>
class Diccionario {
private:
    
    Nodo_dict<Dato>* origen;

public:

    //Constructor de dicionario
    Diccionario();

    // PRE: Recibe un dato
    // POST: Inserta un dato en el diccionario
    void agregar_dato( Dato* dato);
    

    int obtener_id(Dato* dato){
        return ( dato-> devolver_id())
    }

    // PRE : Recibe un id entre 2 valores limites, si son edificios,
    // entre 1 y 7 si son materiales, entre ??? y ???
    // POST: devuelve true si el id se está en el diccionario
    Dato* buscar_dato( int id);

    // PRE: -
    // POST: Borra todos los nodos del diccionario
    void borrar_todo();
    
    

private:

    // PRE: Recibe un nodo y el dato a insertar
    // POST: Ingresa el nodo en su posicion correspondiente
    Nodo_dict<Dato>* agregar_dato( Nodo_dict<Dato>* nodo, Dato* dato);
    
    //PRE: Recibe id y un nodo
    //POST: Devuelve true si el id esta en el diccionacio
    Nodo_dict<Dato>* buscar( Nodo_dict<Dato>* nodo, int id);

    // PRE: Recibe el nodo
    // POST: Borra los nodos derechos e izquierdos en cuestion
    void borrar_todo( Nodo_dict<Dato>* nodo);

    //Destructor de diccionario
    ~Diccionario();
};


template <typename Dato>
Diccionario<Dato>::Diccionario() {
    this -> origen = nullptr;
}

template <typename Dato>
void Diccionario<Dato>::agregar_dato( Dato* dato) {
    this -> origen = agregar_dato( this -> origen, dato);
}

template <typename Dato>
Nodo_dict<Dato>* Diccionario<Dato>::agregar_dato( Nodo_dict<Dato>* nodo, Dato* dato) {
    if (nodo == nullptr)
        nodo = new Nodo_dict(dato);

    else if ( dato -> devolver_id() > nodo -> devolver_id() )
        nodo -> colocar_nodo_derecho( agregar_dato( nodo -> devolver_nodo_derecho(), dato ), nodo);

    else
        nodo -> colocar_nodo_izquierdo( agregar_dato( nodo -> devolver_nodo_izquierdo(), dato ), nodo);


    return nodo;
}

template <typename Dato>
Dato* Diccionario<Dato>::buscar_dato(int id) {
    return ( buscar(this -> origen, id) -> devolver_dato() );
}

template <typename Dato>
Nodo_dict<Dato>* Diccionario<Dato>::buscar( Nodo_dict<Dato>* nodo, int id ) {

    if ( nodo == nullptr || nodo -> devolver_id() == id )
        return nodo;

    if (id > nodo -> devolver_id())
        return buscar(nodo -> devolver_nodo_derecho(), id);

    return buscar(nodo -> devolver_nodo_izquierdo(), id);
}

template <typename Dato>
void Diccionario<Dato>::borrar_todo( Nodo_dict<Dato>* nodo ) {
    
    if ( nodo == NULL ) {
        return;
    }
    
    this -> borrar_todo( nodo-> devolver_nodo_izquierdo() );
    this -> borrar_todo( nodo-> devolver_nodo_derecho() );
    delete nodo;
}

template <typename Dato>
void Diccionario<Dato>::borrar_todo() {
    this -> borrar_todo(this->origen);
}

template <typename Dato>
Diccionario<Dato>::~Diccionario() {
    this -> borrar_todo():
}

#endif //_DICCIONARIO_H