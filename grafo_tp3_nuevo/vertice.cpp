#include "vertice.h"

Vertice::Vertice(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna) {
    this -> numero_vertice = numero_vertice;
    this -> cantidad_filas = cantidad_filas;
    this -> cantidad_columnas = cantidad_columnas;
    this -> fila = fila;
    this -> columna = columna;
}

Vertice::Vertice(){
    numero_vertice = 0;
    cantidad_filas = 0;
    cantidad_columnas = 0;
    fila = 0;
    columna = 0;
}

int Vertice::obtener_numero_vertice() {
    return numero_vertice;
}

int Vertice::obtener_cantidad_filas() {
    return cantidad_filas;
}

int Vertice::obtener_cantidad_columnas() {
    return cantidad_columnas;
}

int Vertice::obtener_fila(){
    return fila;
}

int Vertice::obtener_columna(){
    return columna;
}

