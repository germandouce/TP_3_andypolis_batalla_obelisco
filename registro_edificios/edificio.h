#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include <string>

#include "../colores.h"
#include "../system_clear.h"

using namespace std;

const int MAX_MATERIAL = 50000;
const int MIN_MATERIAL = 0;

const string G = "mina de oro";
const string M = "mina";
const string A = "aserradero";
const string F = "fabrica";
const string E = "escuela";
const string O = "obelisco";
const string P = "planta electrica";

const string ASERRADERO = "A";
const string ESCUELA = "E";
const string FABRICA = "F";
const string MINA_DE_ORO = "G";
const string MINA = "M";
const string OBELISCO = "O";
const string PLANTA_ELECTRICA = "P";

class Edificio {
    protected:

    string nombre;
    string diminutivo;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int brinda;
    int maximo_construir;
    int vida_actual;
    int vida_maxima;
    int fila;
    int columna;

    public:

    // Constructor
    // PRE: -
    // POS: Inicializa el edificio con todos los valores en 0 
    Edificio();

    // PRE: -
    // POS: Como es una clase abstracta cada edificio va a implementar su nombre, aca se
    //      establecen las cantidades requeridas a partir del archivo edificios.txt.
    Edificio(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir,  int fila, int columna);

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve el nombre del edificio ( getter )
    string obtener_nombre();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve el diminutivo del edificio, siendo este la primer letra de la palabra ( getter ).
    string obtener_diminutivo();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de piedra necesaria para construir.
    int obtener_cantidad_piedra();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de madera necesaria para construir.
    int obtener_cantidad_madera();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la cantidad de metal necesaria para construir.
    int obtener_cantidad_metal();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la maxima cantidad de edificios que se pueden construir , informacion que viene dada
    //      en edificio.txt.
    int obtener_maximo_construir();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la vida actual del edificio.
    int obtener_vida_actual();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_piedra();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_madera();

    // PRE: En caso de haberse creado un edificio, se tomaran los valores predeterminados en el edificio selecto.
    // POS: Devuelve la mitad del material, metodo utilizado en caso de eliminar el edificio.
    int obtener_mitad_metal();

    // PRE: -
    // POS: Por cada uno de los edificios muestra por pantalla su respectivo mensaje.
    virtual void mostrar_mensaje() = 0;

    // PRE: Dependiendo al edificio que me diriga.
    // POS: Devuelve una cierta cantidad de material que brinda el edificio en particular.
    int obtener_cantidad_brindada();

    // PRE: Dependiendo al edificio que me diriga.
    // POS: Devuelve el nombre del elemento que brinda el edificio en particular.
    virtual string obtener_material_brindado() = 0;

    //PRE:-
    //POST:Resta 1 a la vida del edificio
    void daniar();

    // PRE: -
    // POS: Devuelve True si el edificio sobrevivio a la explosion en pie y false en caso contrario
    bool edificio_en_pie();

    //PRE:
    //POST: Suma 1 a la cantidad de vida siempre u cuando lo permita dicho edificio.
    void reparar();

    void mostrar_toda_informacion();
    
    void asignar_fila(int fila);

    void asignar_columna(int columna);

    //Devolver posicion X
    //PRE:-
    //POST: Devuelve un entero con la posicion x del edificio
    int obtener_fila();

    //Devolver posicion y
    //PRE:-
    //POST: Devuelve un entero con la posicion y del edificio
    int obtener_columna();

    //PRE: pasamos edificio que queremos modificar las cantidades de los materiales requeridos
    //POST: modifica las cantidades de los materiales requeridos del edificio que se pide.
    void modificar_cantidades_edificio();

    //PRE:-
    //POST: Modifica la cantidad de piedra.
    void modificar_cantidad_piedra();

    
    //PRE:-
    //POST: Modifica la cantidad de madera.
    void modificar_cantidad_madera();

    
    //PRE:-
    //POST: Modifica la cantidad de metal.
    void modificar_cantidad_metal();
    
    //PRE:-
    //POST: Verifica que las cantidades sean validas.
    bool verificacion_cantidades(int cantidad_verificar);

    // Destructor
    // PRE: -
    // POS: Destructor de edificio.
    virtual ~Edificio();
};

#endif // EDIFICIO_H