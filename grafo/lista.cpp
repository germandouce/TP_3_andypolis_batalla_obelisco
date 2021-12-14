#include "lista.h"



Lista::Lista(){

    cantidad_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}


void Lista::agregar_vertices(int cantidad_elementos, int cantidad_filas, int cantidad_columnas){
	int fila = PRIMER_FILA;
	int columna = PRIMER_COLUMNA;

    for(int i = 1; i <= cantidad_elementos; i++){


        agregar(i, cantidad_filas, cantidad_columnas, fila, columna);
        if (columna == cantidad_columnas){
            columna = 0;
            fila++;
        }
        columna++;

    }
}

int Lista::obtener_cantidad_elementos(){
    return cantidad_elementos;
}

void Lista::agregar(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna) {
    Nodo* nuevo_nodo = new Nodo(numero_vertice, cantidad_filas, cantidad_columnas, fila, columna); //cambiar aca
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo); //cambio el atributo de nodo
        ultimo = nuevo_nodo; //cambio el atributo de lista
    }
    cantidad_elementos++;
}

void Lista::agregar(Nodo* nuevo_nodo) {

    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo); //cambio el atributo de nodo
        ultimo = nuevo_nodo; //cambio el atributo de lista
    }
    cantidad_elementos++;
}

void Lista::agregar_fifo(Nodo* nodo_original) {
    Nodo* nuevo_nodo = new Nodo(nodo_original);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {

    	nuevo_nodo -> asignar_siguiente(primero);
        primero = nuevo_nodo;

    }
    cantidad_elementos++;
}

//esto podria ser recursivo
Nodo* devolver_siguiente(Nodo* nodo_actual){
    return nodo_actual -> obtener_siguiente();
}

Nodo* Lista::devolver_nodo(int posicion){
    
    Nodo* nodo_buscado = primero ;
    
    if(posicion != 1){
    	for (int i = 1; i <= posicion - 1; i++){
            
    		nodo_buscado = nodo_buscado -> obtener_siguiente();

    	}
    }
    
    return nodo_buscado;
}
// hay que inicializar toda la lista con sus elementos

void Lista::eliminar_nodo(){
    Nodo* siguiente;
    siguiente = primero -> obtener_siguiente();
    delete primero;
    primero = siguiente;
}




Lista::~Lista() {
    Nodo* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}
