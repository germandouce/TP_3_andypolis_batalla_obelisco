#include "vertice.h"

Vertice::Vertice(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y) {
    this -> numero_vertice = numero_vertice;
    this -> filas = filas;
    this -> columnas = columnas;
    this -> posicion_x = posicion_x;
    this -> posicion_y = posicion_y;
}

Vertice::Vertice(){
    numero_vertice = 0;
    filas = 0;
    columnas = 0;
    posicion_x = 0;
    posicion_y = 0;
}

int Vertice::obtener_numero_vertice() {
    return numero_vertice;
}

int Vertice::obtener_fila() {
    return filas;
}

int Vertice::obtener_columna() {
    return columnas;
}

int Vertice::obtener_posicion_x(){
    return posicion_x;
}

int Vertice::obtener_posicion_y(){
    return posicion_y;
}

