#include "casillero_transitable.h"

Casillero_transitable::Casillero_transitable(int fila, int col){
    this->num = 1;
    this-> fila = fila;
    this-> col = col;
}

int Casillero_transitable ::obtener_fila(){
    return fila;
}

int Casillero_transitable ::obtener_col(){
    return col;
}