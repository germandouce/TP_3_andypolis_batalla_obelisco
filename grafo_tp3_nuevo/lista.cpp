#include "lista.h"

Lista::Lista(){
    cantidad_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

int Lista::obtener_cantidad_elementos(){
    return cantidad_elementos;
}

void Lista::agregar(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y) {
    Nodo* nuevo_nodo = new Nodo(numero_vertice, fila, columna, posicion_x, posicion_y);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo); //cambio el atributo de nodo
        ultimo = nuevo_nodo; //cambio el atributo de lista
    }
    cantidad_elementos++;
}

Lista::~Lista() {
    Nodo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}
