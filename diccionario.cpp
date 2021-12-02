#include "diccionario.h"

Diccionario::Diccionario() {
    this -> origen = nullptr;
}

void Diccionario::agregar_edificio(Edificio* edificio) {
    this -> origen = agregar_edificio(this -> origen, edificio);
}

Nodo_dict* Diccionario::agregar_edificio(Nodo_dict* nodo, Edificio* edificio) {
    
    if (nodo == nullptr) {
        nodo = new Nodo_dict(edificio);
    }
    else if (edificio -> obtener_diminutivo()[0] > nodo -> devolver_id()) {
        nodo -> colocar_nodo_derecho(agregar_edificio(nodo -> devolver_nodo_derecho(), edificio), nodo);
    }
    else {
        nodo -> colocar_nodo_izquierdo(agregar_edificio(nodo -> devolver_nodo_izquierdo(), edificio), nodo);
    }

    return nodo;
}

Edificio* Diccionario::buscar_edificio(int id) {
    return (buscar(this -> origen, id) -> devolver_edificio());
}

Nodo_dict* Diccionario::buscar(Nodo_dict* nodo, int id ) {

    if (nodo == nullptr || nodo -> devolver_id() == id)
        return nodo;

    if (id > nodo -> devolver_id())
        return buscar(nodo -> devolver_nodo_derecho(), id);

    return buscar(nodo -> devolver_nodo_izquierdo(), id);
}

void Diccionario::borrar_todo(Nodo_dict* nodo) {
    
    if (nodo == NULL) {
        return;
    }
    
    this -> borrar_todo(nodo -> devolver_nodo_izquierdo());
    this -> borrar_todo(nodo -> devolver_nodo_derecho());
    delete nodo;
}

void Diccionario::borrar_todo() {
    this -> borrar_todo(this -> origen);
}

Diccionario::~Diccionario() {
    this -> borrar_todo();
}