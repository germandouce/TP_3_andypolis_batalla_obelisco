#ifndef REGISTRO_EDIFICIOS_H
#define REGISTRO_EDIFICIOS_H

#include "Nodo_registro.h"
#include "edificio.h"
#include "planta_electrica.h"
#include "obelisco.h"
#include "mina.h"
#include "mina_de_oro.h"
#include "fabrica.h"
#include "escuela.h"
#include "aserradero.h"

const int NO_EXISTE = 999999;

class Registro_edificios{

//ATRIBUTOS
private:
    int cantidad_edificios;
    Nodo_R* primero;
    Nodo_R* ultimo;
    int cantidad_minas;
    int cantidad_aserraderos;
    int cantidad_fabricas;
    int cantidad_escuelas;
    int cantidad_obeliscos;
    int cantidad_plantas_electricas;
    int cantidad_minas_oro;

//METODOS
public:
    Registro_edificios();

    //pre:
    //post: devuelve la cantidad de edifios que tiene el rergistro
    int obtener_cantidad_edificios();

    //pre:
    //post: devuelve la cantidad de minas que tiene el rergistro
    int obtener_cantidad_minas();

    //pre:
    //post: devuelve la cantidad de aserraderos que tiene el rergistro
    int obtener_cantidad_aserraderos();

    //pre:
    //post: devuelve la cantidad de fabricas que tiene el rergistro
    int obtener_cantidad_fabricas();

    //pre:
    //post: devuelve la cantidad de escuelas que tiene el rergistro
    int obtener_cantidad_escuelas();

    //pre:
    //post: devuelve la cantidad de obeliscos que tiene el rergistro
    int obtener_cantidad_obeliscos();

    //pre:
    //post: devuelve la cantidad de plantas electricas que tiene el rergistro
    int obtener_cantidad_plantas_electricas();

    //pre:
    //post: devuelve la cantidad de minas de oro que tiene el rergistro
    int obtener_cantidad_minas_oro();

    //pre:
    //post: agrega un nuevo nodo con puntero edificio al registro.
    void agregar(Edificio*edificio);

    //pre: recibe int posicion a consultar.
    //post: devuelve true si la posicion consultada es <= a la cantidad de edificios en el registro (largo registro).
    bool posicion_valida_a_consutar(int pos);

    //pre:
    //post: verifica existencia de edificio consultado segun coordenadas.
    bool existe(int coordenada_x , int coordenada_y);

    //pre:
    //post: elimina edificio segun coordenadas.
    void eliminar(int coordenada_x , int coordenada_y);

    //pre:
    //post: presenta registro de edificios en pantalla.
    void mostrar_registro_edificios();

    //pre:
    //post: actualiza cantidad de edificios de un cierto tipo segun el nombre.
    void actualizar_cantidad_tipo_edificio(string nombre_edificio);

    //pre: verifica existencia.
    //post: devuelve posicion del edificion en el registro segun sus coordenadas.
    int buscar_posicion(int coordenada_x , int coordenada_y);

    //pre:  verifica existencia y busca posicion.
    //post: busca y devuelve el edificio en el registro consultado segun sus coordenadas.
    Edificio* buscar_edificio_en_registro(int coordenada_x , int coordenada_y);

    //pre: verifica que 0 < = posicion pedida/consultada < cantiadad de edificios en registro.
    //post: devueve puntero a nodo pedido segun posicion en el registro si confirma validez de posicion pedida/consultada.
    // En caso de que esta no sea valida infoorma y devulve un nullptr.
    Nodo_R* obtener_nodo(int pos);

    int obtener_edificios_construidos(string nombre_edificio);

    //DESTRUCTOR
    ~Registro_edificios();
};

#endif //REGISTRO_EDIFICIOS_H