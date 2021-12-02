#include "mapa.h"

Mapa::Mapa() {}

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

string Mapa::obtener_tipo_casillero(int fila, int columna) {
	return matriz[fila][columna] -> obtener_tipo_casillero();
}

void Mapa::cargar_casillero(int fila, int columna, Casillero* casillero) {
	matriz[fila][columna] = casillero;
}

// CARGA DE ARCHIVOS

bool Mapa::se_cargo_terreno() {

    ifstream archivo(PATH_MAPA);
    int filas;
    int columnas;
    string tipo_casillero;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de mapa." << END_COLOR << endl;
        return false;
    }
    else {

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
    };
    archivo.close();
    return true;
}

void Mapa::asignar_atributos(int filas, int columnas) {
	
	this -> filas = filas;
	this -> columnas = columnas;
	this -> transitables_disponibles = 0;
	
	this -> matriz = new Casillero** [filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new Casillero* [columnas];
    }

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

bool Mapa::se_cargo_diccionario() {

	ifstream archivo(PATH_EDIFICIOS);
    string nombre_edificio;
	int piedra;
	int madera;
	int metal;
    int limite_construccion;

    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << ERROR_COLOR << "ERROR: No se encuentra el archivo de edificios." << END_COLOR << endl;
        return false;
    }
    else {
        while (archivo >> nombre_edificio) {

            piedra = stoi(leer_palabra_compuesta(archivo, nombre_edificio, OPCION_NUMEROS));
            archivo >> madera;
            archivo >> metal;
            archivo >> limite_construccion;

            cargar_edificio(nombre_edificio, piedra, madera, metal, limite_construccion);
        }
    };
    archivo.close();
    return true;
}

void Mapa::cargar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite_construccion) {

	Edificio* edificio;

	if (nombre_edificio == "aserradero") {
		edificio = new Aserradero(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "escuela") {
		edificio = new Escuela(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "fabrica") {
		edificio = new Fabrica(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "mina") {
		edificio = new Mina(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "mina de oro") {
		edificio = new Mina(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "obelisco") {
		edificio = new Obelisco(piedra, madera, metal, limite_construccion);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == "planta electrica") {
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

void Mapa::generar_lluvia_materiales() {

	int piedra_llovida = rand() % CANT_MAX_PIEDRA + CANT_MIN_PIEDRA;
	int madera_llovida = rand() % CANT_MAX_MADERA + CANT_MIN_MADERA;
	int metal_llovido = rand() % CANT_MAX_METAL + CANT_MIN_METAL;
	int andycoins_llovido = rand() % CANT_MAX_ANDYCOINS + CANT_MIN_ANDYCOINS;

	int total_llovido = piedra_llovida + madera_llovida + metal_llovido + andycoins_llovido;
	int material_llovido;
	bool ha_llovido = false;

	cout << ENTER_COLOR << "Se va a generar una lluvia de recursos: " << END_COLOR << endl;
	cout << endl;

	for (int i = 0; i < filas && total_llovido; i++) {
		for (int j = 0; j < columnas && total_llovido; j++) {

			string tipo_casillero = matriz[i][j] -> obtener_tipo_casillero();

			if ((tipo_casillero == CAMINO || tipo_casillero == MUELLE || tipo_casillero == BETUN) && !matriz[i][j] -> obtener_cantidad_contenida()) {

				Material* material_random = llover_material_aleatorio();
				string nombre_material = material_random -> obtener_nombre();

				if (puede_llover_mas(piedra_llovida, madera_llovida, metal_llovido, andycoins_llovido, material_llovido)) {

					matriz[i][j] -> colocar_material(material_random);
					matriz[i][j] -> ocupar_casillero();

					cout << SUCESS_COLOR << "-Ha llovido un/a " << nombre_material << " en las coordenadas (";
					cout << i + 1 << ", " << j + 1 <<")." << END_COLOR << endl;
					
					ha_llovido = true;
					transitables_disponibles--;
					total_llovido--;
				}
			}	
		}
	}

	if (transitables_disponibles && !ha_llovido) {
		cout << ERROR_COLOR << "-El reporte meteorologico estaba equivocado. No ha llovido ningun recurso." << END_COLOR << endl;
	}

	if (!transitables_disponibles) {
		cout << ERROR_COLOR << "-No puede llover mas por falta de casilleros transitables vacios." << END_COLOR << endl;
	}
	cout << endl;
}

bool Mapa::puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int &andycoins_llovido, int material_llovido) {

	bool puede_llover_mas = true;

	if (material_llovido == PIEDRA) {
		if ((piedra_llovida - 1) >= 0) {
			piedra_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == MADERA) {
		if ((madera_llovida - 1) >= 0) {
			madera_llovida--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == METAL) {
		if ((metal_llovido - 1) >= 0) {
			metal_llovido--;
		}
		else {
			puede_llover_mas = false;
		}
	}

	if (material_llovido == ANDYCOINS) {
		if ((andycoins_llovido - 1) >= 0) {
			andycoins_llovido--;
		}
		else {
			puede_llover_mas = false;
		}
	}


	return puede_llover_mas;
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

	fila = fila -1;
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

void Mapa::construir_edificio(int fila, int columna, Edificio* edificio_a_construir) {

	if (matriz[fila][columna] -> obtener_tipo_casillero() == CONSTRUIBLE && !matriz[fila][columna] -> obtener_cantidad_contenida()) {

		matriz[fila][columna] -> construir_edificio(edificio_a_construir);
		matriz[fila][columna] -> ocupar_casillero();

	}
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

Material* Mapa::llover_material_aleatorio() {

	int tipo_material = rand() % CANT_MATERIALES;
	string nombre_material_aleatorio = obtener_tipo_material(tipo_material);
	Material* material_devuelto;

	if (nombre_material_aleatorio == S) {
		material_devuelto = new Piedra(PIEDRA_LLOVIDA);
	}

	if (nombre_material_aleatorio == W) {
		material_devuelto = new Madera(MADERA_LLOVIDA);
	}

	if (nombre_material_aleatorio == I) {
		material_devuelto = new Piedra(METAL_LLOVIDO);
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