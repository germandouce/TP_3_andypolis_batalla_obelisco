#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"
#include "../casilleros/casillero.h"

const int PRIMER_ELEMENTO = 1;

const string G_TERRENO = "T";

const int DISTANCIA_INICIAL_ORIGEN = 0;

class Grafo {

    private:
    int** matriz_adyacencia;
    Lista* lista_vertices;
   
    public:
    
    //pre: cantidad_filas > 0, cantidad_columnas > 0.
    //post: construye el grafo usando la cnatidad de filas y columnas
    Grafo(int cantidad_filas, int cantidad_columnas, Casillero*** mapa);

    //pre: cantidad de nodos> origen > 1
    //post: crea la lista de como va recorrer los nodos del camino minimo
    Lista* crear_lista_a_recorrer(int origen);

    //pre: cantidad de nodos > num_nodo_raiz > 0,cantidad de nodos > num_nodo_adyacente > 0, 1 > es_jugador2 > 0.
    //post: Actualiza los atributos de nodo: anterior(su nodo predecesor) y distancia_origen(representa la mejor distancia desde del origen).
    void recorrer_nodo(int num_nodo_raiz, int num_nodo_adyacente, Casillero*** mapa, bool es_jugador2);

    void recorrer_nodos_adyacentes(int cantidad_nodos_adyacentes,  int* &vector_adyacentes, int num_nodo_raiz, int* &nodos_a_recorrer, int &visitados,  Casillero*** mapa, bool es_jugador2, int &posicion);
    
    //pre: cantidad de nodos > num_nodo_adyacente > 1, cantidad de nodos > cantidad_elementos > 0
    //post: informa si el nodo adyacente ya se encuentra entre los nodos a recorrer.
    bool esta_en_vector(int num_nodo_adyacente, int* nodos_a_recorrer, int cantidad_elementos);

    //pre:
    //post: inicializa la lista de vertices.
    void inicializar_lista_vertices(Lista* lista_vertices);

    //pre:
    //post: inicializa la matriz de adyacencia.
    void inicializar_matriz_adyacencia();

    //pre: cantidad de nodos > cantidad_filas > 0, cantidad de nodos > cantidad_columnas > 0.
    //post: carga la matriz de adyacencias.
    void cargar_matriz_adyacencia(int cantidad_filas, int cantidad_columnas, Casillero*** mapa);

    //pre: cantidad de nodos > cantidad_filas > 0, cantidad de nodos > cantidad_columnas > 0.
    //post: crea el grafo. 
    void crear_grafo(int cantidad_filas, int cantidad_columnas);

    //pre: cantidad de nodos > origen > 1, cantidad de nodos > destino > 1, INFINITO > peso, 0.
    //post: agrega una arista entre dos nodos.
    void agregar_camino(int origen, int destino, int peso);
    
    //pre: cantidad de nodos > origen > 1, cantidad de nodos > destino > 1.
    //post: calcula el camino minimo mediante dijsktra.
    void calcular_camino_minimo_dijsktra(int origen, int destino, Casillero*** mapa, bool es_jugador2);

    //pre: cantidad de filas > fila > 0, cantidad de columnas > columna > 0.
    //post: informa si existe edificio.
    bool existe_edificio(int fila, int columna, Casillero*** matriz);

    //pre: cantidad de nodos > num_nodo > 1.
    //post: informa si se puede ir del origen al destino.
    bool esta_atrapado(Casillero*** matriz, int num_nodo);

    //pre:
    //post: reinicia el vector de vertices para poder calcular los siguientes caminos minimos(distancia_origen, anterior)
    void reiniciar_vector_vertices();
    
    //pre:
    //post: muestra la matriz de adyacencia.
    void mostrar_matriz_adyacencia();

    //pre: cantidad de nodos > visitados > 0, cantidad de nodos > posicion > 1.
    //post: ordena el vector de distancias segun distancia al origen de menor a mayor.
    void ordenar_vector_distancia_min(int* &nodos_a_recorrer, int visitados, int posicion);

    //pre:
    //post: Devuelve la lista de vertices. 
    Lista* devolver_lista_vertices();

    //pre:
    //post: Libera la matriz de adyacencia
    void liberar_matriz_de_adyacencia();
};

#endif //GRAFO_H
