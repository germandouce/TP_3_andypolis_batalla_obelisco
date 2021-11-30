#include "grafo.h"

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    lista_vertices = nullptr;
    
}

void Grafo::calcular_camino_minimo_dijktra(int origen, int destino, int filas, int columnas){
    lista_vertices -> devolver_nodo(origen) -> asignar_distancia_minima();
    int nueva_distancia_minima = lista_vertices -> devolver_nodo(origen) -> obtener_distancia_minima_origen() + matriz_adyacencia[origen][origen + columnas];
    lista_vertices -> devolver_nodo(origen) -> obtener_abajo() -> reemplazar_distancia_minima(nueva_distancia_minima);

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

        for (int j = 0; i < lista_vertices -> obtener_cantidad_elementos(); j++){
            matriz_adyacencia[i][j] = INFINITO;
        }

        matriz_adyacencia[i][i] = 0;

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