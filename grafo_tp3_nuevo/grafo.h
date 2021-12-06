#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"

const int PRIMER_ELEMENTO = 1;

const string G_CAMINO = "C";
const string G_BETUN = "B";
const string G_LAGO = "L";
const string G_MUELLE = "M";
const string G_TERRENO = "T";

//valores tomados desde jugador 1

const int PESO_CAMINO = 4;
const int PESO_BETUN = 0;
const int PESO_LAGO = 2; //el jugador 2 es 5
const int PESO_MUELLE = 5; //el posicionjugador 2 es 2
const int PESO_TERRENO = 25;//25

const int DISTANCIA_INICIAL_ORIGEN = 0;

class Grafo {
//ATRIBUTOS
private:
	string** matriz_terrenos;
    int ** matriz_adyacencia;
    Lista* lista_vertices;
    Lista* camino_minimo;

//METODOS



public:

int transformar_terreno_a_peso(string tipo_terreno);

Grafo(Lista* lista_vertices);

Grafo(int cantidad_filas, int cantidad_columnas);

Lista* crear_lista_a_recorrer(int origen);

void recorrer_nodo(int num_nodo_raiz, int num_nodo_adyacente);

bool no_fue_visitado(int num_nodo_adyacente, Lista* nodos_visitados);

bool no_esta_en_vector(int num_nodo_adyacente, int* nodos_a_recorrer, int cantidad_elementos);

void inicializar_lista_vertices(Lista* lista_vertices);

void inicializar_matriz_adyacencia();

void cargar_matriz_adyacencia(string** matriz_terrenos, int cantidad_filas, int cantidad_columnas);

void crear_grafo(int cantidad_filas, int cantidad_columnas);

void agregar_camino(int origen, int destino, int peso);

void calcular_camino_minimo_dijktra(int origen, int destino);
    
void mostrar_matriz_adyacencia();

void ordenar_vector_distancia_min(int* &nodos_a_recorrer, int visitados, int posicion);

void inicializar_matriz_terrenos(int cantidad_filas, int cantidad_columnas);

Lista* devolver_lista_vertices();

//pre:
//post: Devuelve la matriz de terrenos
string** devolver_matriz_terrenos();

//pre:
//post: Libera la matriz de adyacencia
void liberar_matriz_de_adyacencia();

};

#endif //GRAFO_H
