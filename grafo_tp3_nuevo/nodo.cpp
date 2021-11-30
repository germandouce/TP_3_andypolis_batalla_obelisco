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
    anterior = nullptr;

}

int Nodo::obtener_distancia_minima_origen(){
    return distancia_minima_origen;
}

void Nodo::asignar_distancia_minima(int peso_nodo){
    this -> distancia_minima_origen = 0;
}

void Nodo::asignar_distancia_minima(int peso_nodo){
    this -> distancia_minima_origen = distancia_minima_origen + peso_nodo;
}

void Nodo::reemplazar_distancia_minima(int distancia_minima_origen){
    this -> distancia_minima_origen = distancia_minima_origen;
}

void Nodo::inicializar_existe_adyacente(){
    for (int i = 0; i < CANTIDAD_NODOS_ADYACENTES; i++){
        existe_adyacente[i] = true;
    }
    if (obtener_arriba() == nullptr){
        existe_adyacente[POSICION_ARRIBA] = false;
    }
    else if(obtener_abajo() == nullptr){
        existe_adyacente[POSICION_ABAJO] = false;
    }
    else if(obtener_izquierdo() == nullptr){
        existe_adyacente[POSICION_IZQUIERDO] = false;
    }
    else if (obtener_derecho() == nullptr){
        existe_adyacente[POSICION_DERECHO] = false;
    }
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

void Nodo::asignar_anterior(Nodo* vertice_anterior){
    this -> anterior = vertice_anterior;
}

Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}

Nodo* Nodo::obtener_anterior(){
    return anterior;
}

Nodo* Nodo::obtener_abajo(){
    return adyacente_abajo;
}

Nodo* Nodo::obtener_arriba(){
    return adyacente_arriba;
}

Nodo* Nodo::obtener_derecho(){
    return adyacente_derecho;
}

Nodo* Nodo::obtener_izquierdo(){
    return adyacente_izquierdo;
}

Vertice* Nodo::obtener_vertice(){
    return vertice;
}

bool* Nodo::obtener_existe_adyacente(){
    return existe_adyacente;
}

Nodo::~Nodo() {
    delete vertice;
}
