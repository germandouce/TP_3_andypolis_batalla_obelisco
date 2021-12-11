#include "jugador.h"

Jugador::Jugador() {

    this -> numero_jugador = 0;
    this -> registro_edificios = new Registro_edificios();
    this -> inventario = new Inventario();
    this -> objetivos = new Vector<Objetivo>;
    this -> objetivos_secundarios_cumplidos = 0;
    this -> energia = 50;
    this -> andycoins_acumulados = 0;
    this -> bombas_usadas;
    this -> bombas_compradas = 0;
    this -> fila = 0;
    this -> columna = 0;
    this -> obelisco_construido = false;

    this -> en_juego = true;
    this -> su_turno = true;
}

void Jugador::ubicar_jugador() {
    
    cout<<"Hola jugador "<< devolver_numero_jugador()<<"!" <<endl
    <<"\nPor favor, ingrese las coordenadas en las que desea ubicarse:"<<endl;
    cout<<"Ingrese la fila: ";
    cin >>fila;
    cout<<"Ingrese la columna: ";
    cin >>columna;
    cout<<endl;

    asignar_coordenadas(fila, columna);
}

void Jugador::asignar_coordenadas(int fila, int columna){
    this -> fila = fila;
    this -> columna = columna;
}

int Jugador::devolver_fila(){
    return fila;
}

int Jugador::devolver_columna(){
    return columna;
}

void Jugador::setear_numero_jugador(int numero_jugador){
    this -> numero_jugador = numero_jugador;
}

int Jugador::devolver_numero_jugador(){
    return numero_jugador;
}

void Jugador::asignar_objetivo(Objetivo *objetivo_a_asignar) {
    objetivos -> insertar_ultimo(objetivo_a_asignar);
}

void Jugador::agregar_material_a_inventario(){

}

void Jugador::agregar_edificio_al_registro(Edificio* edificio){
    
    devolver_resgitro_edificios()->agregar(edificio);
}


// Jugador::Jugador(Vector<Material>* inventario){
    
// }

int Jugador::obtener_energia(){
    return energia;
}

void Jugador::mostrar_objetivos(){
    for (int i = 0; i < 3; i++) {
        objetivos->obtener_dato(i)->mostrar_descripcion();
    }
}

void Jugador::verificar_objetivos() {
        // switch (objetivo) {
        //     case COMPRAR_ANDYPOLIS:
        //         if (andycoins_acumulados = 100000){
        //             objetivos_secundarios_cumplidos++;
        //         }
            //     break;

            // case EDAD_PIEDRA:
            //     //if (vector_inventario->obteer_cantidad("piedra") == 50000){
            //         objetivos_secundarios_cumplidos++;
            //     //}
            //     break;

            // case BOMBARDERO:
            //     if (bombas_usadas = 5){
            //         objetivos_secundarios_cumplidos++;
            //     }
            //     break;
                
            // // case ENERGETICO:
            // //     if (energia == 100){
            // //         objetivos_secundarios_cumplidos++;
            // //     }
            // //     break;

            // // case LETRADO:
            // //     // if (registro_edificios->obetner_cantidad_escuelas() = mapa->dict("escuela")->obtener_maxima_cantidad()){
            // //     //     objetivos_secundarios_cumplidos++;
            // //     // }
            // //     break;

            // // case MINERO:
            // //     // if (registro_edificios->obetner_cantidad_mina() && registro_edificios->obetner_cantidad_mina_oro){
            // //     //     objetivos_secundarios_cumplidos++;
            // //     // }
            // //     break;

            // // case CANSADO:
            // //     if (energia = 0){
            // //         objetivos_secundarios_cumplidos++;
            // //     }
            // //     break;

            // // case CONSTRUCTOR:
            // //     // if (andycoins_acumulados = 100000){
            // //     //     objetivos_secundarios_cumplidos++;
            // //     // } 
            // //     // break;

            // // case ARMARDO:
            // //     // if (inventario->obtener_cantidad_bombas == 10){
            // //     //     objetivos_secundarios_cumplidos++;
            // //     // } 
            // //     // break;

            // // case EXTREMISTA:
            // //     if (bombas_compradas= 5000){
            // //         objetivos_secundarios_cumplidos++;
            // //     }
            // //     break;  
    //         }
    // }
}


bool Jugador::gano(){
    bool gano = false;

    if ( objetivos_secundarios_cumplidos == 2 || obelisco_construido){
        gano = true;
    };
    return gano;
}

bool Jugador::esta_sin_energia(){
    return (energia == 0);
}

void Jugador::iniciar_turno(){
    su_turno = true;
}

void Jugador::terminar_truno(){
    su_turno = false;
}

bool Jugador::es_su_turno(){
    return su_turno;
}

void Jugador::salir_del_juego(){
    en_juego = false;
}

bool Jugador::quiere_salir_del_juego(){
    return !en_juego;
}

void Jugador:: sumar_energia(int energia){
    this->energia += energia;
}

void Jugador::esta_obelisco_construido(){
    if (devolver_resgitro_edificios()->obtener_cantidad_obeliscos() == 1){
       obelisco_construido = true;
    }  
}

Registro_edificios* Jugador::devolver_resgitro_edificios(){
    return registro_edificios;
}

Inventario* Jugador::devolver_inventario(){
    return inventario;
}

void Jugador::opcion_demoler_edificio_x_coordenada() {
    cout<< "Energia actual : " << obtener_energia() << endl;
    cout <<" Ingrese coordenadas del edificios a demoler"<<endl;
    int fila;
    cout<< "Ingrese numero de fila: ";
    cin >> fila;
    int columna;
    cout << "Ingrese numero de columna: ";
    cin >> columna;
    devolver_resgitro_edificios()->eliminar(fila, columna);
}

bool Jugador::encuentra_edificio(Diccionario* diccionario, string nombre_edificio_buscar) {
    return (diccionario -> buscar_edificio(nombre_edificio_buscar) != nullptr);
}

bool Jugador::puede_construir_edificio(int piedra, int madera, int metal) {

    bool piedra_suficiente = inventario -> hay_piedra_suficiente(piedra);
    bool madera_suficiente = inventario -> hay_madera_suficiente(madera);
    bool metal_suficiente = inventario -> hay_metal_suficiente(metal);

    return piedra_suficiente && madera_suficiente && metal_suficiente;
}

bool Jugador::acepta_realizar_accion() {
    string eleccion;
    cout << "Desea realizar esta accion? Ingrese 'Si' o 'si para confirmar." << endl;
    cin >> eleccion;
    return (eleccion == "Si" || eleccion == "si");
}

void Jugador::opcion_construir_edificio_x_nombre(Diccionario* diccionario, Casillero*** mapa) {
    
    string nombre_edificio_construir;
    cout << "Ingrese nombre edificio que desea construir: ";
    cin >> nombre_edificio_construir;

    Edificio* edificio_consultado = diccionario -> buscar_edificio(nombre_edificio_construir);
    Edificio* edificio_a_construir;

    if (edificio_consultado != nullptr) {
        
        int piedra = edificio_consultado -> obtener_cantidad_piedra();
        int madera = edificio_consultado -> obtener_cantidad_madera();
        int metal = edificio_consultado -> obtener_cantidad_metal();

        int construidos = registro_edificios -> obtener_edificios_construidos(nombre_edificio_construir);
        int limite = edificio_a_construir -> obtener_maximo_construir();

        if (puede_construir_edificio(piedra, madera, metal) && construidos < limite) {

            if (acepta_realizar_accion()) {

                int fila;
                int columna;
                
                pedir_coordenadas(fila, columna);

                bool esta_ocupado = mapa[fila][columna] -> esta_ocupado();
                string tipo_casillero = mapa[fila][columna] -> obtener_tipo_casillero();

                if (!esta_ocupado && tipo_casillero == TERRENO) {
                    edificio_a_construir = diccionario -> instanciar_edificio(nombre_edificio_construir, fila, columna);
                    mapa[fila][columna] -> construir_edificio(edificio_a_construir);
                    mapa[fila][columna] -> ocupar_casillero();
                    registro_edificios -> agregar(edificio_a_construir);
                    cambia_cantidades_inventario(madera, piedra, metal);
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

void Jugador::pedir_coordenadas(int &fila, int &columna) {
	
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

void Jugador::pedir_fila(int &fila) {
    cout << ENTER_COLOR << "Ingrese la fila del casillero deseado: " << END_COLOR << endl;
    cin >> fila;
    cin.clear();
    cin.ignore(100, '\n');
}

void Jugador::pedir_columna(int &columna) {
    cout << ENTER_COLOR << "Ingrese la columna del casillero deseado: " << END_COLOR << endl;
    cin >> columna;
    cin.clear();
    cin.ignore(100, '\n');
}

void Jugador::cambia_cantidades_inventario(int madera, int piedra, int metal){
    inventario->cambiar_cantidad_elemento("madera", madera);
    inventario->cambiar_cantidad_elemento("piedra", piedra);
    inventario->cambiar_cantidad_elemento("metal", metal);
}