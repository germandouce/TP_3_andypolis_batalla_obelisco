#ifndef NODO_H
#define NODO_H

#include "vertice.h"

const int CANTIDAD_NODOS_ADYACENTES = 4;

const int POSICION_ARRIBA = 0;
const int POSICION_ABAJO = 1;
const int POSICION_IZQUIERDO = 2;
const int POSICION_DERECHO = 3;


class Nodo
{
//ATRIBUTOS
private:
    Vertice* vertice;
    Nodo* adyacente_derecho; 
    Nodo* adyacente_izquierdo; 
    Nodo* adyacente_abajo;     
    Nodo* adyacente_arriba;
    Nodo* siguiente;
    Nodo* anterior;
    int distancia_minima_origen;

    bool* existe_adyacente;


//METODOS

public:
    void inicializar_existe_adyacente();

    //pre:
    //post: Inicializa el nodo con el vertice y sus vertices adyacentes.
    Nodo(int numero_vertice, int fila, int columna, int posicion_x, int posicion_y);

    //pre:
    //post: Inicializa el nodo adyacente derecho.
    void asignar_derecho(Nodo* vertice_derecho);

    //pre:
    //post: Inicializa el nodo adyacente izquierdo.
    void asignar_izquierdo(Nodo* vertice_izquierdo);
    
    //pre:
    //post: Inicializa el nodo adyacente superior.
    void asignar_arriba(Nodo* vertice_arriba);

    //pre:
    //post: Inicializa el nodo adyacente inferior.
    void asignar_abajo(Nodo* vertice_abajo);

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
    //post: Obtiene el nodo arriba
    Nodo* obtener_arriba();

    //pre:
    //post: Obtiene el nodo abajo
    Nodo* obtener_abajo();

    //pre:
    //post: Obtiene el nodo derecho
    Nodo* obtener_derecho();

    //pre:
    //post: Obtiene el nodo izquierdo
    Nodo* obtener_izquierdo();


    //pre:
    //post: Obtiene el vertice del nodo
    Vertice* obtener_vertice();

    //pre:
    //post: Obtiene vector existe_adyacente
    bool* obtener_existe_adyacente();

    //pre:
    //post: Devuelve distancia_minima_origen
    int obtener_distancia_minima_origen();

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