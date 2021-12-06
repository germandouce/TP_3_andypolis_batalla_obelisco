#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "vector.h"
#include "material.h"

using namespace std;

class Jugador {

    private:

    Vector<Material>* inventario;
    Vector<Objetivo>* objetivos;
    Vector<Edificio>* edificios;
    int objetivos_secundarios_cumplidos;
    int energia;
    int andycoins_acumulados;
    int bombas_usadas;
    int bombas_compradas;
    

    // Matriz<int>* matriz_costos;

    public:

    Jugador(Vector<Material>* inventario);


    void verificar_objetivos();
}

#endif // JUGADOR_H