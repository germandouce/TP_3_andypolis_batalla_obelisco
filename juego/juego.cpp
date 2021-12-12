#include "juego.h"

Juego::Juego() {
    this -> jugador_turno = new Jugador();
    this -> jugador_secundario = new Jugador();
    this -> mapa = new Mapa();
    this -> diccionario = new Diccionario();
    this -> objetivos = new Vector<Objetivo>;
}

void Juego::elegir_opcion_menu_np() {
    int opcion_elegida;
            
    system(CLR_SCREEN);
    while (opcion_elegida != COMENZAR_PARTIDA) {

        presentar_menu_np();

        cin >> opcion_elegida;
        cin.clear();
        cin.ignore(100, '\n');

        while (!opcion_valida_np(opcion_elegida)) {
            cout << ERROR_COLOR << "Opcion no valida. Eliga nuevamente." << END_COLOR << endl;
            cin >> opcion_elegida;
            cin.clear();
            cin.ignore(100, '\n');
        }

        procesar_opcion_np(opcion_elegida);
    }  
}

bool Juego::opcion_valida_np(int opcion) {
    return(opcion >= OPCION_MINIMA_NP && opcion <= OPCION_MAXIMA_NP);
}

void Juego::cambiar_turno() {
    Jugador* jugador_auxiliar = jugador_turno;
    jugador_turno = jugador_secundario;
    jugador_secundario = jugador_auxiliar;
}

bool Juego::turno_terminado() {
    
    bool sin_energia = !jugador_turno -> tiene_energia();
    bool alguien_gano = jugador_turno -> gano();
    bool quiere_salir = jugador_turno -> quiere_salir_del_juego();
    bool quiere_terminar_turno = ! (jugador_turno -> es_su_turno());

    return (alguien_gano || sin_energia || quiere_terminar_turno || quiere_salir);
}

bool Juego::juego_terminado() {

    bool alguien_gano = jugador_turno -> gano();
    bool quiere_salir = jugador_turno -> quiere_salir_del_juego();

    return (alguien_gano || quiere_salir);
}

void Juego::jugar_partida() {
    
    int turnos_sin_llover = 0;

    while (!juego_terminado()) {
            
        cambiar_turno();

        cout << "TURNO DEL JUGADOR " << jugador_turno -> devolver_numero_jugador() << endl;
            
        turnos_sin_llover++;

        if (turnos_sin_llover == (TURNOS_PARA_LLOVER)) {
            mapa -> llover();
            turnos_sin_llover = 0;
        }

        //comienzo de turno
        jugar_turno();
    }
}

void Juego::jugar_turno() {

    jugador_turno -> sumar_energia(20);

    while (!turno_terminado()) {

        int opcion;

        //system(CLR_SCREEN);
        mapa -> imprimir_mapa();
        presentar_menu();

        cin >> opcion;
        cin.clear();
        cin.ignore(100, '\n');

        while (!opcion_valida(opcion)) {
            cout << "Opcion no valida. Eliga nuevamente." << endl;
            cin >> opcion;
            cin.clear();
            cin.ignore(100, '\n');
        }

        procesar_opcion(opcion);

        if (jugador_turno -> tiene_energia()) {
            jugador_turno -> terminar_turno();
        } 
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
            cargar_inventario(archivo);
        }
    }
}
  
//void Juego::validar_ingreso_jugador(){}

//achicar esta funcion
void Juego::posicionar_jugadores() {

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

    jugador_turno -> setear_numero_jugador(ingreso);
    jugador_secundario -> setear_numero_jugador(DIFERENCIA_JUGADORES - ingreso);

    ubicar_jugador(jugador_turno);
    ubicar_jugador(jugador_secundario);

    int fila1 = jugador_turno -> devolver_fila();
    int columna1 = jugador_turno -> devolver_columna();

    int fila2 = jugador_secundario -> devolver_fila();
    int columna2 = jugador_secundario -> devolver_columna();

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
void Juego::cargar_inventario(ifstream& inventario) {

    string nombre;
    string cantidad_1;
    string cantidad_2;

    Inventario* inventario_jugador_1 = jugador_turno -> devolver_inventario();
    Inventario* inventario_jugador_2 = jugador_secundario -> devolver_inventario();

    while(inventario >> nombre){
        inventario >> cantidad_1;
        inventario >> cantidad_2;

        if (nombre == I_MADERA) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == I_PIEDRA) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == I_METAL) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
        }
        else if (nombre == I_BOMBAS) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_1->actualizar_cant_anterior_elemento(I_BOMBAS);
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            inventario_jugador_2->actualizar_cant_anterior_elemento(I_BOMBAS);
        }
        else if (nombre == I_ANDYCOINS) {
            inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
            inventario_jugador_1->actualizar_cant_anterior_elemento(I_ANDYCOINS);
            inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            inventario_jugador_2->actualizar_cant_anterior_elemento(I_ANDYCOINS);
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
        }
        else if (nombre_elemento != "1" && nombre_elemento != "2") {
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
    
    jugador_turno -> setear_numero_jugador(1);
    asignar_objetivos(jugador_turno);

    jugador_secundario -> setear_numero_jugador(2);
    asignar_objetivos(jugador_secundario);
}

void Juego::cargar_objetivos(){

    Objetivo *comprar_andypolis = new Comprar_andypolis();
    objetivos->insertar_ultimo(comprar_andypolis);

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

void Juego::asignar_objetivos(Jugador* jugador) {

    int vector_objetivos_jug[3];

    Objetivo* objetivo_a_asignar;

    int objetivo_1 = generar_numero_random(0,9);
    
    objetivo_a_asignar = objetivos -> obtener_dato(objetivo_1);    
    jugador -> asignar_objetivo(objetivo_a_asignar);
    
    vector_objetivos_jug[0] = objetivo_1;
    
    bool ya_toco;
    int cantidad = 1;
    while(cantidad <= 2){
        
        int numero_objetivo = generar_numero_random(0,9);
        ya_toco = false;

        for(int i = 0; i <cantidad; i++){
            if(vector_objetivos_jug[i] == numero_objetivo){
                cout<<vector_objetivos_jug[i];
                ya_toco = true;
            }
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
		edificio = new Mina_de_oro(piedra, madera, metal, limite_construccion, NULA, NULA);
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
    return jugador_turno;
}

Jugador* Juego::devolver_jugador_2() {
    return jugador_secundario;
}

Mapa* Juego::devolver_mapa(){
    return mapa;
}

void Juego::mostrar_todos_edificios() {

	cout << ENTER_COLOR << "Esta es la informacion de todos los edificios: " << END_COLOR << endl;
    cout << endl;

	diccionario -> mostrar_todos_edificios();
}

Edificio* Juego::encontrar_edificio() {

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

void Juego::verificar_construccion() {

    Edificio* edificio_a_construir = encontrar_edificio();
	int fila;
	int columna;
	bool verificacion = true;

	if (edificio_a_construir != nullptr) {

		pedir_coordenadas(fila, columna);
			
		if (mapa -> obtener_casillero(fila, columna) -> esta_ocupado()) {
			cout << ERROR_COLOR << "-Las coordenadas ingresadas se encuentran ocupadas." << END_COLOR << endl;
			verificacion = false;
		}

		if (verificacion) {
			confirmar_construccion(fila, columna, edificio_a_construir);
    	}
	} 
}

void Juego::confirmar_construccion(int fila, int columna, Edificio* edificio_a_construir) {

    string respuesta;
    string nombre_edificio = edificio_a_construir -> obtener_nombre();

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Esta seguro que desea construir un/a '" << nombre_edificio << "'?" << END_COLOR << endl;;
    cout << SUCESS_COLOR << "Ingrese 'si' para confirmar." << END_COLOR << endl;
    mostrar_costo_edificio(edificio_a_construir);
    cin >> respuesta;
    cout << endl;
    
    if (respuesta == "si") {
        mapa -> construir_edificio(fila, columna, edificio_a_construir);
        cout << SUCESS_COLOR << "-Se ha construido exitosamente un/a '" << nombre_edificio << "'." << END_COLOR << endl;
    }
    else {
        cout << ERROR_COLOR << "-No se ha construido el edificio." << END_COLOR << endl;
    }
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
	
	//system(CLR_SCREEN);

	pedir_fila(fila);

    while (fila <= 0 || fila >= devolver_mapa()->obtener_filas() -1 ) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo y no pasar los limites del mapa." << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    pedir_columna(columna);

    while (columna <= 0  || columna >= devolver_mapa()->obtener_columnas() -1 ) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo y no pasar los limites del mapa." << END_COLOR << endl;
        cout << endl;
        pedir_columna(columna);
    }

	fila = fila - 1;
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

void Juego::ubicar_jugador(Jugador*jugador_turno) {
    int fila;
    int columna;

    int numero_jugador = jugador_turno->devolver_numero_jugador();
    
    cout<<"Hola jugador "<< numero_jugador <<"!" <<endl
    <<"\nPor favor, ingrese las coordenadas en las que desea ubicarse:"<<endl;


    pedir_coordenadas(fila, columna);

    if (numero_jugador == 1)
        devolver_jugador_1() -> asignar_coordenadas(fila, columna);
    else if (numero_jugador == 2)
        devolver_jugador_2() -> asignar_coordenadas(fila,columna);
}

void Juego::pedir_posicion(Jugador*jugador_turno) {
	system(CLR_SCREEN);
    int filas = mapa-> obtener_filas();
    int columnas = mapa-> obtener_columnas();
    
	int fila;
    pedir_fila(fila);

    while (fila <= 0 || fila > filas-1) {
        //system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo menor a"<< 
        filas << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    int columna;
    pedir_columna(columna);

    while (columna <= 0 || columna > columnas-1) {
        //system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo menor a "
        << columnas<< END_COLOR << endl;
        
        cout << endl;
        pedir_columna(columna);
    }

	fila = fila - 1;
	columna = columna - 1;
    cout << endl;
}


bool Juego::acepta_realizar_accion() {
    string eleccion;
    cout << "Desea realizar esta accion? Ingrese 'Si' o 'si para confirmar." << endl;
    cin >> eleccion;
    return (eleccion == "Si" || eleccion == "si");
}

void Juego::opcion_construir_edificio_x_nombre() {
    
    string nombre_edificio_construir = pedir_nombre_edificio_construir();

    Edificio* edificio_consultado = diccionario -> buscar_edificio(nombre_edificio_construir);
    Edificio* edificio_a_construir;

    int piedra, madera, metal, construidos;

    if (edificio_consultado != nullptr) {
        obtengo_cantidades_edificio(edificio_consultado, piedra, madera, metal, construidos);
        
        if (puede_construir_edificio(edificio_consultado)) {

            if (acepta_realizar_accion()) {
                construir_edificio(nombre_edificio_construir);
            }
            else {
                cout << "No se ha construido el Edificio." << endl;
                cout << endl;
            }
        }
    }
}

bool Juego::puede_construir_edificio(Edificio* edificio) {
    string nombre_edificio = edificio -> obtener_nombre();
    int limite = edificio -> obtener_maximo_construir();

    int piedra, madera, metal, construidos;
    obtengo_cantidades_edificio(edificio, piedra, madera, metal, construidos);
    
    bool limite_respetado = respeta_limite(construidos, limite);
    bool piedra_suficiente = jugador_turno -> devolver_inventario() -> hay_piedra_suficiente(piedra);
    bool madera_suficiente = jugador_turno -> devolver_inventario() -> hay_madera_suficiente(madera);
    bool metal_suficiente = jugador_turno -> devolver_inventario() -> hay_metal_suficiente(metal);

    return piedra_suficiente && madera_suficiente && metal_suficiente && limite_respetado;
}

bool Juego::respeta_limite(int construidos, int limite) {
    if (construidos > limite) {
        cout << "No se pueden construir mas Edificios de ese tipo." << endl;
        return false;
    }
    return true;
}

void Juego::obtengo_cantidades_edificio(Edificio* edificio, int &piedra, int &madera, int &metal, int &construidos) {    
    string nombre_edificio = edificio -> obtener_nombre();                            
    metal = edificio -> obtener_cantidad_metal();
    piedra = edificio -> obtener_cantidad_piedra();
    metal = edificio-> obtener_cantidad_madera();
    construidos = devuelve_construidos_en_registro(nombre_edificio);
}

void Juego::construir_edificio(string nombre_edificio) {

    int fila, columna;
    pedir_coordenadas(fila, columna);
    bool esta_ocupado = mapa -> obtener_casillero(fila, columna) -> esta_ocupado();
    string tipo_casillero = mapa -> obtener_casillero(fila, columna) -> obtener_tipo_casillero();

    if (!esta_ocupado && tipo_casillero == TERRENO) {
        Edificio *edificio_a_construir = diccionario -> instanciar_edificio(nombre_edificio, fila, columna);
        ubicar_edificio(edificio_a_construir, fila, columna);
    }
    else {
        cout << "Este casillero esta ocupado o no es un terreno." << endl;
    }
}

void Juego::ubicar_edificio(Edificio* edificio_a_construir, int fila, int columna) {

    int piedra, madera, metal, construidos;
    obtengo_cantidades_edificio(edificio_a_construir, piedra, madera, metal, construidos);
    mapa -> obtener_casillero(fila, columna) -> construir_edificio(edificio_a_construir);
    mapa -> obtener_casillero(fila, columna)-> ocupar_casillero();
    jugador_turno -> devolver_resgitro_edificios() -> agregar(edificio_a_construir);
    jugador_turno -> cambia_cantidades_inventario(-madera, -piedra, -metal);
}

void Juego::mostrar_edificios_construidos(){
    jugador_turno->devolver_resgitro_edificios()->mostrar_registro_edificios();
}

void Juego::mostrar_inventario_en_pantalla(){
    jugador_turno -> devolver_inventario() -> mostrar_inventario();
}

void Juego::mostrar_objetivos_jugador() {
    Inventario *inventario = jugador_turno->devolver_inventario();
    Registro_edificios* registro_edificios = jugador_turno->devolver_resgitro_edificios();
    int energia = jugador_turno -> obtener_energia();

    cout<<"Sus objetivo primario es el siguiente: "<<endl;
    cout<<"Construir un obelisco: ";
    if (jugador_turno ->devolver_resgitro_edificios()->obtener_cantidad_obeliscos() != 1){
        cout<<"No completado"<<endl;
    }
    else{
        cout<<"completado, ganaste el juego!";
    }
    cout<<"\nSus objetivos secundarios son los siguientes: \n"<<endl;
    for (int i = 0; i < 3; i++) {
        jugador_turno->mostrar_nombre_objetivo(i);
        jugador_turno->mostrar_descripcion_objetivo(i);
        objetivos->obtener_dato(i)->mostrar_descripcion();
        if ( ! jugador_turno->objetivo_cumplido(i) ) {
            
            jugador_turno->mostrar_progreso_objetivo(i, energia, diccionario);
        }
        else{
            cout<<"Completado";
        }
    }
}

void Juego::verificar_objetivos() {
    Inventario *inventario = jugador_turno -> devolver_inventario();
    Registro_edificios* registro_edificios = jugador_turno -> devolver_resgitro_edificios();
    int energia = jugador_turno -> obtener_energia();
    
    for (int i; i<2; i++){
        if (objetivos->obtener_dato(i) -> comprobar_requisito(inventario, registro_edificios, diccionario, energia)
        && jugador_turno -> objetivo_cumplido(i) ){
            jugador_turno -> cumplir_un_objetivo_secundario();
            jugador_turno -> cumplir_objetivo(i);
        };
    }
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
            break;
    }
}

bool opcion_valida_np(int opcion) {
    return(opcion >= OPCION_MINIMA_NP && opcion <= OPCION_MAXIMA_NP);
}

void Juego::presentar_menu() {
    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
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
    Registro_edificios* registro_edificios = jugador_turno -> devolver_resgitro_edificios();
    
    switch (opcion) {
        case CONSTRUIR_EDIFICIO_X_NOMBRE:
            //falta verificar antes energia
            opcion_construir_edificio_x_nombre();
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mostrar_edificios_construidos();
            break;
        case DEMOLER_EDIFICIO_X_COORDENDA:
            //system("cls");
            break;
        case ATACAR_EDIFICIO_X_COORDENADA:
            break;
        case REPARAR_EDIFICIO_X_COORDENADA :
            // system("cls");
            //REPARAR
            //Pasar coordenada. verificar su existencia en el mapa.
            //Spottear edificio en el mapa.
            //verificar que no sea nuestro
            //Ver estado de edificio.
            //Verificar en inventario materiales (al menos 25% de c/u requerido) y energia.
            //Reparar (si lo desea el usuario--consultar).
            //Volver al menu.
            break;
        case COMPRAR_BOMBAS:
           //  system("cls");
            //COMPRAR BOMBAS
            //Usuario ingresa cantidad deseada de bombas a comprar.
            //Verificar andycoins.
            //Informar situacion al usuario
            //Si se puede comprar preguntar antes de realizar accion.
            //Si el usuario acepta , realizar compra , informar balance final y volver al menu.
            //De lo contrario volver al menu (sin realizar compra).
            break;
        case CONSULTAR_COORDENADA:
            //mapa -> consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            mostrar_inventario_en_pantalla();
            break;
        case MOSTRAR_OBJETIVOS:
            mostrar_objetivos_jugador();
            break;
        case RECOLECTAR_RECURSOS_PRODUCIDOS:
            recolectar_recursos();
            break;
        case MOVERSE_A_UNA_COORDENADA:
            mapa -> moverse(inventario, jugador_turno);
            break;
        case FINALIZAR_TURNO:
            cambiar_turno();
            //OJO CON ESTO!
            break;
        case GUARDAR_Y_SALIR:
           //  system("cls");
            //guardar_materiales(vector_materiales);
            //guardar_ubicaciones(vector_ubicaciones);
            //mapa -> borrar();
            //delete mapa;
            cout << "-Se han guardado exitosamente los cambios efectuados!" << endl;
            jugador_turno->salir_del_juego();
            break;
    }
}

bool Juego::opcion_valida(int opcion) {
    return(opcion >= OPCION_MINIMA && opcion <= OPCION_MAXIMA);
}

string Juego:: pedir_nombre_edificio_construir(){
    string nombre_edificio_construir;
    cout << "Ingrese nombre edificio que desea construir: ";
    cin >> nombre_edificio_construir;
    return nombre_edificio_construir;
    }
    
int Juego::devuelve_construidos_en_registro(string nombre_edificio){
    return (jugador_turno -> devolver_resgitro_edificios() -> obtener_edificios_construidos(nombre_edificio) );
}

void Juego::llover() {
    mapa -> llover();
}

void Juego::recolectar_recursos() {
    Registro_edificios* registro_edificios = jugador_turno -> devolver_resgitro_edificios();
    jugador_turno -> devolver_inventario() -> recolectar_recursos(registro_edificios);
}

bool Juego::es_nuestro_edificio(int fila, int columna){
    return jugador_turno -> devolver_resgitro_edificios() -> existe(fila, columna);
}

//void Juego::demoler_edificio_x_coordenadas(){
    //int costo = 15;
    //int tu energia =jugador_turno -> obtener_energia();
    //cout<<"Costo energetico : " << costo << endl;
    //cout<<"Tu energia actual: "<< tu_energia << endl;
    //if(jugador_turno -> tiene_energia() && tu_energia > costo )
    //  int fila, columna;
    //  pedir_coordenadas(fila, columna);
    //bool ocupado = mapa -> obtener_casillero(fila, columna) -> esta_ocupado();
    //bool es_jugador = mapa -> obtener_casillero(fila, columna) -> esta_ocupado_jugador();
    //string tipo_casillero = mapa -> obtener_tipo_casillero();
    //verificar_vida_actual_edificio.
    //if(!es_nuestro_edificio(fila,columna));
    //Ver tipo y estado de edificio para saber costo de destruccion.
    //inventario -> devolver_cant_bombas();
    //if(acepta_realizar_accion());
    //Volver al menu.
//}