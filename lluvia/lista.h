#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
#include "casillero_transitable.h"

//La clase nodo es exactamente igual!

class Lista {
    // Atributos
private:

    //Un puntero al primero.
    //Si necesito HACER ALTAS AL FINAL PEUDE SER UTIL
    //tener un puntero al ultimo. Como no lo vamos
    //a hacer no lo incluyo
    Nodo* primero;

    //Como no es eficiente ir contando recorriendo la lista
    //cada vez q quiero saber cuantos hay
    int cantidad;

    // Metodos
public:
    //Constructor
    //PRE: -
    //Pone el tope en 0 xq arranca vacia
    //POS: tope = 0
    Lista();

    int Obtener_cantidad();

    //PRE: 1 <= pos <= cantidad + 1
    //Trabajo como si la primera posicion fuera la 1, por eso
    //mayor a 1, como arranca en 1 es menor o igual y xa insertar al final + 1
    //POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(Dato d, int pos);

    //PRE: 1 <= pos <= cantidad
    //Aca es lo mismo para mayor a 1 pero menor a cantidad porque no peudo consultar
    //un elemento que no esta.(+1, es decir al final)
    //POS: devuelve el dato que esta arriba
    Dato consulta(int pos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos);


    //PRE: -
    //POS: devuelve true si la pila esta vacia, false si no
    bool vacia();

    //Destructor
    ~Lista();

    //NO VA COMO PRIMITIVA DE LISTA�
    //void mostrar();

private:
    //mde devolvera un puntero a nodo
    ////Esta privado xq no me interesa que lo use el ususario!
    Nodo* obtener_nodo(int pos);
};



#endif // LISTA_H_INCLUDED
