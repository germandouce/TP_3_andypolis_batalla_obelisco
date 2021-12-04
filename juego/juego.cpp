#include "juego.h"

Juego::Juego(){
    this-> jug_1 = new Jugador();
    this-> jug_2 = new Jugador();
    this -> mapa = 0;
    this -> diccionario_edificios = 0;
}


int Juego:: generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);
}

void Juego::asignar_objetivos(){
    srand( (unsigned)time(0) );
    
    int numero_objetivo;
    
    for(int i = 0; i < ojetivos->obtener_cant_objetivos(); i++){
        numero_objetivo = generar_numero_random();
    }

}
