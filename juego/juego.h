#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <ctime>
#include <string>

#include "../mapa.h"

using namespace std;

const string ARCHIVO_MAPA = "mapa.txt";
const string ARCHIVO_UBICACIONES = "ubicaciones.txt";
const string ARCHIVO_EDIFICIOS = "edificios.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";

const char PARENTESIS_CHAR = '(';
const int OPCION_PARENTESIS = 0;
const int OPCION_NUMEROS = 1;

const int PRIMER_JUGADOR = 1;
const int SEGUNDO_JUGADOR = 2;
const int DIFERENCIA_JUGADORES = 3;

const int TURNOS_PARA_LLOVER = 2;
const int CONTINUAR_PARTIDA = 2;

const int OPCION_MINIMA_NP = 0;
const int OPCION_MAXIMA_NP = 5;

const int MODIFICAR_EDIFICIO_X_NOMBRE = 1;
const int LISTAR_TODOS_LOS_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_SALIR = 5;

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 13;

const int CONSTRUIR_EDIFICIO_X_NOMBRE = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_EDIFICIO_X_COORDENDA = 3;
const int ATACAR_EDIFICIO_X_COORDENADA = 4;
const int REPARAR_EDIFICIO_X_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 10;
const int MOVERSE_A_UNA_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_Y_SALIR = 13;

class Juego {

    private:

    Jugador* jugador_turno;
    Jugador* jugador_secundario;
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

    //
    //PRE:-
    //POST:
    void cambiar_turno();

    //
    //PRE:-
    //POST:
    void jugar_turno();

    //
    //PRE:-
    //POST:
    void jugar_partida();

    //
    //PRE:-
    //POST:
    void leer_archivos(int &archivos_cargados, bool &nueva_partida);

    //
    //PRE:-
    //POST:
    void posicionar_jugadores();

    //Cargar mapa
    //PRE:-
    //POST: Lee el archivo mapa.txt y lo guarda.
    bool cargar_mapa();

    //
    //PRE:-
    //POST:
    void cargar_inventario(ifstream& inventario);
    
    //
    //PRE:-
    //POST:
    void cargar_objetivos();

    //
    //PRE:-
    //POST:
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
    Material* instanciar_material(string nombre_material);

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

    //
    //PRE:-
    //POST:
    Edificio* encontrar_edificio();

    //
    //PRE:-
    //POST:
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

    //
    //PRE:-
    //POST:
    bool son_coordenadas_validas(int &fila, int &columna);

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

    //Pedir coordenadas
    //PRE:-
    //POST: Pide las coordenadas en las q quiere ubicarse al jugador
    void ubicar_jugador();

    //Pedir posicion
    //PRE:
    //POST:
    void pedir_posicion();

    //Opcion construir edificio por nombre
    //PRE:
    //POST:
    void opcion_construir_edificio_x_nombre();

    //Puede construir edificio
    //PRE:
    //POST:
    bool puede_construir_edificio(Edificio* edificio);
    
    //Acepta ralizar accion
    //PRE:
    //POS:
    bool acepta_realizar_accion();

    //
    //PRE:
    //POS: 
    void obtengo_cantidades_edificio(Edificio* edificio, int &piedra, int &madera, int &metal, int &construidos);

    //Construye edificio
    //PRE: verificaciones hechas.
    //POS: construye edificio
    void construyo_edificio(Edificio* edificio_a_construir, int fila, int columna);

    //
    //PRE:
    //POS: 
    bool turno_terminado();
    
    //
    //PRE:
    //POS: 
    bool juego_terminado();

    //
    //PRE:
    //POS: 
    void mostrar_edificios_construidos();

    //
    //PRE:
    //POS: 
    void mostrar_inventario_en_pantalla();

    //
    //PRE:
    //POS: 
    void mostrar_objetivos_jugador();

    //
    //PRE:
    //POS: 
    void elegir_opcion_menu_np();

    //
    //PRE:
    //POS: 
    int devuelve_construidos_en_registro(string nombre_edificio);

    //
    //PRE:
    //POS: 
    void cumplir_un_objetivo_secundario();

    //Verificar objetivos
    //PRE:
    //POST: verifica si cumplio sus objetivos 
    void verificar_objetivos(Jugador * jug_turno);

    // MENUS

    //pre: -
    //post: Imprime menu en pantalla
    void presentar_menu_np();

    //pre: Se debe verificar que la opcion elegida sea valida
    //post: Procesa opcion elegida y la ejecuta
    void procesar_opcion_np(int opcion);

    //pre: -
    //post: Verifica que la opcion elegida sea valida para ejecutar
    bool opcion_valida_np(int opcion);

    //
    //PRE:
    //POS: 
    void presentar_menu();

    //
    //PRE:
    //POS: 
    void procesar_opcion(int opcion);

    //
    //PRE:
    //POS: 
    bool opcion_valida(int opcion);

    //
    //PRE:
    //POS: 
    string pedir_nombre_edificio_construir();

    //
    //PRE:-
    //POST:
    void construir_edificio(string nombre_edificio);

    //
    //PRE:-
    //POST:
    void ubicar_edificio(Edificio* edificio_a_construir, int fila, int columna);
    
    //
    //PRE:
    //POS: 
    void llover();
    
    //
    //PRE:
    //POS:
    void recolectar_recursos();

    //
    //PRE:
    //POS:
    bool es_nuestro_edificio(int fila, int columna);

    //
    //PRE:
    //POS:
    bool respeta_limite(int construidos, int limite);

    //
    //PRE:
    //POS:
    void verificar_objetivos();

    //
    //PRE:
    //POS: muestra en pantalla costo y energia.
    void costo_energia(int costo);
   
    //
    //PRE:
    //POS: devuelve true si tu_energia >= costo de accion.
    bool alcanza_energia(int costo);

    //
    //PRE: verificaciones hechas.
    //POS: elimina el edificio segun coordenadas.
    void demoler_edificio_x_coordenadas();

    void comprar_bombas(Inventario*inventario);

    bool andycoins_suficientes(int tus_andycoins, int precio_total_bombas);

    void muestra_info_precompra_bombas(int precio_total_bombas, int tus_andycoins);

    void se_compran_bombas(int precio_total_bombas, int costo, Inventario*inventario);

    int pide_bombas_deseadas();
};

#endif //JUEGO_H