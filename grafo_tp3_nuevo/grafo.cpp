#include "grafo.h"

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    lista_vertices = nullptr;
    
}

void Grafo::inicializar_lista_vertices(Lista* lista_vertices){
    this -> lista_vertices = lista_vertices;
}

void Grafo::agregar_camino(int origen, int destino, int peso) {
    
    matriz_adyacencia[origen][destino] = peso;
        
}

void Grafo::cargar_matriz_adyacencia(char** matriz_terrenos, int filas, int columnas){
    for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++){
        bool* existe_adyacente = lista_vertices -> devolver_nodo(i) -> obtener_existe_adyacente();
        if (existe_adyacente[POSICION_ARRIBA]){
            matriz_adyacencia[i][i - columnas] = transformar_terreno_a_peso(matriz_terrenos[i][i - columnas]);
        }
        else if (existe_adyacente[POSICION_ABAJO]){
            matriz_adyacencia[i][i + columnas] = transformar_terreno_a_peso(matriz_terrenos[i][i + columnas]);
        }
        else if (existe_adyacente[POSICION_DERECHO]){
            matriz_adyacencia[i][i + 1] = transformar_terreno_a_peso(matriz_terrenos[i][i + 1]);
        }
        else if (existe_adyacente[POSICION_IZQUIERDO]){
            matriz_adyacencia[i][i - 1] = transformar_terreno_a_peso(matriz_terrenos[i][i - 1]);
        }
    }
   
}

int Grafo::transformar_terreno_a_peso(char tipo_terreno){
    int peso;
    
    if (tipo_terreno == CAMINO){
        peso = PESO_CAMINO;
    }
    else if (tipo_terreno == BETUN){
        peso = PESO_BETUN;
    }
    else if (tipo_terreno == LAGO){
        peso = PESO_LAGO;
    }
    else if (tipo_terreno == MUELLE){
        peso = PESO_MUELLE;
    }
    else{
        peso = PESO_TERRENO;
    }

    return peso;
}