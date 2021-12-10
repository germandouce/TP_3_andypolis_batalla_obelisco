#include "juego.h"

Juego::Juego() {
    this -> jugador1 = new Jugador();
    this -> jugador2 = new Jugador();
    this -> mapa = new Mapa();
    this -> diccionario = new Diccionario();
    this -> objetivos = new Vector<Objetivo>;
}

bool Juego::archivo_vacio(ifstream& archivo){
    return (archivo.peek() == ifstream::traits_type::eof());
}

bool Juego::existe_archivo(ifstream& archivo, string nombre_archivo) {
    archivo.open(nombre_archivo);
    return (archivo.is_open());
}

void Juego::instanciar_material(string nombre_material, Material* material){
    if (nombre_material == S) {
        material = new Piedra(PIEDRA_LLOVIDA);
    }
    else if (nombre_material == W) {
        material = new Madera(MADERA_LLOVIDA);
    }
    else if (nombre_material == I) {
        material = new Metal(METAL_LLOVIDO);
    }
    else if (nombre_material == C) {
        material = new Andycoins(ANDYCOINS_LLOVIDO);
    }
}

void Juego::cargar_inventario(ifstream& inventario) {

    string nombre;
    string cantidad_1;
    string cantidad_2;

    Inventario* inventario_jugador_1 = jugador1 -> devolver_inventario();
    Inventario* inventario_jugador_2 = jugador2 -> devolver_inventario();

    while(inventario >> nombre){
        inventario >> cantidad_1;
        inventario >> cantidad_2;

        if (nombre == W) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == S) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == I) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == B) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == C) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        
        inventario_jugador_1-> actualizar_largo_de_inventario();
        inventario_jugador_2-> actualizar_largo_de_inventario();
    }
    inventario.close();
}

void Juego::cargar_ubicaciones(ifstream& ubicaciones) {

    string nombre_elemento;
    string fila;
    string columna;

    Material * material;
    Edificio * edificio;
    Jugador* jugador;

    while (ubicaciones >> nombre_elemento) {
        
        ubicaciones >> fila;   
        fila = limpiar_string(fila, POSICION_INICIAL_FILA, TOPE_CADENA_FILA);

        ubicaciones >> columna;
        columna = limpiar_string(columna, POSICION_INICIAL_COLUMNA, TOPE_CADENA_COLUMNA);

        
        if (nombre_elemento == "1") {
            jugador = jugador1;
            jugador -> asignar_coordenadas(stoi(fila), stoi(columna));
        }
        else if (nombre_elemento == "2") {
            jugador = jugador2;
            jugador -> asignar_coordenadas(stoi(fila), stoi(columna));
        }
        
        if (nombre_elemento == S || nombre_elemento == W || nombre_elemento == I || nombre_elemento == C) {
            instanciar_material(nombre_elemento, material);
            mapa -> colocar_material(stoi(fila) - 1, stoi(columna) - 1, material);
        }
        else {
            edificio = diccionario -> instanciar_edificio(nombre_elemento, stoi(fila), stoi(columna));
            mapa -> construir_edificio(stoi(fila) - 1, stoi(columna) - 1, edificio);
            jugador -> agregar_edificio_al_registro(edificio);
        }
    }
    ubicaciones.close();
}

string Juego::limpiar_string(string cadena, int posicion_inicial, char str_tope) {

	string numero;
	string cifra;

	numero = cadena[posicion_inicial];

	while (cadena[posicion_inicial + 1] != str_tope) {
	    
		posicion_inicial++;
	    
		if (ASCII_NUM_CERO <= cadena[posicion_inicial] && cadena[posicion_inicial] <= ASCII_NUM_NUEVE) {
	    	cifra = cadena[posicion_inicial];
	    	numero = numero + cifra;
	    }
	}
	return numero;
}

bool Juego::es_archivo_legible(ifstream& archivo, string nombre_archivo) {
    
    bool archivo_legible = false;
    
    if (existe_archivo(archivo, nombre_archivo) ){
        if (!archivo_vacio(archivo) ) {
            archivo_legible = true; 
        }
        else {
            archivo.close();
        }   
    }
    return archivo_legible;
}

void Juego::crear_juego() {

    jugador1 -> setear_numero_jugador(1);
    asignar_objetivos(jugador1);

    jugador2 -> setear_numero_jugador(2);
    asignar_objetivos(jugador2);
}

void Juego::cargar_objetivos(){

    Objetivo *edad_piedra = new Edad_piedra();
    objetivos->insertar_ultimo(edad_piedra);

    Objetivo *bombardero = new Bombardero();
    objetivos->insertar_ultimo(bombardero);

    Objetivo *energetico = new Energetico();
    objetivos->insertar_ultimo(energetico);

    Objetivo *letrado = new Letrado();
    objetivos->insertar_ultimo(letrado);

    Objetivo *minero = new Minero();
    objetivos -> insertar_ultimo(minero);

    Objetivo *cansado = new Cansado();
    objetivos->insertar_ultimo(cansado);

    Objetivo *constructor = new Constructor();
    objetivos->insertar_ultimo(constructor);

    Objetivo *armado = new Armado();
    objetivos->insertar_ultimo(armado);

    Objetivo *extremista = new Extremista();
    objetivos->insertar_ultimo(extremista);
}

int Juego::generar_numero_random(int min, int max) {
    int range = max + 1  - min;  
    return min + ( rand() % range);
}

void Juego::asignar_objetivos(Jugador *jugador) {

    int vector_objetivos_jug[3];

    Objetivo *objetivo_a_asignar;

    int objetivo_1 = generar_numero_random(1,10);
    
    objetivo_a_asignar = objetivos -> obtener_dato(objetivo_1);    
    jugador -> asignar_objetivo(objetivo_a_asignar);
    
    vector_objetivos_jug[0] = objetivo_1;
    
    bool ya_toco;
    int cantidad = 1;
    while(cantidad <= 2){
        
        int numero_objetivo = generar_numero_random(1,10);
        ya_toco = false;

        for(int i = 0; i <cantidad; i++){
            vector_objetivos_jug[i] == numero_objetivo;
            ya_toco = true;
        }

        if (!ya_toco){
            objetivo_a_asignar = objetivos->obtener_dato(numero_objetivo);
            jugador -> asignar_objetivo(objetivo_a_asignar);
            cantidad++;
        }
    }
}

void Juego::cargar_diccionario(ifstream &archivo) {

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

void Juego::cargar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite_construccion) {

	Edificio* edificio;

	if (nombre_edificio == A) {
		edificio = new Aserradero(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == E) {
		edificio = new Escuela(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == F) {
		edificio = new Fabrica(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == M) {
		edificio = new Mina(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == G) {
		edificio = new Mina_oro(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == O) {
		edificio = new Obelisco(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}

	if (nombre_edificio == P) {
		edificio = new Planta_electrica(piedra, madera, metal, limite_construccion, NULA, NULA);
		diccionario -> agregar_edificio(edificio);
	}
}

string Juego::leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion) {
	
    string palabra_edificio = "";
	archivo >> palabra_edificio;

	while (!verificar_tipo_caracter(palabra_edificio, opcion)) {
		nombre_edificio = nombre_edificio + " " + palabra_edificio;
		archivo >> palabra_edificio;
	}
	return palabra_edificio;
}

bool Juego::verificar_tipo_caracter(string palabra, int tipo_caracter) {
	
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

bool Juego::es_numero(string palabra) {
	return (ASCII_NUM_CERO <= palabra[POSICION_INICIAL] && palabra[POSICION_INICIAL] <= ASCII_NUM_NUEVE);
}

Jugador* Juego::devolver_jugador_1() {
    return jugador1;
}

Jugador* Juego::devolver_jugador_2() {
    return jugador2;
}