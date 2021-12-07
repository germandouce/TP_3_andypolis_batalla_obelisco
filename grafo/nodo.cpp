#include "nodo.h"

Nodo::Nodo(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna){
    
    vertice = new Vertice(numero_vertice, cantidad_filas, cantidad_columnas, fila, columna);
    siguiente = nullptr;
    anterior = 0;
    vector_adyacentes = nullptr;
    distancia_minima_origen = INFINITO;

}

Nodo::Nodo(Nodo* nodo_original){

    vertice = nodo_original -> obtener_vertice();
    siguiente = nullptr;
    anterior = 0;
    vector_adyacentes = nodo_original -> obtener_vector_adyacentes();
    distancia_minima_origen = INFINITO;
}

int Nodo::devolver_cantidad_aristas(){
	return  encontrar_tipo_nodo(obtener_vertice() -> obtener_fila(),  obtener_vertice() -> obtener_columna(), obtener_vertice()-> obtener_cantidad_filas(), obtener_vertice() -> obtener_cantidad_columnas());
}

void Nodo::cargar_vector_adyacentes(){
	int numero_vertice = obtener_vertice() -> obtener_numero_vertice();
	int cantidad_filas = obtener_vertice()-> obtener_cantidad_filas();
	int cantidad_columnas = obtener_vertice() -> obtener_cantidad_columnas();
	int fila = obtener_vertice() -> obtener_fila();
	int columna = obtener_vertice() -> obtener_columna();
	int cantidad_aristas = encontrar_tipo_nodo(fila, columna, cantidad_filas, cantidad_columnas);

	vector_adyacentes = new int[cantidad_aristas];
	int i = 0;
	if (!esta_arriba(fila, columna, cantidad_filas, cantidad_columnas)){
		vector_adyacentes[i] = numero_vertice - cantidad_filas;
		i++;
	}
	if (!esta_izquierda(fila, columna, cantidad_filas, cantidad_columnas)){
		vector_adyacentes[i] = numero_vertice - 1;
		i++;
	}
	if (!esta_derecha(fila, columna, cantidad_filas, cantidad_columnas)){
		vector_adyacentes[i] = numero_vertice + 1;
		i++;
	}
	if (!esta_abajo(fila, columna, cantidad_filas, cantidad_columnas)){
		vector_adyacentes[i] = numero_vertice + cantidad_columnas;
		i++;
	}
}

bool Nodo::esta_arriba(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (fila == PRIMERA_FILA);
}

bool Nodo::esta_abajo(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (fila == cantidad_filas);
}

bool Nodo::esta_izquierda(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (columna == PRIMERA_COLUMNA);
}

bool Nodo::esta_derecha(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (columna == cantidad_columnas);
}

bool Nodo::tiene_dos_aristas(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (esta_en_los_bordes(fila, columna, cantidad_filas, cantidad_columnas) && (fila == PRIMERA_FILA || fila == cantidad_filas) && (columna == PRIMERA_COLUMNA || columna == cantidad_columnas));
}

bool Nodo::tiene_tres_aristas(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (esta_en_los_bordes(fila, columna, cantidad_filas, cantidad_columnas) && !tiene_dos_aristas(fila, columna, cantidad_filas, cantidad_columnas));
}

bool Nodo::tiene_cuatro_aristas(int fila,  int columna,  int cantidad_filas, int cantidad_columnas){
	return (fila >PRIMERA_FILA && fila <cantidad_filas && columna > PRIMERA_COLUMNA && columna < cantidad_columnas);
}

bool Nodo::esta_en_los_bordes(int fila, int columna ,  int cantidad_filas, int cantidad_columnas){
	return (!tiene_cuatro_aristas(fila, columna, cantidad_filas, cantidad_columnas));
}

int Nodo::encontrar_tipo_nodo(int fila, int columna, int cantidad_filas, int cantidad_columnas){
	int tipo_nodo;
	if (tiene_cuatro_aristas(fila, columna,  cantidad_filas, cantidad_columnas)){
		tipo_nodo = CUATRO_ARISTAS;
	}
	else if (tiene_dos_aristas(fila, columna,  cantidad_filas, cantidad_columnas)){
		tipo_nodo = DOS_ARISTAS;
	}
	else if (tiene_tres_aristas(fila, columna,  cantidad_filas, cantidad_columnas)){
		tipo_nodo = TRES_ARISTAS;
	}

	return tipo_nodo;
}

int Nodo::obtener_distancia_minima_origen(){
    return distancia_minima_origen;
}

int* Nodo::obtener_vector_adyacentes(){
	return vector_adyacentes;
}

void Nodo::asignar_siguiente(Nodo* vertice_siguiente){
    this -> siguiente = vertice_siguiente;
}

void Nodo::asignar_anterior(int vertice_anterior){
    this -> anterior = vertice_anterior;
}

void Nodo::asignar_distancia_minima(){
    this -> distancia_minima_origen = 0;
}

void Nodo::asignar_distancia_minima(int peso_nodo){
    this -> distancia_minima_origen = peso_nodo;
}

void Nodo::reemplazar_distancia_minima(int distancia_minima_origen){
    this -> distancia_minima_origen = distancia_minima_origen;
}

Nodo* Nodo::obtener_siguiente(){

    return siguiente;
}

int Nodo::obtener_anterior(){
    return anterior;
}

Vertice* Nodo::obtener_vertice(){
	return vertice;
}

Nodo::~Nodo() {
    delete vertice;
}
