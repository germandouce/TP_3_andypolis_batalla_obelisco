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

void Lista::mostrar(){
	int fila = primero -> obtener_vertice() -> obtener_fila();
	int columna = primero -> obtener_vertice() -> obtener_columna();
	int cantidad_filas = primero -> obtener_vertice() -> obtener_cantidad_filas();
	int cantidad_columnas = primero -> obtener_vertice() -> obtener_cantidad_columnas();
	cout << "nodo " << primero -> obtener_vertice()-> obtener_numero_vertice() << " :" << endl;
	cout << "fila, columna: (" << fila << ", " << columna << ")" << endl;
	cout << "Nodos_adyacentes: " << endl;
	for(int j = 0; j < primero->encontrar_tipo_nodo(fila, columna, cantidad_filas, cantidad_columnas) ; j++){
		cout << "nodo " << primero -> obtener_vector_adyacentes()[j] <<", "<< endl;
	}
	cout << " " << endl;
	Nodo* auxiliar = primero;
	for (int i = 1; i < cantidad_elementos ; i++){

		auxiliar = auxiliar -> obtener_siguiente();
		if (auxiliar != nullptr){
			fila = auxiliar -> obtener_vertice() -> obtener_fila();
			columna = auxiliar -> obtener_vertice() -> obtener_columna();
			cantidad_filas = auxiliar -> obtener_vertice() -> obtener_cantidad_filas();
			cantidad_columnas = auxiliar -> obtener_vertice() -> obtener_cantidad_columnas();

			cout << "nodo " << auxiliar -> obtener_vertice()-> obtener_numero_vertice() << " :" << endl;
			cout << "fila, columna: (" << auxiliar -> obtener_vertice() -> obtener_fila() << ", " << auxiliar -> obtener_vertice() -> obtener_columna() << ")" << endl;
			cout << "Nodos_adyacentes: " << endl;
			for(int k = 0; k < auxiliar -> encontrar_tipo_nodo(fila, columna, cantidad_filas, cantidad_columnas) ; k++){
				cout << " nodo " << auxiliar -> obtener_vector_adyacentes()[k] <<", " << endl;
			}
			cout << " " << endl;
		}
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
