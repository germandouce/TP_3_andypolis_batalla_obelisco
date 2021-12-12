#include "juego.h"

Juego::Juego() {
    this -> jugador1 = new Jugador();
    this -> jugador2 = new Jugador();
    this -> mapa = new Mapa();
    this -> diccionario = new Diccionario();
    this -> objetivos = new Vector<Objetivo>;
}

/*
void Juego::turno_jugador(bool &alguien_gano, bool &sin_energia, bool &quiere_terminar_turno, bool &quiere_salir, ){
    while (!alguien_gano && !sin_energia && !quiere_terminar_turno && !quiere_salir) {
                
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

                procesar_opcion(opcion ,juego, jug_turno, jug_secundario);
                
                sin_energia = jug_turno ->esta_sin_energia();
                alguien_gano = jug_turno ->gano();
                quiere_salir = jug_turno -> quiere_salir_del_juego();
                quiere_terminar_turno = ! ( jug_turno -> es_su_turno() );
            }
}
*/


void Juego::leer_archivos(Mapa* &mapa, int &archivos_cargados, bool nueva_partida, Jugador* &jug_1, Jugador* &jug_2) {
    
    ifstream archivo;

    if (es_archivo_legible(archivo, ARCHIVO_MAPA)) {
        devolver_mapa() -> cargar_mapa(archivo);
        mapa = devolver_mapa();  
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

//    if (!nueva_partida) {
        if (es_archivo_legible(archivo, ARCHIVO_MATERIALES)) {
            cargar_inventario(archivo);
        }
    // }
}

void Juego::posicionar_jugadores(Jugador* &jug_1, Jugador* &jug_2, Mapa* &mapa) {

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

    jug_1 -> setear_numero_jugador(ingreso);
    jug_2 -> setear_numero_jugador(DIFERENCIA_JUGADORES - ingreso);

    // pedir_coordenadas()
    // pedir_coordenadas()

    ubicar_jugador(jug_1);
    ubicar_jugador(jug_2);

    int fila1 = jug_1 -> devolver_fila();
    int columna1 = jug_1 -> devolver_columna();

    int fila2 = jug_2 -> devolver_fila();
    int columna2 = jug_2 -> devolver_columna();

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

    Inventario* inventario_jugador_1 = jugador1 -> devolver_inventario();
    Inventario* inventario_jugador_2 = jugador2 -> devolver_inventario();

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
            jugador = jugador1;
            jugador -> asignar_coordenadas(stoi(fila), stoi(columna));
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_jugador1();
            mapa -> obtener_casillero(stoi(fila) - 1, stoi(columna) - 1) -> ocupar_casillero();
        }
        else if (nombre_elemento == "2") {
            jugador = jugador2;
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
    return jugador1;
}

Jugador* Juego::devolver_jugador_2() {
    return jugador2;
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

    while (fila <= 0 || fila > devolver_mapa()->obtener_filas() -1 ) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
        cout << endl;
        pedir_fila(fila);
    }

    pedir_columna(columna);

    while (columna <= 0  || columna > devolver_mapa()->obtener_columnas() -1 ) {
        system(CLR_SCREEN);
        cout << ERROR_COLOR << "-Debe ingresar un numero positivo." << END_COLOR << endl;
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

void Juego::ubicar_jugador(Jugador*jug_turno) {
    int fila;
    int columna;

    int numero_jugador = jug_turno->devolver_numero_jugador();
    
    cout<<"Hola jugador "<< numero_jugador <<"!" <<endl
    <<"\nPor favor, ingrese las coordenadas en las que desea ubicarse:"<<endl;


    pedir_coordenadas(fila, columna);

    if (numero_jugador == 1)
        devolver_jugador_1() -> asignar_coordenadas(fila, columna);
    else if (numero_jugador == 2)
        devolver_jugador_2() -> asignar_coordenadas(fila,columna);
}

void Juego::pedir_posicion(Jugador*jug_turno) {
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

void Juego::opcion_construir_edificio_x_nombre(Jugador*jug_turno) {
    Registro_edificios* registro_edificios = jug_turno -> devolver_resgitro_edificios();
    Inventario*inventario = jug_turno->devolver_inventario();
    Casillero ***casillero = devolver_mapa()->devolver_matriz();
    
    string nombre_edificio_construir;
    cout << "Ingrese nombre edificio que desea construir: ";
    cin >> nombre_edificio_construir;

    Edificio* edificio_consultado = diccionario -> buscar_edificio(nombre_edificio_construir);
    Edificio* edificio_a_construir;

    if (edificio_consultado != nullptr) {
        
        int piedra = edificio_consultado -> obtener_cantidad_piedra();
        int madera = edificio_consultado -> obtener_cantidad_madera();
        int metal = edificio_consultado -> obtener_cantidad_metal();

        int construidos =  registro_edificios-> obtener_edificios_construidos(nombre_edificio_construir);
        int limite = edificio_consultado -> obtener_maximo_construir();

        if (puede_construir_edificio(piedra, madera, metal, jug_turno) && construidos < limite) {

            if (acepta_realizar_accion()) {

                int fila;
                int columna;
                
                pedir_coordenadas(fila, columna);

                bool esta_ocupado = casillero[fila][columna] -> esta_ocupado();
                string tipo_casillero = casillero[fila][columna] -> obtener_tipo_casillero();

                if (!esta_ocupado && tipo_casillero == TERRENO) {
                    edificio_a_construir = diccionario -> instanciar_edificio(nombre_edificio_construir, fila, columna);
                    casillero[fila][columna] -> construir_edificio(edificio_a_construir);
                    casillero[fila][columna] -> ocupar_casillero();
                    registro_edificios -> agregar(edificio_a_construir);
                    jug_turno -> cambia_cantidades_inventario(-madera,-piedra, -metal);
                }
                else{
                    cout<<"Este casillero esta ocupado o no es un terreno"<<endl;
                }
            }
            else {
                cout << "No se ha construido el Edificio." << endl;
                cout << endl;
            }
        }
        else {
            cout << "No cumples con los requisitos necesarios para construir el Edificio." << endl;
            cout << endl;
        }
    }
}

bool Juego::puede_construir_edificio(int piedra, int madera, int metal, Jugador*jug_turno) {


    bool piedra_suficiente = jug_turno -> devolver_inventario() -> hay_piedra_suficiente(piedra);
    bool madera_suficiente = jug_turno -> devolver_inventario() -> hay_madera_suficiente(madera);
    bool metal_suficiente = jug_turno -> devolver_inventario() -> hay_metal_suficiente(metal);

    return piedra_suficiente && madera_suficiente && metal_suficiente;
}