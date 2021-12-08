#include "mapa.h"

Mapa::Mapa() {}

Mapa::~Mapa() {
	borrar();
}

void Mapa::borrar() {

	for (int i = 0; i < filas; i++) {

		for (int j = 0; j < columnas; j++) {
			delete matriz[i][j];
		}

		delete[] matriz[i];
	}

	delete[] matriz;
	this -> matriz = nullptr;
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

Diccionario* Mapa::obtener_diccionario() {
	return diccionario;
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

	string** matriz_terrenos = grafo -> devolver_matriz_terrenos();
        
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
                
            archivo >> tipo_casillero;
            Casillero* casillero = crear_subcasillero(i, j, tipo_casillero);
            cargar_casillero(i, j, casillero);
            sumar_casillero_por_tipo(tipo_casillero);

			matriz_terrenos[i][j] = tipo_casillero;
        }
    }

	grafo -> cargar_matriz_adyacencia(filas, columnas);
	archivo.close();
}  

void Mapa::asignar_atributos(int filas, int columnas) {
	
	this -> filas = filas;
	this -> columnas = columnas;
	this -> transitables_disponibles = 0;
	
	this -> matriz = new Casillero** [filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Casillero* [columnas];
    }
	
	this -> grafo = new Grafo(filas, columnas);
	this -> diccionario = new Diccionario();
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

void Mapa::cargar_diccionario(ifstream &archivo) {

    string nombre_edificio;
	int piedra;
	int madera;
	int metal;
    int limite_construccion;

	while (archivo >> nombre_edificio) {

		piedra = stoi(leer_palabra_compuesta(archivo, nombre_edificio, OPCION_NUMEROS));
		archivo >> madera;
		archivo >> metal;
		archivo >> limite_construccion;

		cargar_edificio(nombre_edificio, piedra, madera, metal, limite_construccion);
	}
    archivo.close();
}

void Mapa::cargar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite_construccion) {

	Edificio* edificio;

	if (nombre_edificio == A) {
		edificio = new Aserradero(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == E) {
		edificio = new Escuela(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == F) {
		edificio = new Fabrica(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == M) {
		edificio = new Mina(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == G) {
		edificio = new Mina_oro(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == O) {
		edificio = new Obelisco(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == P) {
		edificio = new Planta_electrica(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}
}

// FUNCIONALIDADES

void Mapa::imprimir_mapa() {

	string coordenas_columnas = "     ";
	string lineas_columnas = "  -";
	string separador = "  |";
	string espacios = "   ";

	cout << SUCESS_COLOR << "Este es el mapa de la ciudad: " << endl;
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

void Mapa::mostrar_todos_edificios() {

	cout << ENTER_COLOR << "Esta es la informacion de todos los edificios: " << END_COLOR << endl;
    cout << endl;

	diccionario -> mostrar_todos_edificios();
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

void Mapa::moverse() {
	
	int fila_origen;
	int columna_origen;
	int origen;

	int fila_destino;
	int columna_destino;
	int destino;
	
	pedir_coordenadas(fila_origen, columna_origen);
	pedir_coordenadas(fila_destino, columna_destino);
	system(CLR_SCREEN);

	origen = fila_origen * filas + columna_origen + 1;
	destino = fila_destino * filas + columna_destino + 1;

	grafo -> calcular_camino_minimo_dijsktra(origen, destino);
	
	Lista* lista_vertices = grafo -> devolver_lista_vertices();

	imprimir_camino_recorrido(lista_vertices, origen, destino);

	grafo -> reiniciar_vector_vertices();
}

void Mapa::imprimir_camino_recorrido(Lista* lista_vertices, int origen, int destino) {

	int fila;
	int columna;

	Nodo* nodo = lista_vertices -> devolver_nodo(destino);

	fila = nodo -> obtener_vertice() -> obtener_fila() - 1;
	columna = nodo -> obtener_vertice() -> obtener_columna() - 1;

	if (destino != origen) {
		int destino = nodo -> obtener_anterior();
		imprimir_camino_recorrido(lista_vertices, origen, destino);
	}
	else {
		cout << endl;
		cout << SUCESS_COLOR << "El Jugador esta pensando cual es camino mas conveniente..." << END_COLOR << endl;
	}

	print_lento(ESPERA);

	matriz[fila][columna] -> iluminar_casillero();
	system(CLR_SCREEN);
	imprimir_mapa();
	matriz[fila][columna] -> desiluminar_casillero();
}

void Mapa::print_lento(unsigned int tiempo) {
    #ifdef _WIN32
        Sleep((DWORD) tiempo);
    #else
        usleep(tiempo);
    #endif
}

void Mapa::borrar_casillero(Casillero* casillero) {
	delete casillero;
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
		cout << ERROR_COLOR << "-Las coordenadas ingresadas estan fuera del mapa." << END_COLOR << endl;
		cout << endl;
	}
}

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
    cout << ENTER_COLOR << "Ingrese la fila del casillero que desea consultar: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void Mapa::pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna del casillero que desea consultar: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

// CONSTRUIR EDIFICIO

Edificio* Mapa::encontrar_edificio() {

    string nombre_ingresado;

    cout << ENTER_COLOR << "Ingrese el nombre del edificio deseado: " << END_COLOR << endl;
    
    getline(cin, nombre_ingresado);
    
	Edificio* edificio_encontrado = diccionario -> buscar_edificio(nombre_ingresado);

    if (edificio_encontrado == nullptr) {
        cout << endl;
        cout << ERROR_COLOR << "-El nombre del edificio ingresado es incorrecto." << END_COLOR << endl;
    }
    
    return edificio_encontrado;
}

void Mapa::verificar_construccion() {

    Edificio* edificio_a_construir = encontrar_edificio();
	int fila;
	int columna;
	bool verificacion = true;

	if (edificio_a_construir != nullptr) {

		pedir_coordenadas(fila, columna);
			
		if (matriz[fila][columna] -> esta_ocupado()) {
			cout << ERROR_COLOR << "-Las coordenadas ingresadas se encuentran ocupadas." << END_COLOR << endl;
			verificacion = false;
		}

		if (verificacion) {
			confirmar_construccion(fila, columna, edificio_a_construir);
    	}
	} 
}

void Mapa::confirmar_construccion(int fila, int columna, Edificio* edificio_a_construir) {

    string respuesta;
    string nombre_edificio = edificio_a_construir -> obtener_nombre();

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea construir un/a '" << nombre_edificio << "'?" << END_COLOR << endl;;
    cout << SUCESS_COLOR << "Ingrese 'si' para confirmar." << END_COLOR << endl;
    mostrar_costo_edificio(edificio_a_construir);
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        construir_edificio(fila, columna, edificio_a_construir);
        cout << SUCESS_COLOR << "-Se ha construido exitosamente un/a '" << nombre_edificio << "'." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha construido el edificio." << END_COLOR << endl;
    }
}

void Mapa::mostrar_costo_edificio(Edificio* edificio_a_construir) {
    cout << endl;
    cout << ENTER_COLOR << "Costos de construccion: " << END_COLOR << endl;
    cout << SUCESS_COLOR;
    cout << "-" << edificio_a_construir -> obtener_cantidad_piedra() << " unidades de piedra." << endl;
    cout << "-" << edificio_a_construir -> obtener_cantidad_madera() << " unidades de madera." << endl;
    cout << "-" << edificio_a_construir -> obtener_cantidad_metal() << " unidades de metal." << endl;
    cout << END_COLOR << endl;
}

void Mapa::construir_edificio(int fila, int columna, Edificio* edificio_a_construir) {
	matriz[fila][columna] -> construir_edificio(edificio_a_construir);
	matriz[fila][columna] -> ocupar_casillero();
}

// METODOS PRIVADOS

void Mapa::sumar_casillero_por_tipo(string tipo_casillero) {

	if (tipo_casillero == CAMINO || tipo_casillero == MUELLE || tipo_casillero == BETUN) {
		transitables_disponibles++;
	}
	
}

string Mapa::leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion) {
	
    string palabra_edificio = "";
	archivo >> palabra_edificio;

	while (!verificar_tipo_caracter(palabra_edificio, opcion)) {
		nombre_edificio = nombre_edificio + " " + palabra_edificio;
		archivo >> palabra_edificio;
	}
	return palabra_edificio;
}

bool Mapa::verificar_tipo_caracter(string palabra, int tipo_caracter) {
	
    bool es_caracter_evaluado = false;

	if (tipo_caracter == OPCION_NUMEROS) {
		es_caracter_evaluado = es_numero(palabra);
	}
	else {
		if (palabra[POSICION_INICIAL] == PARENTESIS_CHAR) {
			es_caracter_evaluado = true;
		}
	}
	return es_caracter_evaluado;
}

bool Mapa::es_numero(string palabra) {
	return (ASCII_NUM_CERO <= palabra[POSICION_INICIAL] && palabra[POSICION_INICIAL] <= ASCII_NUM_NUEVE);
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