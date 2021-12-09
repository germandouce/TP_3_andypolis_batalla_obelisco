#include "jugador.h"
#include "..\inventario\inventario.h"

Jugador::Jugador(){

    this -> numero_jugador = 0;

    // this -> Vector<Material>* inventario;
    // this -> Vector<Objetivo>* objetivos;
    //this -> Vector<Edificio>* edificios;
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

void Jugador::pedir_coordenadas(){
    
    cout<<"¡Hola jugador "<< devolver_numero_jugador()<<"!" <<endl
    <<"Por favor, ingrese las coordenadas en las que desea ubicarse:"<<endl;
    cout<<"Ingrese la fila:"<<endl;
    cin >>fila;
    cout<<"Ingrese la columna:"<<endl;
    cin >>columna;
}

void Jugador::asignar_coordenadas(int fila, int columna){
    this -> fila = fila;
    this -> columna = columna;
}

void Jugador::setear_numero_jugador(int numero_jugador){
    this -> numero_jugador = numero_jugador;
}

int Jugador::devolver_numero_jugador(){
    return numero_jugador;
}


void Jugador::asignar_objetivo(int objetivo, int numero_objetivo){
    objetivos[numero_objetivo]  = objetivo;
}

void Jugador::agregar_material_a_inventario(){

}

void Jugador::agregar_edificio_al_registro(Edificio* edificio){
    
}


// Jugador::Jugador(Vector<Material>* inventario){
    
// }

int Jugador::obtener_energia(){
    return energia;
}

void Jugador::verificar_objetivos(int objetivo, int escuelas_construidas, int cantidad_minas, int distintos_edificios) {

    for (int i = 0; i < 3; i++) {
        switch (objetivo) {
            case COMPRAR_ANDYPOLIS:
                if (andycoins_acumulados = 100000){
                    objetivos_secundarios_cumplidos++;
                }
                break;

            case EDAD_PIEDRA:
                //if (vector_inventario->obteer_cantidad("piedra") == 50000){
                    objetivos_secundarios_cumplidos++;
                //}
                break;

            case BOMBARDERO:
                if (bombas_usadas = 5){
                    objetivos_secundarios_cumplidos++;
                }
                break;
                
            case ENERGETICO:
                if (energia == 100){
                    objetivos_secundarios_cumplidos++;
                }
                break;

            case LETRADO:
                // if (registro_edificios->obetner_cantidad_escuelas() = mapa->dict("escuela")->obtener_maxima_cantidad()){
                //     objetivos_secundarios_cumplidos++;
                // }
                break;

            case MINERO:
                // if (registro_edificios->obetner_cantidad_mina() && registro_edificios->obetner_cantidad_mina_oro){
                //     objetivos_secundarios_cumplidos++;
                // }
                break;

            case CANSADO:
                if (energia = 0){
                    objetivos_secundarios_cumplidos++;
                }
                break;

            case CONSTRUCTOR:
                // if (andycoins_acumulados = 100000){
                //     objetivos_secundarios_cumplidos++;
                // } 
                // break;

            case ARMARDO:
                // if (inventario->obtener_cantidad_bombas == 10){
                //     objetivos_secundarios_cumplidos++;
                // } 
                // break;

            case EXTREMISTA:
                if (bombas_compradas= 5000){
                    objetivos_secundarios_cumplidos++;
                }
                break;  
            }
    }
}


bool Jugador::gano(){
    bool gano = false;

    if ( objetivos_secundarios_cumplidos == 2 || obelisco_construido){
        gano = true;
    };
    return gano;
}

bool Jugador::sin_energia(){
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