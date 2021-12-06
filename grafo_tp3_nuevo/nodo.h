#ifndef NODO_H
#define NODO_H

#include "vertice.h"



const int INFINITO = 99999;

const int CANTIDAD_NODOS_ADYACENTES = 4;

const int CUATRO_ARISTAS = 4;
const int TRES_ARISTAS = 3;
const int DOS_ARISTAS = 2;

const int PRIMERA_FILA = 1;
const int PRIMERA_COLUMNA = 1;


class Nodo
{
//ATRIBUTOS
private:
	int* vector_adyacentes;
    Vertice* vertice;
    Nodo* siguiente;
    Nodo* anterior;
    int distancia_minima_origen;




//METODOS

public:

    bool tiene_cuatro_aristas(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool tiene_tres_aristas(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool tiene_dos_aristas(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool esta_en_los_bordes(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool esta_arriba(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool esta_abajo(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool esta_izquierda(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);

    bool esta_derecha(int fila, int columna ,  int cantidad_filas, int cantidad_columnas);


    int encontrar_tipo_nodo(int fila, int columna, int cantidad_filas, int cantidad_columnas);

    //pre: Se tiene que haber inicializado los nodos primero
    //post: carga la lista de nodos adyacentes al nodo
    void cargar_vector_adyacentes();

    //pre:
    //post: Inicializa el nodo con el vertice y sus vertices adyacentes.
    Nodo(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna);

    Nodo(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna, Nodo* nodo_original);

    //pre:
    //post: Asigna el siguiente nodo por orden de numero de vertice
    void asignar_siguiente(Nodo* vertice_siguiente);

    //pre:
    //post: Asigna el nodo previo 
    void asignar_anterior(Nodo* vertice_anterior);

    //pre:
    //post: Obtiene el nodo siguiente
    Nodo* obtener_siguiente();

    //pre:
    //post: Obtiene el nodo anterior
    Nodo* obtener_anterior();

    //pre:
    //post: Obtiene el vertice del nodo
    Vertice* obtener_vertice();

    //pre:
    //post: Devuelve distancia_minima_origen
    int obtener_distancia_minima_origen();

    //pre:
    //post: Devuelve el vector de vertices adyacentes
    int* obtener_vector_adyacentes();

    //pre: distancia_minima_origen tiene que haber sido inicializado en 0.
    //post: Asigna el camino minimo desde el origen hasta el nodo.
    void asignar_distancia_minima(int peso_nodo);

    //pre:
    //post: Inicializa en 0 en el camino minimo desde el origen hasta el nodo.
    void asignar_distancia_minima();

    //pre:
    //post: Reemplaza el distancia_minima_origen por el nuevo valor.
    void reemplazar_distancia_minima(int distancia_minima_origen);

    //pre:
    //post: Elimina el vertice.
    ~Nodo();
};

#endif // NODO_H
