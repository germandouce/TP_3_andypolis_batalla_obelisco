#include "grafo.h"

Grafo::Grafo(Lista* lista_vertices) {
   // matriz_adyacencia = nullptr;

   this -> lista_vertices = lista_vertices;
   nodos_a_visitar = nullptr;
   camino_minimo = nullptr;
   matriz_adyacencia = new int*[lista_vertices->obtener_cantidad_elementos()];
   for(int i = 0; i < lista_vertices->obtener_cantidad_elementos(); i++){
	   matriz_adyacencia[i] = new int[lista_vertices->obtener_cantidad_elementos()];
   }
    
}

bool Grafo::no_fue_visitado(int num_nodo_adyacente, Lista* nodos_visitados){
	int i = 1;
	int num_nodo_visitados;
	int cantidad_nodos_visitados;



	if (nodos_visitados -> obtener_cantidad_elementos() != 0){
		num_nodo_visitados = nodos_visitados -> devolver_nodo(i) -> obtener_vertice() -> obtener_numero_vertice();
		cantidad_nodos_visitados = nodos_visitados -> obtener_cantidad_elementos();
	}
	else{
		num_nodo_visitados = 0;
		cantidad_nodos_visitados = 0;
	}

	//cout << "nodo_adyacente: " << num_nodo_adyacente << endl;
	//cout << "nodo visitados: " << num_nodo_visitados << endl;

	while((num_nodo_adyacente != num_nodo_visitados ) && i < cantidad_nodos_visitados ){
		///NO ESTA ENTRANDO

		i++;
		num_nodo_visitados = nodos_visitados -> devolver_nodo(i) -> obtener_vertice() -> obtener_numero_vertice();
		cantidad_nodos_visitados = nodos_visitados -> obtener_cantidad_elementos();
	}

	return (num_nodo_adyacente != num_nodo_visitados );

}

void Grafo::recorrer_nodo(Nodo* nodo_anterior, int distancia_origen_nodo_anterior, int num_nodo_anterior, int num_nodo_adyacente){



	Nodo* p_nodo_recorrido ;
	p_nodo_recorrido = lista_vertices -> devolver_nodo(num_nodo_adyacente);
	int peso_anterior = p_nodo_recorrido -> obtener_distancia_minima_origen();
	int num_nodo_recorrido = p_nodo_recorrido -> obtener_vertice() -> obtener_numero_vertice();
	int peso_nodo  = distancia_origen_nodo_anterior + matriz_adyacencia[num_nodo_anterior][num_nodo_recorrido];
	if (peso_nodo < peso_anterior){
		p_nodo_recorrido -> asignar_distancia_minima(peso_nodo);
		p_nodo_recorrido -> asignar_anterior(nodo_anterior);
	}
}

void Grafo::calcular_camino_minimo_dijktra(int origen, int destino){
		// hay que agregar le una condicion para que agregue los edificios a vector_num_visitados

		Lista nodos_visitados;
		Lista nodos_recorrer;

		Lista* p_nodos_visitados = &nodos_visitados;
		Lista* p_nodos_recorrer = &nodos_recorrer;


		Nodo* nodo_origen = lista_vertices -> devolver_nodo(origen);


		int* vector_adyacentes = nodo_origen -> obtener_vector_adyacentes();
		int fila = nodo_origen -> obtener_vertice()-> obtener_fila();
		int columna = nodo_origen -> obtener_vertice()-> obtener_columna();
		int cantidad_filas = nodo_origen -> obtener_vertice()-> obtener_cantidad_filas();
		int cantidad_columnas = nodo_origen -> obtener_vertice()-> obtener_cantidad_columnas();
		int cantidad_nodos_adyacentes = nodo_origen -> encontrar_tipo_nodo(fila, columna, cantidad_filas, cantidad_columnas);

		Nodo* nodo_anterior = nodo_origen;
		int num_nodo_anterior = nodo_anterior -> obtener_vertice() -> obtener_numero_vertice();
		p_nodos_recorrer -> agregar(num_nodo_anterior, cantidad_filas, cantidad_columnas, fila, columna,  lista_vertices ->devolver_nodo(num_nodo_anterior));
		p_nodos_recorrer -> devolver_nodo(1) -> asignar_distancia_minima();
		int distancia_origen_nodo_anterior = nodo_anterior -> obtener_distancia_minima_origen();
		while(lista_vertices -> obtener_cantidad_elementos() != p_nodos_visitados -> obtener_cantidad_elementos()){
			for (int i = 0; i <= cantidad_nodos_adyacentes; i++){

				//cout << "posicion:" << i << endl;
				int num_nodo_adyacente = vector_adyacentes[i];

				//cout << "nodos adyacentes for: " << num_nodo_adyacente << endl;
				if (no_fue_visitado(num_nodo_adyacente,p_nodos_visitados)){
					//cout << "num nodo adyacente:" << num_nodo_adyacente << endl;
					int fila = lista_vertices ->devolver_nodo(num_nodo_adyacente) -> obtener_vertice() -> obtener_fila();
					int columna = lista_vertices ->devolver_nodo(num_nodo_adyacente) -> obtener_vertice() -> obtener_columna();;
					Nodo nodo_adyacente(num_nodo_adyacente, cantidad_filas, cantidad_columnas, fila, columna, lista_vertices ->devolver_nodo(num_nodo_adyacente));
					Nodo* p_nodo_adyacente = &nodo_adyacente;
					recorrer_nodo(p_nodo_adyacente, distancia_origen_nodo_anterior, num_nodo_anterior, num_nodo_adyacente);
					p_nodos_recorrer -> agregar(num_nodo_adyacente, cantidad_filas, cantidad_columnas, fila, columna, lista_vertices ->devolver_nodo(num_nodo_adyacente));
				}
			}
		//cout << p_nodos_recorrer -> devolver_nodo(1) -> obtener_vertice() -> obtener_numero_vertice() << endl;

		p_nodos_recorrer -> eliminar_nodo();
		//p_nodos_recorrer -> mostrar();
		fila = nodo_anterior -> obtener_vertice()-> obtener_fila();
		columna = nodo_anterior -> obtener_vertice()-> obtener_columna();
		p_nodos_visitados -> agregar(num_nodo_anterior, cantidad_filas, cantidad_columnas, fila, columna);
		cout << "nodos visitados: " << endl;
		p_nodos_visitados -> mostrar();
		//cout << "nodos visitados: " << num_nodo_anterior << endl;

		//cout << "nodo visitado: " << p_nodos_visitados -> devolver_nodo(1) -> obtener_vertice() -> obtener_numero_vertice() << endl;
		nodo_anterior = p_nodos_recorrer -> devolver_nodo(1);
		//cout << "nodo a recorrer:" << nodo_anterior -> obtener_vertice() -> obtener_numero_vertice()<< endl;
		num_nodo_anterior = nodo_anterior -> obtener_vertice() -> obtener_numero_vertice();
		vector_adyacentes = nodo_anterior -> obtener_vector_adyacentes(); //CAMBIAR


		}
		cout << "SALE" << endl;

		//RECOMPONE CAMINO MINIMO

		Nodo* nodo_destino = lista_vertices -> devolver_nodo(destino);
		nodo_anterior = nodo_destino -> obtener_anterior();
		fila = nodo_destino -> obtener_vertice()-> obtener_fila();
		columna = nodo_destino -> obtener_vertice()-> obtener_columna();
		camino_minimo -> agregar_fifo(destino, cantidad_filas, cantidad_columnas, fila, columna);

		while(nodo_anterior != nodo_origen){
			int num_nodo_anterior = nodo_anterior -> obtener_vertice() -> obtener_numero_vertice();
			cout << num_nodo_anterior << endl; //prueba
			fila = nodo_anterior -> obtener_vertice()-> obtener_fila();
			columna = nodo_anterior -> obtener_vertice()-> obtener_columna();
			camino_minimo -> agregar_fifo(num_nodo_anterior, cantidad_filas, cantidad_columnas, fila, columna);
			nodo_anterior = nodo_anterior -> obtener_anterior();
		}
}

void Grafo::inicializar_lista_vertices(Lista* lista_vertices){
    this -> lista_vertices = lista_vertices;
}

void Grafo::agregar_camino(int origen, int destino, int peso) {
    
    matriz_adyacencia[origen][destino] = peso;
        
}

void Grafo::cargar_matriz_adyacencia(char** matriz_terrenos, int cantidad_filas, int cantidad_columnas){
    //FALTA HACER LOS CAMBIOS SI APARECE UN EDIFICIO
	for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos() ; i++){
    	int k = 0;

    	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos()  ; j++){


    		int numero_nodo_adyacente = lista_vertices-> devolver_nodo(i + 1) -> obtener_vector_adyacentes()[k];

    		if ((j + 1) == numero_nodo_adyacente){
    			Nodo* nodo_adyacente = lista_vertices-> devolver_nodo(j + 1);
    			int fila = nodo_adyacente -> obtener_vertice() -> obtener_fila();
    			int columna = nodo_adyacente -> obtener_vertice() -> obtener_columna();
    			int peso = transformar_terreno_a_peso(matriz_terrenos[fila - 1][columna - 1]);
    			matriz_adyacencia[i][j] = peso;
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
    for (int i = 0; i < lista_vertices -> obtener_cantidad_elementos() ; i++){
    	cout << endl;
       	for (int j = 0; j < lista_vertices -> obtener_cantidad_elementos()  ; j++){
    		if (matriz_adyacencia[i][j] == INFINITO){
    			cout << matriz_adyacencia[i][j] << " | ";
    		}
    		else if(matriz_adyacencia[i][j] == PESO_TERRENO){
    			cout << matriz_adyacencia[i][j] << "    | ";
    		}
    		else{
    			cout << matriz_adyacencia[i][j] << "     | ";
    		}
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
