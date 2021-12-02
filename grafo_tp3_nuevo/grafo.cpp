#include "grafo.h"

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    lista_vertices = nullptr;
    
}

void Grafo::calcular_camino_minimo_dijktra(int origen, int destino, int cantidad_filas, int cantidad_columnas){
    //tengo que tener la lista con todos los nodos y si paso por ahi
    // arranco del origen y tengo que ver los nodos adyacentes empesando por el que tiene menos peso
	/*
    lista_vertices -> devolver_nodo(origen) -> asignar_distancia_minima();
    int nueva_distancia_minima = lista_vertices -> devolver_nodo(origen) -> obtener_distancia_minima_origen() + matriz_adyacencia[origen][origen + cantidad_columnas];
    lista_vertices -> devolver_nodo(origen) -> obtener_abajo() -> reemplazar_distancia_minima(nueva_distancia_minima);
*/
}

void Grafo::inicializar_lista_vertices(Lista* lista_vertices){
    this -> lista_vertices = lista_vertices;
}

void Grafo::agregar_camino(int origen, int destino, int peso) {
    
    matriz_adyacencia[origen][destino] = peso;
        
}

void Grafo::cargar_matriz_adyacencia(char** matriz_terrenos, int cantidad_filas, int cantidad_columnas){
    for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++){
    	int k = 0;
    	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos(); j++){

    		int nodo_adyacente = lista_vertices-> devolver_nodo(i) -> obtener_vector_adyacentes()[k];

    		if ((j + 1) == nodo_adyacente){
    			matriz_adyacencia[i][j] = transformar_terreno_a_peso(matriz_terrenos[i][j]);
    			k++;
    		}
    		else if (i == j){
    			matriz_adyacencia[i][j] = 0;
    		}
    		else{
    			matriz_adyacencia[i][j] = INFINITO;
    		}
    	}
    }
}

void Grafo::mostrar_matriz_adyacencia(){
    for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++){
    	cout << endl;
       	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos(); j++){
    		cout <<"["<< matriz_adyacencia[i][j] << "] ";
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
