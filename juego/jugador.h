#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "vector.h"
#include "material.h"
#include ".\edificio.h"

const int COMPRAR_ANDYPOLIS = 1;
const int EDAD_PIEDRA = 2;
const int BOMBARDERO = 3;
const int ENERGETICO = 4;
const int LETRADO = 5;
const int MINERO = 6;
const int CANSADO = 7;
const int CONSTRUCTOR = 8;
const int ARMARDO = 9;
const int EXTREMISTA = 10;

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
    int bombas_usadas;
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
    void Jugador::verificar_objetivos(int objetivo, int escuelas_construidas, int cantidad_minas, int distintos_edificios);

};

#endif // JUGADOR_H