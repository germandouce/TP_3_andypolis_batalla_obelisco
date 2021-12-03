#include "Nodo_listas.h"

Nodo_Reg_ed::Nodo_Reg_ed() {
    edificio = edificio;
    siguiente = 0;
}

Edificio* Nodo_Reg_ed::obtener_edificio() {
    return edificio;
}

Nodo_Reg_ed* Nodo_Reg_ed::obtener_siguiente() {
    return siguiente;
}

void Nodo_Reg_ed:: cambiar_siguiente(Nodo_Reg_ed* puntero) {
    siguiente = puntero;
}



