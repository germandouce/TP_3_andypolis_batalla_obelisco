#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "vector.h"
#include "material.h"

using namespace std;

class Jugador {

    private:    

    int  numero_jugador;

    // Vector<Material>* inventario;
    // Vector<Objetivo>* objetivos;
    // Vector<Edificio>* edificios;
    int objetivos_secundarios_cumplidos;
    int energia;
    int andycoins_acumulados;
    //int bombas_usadas;
    int bombas_compradas;
    
    public:

    //Jugador(Vector<Material>* inventario);
    
    //Constructor de jugador
    Jugador();

    //Setear numero jugador
    //PRE:Recibe un entero con el numero de jugador
    //POST: Modifica el atributo numero de jugador colocandole
    //el numero que se pase por parametro
    void setear_numero_jugador(int numero_jugador);

    //Asignar objetivos
    //PRE:
    //POST: Asigna objetivos al jugador
    void asignar_objetivos(int numero_random);
    
    
    //Verificar objetivos
    //PRE:
    //POST: verifica si cumplio sus objetivos 
    //void verificar_objetivos();
};

#endif // JUGADOR_H