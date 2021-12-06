#include "jugador.h"



Jugador::Jugador(){

    this -> numero_jugador = 0;

    // this -> Vector<Material>* inventario;
    // this -> Vector<Objetivo>* objetivos;
    // this -> Vector<Edificio>* edificios;
    this -> objetivos_secundarios_cumplidos = 0;
    this -> energia = 50;
    this -> andycoins_acumulados = 0;
    this -> bombas_usadas;
    this -> bombas_compradas = 0;
    int coordenada_x = 0;
    int coordenada_y = 0;

}

void Jugador::setear_numero_jugador(int numero_jugador){
    this -> numero_jugador = numero_jugador;
}

void Jugador::asignar_objetivo(int objetivo, int numero_objetivo){
    objetivos[numero_objetivo]  = objetivo;
}

void Jugador::agregar_material_a_inventario(){

}

void Jugador::agregar_edificio_al_registro_(Edificio* edificio){

}

void Jugador::asignar_coordenadas(int fila, int columna){
    this -> fila = columna;
    this -> fila = columna;
}

// Jugador::Jugador(Vector<Material>* inventario){
    
// }



void Jugador::verificar_objetivos(int objetivo, int escuelas_construidas, int cantidad_minas, int distintos_edificios) {

    for (int i = 0; i < 3; i++) {
        //const int objetivo; COMO ES ESTO NICO??? AYUDAAAAAA 
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
