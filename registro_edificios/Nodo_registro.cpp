#include "Nodo_registro.h"

Nodo_R::Nodo_R() {
    edificio = nullptr;
    siguiente = nullptr;
}

Nodo_R::Nodo_R(Edificio*edificio) {
    this -> edificio = edificio;
    siguiente = nullptr;

}

Edificio* Nodo_R::obtener_edificio() {
    return edificio;
}

Nodo_R* Nodo_R::obtener_siguiente() {
    return siguiente;
}

void Nodo_R:: cambiar_siguiente(Nodo_R* puntero) {
    siguiente = puntero;
}



