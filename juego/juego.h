#ifndef JUEGO_H
#define JUEGO_H


#include <time>
#include ".\mapa.h"
#include "Jugador.h"
#include ".\diccionario.h"

class Juego{

private:
    Jugador * jug_1;
    Jugador * jug_2;
    Mapa * mapa;
    Diccionario * diccionario_edificios;
    //List lista_objetivos

public:
    
    //Constructor de juego
    Juego();

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limite (inclusives) entre los cuales se desea generar el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    //Asignar objetivos
    //PRE:
    //POST: Asigna objetivos al jugador
    void asignar_objetivos();

};

#endif //JUEGO_H



