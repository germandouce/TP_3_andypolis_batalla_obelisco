#include "Nodo_listas.h"

Nodo_l::Nodo_l() {
    edificio = edificio;
    siguiente = nullptr;
}

Edificio* Nodo_l::obtener_edificio() {
    return edificio;
}

Nodo_l* Nodo_l::obtener_siguiente() {
    return siguiente;
}

void Nodo_l:: cambiar_siguiente(Nodo_l* puntero) {
    siguiente = puntero;
}



