#include "jugador.h"

Jugador::Jugador() {

    this -> numero_jugador = 0;
    this -> registro_edificios = new Registro_edificios();
    this -> inventario = new Inventario();
    this -> objetivos = new Vector<Objetivo>;
    this -> objetivos_secundarios_cumplidos = 0;
    this -> objetivos_cumplidos = new Vector<bool>;
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
    objetivos_cumplidos -> insertar_ultimo(false);
}

bool Jugador::objetivo_cumplido(int numero_objetivo){
    return objetivos_cumplidos->obtener_dato(numero_objetivo);
}

void Jugador::agregar_material_a_inventario(){

}

void Jugador::agregar_edificio_al_registro(Edificio* edificio){
    
    devolver_resgitro_edificios()->agregar(edificio);
}

void Jugador::mostrar_nombre_objetivo(int numero_objetivo){
    objetivos->obtener_dato(numero_objetivo)->mostrar_nombre_objetivo();
}

void Jugador::mostrar_descripcion_objetivo(int numero_objetivo){
    objetivos->obtener_dato(numero_objetivo)->mostrar_descripcion();
}

void Jugador::mostrar_progreso_objetivo(int numero_objetivo, int energia, Diccionario* diccionario) {
    objetivos->obtener_dato(numero_objetivo)->mostrar_progreso(inventario, registro_edificios, diccionario, energia);
}

int Jugador::obtener_energia(){
    return energia;
}

void Jugador::cumplir_un_objetivo_secundario(){
    objetivos_secundarios_cumplidos++;
}

void Jugador::cumplir_objetivo(int numero_objetivo){
    bool* cumplido = new bool;
    *cumplido = true;
    objetivos_cumplidos->insertar_posicion(numero_objetivo, cumplido);    
}

bool Jugador::gano(){
    bool gano = false;

    if ( objetivos_secundarios_cumplidos == 2 || obelisco_construido){
        gano = true;
    };
    return gano;
}

bool Jugador::tiene_energia() {
    return energia;
}

void Jugador::iniciar_turno(){
    su_turno = true;
}

void Jugador::terminar_turno(){
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

void Jugador:: sumar_energia(int energia_ganada) {
    if (energia + energia_ganada > ENERGIA_MAXIMA) {
        energia += ENERGIA_MAXIMA;
    }
    else {
        energia += energia_ganada;
    }
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