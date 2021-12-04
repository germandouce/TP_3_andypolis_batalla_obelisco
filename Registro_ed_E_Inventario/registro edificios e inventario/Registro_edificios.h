#ifndef REGISTRO_EDIFICIOS_H
#define REGISTRO_EDIFICIOS_H
#include "Nodo_listas.h"

class Registro_edificios{

//ATRIBUTOS
private:
    int cantidad_edificios;
    Nodo_l* primero;
    Nodo_l* ultimo;
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
    void agregar();


    //pre:
    //post: verifica existencia de edificio consultado segun coordenadas.
    bool existe(int coordenada_x , int coordenada_y);

    //pre:
    //post: elimina edificio segun coordenadas.
    void eliminar(int coordenada_x , int coordenada_y);

    //pre:
    //post: presenta registro de edificios en pantalla.
    void mostrar_registro_edificios(Edificio edificio);


    //pre:
    //post: devuelve posicion del edificion en el registro segun sus coordenadas.
    int buscar_posicion(int coordenada_x , int coordenada_y);

    //pre: agregar nodo con puntero a edificio al registro.
    //post: toma nuevo nodo y segun nombre del edificio al que apunta, se incrementa la cantidad de su tipo en el registro.
    void contar(Nodo_l*nodo);

    //pre:
    //post: busca y devuelve el edificio en el registro consultado segun sus coordenadas.
    Edificio* buscar_edificio_en_registro(int coordenada_x , int coordenada_y);

    //pre:
    //post: devueve un nodo aux segun posicion.
    Nodo_l* obtener_nodo(int pos);

    //DESTRUCTOR
    ~Registro_edificios();
};

#endif //REGISTRO_EDIFICIOS_H