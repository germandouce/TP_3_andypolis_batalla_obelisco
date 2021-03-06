#include "juego.h"

Juego::Juego() {
    jugador_turno = new Jugador();
    jugador_secundario = new Jugador();
    mapa = new Mapa();
    diccionario = new Diccionario();
    objetivos = new Vector<Objetivo>;
}

Juego::~Juego() {
    delete jugador_turno;
    delete jugador_secundario;
    delete mapa;
    delete diccionario;
    delete objetivos;
}

void Juego::elegir_opcion_menu_np() {
    
    int opcion_elegida;
            
    system(CLR_SCREEN);
    
    while (opcion_elegida != COMENZAR_PARTIDA) {

        presentar_menu_np();
        opcion_elegida = validar_opcion(opcion_elegida);
        procesar_opcion_np(opcion_elegida);
    }  
}

int Juego::validar_opcion_np(int opcion_elegida) {
    
    cin >> opcion_elegida;
    cin.clear();
    cin.ignore(100, '\n');

    while (!opcion_valida_np(opcion_elegida)) {
        cout << endl;
        cout << ERROR_COLOR << "Opcion invalida. Elija nuevamente." << END_COLOR << endl;
        cin >> opcion_elegida;
        cin.clear();
        cin.ignore(100, '\n');
    }
    
    return opcion_elegida;
}

int Juego::validar_opcion(int opcion_elegida) {
    
    cin >> opcion_elegida;
    cin.clear();
    cin.ignore(100, '\n');

    while (!opcion_valida(opcion_elegida)) {
        cout << ERROR_COLOR << "Opcion invalida. Elija nuevamente." << END_COLOR << endl;
        cin >> opcion_elegida;
        cin.clear();
        cin.ignore(100, '\n');
    }
    
    return opcion_elegida;
}

bool Juego::opcion_valida_np(int opcion) {
    return (opcion >= OPCION_MINIMA_NP && opcion <= OPCION_MAXIMA_NP);
}

void Juego::cambiar_turno() {
    Jugador* jugador_auxiliar = jugador_turno;
    jugador_turno = jugador_secundario;
    jugador_secundario = jugador_auxiliar;
}

bool Juego::turno_terminado() {
    
    bool tiene_energia = jugador_turno -> tiene_energia();
    bool alguien_gano = jugador_turno -> gano();
    bool quiere_salir = jugador_turno -> quiere_salir_del_juego();
    bool quiere_terminar_turno = jugador_turno -> es_su_turno();

    if (!tiene_energia){
        cambiar_turno();
    }
    
    return (alguien_gano || !tiene_energia || !quiere_terminar_turno || quiere_salir);
}

bool Juego::juego_terminado() {

    bool alguien_gano = jugador_turno -> gano();
    bool quiere_salir = jugador_turno -> quiere_salir_del_juego();

    return (alguien_gano || quiere_salir);
}

void Juego::jugar_partida() {
    
    int turnos_sin_llover = 0;

    while (!juego_terminado()) {
            
        turnos_sin_llover++;

        if (turnos_sin_llover == (TURNOS_PARA_LLOVER)) {
            mapa -> llover();
            turnos_sin_llover = 0;
        }
        jugar_turno();
    }
}

void Juego::jugar_turno() {

    jugador_turno -> iniciar_turno();
    jugador_turno -> sumar_energia(ENERGIA_POR_TURNO);

    cout << SUCESS_COLOR << "Es el turno del Jugador " << jugador_turno -> devolver_numero_jugador() << "." << endl;
    cout << endl;

    while (!turno_terminado()) {

        int opcion;
        
        if (opcion != MOVERSE_A_UNA_COORDENADA) {
            mapa -> imprimir_mapa();
        }
        presentar_menu();
        opcion = validar_opcion(opcion);        
        procesar_opcion(opcion);
    }      
}

void Juego::leer_archivos(int &archivos_cargados, bool &nueva_partida) {
    
    ifstream archivo;

    if (es_archivo_legible(archivo, ARCHIVO_MAPA)) {
        mapa -> cargar_mapa(archivo);  
        archivos_cargados++;
    }

    if (es_archivo_legible(archivo, ARCHIVO_EDIFICIOS)) {
        cargar_diccionario(archivo);
        archivos_cargados++;
    }

    if (es_archivo_legible(archivo, ARCHIVO_UBICACIONES)) {
        cargar_ubicaciones(archivo);
        nueva_partida = false;
    }

    if (!nueva_partida) {
        if (es_archivo_legible(archivo, ARCHIVO_MATERIALES)) {
            actualizar_inventario(archivo);
        }
    }
}

void Juego::guardar_edificios() {

    ofstream edificios(ARCHIVO_EDIFICIOS);

    diccionario -> guardar_edificios(edificios);

    edificios.close();
}

void Juego::guardar_ubicaciones() {

    ofstream ubicaciones(ARCHIVO_UBICACIONES);

    mapa -> guardar_lluvia(ubicaciones);

    int numero_jugador = jugador_turno -> devolver_numero_jugador();

    if (numero_jugador == SEGUNDO_JUGADOR) {
        cambiar_turno();
    }

    guardar_jugador(ubicaciones);
    jugador_turno -> guardar_edificios(ubicaciones);

    cambiar_turno();

    guardar_jugador(ubicaciones);
    jugador_turno -> guardar_edificios(ubicaciones);

    ubicaciones.close();
}

void Juego::guardar_inventarios() {

    ofstream materiales(ARCHIVO_MATERIALES);

    Inventario* inventario1 = jugador_turno -> devolver_inventario();
    Inventario* inventario2 = jugador_secundario -> devolver_inventario();

    materiales << S << " " << inventario1 -> devolver_cant_piedra() << " " << inventario2 -> devolver_cant_piedra() << endl;
    materiales << W << " " << inventario1 -> devolver_cant_madera() << " " << inventario2 -> devolver_cant_madera() << endl;
    materiales << I << " " << inventario1 -> devolver_cant_metal() << " " << inventario2 -> devolver_cant_metal() << endl;
    materiales << B << " " << inventario1 -> devolver_cant_bombas() << " " << inventario2 -> devolver_cant_metal() << endl;
    materiales << C << " " << inventario1 -> devolver_cant_andycoins() << " " << inventario2 -> devolver_cant_andycoins() << endl;

    materiales.close();
}

void Juego::guardar_jugador(ofstream &archivo) {

    int fila = jugador_turno -> devolver_fila();
    int columna = jugador_turno -> devolver_columna();
    int numero_jugador = jugador_turno -> devolver_numero_jugador();

    archivo << numero_jugador << " (" << fila << ", " << columna << ")" << endl;
}

int Juego::validar_jugador(){
    
    int ingreso;
    
    cout << ENTER_COLOR << "Desea ser Jugador 1 o el Jugador 2? Ingrese 1 o 2:" << END_COLOR << endl;
    cin >> ingreso;
    cin.clear();
    cin.ignore(100, '\n');

    while(ingreso != PRIMER_JUGADOR && ingreso != SEGUNDO_JUGADOR) {
        cout << ERROR_COLOR << "La opcion ingresada es invalida. Intente de nuevo." << END_COLOR << endl;
        cout << endl;
        cout << ENTER_COLOR << "Desea ser Jugador 1 o el Jugador 2? Ingrese 1 o 2:" << END_COLOR << endl;
        cin >> ingreso;
        cin.clear();
        cin.ignore(100, '\n');
    }

    return ingreso;
 
}

void Juego::posicionar_jugadores() {

    int ingreso = validar_jugador();

    jugador_turno -> setear_numero_jugador(ingreso);
    jugador_secundario -> setear_numero_jugador(DIFERENCIA_JUGADORES - ingreso);

    ubicar_jugador();
    cambiar_turno();
    ubicar_jugador();

    if (ingreso == PRIMER_JUGADOR) {
        cambiar_turno();
    }

    int fila1 = jugador_turno -> devolver_fila() - 1;
    int columna1 = jugador_turno -> devolver_columna() - 1;

    int fila2 = jugador_secundario -> devolver_fila() - 1;
    int columna2 = jugador_secundario -> devolver_columna() - 1;

    mapa -> obtener_casillero(fila1, columna1) -> ocupar_jugador1();
    mapa -> obtener_casillero(fila2, columna2) -> ocupar_jugador2();
}

bool Juego::archivo_vacio(ifstream& archivo){
    return (archivo.peek() == ifstream::traits_type::eof());
}

bool Juego::existe_archivo(ifstream& archivo, string nombre_archivo) {
    archivo.open(nombre_archivo);
    return (archivo.is_open());
}

Material* Juego::instanciar_material(string nombre_material) {
    
    Material* material;
    
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

    return material;
}

void Juego::actualizar_inventario(ifstream& inventario) {
    
    string nombre;
    int cantidad_1;
    int cantidad_2;
  
    Inventario* inventario_jugador_1 = jugador_turno -> devolver_inventario();
    Inventario* inventario_jugador_2 = jugador_secundario -> devolver_inventario();
    
    while(inventario >> nombre) {
        
        inventario >> cantidad_1;
        inventario >> cantidad_2;

    if ((nombre == I_MADERA) || (nombre == I_PIEDRA) || (nombre == I_METAL) | (nombre == I_BOMBAS)  || (nombre == I_ANDYCOINS)) {
        inventario_jugador_1 -> cambiar_cantidad_elemento(nombre, cantidad_1);
        inventario_jugador_2 -> cambiar_cantidad_elemento(nombre, cantidad_2);
    }
   
    inventario_jugador_1 -> actualizar_largo_de_inventario();
    inventario_jugador_2 -> actualizar_largo_de_inventario();
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

        fila = leer_palabra_compuesta(ubicaciones, nombre_elemento, OPCION_PARENTESIS);
        fila = limpiar_string(fila, POSICION_INICIAL_FILA, TOPE_CADENA_FILA);

        ubicaciones >> columna;
    
        columna = limpiar_string(columna, POSICION_INICIAL_COLUMNA, TOPE_CADENA_COLUMNA);

        if (nombre_elemento == "1") {
            jugador = jugador_turno;
            jugador -> asignar_coordenadas(stoi(fila), stoi(columna));
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_jugador1();
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_casillero();
        }
        else if (nombre_elemento == "2") {
            jugador = jugador_secundario;
            jugador -> asignar_coordenadas(stoi(fila), stoi(columna));
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_jugador2();
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_casillero();
        }
        
        if (nombre_elemento == S || nombre_elemento == W || nombre_elemento == I || nombre_elemento == C) {
            material = instanciar_material(nombre_elemento);
            mapa -> colocar_material(stoi(fila) - 1, stoi(columna) - 1, material);
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_casillero();
        }
        else if (nombre_elemento != "1" && nombre_elemento != "2") {
            edificio = diccionario -> instanciar_edificio(nombre_elemento, stoi(fila), stoi(columna));
            mapa -> construir_edificio(stoi(fila) - 1, stoi(columna) - 1, edificio);
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_casillero();
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
    
    if (existe_archivo(archivo, nombre_archivo)) {
        if (!archivo_vacio(archivo)) {
            archivo_legible = true; 
        }
        else {
            archivo.close();
        }
    }
    return archivo_legible;
}

void Juego::crear_juego() {
    
    jugador_turno -> setear_numero_jugador(PRIMER_JUGADOR);
    asignar_objetivos(jugador_turno);

    jugador_secundario -> setear_numero_jugador(SEGUNDO_JUGADOR);
    asignar_objetivos(jugador_secundario);
    jugador_secundario -> terminar_turno();
}

void Juego::cargar_objetivos(){

    Objetivo* comprar_andypolis = new Comprar_andypolis();
    objetivos -> insertar_ultimo(comprar_andypolis);

    Objetivo* edad_piedra = new Edad_piedra();
    objetivos -> insertar_ultimo(edad_piedra);

    Objetivo* bombardero = new Bombardero();
    objetivos -> insertar_ultimo(bombardero);

    Objetivo* energetico = new Energetico();
    objetivos -> insertar_ultimo(energetico);

    Objetivo* letrado = new Letrado();
    objetivos -> insertar_ultimo(letrado);

    Objetivo* minero = new Minero();
    objetivos -> insertar_ultimo(minero);

    Objetivo* cansado = new Cansado();
    objetivos -> insertar_ultimo(cansado);

    Objetivo* constructor = new Constructor();
    objetivos -> insertar_ultimo(constructor);

    Objetivo* armado = new Armado();
    objetivos -> insertar_ultimo(armado);

    Objetivo* extremista = new Extremista();
    objetivos -> insertar_ultimo(extremista);
}

int Juego::generar_numero_random(int min, int max) {
    int range = max + 1 - min;  
    return min + (rand() % range);
}

void Juego::asignar_objetivos(Jugador* jugador) {

    int vector_objetivos_jug[CANTIDAD_OBJETIVOS];
    int posicion = 0;

    Objetivo* objetivo_a_asignar;

    int objetivo_1 = generar_numero_random(MINIMO_OBJETIVO, MAXIMO_OBJETIVO);
    
    objetivo_a_asignar = objetivos -> obtener_dato(objetivo_1);    
    jugador -> asignar_objetivo(objetivo_a_asignar);
    
    vector_objetivos_jug[posicion] = objetivo_1;
    posicion++;

    bool ya_toco;
    int cantidad = 1;

    while (cantidad <= 2) {
        
        int numero_objetivo = generar_numero_random(MINIMO_OBJETIVO, MAXIMO_OBJETIVO);
        ya_toco = false;

        for (int i = 0; i < cantidad; i++) {
            if (vector_objetivos_jug[i] == numero_objetivo) {
                ya_toco = true;
            }
        }

        if (!ya_toco) {
            vector_objetivos_jug[posicion] = numero_objetivo;
            objetivo_a_asignar = objetivos -> obtener_dato(numero_objetivo);
            jugador -> asignar_objetivo(objetivo_a_asignar);
            posicion++;
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
	}

	else if (nombre_edificio == E) {
		edificio = new Escuela(piedra, madera, metal, limite_construccion, NULA, NULA);
	}

	else if (nombre_edificio == F) {
		edificio = new Fabrica(piedra, madera, metal, limite_construccion, NULA, NULA);
	}

	else if (nombre_edificio == M) {
		edificio = new Mina(piedra, madera, metal, limite_construccion, NULA, NULA);
	}

	else if (nombre_edificio == G) {
		edificio = new Mina_de_oro(piedra, madera, metal, limite_construccion, NULA, NULA);
	}

	else if (nombre_edificio == O) {
		edificio = new Obelisco(piedra, madera, metal, limite_construccion, NULA, NULA);
	}

	else if (nombre_edificio == P) {
		edificio = new Planta_electrica(piedra, madera, metal, limite_construccion, NULA, NULA);
	}
    
    diccionario -> agregar_edificio(edificio);
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
    return jugador_turno;
}

Jugador* Juego::devolver_jugador_2() {
    return jugador_secundario;
}

Mapa* Juego::devolver_mapa() {
    return mapa;
}

void Juego::mostrar_todos_edificios() {

	cout << ENTER_COLOR << "Esta es la informacion de todos los edificios: " << END_COLOR << endl;
    cout << endl;

	diccionario -> mostrar_todos_edificios();
}

void Juego::mostrar_costo_edificio(Edificio* edificio_a_construir) {
    cout << endl;
    cout << ENTER_COLOR << "Costos de construccion: " << END_COLOR << endl;
    cout << SUCESS_COLOR;
    cout << "-" << edificio_a_construir -> obtener_cantidad_piedra() << " unidades de piedra." << endl;
    cout << "-" << edificio_a_construir -> obtener_cantidad_madera() << " unidades de madera." << endl;
    cout << "-" << edificio_a_construir -> obtener_cantidad_metal() << " unidades de metal." << endl;
    cout << END_COLOR << endl;
}

void Juego::pedir_coordenadas(int &fila, int &columna) {
	
	pedir_fila(fila);

    while (fila <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo. No puede pasar el limite de filas en el mapa." << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    pedir_columna(columna);

    while (columna <= 0) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo. No puede pasar el limite de columnas en el mapa." << END_COLOR << endl;
        cout << endl;
        pedir_columna(columna);
    }
    
    fila = fila -1;
	columna = columna - 1;
    cout << endl;
}

void Juego::pedir_fila(int &fila) {
    cout << ENTER_COLOR << "Ingrese la fila del casillero deseado: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void Juego::pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna del casillero deseado: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

Diccionario* Juego:: devolver_diccionario(){
    return diccionario;
}

bool Juego::son_coordenadas_validas(int &fila, int &columna) {
        
    int filas = mapa -> obtener_filas();
    int columnas = mapa -> obtener_columnas();

    return (fila <= filas - 1 && columna <= columnas - 1);
}

void Juego::ubicar_jugador() {
    
    int fila;
    int columna;

    int numero_jugador = jugador_turno -> devolver_numero_jugador();
    
    cout << ENTER_COLOR << "Hola Jugador " << numero_jugador << "!" << END_COLOR << endl;
    cout << ENTER_COLOR << "Por favor, ingrese las coordenadas en las que desea ubicarse: " << END_COLOR << endl;

    pedir_coordenadas(fila, columna);
    
    while (!son_coordenadas_validas(fila, columna)) { 
        cout << ERROR_COLOR << "Las coordenadas ingresadas se encuentran fuera del Mapa." << END_COLOR << endl;
        pedir_coordenadas(fila, columna);
    }

    jugador_turno -> asignar_coordenadas(fila, columna);
}

bool Juego::acepta_realizar_accion() {
    string eleccion;
    cout << ENTER_COLOR << "Desea realizar esta accion? Ingrese 'Si' o 'si para confirmar: " << END_COLOR << endl;
    cin >> eleccion;
    return (eleccion == "Si" || eleccion == "si");
}

void Juego::opcion_construir_edificio_x_nombre() {

    int costo = 15;
    costo_energia(costo);

    if (alcanza_energia(costo)) {
        
        string nombre_edificio_construir = pedir_nombre_edificio_construir();
        Edificio* edificio_consultado = diccionario -> buscar_edificio(nombre_edificio_construir);

        int piedra, madera, metal, construidos;

        if (edificio_consultado != nullptr) {
            obtengo_cantidades_edificio(edificio_consultado, piedra, madera, metal, construidos);
            mostrar_costo_edificio(edificio_consultado);
            mostrar_inventario_en_pantalla();
            if (acepta_realizar_accion()) {
                int fila, columna;
                pedir_coordenadas(fila, columna);
                if (puede_construir_edificio(edificio_consultado, fila, columna)) {
                    construir_edificio(nombre_edificio_construir, fila, columna);
                    jugador_turno -> restar_energia(costo);
                }
                else { 
                    cout << ERROR_COLOR << "No se ha construido edificio." << END_COLOR << endl;
                    cout << ERROR_COLOR << "Este Casillero esta ocupado o no es un Terreno." << END_COLOR << endl;
                }
            }
            else {
                no_acepta_realzar_accion();
        
            }
        }
    }
}

bool Juego::puede_construir_edificio(Edificio* edificio, int &fila, int &columna) {
    
    string nombre_edificio = edificio -> obtener_nombre();
    int limite = edificio -> obtener_maximo_construir();
    int piedra, madera, metal, construidos;
    obtengo_cantidades_edificio(edificio, piedra, madera, metal, construidos);
    bool limite_respetado = respeta_limite(construidos, limite);
    bool piedra_suficiente = jugador_turno -> devolver_inventario() -> hay_piedra_suficiente(piedra);
    bool madera_suficiente = jugador_turno -> devolver_inventario() -> hay_madera_suficiente(madera);
    bool metal_suficiente = jugador_turno -> devolver_inventario() -> hay_metal_suficiente(metal);
    bool esta_ocupado = mapa -> obtener_casillero(fila, columna) -> esta_ocupado();
    bool hay_jugador = mapa -> obtener_casillero(fila, columna) -> esta_ocupado_jugador();
    string tipo_casillero = mapa -> obtener_casillero(fila, columna) -> obtener_tipo_casillero();

    return piedra_suficiente && madera_suficiente && metal_suficiente && limite_respetado && tipo_casillero == TERRENO && !esta_ocupado && !hay_jugador;
}

bool Juego::respeta_limite(int construidos, int limite) {
    
    if (construidos >= limite) {
        cout << ERROR_COLOR << "No se pueden construir mas Edificios de ese tipo." << END_COLOR << endl;
        return false;
    }
    return true;
}

void Juego::obtengo_cantidades_edificio(Edificio* edificio, int &piedra, int &madera, int &metal, int &construidos) {    
    
    string nombre_edificio = edificio -> obtener_nombre();
    piedra = edificio -> obtener_cantidad_piedra();                         
    madera = edificio -> obtener_cantidad_madera();
    metal = edificio -> obtener_cantidad_metal();
    construidos = devuelve_construidos_en_registro(nombre_edificio);
}

void Juego::construir_edificio(string nombre_edificio, int &fila, int &columna) {
    Edificio* edificio_a_construir = diccionario -> instanciar_edificio(nombre_edificio, fila + 1, columna + 1);
    ubicar_edificio(edificio_a_construir, fila, columna);
    cout << SUCESS_COLOR << "Se ha construido el Edificio existosamente!" << END_COLOR << endl;
}

void Juego::ubicar_edificio(Edificio* edificio_a_construir, int fila, int columna) {

    int piedra, madera, metal, construidos;
    obtengo_cantidades_edificio(edificio_a_construir, piedra, madera, metal, construidos);
    mapa -> obtener_casillero(fila, columna) -> construir_edificio(edificio_a_construir);
    mapa -> obtener_casillero(fila, columna)-> ocupar_casillero();
    jugador_turno -> devolver_registro_edificios() -> agregar(edificio_a_construir);
    jugador_turno -> cambia_cantidades_inventario(-madera, -piedra, -metal);
}

void Juego::mostrar_edificios_construidos() {
    jugador_turno -> devolver_registro_edificios() -> mostrar_registro_edificios();
}

void Juego::mostrar_inventario_en_pantalla() {
    jugador_turno -> devolver_inventario() -> mostrar_inventario();
}


void Juego::mostrar_objetivos_jugador() {

    int energia = jugador_turno -> obtener_energia();

    cout << ENTER_COLOR << "\nSu objetivo primario, construir un obelisco: " << END_COLOR;

    if (jugador_turno -> devolver_registro_edificios() -> obtener_cantidad_obeliscos() != OBELISCO_CONSTRUIDO) {
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
    }
    else {
        cout << SUCESS_COLOR << "COMPLETADO, GANASTE EL JUEGO!" << END_COLOR << endl;
    }
    
    cout << endl;
    cout << ENTER_COLOR << "Sus objetivos secundarios son los siguientes:" << END_COLOR << endl << endl;
    
    for (int i = 0; i < CANTIDAD_OBJETIVOS; i++) {
        jugador_turno -> mostrar_nombre_objetivo(i);
        jugador_turno -> mostrar_descripcion_objetivo(i);

        if (!jugador_turno -> objetivo_cumplido(i)) {
            jugador_turno -> mostrar_progreso_objetivo(i, energia, diccionario);
            cout<<endl;
        }
        else {
            cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
        }
    }
}

void Juego::verificar_objetivos() {

    Inventario *inventario = jugador_turno -> devolver_inventario();
    Registro_edificios* registro_edificios = jugador_turno -> devolver_registro_edificios();
    int energia = jugador_turno -> obtener_energia();
    
    for (int i = 0; i < CANTIDAD_OBJETIVOS; i++) {
        if (objetivos -> obtener_dato(i) -> comprobar_requisito(inventario, registro_edificios, diccionario, energia)){
            jugador_turno -> cumplir_objetivo(i);
            jugador_turno -> cumplir_un_objetivo_secundario();
        }
    }
    jugador_turno->gano();
}

void Juego::presentar_menu_np() {

    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;
    cout << "1) Modificar edificio por nombre." << endl;
    cout << "2) Listar todos los edificios." << endl;
    cout << "3) Mostrar mapa." << endl;
    cout << "4) Comenzar partida." << endl;
    cout << "5) Guardar y salir." << endl;
    cout << END_COLOR;
}

void Juego::procesar_opcion_np(int opcion) {

    switch (opcion) {
        case MODIFICAR_EDIFICIO_X_NOMBRE:
            diccionario -> modificar_valores_edificios();
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            system(CLR_SCREEN);
            diccionario -> mostrar_todos_edificios();
            break;
        case MOSTRAR_MAPA:
            mapa -> imprimir_mapa();
            break;
        case COMENZAR_PARTIDA:
            posicionar_jugadores();
            break;
        case GUARDAR_SALIR:
            guardar_edificios();
            jugador_turno -> salir_del_juego();
            break;
    }
}

bool opcion_valida_np(int opcion) {
    return(opcion >= OPCION_MINIMA_NP && opcion <= OPCION_MAXIMA_NP);
}

void Juego::presentar_menu() {
    cout << ENTER_COLOR << "Jugador " << jugador_turno -> devolver_numero_jugador();
    cout << ", puede elegir entre las siguientes opciones: " << END_COLOR << endl;
    cout << endl;
    cout << ENTER_COLOR << "Tu energia --> " << jugador_turno -> obtener_energia() << END_COLOR << endl << endl;
    cout << SUCESS_COLOR;
    cout << "1) Construir edificio por nombre." << endl;
    cout << "2) Listar los edificios construidos." << endl;
    cout << "3) Demoler un edificio por coordenada." << endl;
    cout << "4) Atacar un edificio por coordenada." << endl;
    cout << "5) Reparar un edificio por coordenada." << endl;
    cout << "6) Comprar bombas." << endl;
    cout << "7) Consultar coordenada." << endl;
    cout << "8) Mostrar inventario." << endl;
    cout << "9) Mostrar objetivos." << endl;
    cout << "10) Recolectar recursos producidos." << endl;
    cout << "11) Moverse a una coordenada." << endl;
    cout << "12) Finalizar turno." << endl;
    cout << "13) Guardar y salir." << endl;
    cout << END_COLOR;
}

void Juego::procesar_opcion(int opcion) {

    //system(CLR_SCREEN);
    Inventario* inventario = jugador_turno -> devolver_inventario();
    
    switch (opcion) {
        case CONSTRUIR_EDIFICIO_X_NOMBRE:
            opcion_construir_edificio_x_nombre();
            jugador_turno -> gano();
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mostrar_edificios_construidos();
            break;
        case DEMOLER_EDIFICIO_X_COORDENDA:
            demoler_edificio_x_coordenadas(inventario);
            jugador_turno -> gano();
            break;
        case ATACAR_EDIFICIO_X_COORDENADA:
            atacar_edificio_x_coordenadas(inventario);
            jugador_turno -> gano();
            break;
        case REPARAR_EDIFICIO_X_COORDENADA :
            reparar_edificio_x_coordenadas(inventario);
            jugador_turno -> gano();
            break;
        case COMPRAR_BOMBAS:
            comprar_bombas(inventario);
            jugador_turno -> gano();
            break;
        case CONSULTAR_COORDENADA:
            mapa -> consultar_casillero();
            break;
        case MOSTRAR_INVENTARIO:
            mostrar_inventario_en_pantalla();
            break;
        case MOSTRAR_OBJETIVOS:
            mostrar_objetivos_jugador();
            break;
        case RECOLECTAR_RECURSOS_PRODUCIDOS:
            recolectar_recursos();
            jugador_turno -> gano();
            break;
        case MOVERSE_A_UNA_COORDENADA:
            mapa -> moverse(jugador_turno);
            jugador_turno -> gano();
            break;
        case FINALIZAR_TURNO:
            finalzar_turno(inventario);
            break;
        case GUARDAR_Y_SALIR:
            int andycoins_partida = inventario -> devolver_cant_andycoins_acumulados();
            inventario ->cambiar_cantidad_elemento("andycoins acumulados", - andycoins_partida);
            guardar_edificios();
            guardar_ubicaciones();
            guardar_inventarios();
            jugador_turno -> salir_del_juego();
            cout << SUCESS_COLOR << "-Se han guardado exitosamente los cambios efectuados!" << END_COLOR << endl;
            break;
    }
}

bool Juego::opcion_valida(int opcion) {
    return(opcion >= OPCION_MINIMA && opcion <= OPCION_MAXIMA);
}

void Juego::finalzar_turno(Inventario*inventario){
    int bombas_compradas_partida = inventario ->devolver_cant_bombas_compradas();
    mostrar_objetivos_jugador();
    verificar_objetivos();
    inventario ->cambiar_cantidad_elemento("bombas compradas", - bombas_compradas_partida);
    jugador_turno -> terminar_turno();
    cambiar_turno();
}

string Juego::pedir_nombre_edificio_construir() {
    string nombre_edificio_construir;
    cout << ENTER_COLOR << "Ingrese el nombre edificio que desea construir: " << END_COLOR << endl;;
    getline(cin, nombre_edificio_construir);
    return nombre_edificio_construir;
}
    
int Juego::devuelve_construidos_en_registro(string nombre_edificio) {
    return (jugador_turno -> devolver_registro_edificios() -> obtener_edificios_construidos(nombre_edificio));
}

void Juego::llover() {
    mapa -> llover();
}

void Juego::recolectar_recursos() {
    
    int costo = 20;

    costo_energia(costo);
    
    if (alcanza_energia(costo)) {
        Registro_edificios* registro_edificios = jugador_turno -> devolver_registro_edificios();
        jugador_turno -> devolver_inventario() -> recolectar_recursos(registro_edificios);
    }
}

void Juego::demoler_edificio_x_coordenadas(Inventario* inventario) {

    int costo = 15;

    costo_energia(costo);
    if (alcanza_energia(costo)) {
        int fila, columna;

        pedir_coordenadas(fila, columna);
        Edificio*edificio_demoler = jugador_turno->devolver_registro_edificios()-> buscar_edificio_en_registro(fila+1,columna+1);

        bool ocupado = mapa->obtener_casillero(fila, columna)->esta_ocupado();
        bool es_jugador = mapa->obtener_casillero(fila, columna)->esta_ocupado_jugador();
        string tipo_terreno = mapa->obtener_casillero(fila, columna)->obtener_tipo_casillero();
        string nombre_edificio = edificio_demoler->obtener_nombre();

        if (tipo_terreno == TERRENO && ocupado && !es_jugador && edificio_demoler!= nullptr) {
            materiales_por_demolicion(nombre_edificio);
            if (acepta_realizar_accion()) {
                jugador_turno ->devolver_registro_edificios()->eliminar(fila , columna);
                mapa->obtener_casillero(fila, columna)->construir_edificio(nullptr);
                recuperar_mitad_materiales(nombre_edificio);
                jugador_turno -> restar_energia(costo);
                cout << SUCESS_COLOR << "El edificio se ha demolido exitosamente." << END_COLOR << endl;
            }
            else {
                no_acepta_realzar_accion();
                cout << "Ningun edificio demolido." << endl;
            }
        }
        else {
            cout << ERROR_COLOR << "No se encuentra un Edificio en esas coordenadas." << END_COLOR << endl;
        }
    }
}

void Juego::costo_energia(int costo) {
    cout << ENTER_COLOR << "Costo de energia: " << SUCESS_COLOR << costo << END_COLOR << endl;
}

bool Juego::alcanza_energia(int costo) {
    
    int tu_energia = jugador_turno -> obtener_energia();

    cout << ENTER_COLOR << "Tu energia actual: " << SUCESS_COLOR << tu_energia << END_COLOR << endl;

    if (tu_energia < costo) {
        cout << ERROR_COLOR << "No tienes energia suficiente para realizar esta accion." << END_COLOR << endl;
        return false;
    }
    return true;
}

void Juego:: comprar_bombas(Inventario*inventario) {
    
    int costo = 5;
    
    costo_energia(costo);
    
    if (alcanza_energia(costo)) {

        int tus_andycoins = inventario -> devolver_cant_andycoins();
        int precio_bomba = 100;
        int bombas_deseadas = pide_bombas_deseadas();
        int precio_total_bombas = precio_bomba*bombas_deseadas;

        muestra_info_precompra_bombas(precio_total_bombas, tus_andycoins);

        if (andycoins_suficientes(tus_andycoins, precio_total_bombas) && acepta_realizar_accion()) {
            se_compran_bombas(precio_total_bombas, costo, inventario);
            inventario -> acumular_bombas(bombas_deseadas);
          }
        else {
            no_acepta_realzar_accion();
            no_compra_bombas(inventario);
        }
    }
}

int Juego::pide_bombas_deseadas() {
    
    int bombas_pedidas;

    cout << ENTER_COLOR << "Ingrese la cantidad de bombas que desea adquirir: " << END_COLOR << endl;
    cin >> bombas_pedidas;
    cin.clear();
    cin.ignore(100, '\n');

    return bombas_pedidas;
}

bool Juego::andycoins_suficientes(int tus_andycoins, int precio_total_bombas) {
    if (tus_andycoins < precio_total_bombas) {
        cout << ERROR_COLOR << "No tienes suficientes Andycoins para realizar la compra." << END_COLOR << endl;
        return false;
    }
    return true;     
}

void Juego::muestra_info_precompra_bombas(int precio_total_bombas, int tus_andycoins) {
    cout << ENTER_COLOR << "Precio de total de Andycoins: " << SUCESS_COLOR << precio_total_bombas << END_COLOR << endl;
    cout << ENTER_COLOR << "Tus andycoins: " << SUCESS_COLOR << tus_andycoins << END_COLOR << endl;
}

void Juego::se_compran_bombas(int precio_total_bombas, int costo, Inventario* inventario) {

    inventario -> cambiar_cantidad_elemento(C, -precio_total_bombas);
    inventario -> cambiar_cantidad_elemento(B, precio_total_bombas / CIEN);

    int andycoins_actuales = inventario -> devolver_cant_andycoins();
    int bombas_actuales = inventario -> devolver_cant_bombas();
    int tu_energia = jugador_turno->obtener_energia();

    cout << ENTER_COLOR << "Ha comprado: " << SUCESS_COLOR << precio_total_bombas / CIEN << " bombas." << END_COLOR << endl;
    cout << ENTER_COLOR << "Ahora tienes un total de: " << SUCESS_COLOR << bombas_actuales << " bombas." << END_COLOR << endl;
    cout << ENTER_COLOR << "Ahora tienes un total de: " << SUCESS_COLOR << andycoins_actuales << " Andycoins." << END_COLOR << endl;
    cout << ENTER_COLOR << "Ahora tienes un total de: " << SUCESS_COLOR << tu_energia << " energia." << END_COLOR << endl;

    jugador_turno -> restar_energia(costo);
}

void Juego::no_compra_bombas(Inventario* inventario) {

    int bombas = inventario -> devolver_cant_bombas();
    int andycoins = inventario->devolver_cant_andycoins();
    cout << ERROR_COLOR << "No has comprado bombas." << END_COLOR << endl;
    cout << ENTER_COLOR << "Tienes un total de: " << SUCESS_COLOR << bombas << " bombas." << END_COLOR << endl;
    cout << ENTER_COLOR << "Tienes un total de: " << SUCESS_COLOR << andycoins << " Andycoins." << END_COLOR << endl;
}

void Juego::no_acepta_realzar_accion(){
    int tu_energia = jugador_turno->obtener_energia();
    cout << ENTER_COLOR << "No aceptaste realizar accion." << SUCESS_COLOR << endl;
    cout << ENTER_COLOR << "Tienes un total de: " << SUCESS_COLOR << tu_energia << " energia." << END_COLOR << endl;
}

void Juego::materiales_por_demolicion(string nombre_edificio){
    int madera_recuperada = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_madera();
    int piedra_recuperada = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_piedra();
    int metal_recuperado = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_metal();
    cout << ENTER_COLOR << "Materiales recuperados" << END_COLOR << endl;
    cout << SUCESS_COLOR << "Madera: " << madera_recuperada << endl;
    cout << "Piedra: " << piedra_recuperada << endl;
    cout << "Metal: " << metal_recuperado << endl;
}

void Juego::recuperar_mitad_materiales(string nombre_edificio) {
    int madera_recuperada = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_madera();
    int piedra_recuperada = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_piedra();
    int metal_recuperado = diccionario->buscar_edificio(nombre_edificio)-> obtener_mitad_metal();
    jugador_turno -> devolver_inventario() ->cambiar_cantidad_elemento("madera", madera_recuperada );
    jugador_turno -> devolver_inventario() ->cambiar_cantidad_elemento("piedra", piedra_recuperada );
    jugador_turno -> devolver_inventario() ->cambiar_cantidad_elemento("metal", metal_recuperado );
}

void Juego::atacar_edificio_x_coordenadas(Inventario* inventario) {

    int costo = 30;

    costo_energia(costo);
    if (alcanza_energia(costo)) {
        int fila, columna;

        pedir_coordenadas(fila, columna);
	    Edificio*edificio_atacar = jugador_secundario-> devolver_registro_edificios()->buscar_edificio_en_registro(fila+1,columna+1);
        bool ocupado = mapa->obtener_casillero(fila, columna)->esta_ocupado();
        bool es_jugador = mapa->obtener_casillero(fila, columna)->esta_ocupado_jugador();
	    string nombre_edificio = edificio_atacar->obtener_nombre();
        
        if (ocupado && !es_jugador && edificio_atacar!= nullptr) {
            int vida_edificio = edificio_atacar ->obtener_vida_actual();
		    cout << nombre_edificio << " tiene " << vida_edificio <<" vida/s."<< endl;
		    cout << "Necesitas " << vida_edificio << " bombas para destruir completamente." << endl;
        
		    if (acepta_realizar_accion()) {
			
                if ( (nombre_edificio == "fabrica") || (nombre_edificio == "mina" )){
                    int bombas_ataque = bombas_a_usar(vida_edificio);
                    int vida_pos_ataque = edificio_atacar -> restar_vida(bombas_ataque);
                    inventario -> sumar_bombas_usadas(bombas_ataque);
                    inventario -> cambiar_cantidad_elemento("bombas", -bombas_ataque);
                    
                    if (vida_pos_ataque == 0){
                        jugador_secundario -> devolver_registro_edificios() -> eliminar(fila+1, columna+1);
                        mapa->obtener_casillero(fila, columna)->construir_edificio(nullptr);
                        mapa->obtener_casillero(fila, columna)->desocupar_casillero();
                        jugador_turno -> restar_energia(costo);
                        cout << "Has derribado el edificio del oponente."<< endl;
                    }
                
                    else if (vida_pos_ataque > 0) {
                        jugador_turno -> restar_energia(costo);
                        cout<< SUCESS_COLOR << "Has atacado el edificio del oponente pero sigue en pie. Le quedaron " << edificio_atacar->obtener_vida_actual() << " vidas." << END_COLOR << endl;
                    }
                }
                
                else{
                    int bombas_ataque = bombas_a_usar(vida_edificio);
				    jugador_turno -> restar_energia(costo);
				    jugador_secundario ->devolver_registro_edificios() -> eliminar(fila+1, columna+1);
                    inventario -> sumar_bombas_usadas(bombas_ataque);
                    inventario -> cambiar_cantidad_elemento("bombas", -bombas_ataque);
                    mapa->obtener_casillero(fila, columna)->construir_edificio(nullptr);
                    mapa->obtener_casillero(fila, columna)->desocupar_casillero();
				    cout << "Has derribado el edificio del oponente."<< endl;
				    cout << "Te quedan: " << inventario ->devolver_cant_bombas()  << " bombas." << endl;
                }
		    }
		
        else{
			no_acepta_realzar_accion();
			cout << "Ningun edificio demolido." << endl;
		}
        
    }
}
}


int Juego::bombas_a_usar(int limite){
    int bombas_usadas = 0;
	while (bombas_usadas <= 0 || bombas_usadas > limite){
        cout << ENTER_COLOR << "Ingrese cantidad bombas a usar (solo necesitas" << limite << " bombas): " << END_COLOR;
        cin >> bombas_usadas;
	}
	return bombas_usadas;
}
void Juego::reparar_edificio_x_coordenadas(Inventario*inventario){
    int costo = 25;
    costo_energia(costo);
    if (alcanza_energia(costo)) {
        int fila, columna;

        pedir_coordenadas(fila, columna);
        Edificio*edificio_reparar = jugador_turno-> devolver_registro_edificios()->buscar_edificio_en_registro(fila+1,columna+1);
        bool ocupado = mapa->obtener_casillero(fila, columna)->esta_ocupado();
        bool es_jugador = mapa->obtener_casillero(fila, columna)->esta_ocupado_jugador();

        if (ocupado && !es_jugador && edificio_reparar!= nullptr && tengo_el_porcentaje_necesario(edificio_reparar)) {

            string nombre_edificio_r = edificio_reparar -> obtener_nombre();
            int vida_edificio = edificio_reparar ->obtener_vida_actual();

            if ((nombre_edificio_r == F) || (nombre_edificio_r == M)){
                cout << ENTER_COLOR << nombre_edificio_r << " tiene " << vida_edificio <<" vida/s."<< END_COLOR << endl;
                int costo_madera = inventario->devolver_cant_madera() / 4;
                int costo_piedra = inventario->devolver_cant_piedra() / 4;
                int costo_metal = inventario->devolver_cant_metal() / 4;
                if ( vida_edificio == 2){
                    cout << ERROR_COLOR << "\nEl edificio no necesita reparacion." << END_COLOR << endl;
                }
                else if (vida_edificio == 1){
                    cout << ENTER_COLOR << "Costo madera: " << costo_madera << endl;
                    cout << "Costo piedra: " << costo_piedra << endl;
                    cout << "Costo metal:" << costo_metal<< END_COLOR << endl;
                    cout << SUCESS_COLOR << "\nEl edificio necesita reparacion." << END_COLOR << endl;
                    if (acepta_realizar_accion()){
                        edificio_reparar ->sumar_vida(1);
                        inventario ->cambiar_cantidad_elemento("madera",-costo_madera);
                        inventario ->cambiar_cantidad_elemento("piedra",-costo_piedra);
                        inventario ->cambiar_cantidad_elemento("metal",-costo_metal);
                        jugador_turno ->restar_energia(costo);

                    }
                    else{
                        cout << SUCESS_COLOR << "No se ha reparado edificio." << END_COLOR << endl;
                        no_acepta_realzar_accion();
                    }
                }
            }
            else{
                cout << ERROR_COLOR << "Edificio no reparable y en pien." << END_COLOR << endl;
            }
        }
        else{
            cout << ERROR_COLOR << "No es posible reparar edificio." << END_COLOR << endl;
        }
    }
}

bool Juego::tengo_el_porcentaje_necesario(Edificio*edificio){
    Registro_edificios*registro_edificios = jugador_turno->devolver_registro_edificios();
    int fila = edificio->obtener_fila();
    int columna = edificio -> obtener_columna();
    bool tengo_madera = jugador_turno->devolver_inventario()->porcentaje_de_madera_existente((25/100),registro_edificios,fila,columna);
    bool tengo_piedra = jugador_turno->devolver_inventario()->porcentaje_de_piedra_existente((25/100),registro_edificios,fila,columna);
    bool tengo_metal = jugador_turno->devolver_inventario()->porcentaje_de_metal_existente((25/100),registro_edificios,fila,columna);
    if (tengo_madera  && tengo_metal && tengo_piedra){
        cout << SUCESS_COLOR << "Tengo los materiales necesarios." << END_COLOR << endl;
        return true;
    }
    else {
        cout << ERROR_COLOR << "No tengo los materiales necesario." << END_COLOR << endl;
        return false;
    }
}