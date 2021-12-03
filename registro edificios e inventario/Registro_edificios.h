#ifndef REGISTRO_EDIFICIOS_H
#define REGISTRO_EDIFICIOS_H
#include "Nodo_listas.h"

class Registro_edificios{

//ATRIBUTOS
private:
    int cantidad_edificios;
    Nodo_Reg_ed* primero;
    Nodo_Reg_ed* ultimo;

//METODOS
public:
    Registro_edificios();

    //pre:
    //post: devuelve la cantidad de edifios que tiene el rergistro
    int obtener_cantidad_edificios();

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

    //pre:
    //post: busca y devuelve el edificio en el registro consultado segun sus coordenadas.
    Edificio* buscar_edificio_en_registro(int coordenada_x , int coordenada_y);

    //pre:
    //post: devueve un nodo aux segun posicion.
    Nodo_Reg_ed* obtener_nodo(int pos);

    //DESTRUCTOR
    ~Registro_edificios();
};

#endif //REGISTRO_EDIFICIOS_H