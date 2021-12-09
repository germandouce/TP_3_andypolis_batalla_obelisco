#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>

class Inventario {
    //ATRIBUTOS
private:
    int cantidad_elementos;
    int cant_madera;
    int cant_piedra;
    int cant_metal;
    int cant_andycoins;
    int cant_bombas;

public:
    //CONSTRUCTOR
    Inventario();

    //PRE:
    //POS: devuelve cantidad de madera en el inventario.
    int devolver_cant_madera();

    //PRE:
    //POS: devuelve cantidad de piedra en el inventario.
    int devolver_cant_piedra();

    //PRE:
    //POS: devuelve cantidad de metal en el inventario.
    int devolver_cant_metal();

    //PRE:
    //POS: devuelve cantidad de andycoins en el inventario.
    int devolver_cant_andycoins();

    //PRE:
    //POS: devuelve cantidas de bombas en el inventario.
    int devolver_cant_bombas();

    //PRE:
    //POS: muestra en pantalla el inventario.
    void mostrar_inventario();

    //PRE: se lee el archivo materiales previamente verificada su existencia.
    //POS: incrementa +1 la cantidad de elementos en el inventario cada vez que se agrega 1 elemento al inventario
    // de esta manera incrementa +1 el largo del invario.
    void actualizar_largo_de_inventario();

    //PRE: cantidad sumar o restar depende del signo. Si quiere restar inlcuir signo menos o negativo "-".
    //POS: busca elemento segun el nombre y le modifica su cantidad actual registrada en el inventario.
    void cambiar_cantidad_elemento(std::string nombre_elemento, int cantidad_sumar_o_restar);

    //DESTRUCTOR
    ~Inventario();


};


#endif //INVENTARIO_INVENTARIO_H
