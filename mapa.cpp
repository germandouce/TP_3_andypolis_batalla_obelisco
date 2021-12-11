#include "mapa.h"

Mapa::Mapa() {}

Mapa::~Mapa() {

	for (int i = 0; i < filas; i++) {

		for (int j = 0; j < columnas; j++) {
			delete matriz[i][j];
		}

		delete[] matriz[i];
	}

	delete[] matriz;
	matriz = nullptr;

	delete grafo;
	grafo = nullptr;
}

int Mapa::obtener_filas() {
	return filas;
}

int Mapa::obtener_columnas() {
	return columnas;
}

Casillero* Mapa::obtener_casillero(int fila, int columna) {
	return matriz[fila][columna];
}

string Mapa::obtener_tipo_casillero(int fila, int columna) {
	return matriz[fila][columna] -> obtener_tipo_casillero();
}

void Mapa::cargar_casillero(int fila, int columna, Casillero* casillero) {
	matriz[fila][columna] = casillero;
}

void Mapa::colocar_material(int fila, int columna, Material* material) {
	matriz[fila][columna] -> colocar_material(material);
}

// CARGA DE ARCHIVOS

void Mapa::cargar_mapa(ifstream& archivo) {

    int filas;
    int columnas;
    string tipo_casillero;

    archivo >> filas;
    archivo >> columnas;

    asignar_atributos(filas, columnas);
        
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
                
            archivo >> tipo_casillero;
            Casillero* casillero = crear_subcasillero(i, j, tipo_casillero);
            cargar_casillero(i, j, casillero);
            sumar_casillero_por_tipo(tipo_casillero);
        }
    }

	grafo = new Grafo(filas, columnas, matriz);
	archivo.close();
}  

void Mapa::asignar_atributos(int filas, int columnas) {
	
	this -> filas = filas;
	this -> columnas = columnas;
	
	transitables_disponibles = 0;
	
	matriz = new Casillero** [filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Casillero* [columnas];
    }
}

Casillero* Mapa::crear_subcasillero(int fila, int columna, string tipo_casillero) {

	Casillero* casillero_devuelto;

	if (tipo_casillero == TERRENO) {
		casillero_devuelto = new Terreno(fila, columna);
	}

	if (tipo_casillero == LAGO) {
		casillero_devuelto = new Lago(fila, columna);
	}

	if (tipo_casillero == CAMINO) {
		casillero_devuelto = new Camino(fila, columna);
	}

	if (tipo_casillero == MUELLE) {
		casillero_devuelto = new Muelle(fila, columna);
	}

	if (tipo_casillero == BETUN) {
		casillero_devuelto = new Betun(fila, columna);
	}

	return casillero_devuelto;
}

// FUNCIONALIDADES

void Mapa::imprimir_mapa() {

	string coordenas_columnas = "     ";
	string lineas_columnas = "  -";
	string separador = "  |";
	string espacios = "   ";

	cout << SUCESS_COLOR << "Este es el mapa de Andypolis: " << endl;
	cout << END_COLOR << endl;

	for (int c = 0; c < columnas; c++) {
		if (c > 8) {
			espacios = "  ";
		}

		coordenas_columnas += to_string(c + 1) + espacios;
		lineas_columnas += "----";
	}

	cout << ENTER_COLOR << coordenas_columnas << endl;
	cout << ENTER_COLOR << " " << lineas_columnas << endl;

	for (int i = 0; i < filas; i++) {

		if (i > 8) {
			separador = " |";
		}

		cout << ENTER_COLOR << i + 1 << separador << END_COLOR;
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] -> imprimir_casillero();
			cout << ENTER_COLOR << "|" << END_COLOR;
		}
		cout << endl;
		cout << ENTER_COLOR << " " << lineas_columnas << endl;
	}
	cout << END_COLOR << endl;
}

void Mapa::consultar_casillero() {
	
	int fila;
	int columna;
	
	pedir_coordenadas(fila, columna);

	if (fila <= filas - 1 && columna <= columnas - 1) {
		system(CLR_SCREEN);
		cout << ENTER_COLOR << "El casillero de la coordenada (" << fila + 1 << ", " << columna + 1 << ") dice: " << END_COLOR << endl;
		cout << endl;
		matriz[fila][columna] -> mostrar();
	}
	else {
		cout << ERROR_COLOR << "-Las coordenadas ingresadas estan fuera del Mapa." << END_COLOR << endl;
		cout << endl;
	}
}

// LLUVIA DE MATERIALES

void Mapa::llover() {

	if (transitables_disponibles) {
		generar_lluvia_materiales();
	}
	else {
		cout << ERROR_COLOR << "-No puede llover mas por falta de casilleros transitables vacios." << END_COLOR << endl;
	}
	cout << endl;
}

void Mapa::generar_lluvia_materiales() {

	int piedra_llovida = rand() % CANT_MAX_PIEDRA + CANT_MIN_PIEDRA;
	int madera_llovida = rand() % CANT_MAX_MADERA + CANT_MIN_MADERA;
	int metal_llovido = rand() % CANT_MAX_METAL + CANT_MIN_METAL;
	int andycoins_llovido = rand() % CANT_MAX_ANDYCOINS + CANT_MIN_ANDYCOINS;

	int material_llovido;
	int posicion_vector;

	cout << ENTER_COLOR << "Se va a generar una lluvia de recursos: " << END_COLOR << endl;
	cout << endl;

	cargar_casilleros_lluvia();

	for (int i = 0; i < casilleros_lluvia.obtener_largo() && transitables_disponibles; i++) {
		
		posicion_vector = rand() % casilleros_lluvia.obtener_largo() + ZERO;
		Casillero* casillero_random = casilleros_lluvia.obtener_dato(posicion_vector);

		while(casillero_random -> esta_ocupado()) {
			posicion_vector = rand() % casilleros_lluvia.obtener_largo() + ZERO;
			casillero_random = casilleros_lluvia.obtener_dato(posicion_vector);
		}

		Material* material_random = llover_material_aleatorio(material_llovido);
		string nombre_material = material_random -> obtener_nombre();

		if (puede_llover_mas(piedra_llovida, madera_llovida, metal_llovido, andycoins_llovido, material_llovido)) {

			casillero_random -> colocar_material(material_random);
			casillero_random -> ocupar_casillero();

			cout << SUCESS_COLOR << "-Ha llovido un/a " << nombre_material << " en las coordenadas (";
			cout << casillero_random -> obtener_fila() + 1 << ", " << casillero_random -> obtener_columna() + 1 << ").";
			cout << END_COLOR << endl;
			
			transitables_disponibles--;
		}	
	}
}

void Mapa::cargar_casilleros_lluvia() {

	if (transitables_disponibles) {
		casilleros_lluvia.borrar_todo();
	}

	for (int i = 0; i < filas && transitables_disponibles; i++) {
		for (int j = 0; j < columnas; j++) {

			string tipo_casillero = matriz[i][j] -> obtener_tipo_casillero();

			if ((tipo_casillero == CAMINO || tipo_casillero == MUELLE || tipo_casillero == BETUN)
				&& !(matriz[i][j] -> esta_ocupado())) {

				casilleros_lluvia.insertar_ultimo(matriz[i][j]);
			}
		}
	}
}

bool Mapa::puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int &andycoins_llovido, int material_llovido) {

	bool puede_llover_mas = true;

	if (material_llovido == PIEDRA) {
		if (piedra_llovida > ZERO) {
			piedra_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == MADERA) {
		if (madera_llovida > ZERO) {
			madera_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == METAL) {
		if (metal_llovido > ZERO) {
			metal_llovido--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == ANDYCOINS) {
		if (andycoins_llovido > ZERO) {
			andycoins_llovido--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	return puede_llover_mas;
}

// MOVIMIENTO

void Mapa::moverse(Inventario* inventario, Jugador* jugador) {
	
	bool es_jugador2 = jugador -> devolver_numero_jugador() == NUMERO_JUGADOR2;

	int fila_origen = jugador -> devolver_fila() - 1;
	int columna_origen = jugador -> devolver_columna() - 1;
	int origen;

	int fila_destino;
	int columna_destino;
	int destino;
	
	pedir_coordenadas(fila_destino, columna_destino);

	if (es_movimiento_valido(fila_destino, columna_destino)) {

		system(CLR_SCREEN);

		origen = fila_origen * filas + columna_origen + 1;
		destino = fila_destino * filas + columna_destino + 1;

		grafo -> calcular_camino_minimo_dijsktra(origen, destino, matriz, es_jugador2);
		
		Lista* lista_vertices = grafo -> devolver_lista_vertices();
		int distancia = lista_vertices -> devolver_nodo(destino) -> obtener_distancia_minima_origen();

		if (distancia != INFINITO) {
			imprimir_camino_recorrido(lista_vertices, inventario, origen, destino, es_jugador2);
			ocupar_jugador(fila_destino, columna_destino, es_jugador2);

			jugador -> asignar_coordenadas(fila_destino + 1, columna_destino + 1);

			cout << SUCESS_COLOR << "El costo para moverse fue de: " << distancia << " de energia." << END_COLOR << endl;
			cout << endl;

		}
		else {
			cout << ERROR_COLOR << "El Jugador no puede llegar a la coordenada elegida." << END_COLOR << endl;
			cout << endl;
		}
		
		grafo -> reiniciar_vector_vertices();
	}
}

bool Mapa::es_movimiento_valido(int fila, int columna) {
	
	bool movimiento_valido = true;
	bool coordenadas_validas = fila <= filas - 1 && columna <= columnas - 1;

	if (coordenadas_validas) {

		Casillero* casillero_destino = matriz[fila][columna];
		string tipo_casillero = casillero_destino -> obtener_tipo_casillero();

		bool esta_ocupado = casillero_destino -> esta_ocupado();
		bool hay_jugador = casillero_destino -> hay_jugador1() || casillero_destino -> hay_jugador2();

		if (hay_jugador) {
			cout << ERROR_COLOR << "-No puedes moverte a una coordenada ocupada por otro Jugador." << END_COLOR << endl;
			cout << endl;
			movimiento_valido = false;
		}
		else if (tipo_casillero == TERRENO && esta_ocupado) {
			cout << ERROR_COLOR << "-No puedes moverte a una coordenada ocupada por un Edificio." << END_COLOR << endl;
			cout << endl;
			movimiento_valido = false;
		}
	}
	else {
		cout << ERROR_COLOR << "-Las coordenadas ingresadas estan fuera del Mapa." << END_COLOR << endl;
		cout << endl;
		movimiento_valido = false;
	}

	return movimiento_valido;
}

void Mapa::imprimir_camino_recorrido(Lista* lista_vertices, Inventario* inventario, int origen, int destino, bool es_jugador2) {

	int fila;
	int columna;

	Nodo* nodo = lista_vertices -> devolver_nodo(destino);

	fila = nodo -> obtener_vertice() -> obtener_fila() - 1;
	columna = nodo -> obtener_vertice() -> obtener_columna() - 1;

	if (destino != origen) {
		int destino = nodo -> obtener_anterior();
		imprimir_camino_recorrido(lista_vertices, inventario, origen, destino, es_jugador2);
	}
	else {
		cout << endl;
		cout << SUCESS_COLOR << "El Jugador esta pensando cual es camino mas conveniente..." << END_COLOR << endl;
	}

	ocupar_jugador(fila, columna, es_jugador2);
	recolectar_recursos(fila, columna, inventario);

	print_lento(ESPERA);

	matriz[fila][columna] -> iluminar_casillero();
	system(CLR_SCREEN);
	imprimir_mapa();
	matriz[fila][columna] -> desiluminar_casillero();

	desocupar_jugador(fila, columna, es_jugador2);
}

void Mapa::print_lento(unsigned int tiempo) {
    #ifdef _WIN32
        Sleep((DWORD) tiempo);
    #else
        usleep(tiempo);
    #endif
}

void Mapa::ocupar_jugador(int fila, int columna, bool es_jugador2) {

	if (es_jugador2) {
		matriz[fila][columna] -> ocupar_jugador2();
	}
	else {
		matriz[fila][columna] -> ocupar_jugador1();
	}
}

void Mapa::desocupar_jugador(int fila, int columna, bool es_jugador2) {

	if (es_jugador2) {
		matriz[fila][columna] -> desocupar_jugador2();
	}
	else {
		matriz[fila][columna] -> desocupar_jugador1();
	}
}

void Mapa::recolectar_recursos(int fila, int columna, Inventario* inventario) {

	string tipo_casillero = matriz[fila][columna] -> obtener_tipo_casillero();
	bool ocupado = matriz[fila][columna] -> esta_ocupado();

	if ((tipo_casillero == CAMINO || tipo_casillero == MUELLE || tipo_casillero == BETUN) && ocupado) {
		
		Material* material = matriz[fila][columna] -> obtener_material();
		string nombre_material = material -> obtener_nombre();
		int cantidad_material = material -> obtener_cantidad();
	
		inventario -> cambiar_cantidad_elemento(nombre_material, cantidad_material);
		matriz[fila][columna] -> colocar_material(nullptr);
		matriz[fila][columna] -> desocupar_casillero();
		transitables_disponibles++;
	}
}

// CONSTRUIR EDIFICIO

void Mapa::construir_edificio(int fila, int columna, Edificio* edificio_a_construir) {
	matriz[fila][columna] -> construir_edificio(edificio_a_construir);
	matriz[fila][columna] -> ocupar_casillero();
}

// METODOS PRIVADOS

void Mapa::pedir_coordenadas(int &fila, int &columna) {
	
	system(CLR_SCREEN);

	pedir_fila(fila);

    while (fila <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    pedir_columna(columna);

    while (columna <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
        cout << endl;
        pedir_columna(columna);
    }

	fila = fila - 1;
	columna = columna - 1;
    cout << endl;
}

void Mapa::pedir_fila(int &fila) {
    cout << ENTER_COLOR << "Ingrese la fila del casillero deseado: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void Mapa::pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna del casillero deseado: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

void Mapa::sumar_casillero_por_tipo(string tipo_casillero) {

	if (tipo_casillero == CAMINO || tipo_casillero == MUELLE || tipo_casillero == BETUN) {
		transitables_disponibles++;
	}
}

Material* Mapa::llover_material_aleatorio(int &material_llovido) {

	material_llovido = rand() % CANT_MATERIALES + ZERO;
	string nombre_material_aleatorio = obtener_tipo_material(material_llovido);
	Material* material_devuelto;

	if (nombre_material_aleatorio == S) {
		material_devuelto = new Piedra(PIEDRA_LLOVIDA);
	}

	if (nombre_material_aleatorio == W) {
		material_devuelto = new Madera(MADERA_LLOVIDA);
	}

	if (nombre_material_aleatorio == I) {
		material_devuelto = new Metal(METAL_LLOVIDO);
	}

	if (nombre_material_aleatorio == C) {
		material_devuelto = new Andycoins(ANDYCOINS_LLOVIDO);
	}

	return material_devuelto;
}

string Mapa::obtener_tipo_material(int tipo_material) {
	
	string nombre_material;

	switch(tipo_material) {
		case PIEDRA:
			nombre_material = "piedra";
			break;
		case MADERA:
			nombre_material = "madera";
			break;
		case METAL:
			nombre_material = "metal";
			break;
		case ANDYCOINS:
			nombre_material = "andycoins";
	}
	return nombre_material;
}
