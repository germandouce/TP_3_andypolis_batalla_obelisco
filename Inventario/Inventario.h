#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <string>

const std::string PATH_MATERIALES = "C:\\Users\\FacuNano\\Desktop\\Inventario\\materiales.txt";

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

    //PRE: el inventario se crea en default (todas las cantidades en 0).
    //POS: procesa el archivo de materiales y carga/ actualiza las cantidades de cada elemento en el inventario.
    void procesar_archivo_materiales();

    //PRE: no se encuentra el archivo materiales.
    //POS: crea archivo faltante de materiales, todas las cantidades en 0.
    void crear_archivo_faltante();

    //PRE: cantidad sumar o restar depende del signo. Si quiere restar inlcuir signo menos o negativo "-".
    //POS: busca elemento segun el nombre y le modifica su cantidad actual registrada en el inventario.
    void cambiar_cantidad_elemento(std::string nombre_elemento, int cantidad_sumar_o_restar);

};


#endif //INVENTARIO_INVENTARIO_H
