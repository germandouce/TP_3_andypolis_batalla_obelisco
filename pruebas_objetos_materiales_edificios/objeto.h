#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto {

    protected:
    
    string nombre;
    string diminutivo;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un objeto con su nombre
    Objeto();
    
    //pre: -
    //post: Devuelve el nombre del objeto.
    virtual string obtener_nombre() = 0;

    // PRE: 
    // POS: Devuelve el diminutivo del objeto
    virtual string obtener_diminutivo() = 0;

    //PRE:-
    //POST: Muestra por pantalla un mensaje a traves del cual cada objeto (material o edficio) saluda
    //de manera distinta
    virtual void saludar() = 0;

    //pre: - 
    //post: Si es un edificio devuelve 1 (no deberia ejecutarse) si es un material, devuelve la cantidad de
    //elementos en el paquete
    virtual int obtener_cantidad() = 0;


    
    
    ~Objeto();
}; 

#endif // OBJETO_H