#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "vector.h"
#include "material.h"
#include ".\edificio.h"


using namespace std;

class Jugador {

    private:    

    int  numero_jugador;

    // Vector<Material>* inventario;
    //Vector<Objetivo>* objetivos;
    int objetivos[3];
    // Vector<Edificio>* edificios;
    int objetivos_secundarios_cumplidos;
    int energia;
    int andycoins_acumulados;
    //int bombas_usadas;
    int bombas_compradas;
    
    int fila;
    int columna;

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
    //POST: Asigna 1 objetivo al jugador agregandolo a la lista de objetivos
    void asignar_objetivo(int objetivo, int numero_objetivo);

    //Cargar el inventario
    //PRE:
    //POST:-
    void agregar_material_a_inventario();

    //Cargar resgistro edificios
    //PRE:-
    //POST: Lee el archivo de edificios y va cargandolos en el registro
    void agregar_edificio_al_registro_(Edificio* edificio);

    //Asignar coordenadas
    //PRE:Recibe dos enteros con las coordenadas x e y respectivamente.
    //POST: Asigna al jugador en los atributos las coordenadas correspondientes.
    void asignar_coordenadas(int fila, int columna);

    //Verificar objetivos
    //PRE:
    //POST: verifica si cumplio sus objetivos 
    //void verificar_objetivos();
};

#endif // JUGADOR_H