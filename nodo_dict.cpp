#include "nodo_dict.h"

Nodo_dict::Nodo_dict(Edificio* edificio) {
    this -> edificio = edificio;
    this -> clave = edificio -> obtener_nombre();
    this -> izquierdo = nullptr;
    this -> derecho = nullptr;
    this -> padre = nullptr;
}

Edificio* Nodo_dict::devolver_edificio() {
    return edificio;
}

string Nodo_dict::devolver_clave() {
    return clave;
}

void Nodo_dict::colocar_edificio(Edificio* edificio) {
    this -> edificio = edificio;
}

void Nodo_dict::colocar_nodo_derecho(Nodo_dict* derecho, Nodo_dict* padre) {
    this -> derecho = derecho;
    this -> padre = padre;
}

void Nodo_dict::colocar_nodo_izquierdo(Nodo_dict* izquierdo, Nodo_dict* padre) {
    this -> izquierdo = izquierdo;
    this -> padre = padre;
}

void Nodo_dict::colocar_nodo_derecho(Nodo_dict* derecho) {
    this -> derecho = derecho;
}

void Nodo_dict::colocar_nodo_izquierdo(Nodo_dict* izquierdo) {
    this -> izquierdo = izquierdo;
}

void Nodo_dict::coloca_nodo_padre(Nodo_dict* padre) {
    this -> padre = padre;
}

Nodo_dict* Nodo_dict::devolver_nodo_derecho() {
    return derecho;
}

Nodo_dict* Nodo_dict::devolver_nodo_izquierdo() {
    return izquierdo;
}

Nodo_dict* Nodo_dict::devolver_nodo_padre() {
    return padre;
}

bool Nodo_dict::es_hoja() {
    return devolver_nodo_derecho() == nullptr && devolver_nodo_izquierdo() == nullptr;
}

bool Nodo_dict::hijo_derecho_unico() {
    return devolver_nodo_izquierdo() == nullptr && devolver_nodo_derecho() != nullptr;
}

bool Nodo_dict::hijo_izquierdo_unico() {
    return devolver_nodo_derecho() == nullptr && devolver_nodo_izquierdo() != nullptr;
}

Nodo_dict::~Nodo_dict() {
    delete edificio;
}