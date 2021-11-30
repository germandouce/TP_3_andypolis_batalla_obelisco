#include "lista.h"

Lista::Lista(){
    cantidad_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

Lista::Lista(int cantidad_elementos, int filas, int columnas){
    for(int i = 1; i <= cantidad_elementos; i++){
        int columna = i;
        int fila = PRIMER_FILA;
        agregar(i, filas, columnas, fila, columna);
        asignar_nodos_adyacentes(filas, columnas, devolver_nodo(i));
        devolver_nodo(i) -> inicializar_existe_adyacente();
        devolver_nodo(i) -> asignar_distancia_minima();
        devolver_nodo(i) -> asignar_distancia_minima(INFINITO);
        if (columna == columnas){
            columna = 0;
            fila++;
        }
    }

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

//esto podria ser recursivo
Nodo* devolver_siguiente(Nodo* nodo_actual){
    return nodo_actual -> obtener_siguiente();
}

Nodo* Lista::devolver_nodo(int posicion){
    
    Nodo* siguiente = primero -> obtener_siguiente();
    
    for (int i = 0; i <= posicion; i++){
            
        siguiente = siguiente -> obtener_siguiente();

    }
    
    return siguiente;
}
// hay que inicializar toda la lista con sus elementos


void Lista::asignar_nodos_horizontales(int filas, int columnas, Nodo* nodo){

    if (nodo -> obtener_vertice() -> obtener_posicion_x() == PRIMER_COLUMNA){
        nodo -> asignar_izquierdo(nullptr);
    }
    else if(nodo -> obtener_vertice() -> obtener_posicion_x() == columnas){
        nodo -> asignar_derecho(nullptr);
    }
    else{
        nodo -> asignar_izquierdo(nodo -> obtener_anterior());
        nodo -> asignar_derecho(nodo -> obtener_siguiente());
    }

}

void Lista::asignar_nodos_verticales(int filas, int columnas, Nodo* nodo){

    if (nodo -> obtener_vertice() -> obtener_posicion_y() == PRIMER_FILA){
        nodo -> asignar_arriba(nullptr);
    }
    else if(nodo -> obtener_vertice() -> obtener_posicion_y() == filas){
        nodo -> asignar_abajo(nullptr);
    }
    else{
        nodo -> asignar_arriba(devolver_nodo(nodo ->obtener_vertice() -> obtener_posicion_x() - columnas));
        nodo -> asignar_abajo(devolver_nodo(nodo ->obtener_vertice() -> obtener_posicion_x() + columnas));
    }

}

void Lista::asignar_nodos_adyacentes(int filas, int columnas, Nodo* nodo){

    asignar_nodos_verticales(filas, columnas, nodo);
    asignar_nodos_horizontales(filas, columnas, nodo);

}

Lista::~Lista() {
    Nodo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}
