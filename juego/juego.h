#ifndef JUEGO_H
#define JUEGO_H

#include <ctime>
#include "..\mapa.h"
#include "jugador.h"

const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";
const string ARCHIVO_EDIFICIOS = "edificios.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";

const char PARENTESIS_CHAR = '(';
const int OPCION_PARENTESIS = 0;
const int OPCION_NUMEROS = 1;

class Juego {

    private:

    Jugador* jugador1;
    Jugador* jugador2;
    Mapa* mapa;
    Diccionario* diccionario;
    Vector<Objetivo>* objetivos;

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

    //
    //
    //
    void cargar_inventario(ifstream& inventario);
    
    void cargar_objetivos();
    
    void agregar_edificio_al_registro(Edificio* edificio);

    ////Devolver jugador 2
    //PRE:-
    //POSR: Devuelve un puntero al jugador 1
    Jugador* devolver_jugador_1();

    //Devolver jugador 2
    //PRE:-
    //POST:Devuelve un puntero al jugador 2
    Jugador* devolver_jugador_2();


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
    // void instanciar_edificio(string nombre_edificio, Edificio* edificio);

    //Guardar material
    //PRE: Recibe el nombre del material y un puntero a material
    //POST: instancia el material y lo guarda en el puntero recibido
    void instanciar_material(string nombre_material, Material* material);

    //Cargar ubicaciones
    //PRE: El acrhivo ubicaciones debe estar abierto. Recibe un puntero a jugador 1 y a jugador 2 y 
    //un objeto ifstream
    //POST: lee el archivo ubicaciones y carga sus datos en las listas de los edificios de cada jugador
    //y en el mapa colocando los materiales y edificios
    void cargar_ubicaciones(ifstream& ubicaciones);

    //Generar numero random
    //PRE: Recibe los enteros "min" y "max" con los valores limite (inclusives) entre los cuales se desea generar el numero random 
    //POST: Devuelve un valor random entre "min" y "max"
    int generar_numero_random(int min, int max);

    //Asignar objetivos
    //PRE:
    //POST: Asigna objetivos al jugador
    void asignar_objetivos(Jugador* jugador);

    //Limpiar string
    //PRE: Receibe una string con la cadena a limpiar, un entero con la posicion incicial,
    // y un string con el tope
    //POST: Devuelve un entero con el valor del numero leido.
    string limpiar_string(string cadena, int posicion_inicial, char str_tope);
    
    //Cargar diccionario
    //PRE: Recibe un objeto ifstream
    //POST: Carga el diccionario
    void cargar_diccionario(ifstream &archivo);

    //Cargar edificio
    //PRE: Recibe el nombre del edificio las cantidades de piedra madera y metal y limite max de construccion
    //POST: Carga el edificio en el diccionario
    void cargar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite_construccion);

    //Leer palabra compuesta
    //PRE:Recibe un objeto ifstream, el nombre del edificio y un entero con la opcion de si se queire
    //evitar un numero o un parentesis
    //POST: Lee las elmentos de mas de una palabra delimitados por un numero o un paretesis
    string leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion);

    //Verificar tipo caracter
    //PRE:Recibe una palabra y un entero que puede ser un ???? o un ??
    //POST: Devuelve true si es un parentesis o false si es un numero
    bool verificar_tipo_caracter(string palabra, int tipo_caracter);

    //Es numero
    //PRE: Recibe un string con la palabra
    //POST: Devuelve true si es un numero o false en caso contrario
    bool es_numero(string palabra);

    Edificio* encontrar_edificio();

    //
    //
    //
    void mostrar_todos_edificios();

    
    //Verificar construccion
    //PRE:-
    //POST:-
    void verificar_construccion();

    //Confirmar construccion
    //PRE:
    //POST:
    void confirmar_construccion(int fila, int columna, Edificio* edificio_a_construir);

    //Mostrar costo edificio
    //PRE:-
    //POST:
    void mostrar_costo_edificio(Edificio* edificio_a_construir);
    
    //Devolver mapa
    //PRE:
    //POST:
    void pedir_coordenadas(int &fila, int &columna);

    //Devolver mapa
    //PRE:
    //POST:
    void pedir_fila(int &fila);

    
    //Devolver mapa
    //PRE:
    //POST:
    void pedir_columna(int &columna);

    //PRE:
    //POST: devuelve diccionario.
    Diccionario* devolver_diccionario();

    //Devolver mapa
    //PRE:
    //POST:
    Mapa* devolver_mapa();
};

#endif //JUEGO_H



