#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"
#include <iostream>

const char CAMINO = 'C';
const char BETUN = 'B';
const char LAGO = 'L';
const char MUELLE = 'M';
const char TERRENO = 'T';

//valores tomados desde jugador 1

const int PESO_CAMINO = 4;
const int PESO_BETUN = 0;
const int PESO_LAGO = 2; //el jugador 2 es 5
const int PESO_MUELLE = 5; //el jugador 2 es 2
const int PESO_TERRENO = 25;

using namespace std;

class Grafo {
//ATRIBUTOS
private:
    int ** matriz_adyacencia;
    Lista* lista_vertices;

//METODOS

int transformar_terreno_a_peso(char tipo_terreno);

public:

Grafo();

void inicializar_lista_vertices(Lista* lista_vertices);

void inicializar_matriz_adyacencia();

void cargar_matriz_adyacencia(char** matriz_terrenos, int filas, int columnas);

void crear_grafo(int filas, int columnas);

void agregar_camino(int origen, int destino, int peso);
    
void mostrar_grafo();





};

#endif //GRAFO_H
