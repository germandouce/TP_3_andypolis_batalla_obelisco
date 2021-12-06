#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"


const char CAMINO = 'C';
const char BETUN = 'B';
const char LAGO = 'L';
const char MUELLE = 'M';
const char TERRENO = 'T';

//valores tomados desde jugador 1

const int PESO_CAMINO = 4;
const int PESO_BETUN = 0;
const int PESO_LAGO = 2; //el jugador 2 es 5
const int PESO_MUELLE = 5; //el posicionjugador 2 es 2
const int PESO_TERRENO = 25;

const int DISTANCIA_INICIAL_ORIGEN = 0;

class Grafo {
//ATRIBUTOS
private:
    int ** matriz_adyacencia;
    Lista* lista_vertices;
    Lista* nodos_a_visitar;
    Lista* camino_minimo;

//METODOS



public:

int transformar_terreno_a_peso(char tipo_terreno);

Grafo(Lista* lista_vertices);

void recorrer_nodo(Nodo* nodo_anterior, int distancia_origen_nodo_anterior, int num_nodo_anterior, int num_nodo_adyacente);

bool no_fue_visitado(int num_nodo_adyacente, Lista* nodos_visitados);

void inicializar_lista_vertices(Lista* lista_vertices);

void inicializar_matriz_adyacencia();

void cargar_matriz_adyacencia(char** matriz_terrenos, int cantidad_filas, int cantidad_columnas);

void crear_grafo(int cantidad_filas, int cantidad_columnas);

void agregar_camino(int origen, int destino, int peso);

void calcular_camino_minimo_dijktra(int origen, int destino);
    
void mostrar_matriz_adyacencia();





};

#endif //GRAFO_H
