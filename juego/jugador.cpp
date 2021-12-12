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

    cout<<"Sus objetivo primario es el siguiente: "<<endl;
    cout<<"Construir un obelisco: ";
    if (devolver_resgitro_edificios()->obtener_cantidad_obeliscos() != 1){
        cout<<"No completado"<<endl;
    }
    else{
        cout<<"completado, ganaste el juego!";
    }
    cout<<"\nSus objetivos secundarios son los siguientes: \n"<<endl;
    for (int i = 0; i < 3; i++) {
        objetivos->obtener_dato(i)->mostrar_descripcion();
    }
}

// void Jugador::cumplir_un_objetivo_secundario(){
//     objetivos_secundarios_cumplidos ++;
// }

// void Jugador::verificar_objetivos(Jugador *jug_turno) {

//     for (int i; i<2; i++){
//         if (objetivos->obtener_dato(i)->comprobar_requisito(inventario, registro_edificios, diccionario, energia) ){
//             jug_turno -> cumplir_un_objetivo_secundario();
//         };
//     }
// }


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