#include "grafo.h"

Grafo::Grafo(int cantidad_filas, int cantidad_columnas) {
	
	int num_nodo = PRIMER_ELEMENTO;
	lista_vertices = new Lista();
	
	for (int j = PRIMER_ELEMENTO; j <= cantidad_filas; j++) {
		for (int i = 1; i <= cantidad_columnas; i++) {

			lista_vertices -> agregar(num_nodo, cantidad_filas, cantidad_columnas, j, i);
			lista_vertices -> devolver_nodo(num_nodo) -> cargar_vector_adyacentes();
			num_nodo++;
		}
	}

   matriz_adyacencia = new int* [lista_vertices -> obtener_cantidad_elementos()];

   for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++) {
	   matriz_adyacencia[i] = new int [lista_vertices -> obtener_cantidad_elementos()];
   }

   inicializar_matriz_terrenos(cantidad_filas, cantidad_columnas);
}

Grafo::Grafo(Lista* lista_vertices) {

   this -> lista_vertices = lista_vertices;

   matriz_adyacencia = new int* [lista_vertices -> obtener_cantidad_elementos()];

   for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++) {
	   matriz_adyacencia[i] = new int [lista_vertices -> obtener_cantidad_elementos()];
	}

   int cantidad_filas = lista_vertices -> devolver_nodo(PRIMER_ELEMENTO) -> obtener_vertice() -> obtener_cantidad_filas();
   int cantidad_columnas = lista_vertices -> devolver_nodo(PRIMER_ELEMENTO) -> obtener_vertice() -> obtener_cantidad_columnas();
   
   inicializar_matriz_terrenos(cantidad_filas, cantidad_columnas);
}


void Grafo::inicializar_matriz_terrenos(int cantidad_filas, int cantidad_columnas) {
	
	matriz_terrenos = new string* [cantidad_filas];
	
	for (int i = 0; i < cantidad_filas; i++) {
		matriz_terrenos[i] = new string [cantidad_columnas];
	}
}

bool Grafo::no_fue_visitado(int num_nodo_adyacente, Lista* nodos_visitados) {
	int i = 1;
	int num_nodo_visitados;
	int cantidad_nodos_visitados;

	if (nodos_visitados -> obtener_cantidad_elementos() != 0) {
		num_nodo_visitados = nodos_visitados -> devolver_nodo(i) -> obtener_vertice() -> obtener_numero_vertice();
		cantidad_nodos_visitados = nodos_visitados -> obtener_cantidad_elementos();
	}
	else {
		num_nodo_visitados = 0;
		cantidad_nodos_visitados = 0;
	}

	while (num_nodo_adyacente != num_nodo_visitados && i < cantidad_nodos_visitados) {
		i++;
		num_nodo_visitados = nodos_visitados -> devolver_nodo(i) -> obtener_vertice() -> obtener_numero_vertice();
		cantidad_nodos_visitados = nodos_visitados -> obtener_cantidad_elementos();
	}

	return (num_nodo_adyacente != num_nodo_visitados);
}

bool Grafo::no_esta_en_vector(int num_nodo_adyacente, int* nodos_a_recorrer, int cantidad_elementos) {
		
	int posicion = 0;

	while (num_nodo_adyacente != nodos_a_recorrer[posicion] && posicion < cantidad_elementos) {
		posicion++;
	}

	return (num_nodo_adyacente != nodos_a_recorrer[posicion] );
}

void Grafo::recorrer_nodo(int num_nodo_raiz, int num_nodo_adyacente) {

	int peso_anterior = lista_vertices -> devolver_nodo(num_nodo_adyacente) -> obtener_distancia_minima_origen();
	int peso_nodo  = lista_vertices -> devolver_nodo(num_nodo_raiz) -> obtener_distancia_minima_origen() + matriz_adyacencia[num_nodo_raiz - 1][num_nodo_adyacente - 1];

	if (peso_nodo < peso_anterior) {
		
		lista_vertices -> devolver_nodo(num_nodo_adyacente) -> asignar_distancia_minima(peso_nodo);
		lista_vertices -> devolver_nodo(num_nodo_adyacente) -> asignar_anterior(num_nodo_raiz);
	}
}

void Grafo::ordenar_vector_distancia_min(int* &nodos_a_recorrer, int visitados, int posicion) {

	for (int i = visitados; i < posicion + 1 ; i++) {
		for (int j = i + 1; j < posicion + 1 ; j++) {

			int distancia_i = lista_vertices -> devolver_nodo(nodos_a_recorrer[i]) -> obtener_distancia_minima_origen();
			int distancia_j = lista_vertices -> devolver_nodo(nodos_a_recorrer[j]) -> obtener_distancia_minima_origen();
			
			if (distancia_i > distancia_j) {
				int aux = nodos_a_recorrer[i];
				nodos_a_recorrer[i] = nodos_a_recorrer[j];
				nodos_a_recorrer[j] = aux;
			}
		}
	}
}

void Grafo::calcular_camino_minimo_dijsktra(int origen, int destino) {

	int cantidad_edificios = 0;
	int posicion = 0;
	int visitados = 0;

	int* nodos_a_recorrer = new int [lista_vertices -> obtener_cantidad_elementos() - cantidad_edificios];
	nodos_a_recorrer[posicion] = origen;

	int cantidad_nodos_adyacentes = lista_vertices -> devolver_nodo(origen) -> devolver_cantidad_aristas();
	lista_vertices -> devolver_nodo(origen) -> asignar_distancia_minima();
	
	int num_nodo_raiz = origen;
	int* vector_adyacentes = lista_vertices -> devolver_nodo(num_nodo_raiz) -> obtener_vector_adyacentes();

	while (visitados != (lista_vertices -> obtener_cantidad_elementos() - cantidad_edificios)) {
		for (int i = 0; i < cantidad_nodos_adyacentes; i++) {

			int num_nodo_adyacente = vector_adyacentes[i];

			if (no_esta_en_vector(num_nodo_adyacente, nodos_a_recorrer, visitados)) {
				recorrer_nodo(num_nodo_raiz, num_nodo_adyacente);
			}

			if (no_esta_en_vector(num_nodo_adyacente, nodos_a_recorrer, posicion)) {

				posicion++;
				nodos_a_recorrer[posicion] = vector_adyacentes[i];
			}
		}

		visitados++;
		ordenar_vector_distancia_min(nodos_a_recorrer, visitados, posicion);

		num_nodo_raiz = nodos_a_recorrer[visitados];
		cantidad_nodos_adyacentes = lista_vertices -> devolver_nodo(num_nodo_raiz) -> devolver_cantidad_aristas();
		vector_adyacentes = lista_vertices -> devolver_nodo(num_nodo_raiz) -> obtener_vector_adyacentes();
	}
}

void Grafo::reiniciar_vector_vertices() {
	
	for(int i = PRIMER_ELEMENTO; i < lista_vertices -> obtener_cantidad_elementos(); i++) {
		lista_vertices -> devolver_nodo(i) -> asignar_distancia_minima(INFINITO);
		lista_vertices -> devolver_nodo(i) -> asignar_anterior(0);
	}
}

void Grafo::inicializar_lista_vertices(Lista* lista_vertices) {
    this -> lista_vertices = lista_vertices;
}

void Grafo::agregar_camino(int origen, int destino, int peso) {
    matriz_adyacencia[origen][destino] = peso;     
}

void Grafo::cargar_matriz_adyacencia(int cantidad_filas, int cantidad_columnas) {
	
	for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos() ; i++) {
		
		int k = 0;

    	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos()  ; j++) {

    		int numero_nodo_adyacente = lista_vertices-> devolver_nodo(i + 1) -> obtener_vector_adyacentes()[k];

    		if ((j + 1) == numero_nodo_adyacente) {
    			Nodo* nodo_adyacente = lista_vertices-> devolver_nodo(j + 1);

    			int fila = nodo_adyacente -> obtener_vertice() -> obtener_fila();
    			int columna = nodo_adyacente -> obtener_vertice() -> obtener_columna();
    			int peso = transformar_terreno_a_peso(matriz_terrenos[fila - 1][columna - 1]);

    			matriz_adyacencia[i][j] = peso;
    			k++;
    		}
    		else if (i == j) {
    			matriz_adyacencia[i][j] = 0;
    		}
    		else {
    			matriz_adyacencia[i][j] = INFINITO;
    		}
    	}
    }
}

void Grafo::mostrar_matriz_adyacencia() {
    
	for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++) {
    	cout << endl;
       	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos(); j++) {
    		
			if (matriz_adyacencia[i][j] == INFINITO) {
    			cout << matriz_adyacencia[i][j] << " | ";
    		}
    		else if (matriz_adyacencia[i][j] == PESO_TERRENO) {
    			cout << matriz_adyacencia[i][j] << "    | ";
    		}
    		else {
    			cout << matriz_adyacencia[i][j] << "     | ";
    		}
    	}
    }
    cout << "" << endl;
}

int Grafo::transformar_terreno_a_peso(string tipo_terreno) {
    
	int peso;
    
    if (tipo_terreno == G_CAMINO) {
        peso = PESO_CAMINO;
    }
    else if (tipo_terreno == G_BETUN) {
        peso = PESO_BETUN;
    }
    else if (tipo_terreno == G_LAGO) {
        peso = PESO_LAGO;
    }
    else if (tipo_terreno == G_MUELLE) {
        peso = PESO_MUELLE;
    }
    else {
        peso = PESO_TERRENO;
    }

    return peso;
}

string** Grafo::devolver_matriz_terrenos() {
	return matriz_terrenos;
}

void Grafo::liberar_matriz_de_adyacencia() {
    
	for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos(); i++) {
        delete[] matriz_adyacencia[i];
    }

    delete[] matriz_adyacencia;
}

Lista* Grafo::devolver_lista_vertices(){
	return lista_vertices;
}