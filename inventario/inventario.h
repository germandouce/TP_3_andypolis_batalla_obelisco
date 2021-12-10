#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>

using namespace std;

const string I_PIEDRA = "piedra";
const string I_MADERA = "madera";
const string I_METAL = "metal";
const string I_BOMBAS = "bombas";
const string I_ANDYCOINS = "andycoins";

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
    void cambiar_cantidad_elemento(string nombre_elemento, int cantidad_sumar_o_restar);

    //PRE: es valida la cantidad a cambiar.
    //POS: cambia cantidad andycoins.
    void cambio_cantidad_andycoins(int cantidad);

    //PRE: es valida la cantidad a cambiar.
    //POS: cam
    void cambio_cantidad_bombas(int cantidad);

    //PRE: es valida la cantidad a cambiar.
    //POS: cambia cantidad metal.
    void cambio_cantidad_metal(int cantidad);



    //PRE: es valida la cantidad a cambiar.
    //POS: cambia cantidad madera.
    void cambio_cantidad_madera(int cantidad);




    //PRE: es valida la cantidad a cambiar.
    //POS: cambia cantidad de piedra.
    void cambio_cantidad_piedra(int cantidad);




    //PRE:
    //POS: devuelve true si es valida la cantidad a cambiar a andypolis.
    bool cambio_cantidad_andycoins_valida( int cantidad_consultada);

    //PRE:
    //POS: devuelve true si es valida  la cantidad 
    bool cambio_cantidad_bombas_valida( int cantidad_consultada);

    //PRE:
    //POS:
    bool cambio_cantidad_madera_valida( int cantidad_consultada);

    //PRE:
    //POS:
    bool cambio_cantidad_metal_valida( int cantidad_consultada);

    //PRE:
    //POS:
    bool cambio_cantidad_piedra_valida( int cantidad_consultada);

    //DESTRUCTOR
    ~Inventario();


};


#endif //INVENTARIO_INVENTARIO_H
