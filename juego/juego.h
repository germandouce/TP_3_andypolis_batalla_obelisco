#ifndef JUEGO_H
#define JUEGO_H

#include <ctime>
#include "..\mapa.h"
#include "jugador.h"

const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";
const string ARCHIVO_EDIFICIOS = "edificios.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";


class Juego{

private:
    Mapa * mapa;
    //Diccionario * diccionario_edificios;
    string objetivos[10];

public:
    
    //Constructor de juego
    Juego();

    //Inicia una nueva partida
    //PRE:-
    //POST:-
    void crear_juego(Jugador * jug_1, Jugador * jug_2);

    //Cargar mapa
    //PRE:-
    //POST: Lee el archivo mapa.txt y lo guarda.
    bool cargar_mapa();

    //
    //
    //
    void cargar_inventario(ifstream& inventario,Inventario*inventario_jugador_1,Inventario* inventario_jugador_2);
    
    void cargar_vector_de_objetivos();
    
    //es archivo legible
    //PRE: 
    //POST: Devuelve true si el archivo existe y no esta vacio. Si no existe, no lo llega a abrir. Si existe
    //y esta vacio, lo cierra.
    bool es_archivo_legible(ifstream& archivo, string nombre_archivo);
    
    //Archivo vacio
    //PRE: Recibe el archivo
    //POST: Devuelve true si el archivo esta vaio false en caso contrario
    bool archivo_vacio(ifstream& archivo);
    
    //Existe archivo
    //PRE: Recibe un objeto de tipo ifstream y el nombre del archivo
    //POST: intenta abrir el archivo y Devuelve true si el archivo existe y flase en caso contrario
    bool existe_archivo(ifstream& archivo,string nombre_archivo);

    //Guardar edificio
    //PRE: Recibe el nombre del edificio y un punetro a edificio
    //POST: Instancia el edificio y lo guarda en el puntero recibido
    void instanciar_edificio(string nombre_edificio, Edificio* edificio);

    //Guardar material
    //PRE: Recibe el nombre del material y un puntero a material
    //POST: instancia el material y lo guarda en el puntero recibido
    void instanciar_material(string nombre_material, Material * material);

    //Cargar ubicaciones
    //PRE: El acrhivo ubicaciones debe estar abierto. Recibe un puntero a jugador 1 y a jugador 2 y 
    //un objeto ifstream
    //POST: lee el archivo ubicaciones y carga sus datos en las listas de los edificios de cada jugador
    //y en el mapa colocando los materiales y edificios
    void cargar_ubicaciones(ifstream& ubicaciones, Jugador * jug_1, Jugador * jug_2);

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limite (inclusives) entre los cuales se desea generar el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    //Asignar objetivos
    //PRE:
    //POST: Asigna objetivos al jugador
    void asignar_objetivos(Jugador * jugador);

    //Limpiar string
    //PRE: Receibe una string con la cadena a limpiar, un entero con la posicion incicial,
    // y un string con el tope
    //POST: Devuelve un entero con el valor del numero leido.
    int limpiar_string(string cadena, int posicion_inicial, char str_tope);

};

#endif //JUEGO_H



