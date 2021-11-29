#include "nodo.h"

const int PRIMERA_FILA = 1;
const int PRIMERA_COLUMNA = 1;

Nodo::Nodo(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y){
    
    vertice = new Vertice(numero_vertice, fila, columna, posicion_x, posicion_y);
    adyacente_arriba = nullptr;
    adyacente_abajo = nullptr;
    adyacente_izquierdo = nullptr;
    adyacente_derecho = nullptr;
    siguiente = nullptr;

}

void Nodo::asignar_abajo(Nodo* vertice_abajo){
    this -> adyacente_abajo = vertice_abajo;
}

void Nodo::asignar_arriba(Nodo* vertice_arriba){
    this -> adyacente_arriba = vertice_arriba;
}

void Nodo::asignar_derecho(Nodo* vertice_derecho){
    this -> adyacente_derecho = vertice_derecho;
}

void Nodo::asignar_izquierdo(Nodo* vertice_izquierdo){
    this -> adyacente_izquierdo = vertice_izquierdo;
}

void Nodo::asignar_siguiente(Nodo* vertice_siguiente){
    this -> siguiente = vertice_siguiente;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}

Nodo::~Nodo() {
    delete vertice;
}

    /*
    //inicializar variables del vertice
    int numero_vertice = vertice -> obtener_vertice();
    int filas = vertice -> obtener_fila();
    int columnas = vertice -> obtener_columna();
    int posicion_x = vertice -> obtener_posicion_x();
    int posicion_y = vertice -> obtener_posicion_y();

    //asignar adyacentes
    if (posicion_x == PRIMERA_FILA){
        adyacente_arriba = nullptr;
    }

    else if(posicion_x == filas){
        adyacente_abajo = nullptr;
    }
    
    if (posicion_y == PRIMERA_COLUMNA){
        adyacente_izquierdo = nullptr;
    }
    */
 