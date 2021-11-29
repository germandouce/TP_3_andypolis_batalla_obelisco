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

void Lista::asignar_nodos_adyacentes(int filas, int columnas, Nodo* nodo){
    primero -> asignar_derecho(primero ->obtener_siguiente());
    primero -> asignar_abajo(devolver_nodo(columnas + 1));

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

Lista::~Lista() {
    Nodo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}
