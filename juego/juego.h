#ifndef JUEGO_H
#define JUEGO_H


#include <ctime>
#include ".\mapa.h"
#include "Jugador.h"
#include ".\diccionario.h"

class Juego{

private:
    Mapa * mapa;
    Diccionario * diccionario_edificios;
    //List lista_objetivos

public:
    
    //Constructor de juego
    Juego();

    //Inicia una nueva partida
    //PRE:-
    //POST:-
    void crear_juego();

    //Cargar mapa
    //PRE:-
    //POST: Lee el archivo mapa.txt y lo guarda.
    bool cargar_mapa();

    //Cargar datos jugadores
    void cargar_ubicaciones(Jugador * jug_1, Jugador * jug_2);

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limite (inclusives) entre los cuales se desea generar el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    //Asignar objetivos
    //PRE:
    //POST: Asigna objetivos al jugador
    void asignar_objetivos(Jugador * jugador);

};

#endif //JUEGO_H



