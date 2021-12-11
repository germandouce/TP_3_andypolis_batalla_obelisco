#ifndef OBJETIVO_H_INCLUDED
#define OBJETIVO_H_INCLUDED

#include <iostream>
#include <string>

#include "../Inventario/Inventario.h"
#include "../registro_edificios/Registro_edificios.h"
#include  "../diccionario.h"

using namespace std;

const int COMPRAR_ANDYPOLIS = 1;
const int REQUISITO_COMPRAR_ANDYPOLIS = 100000;

const int EDAD_PIEDRA = 2;
const int REQUISITO_EDAD_PIEDRA = 50000;

const int BOMBARDERO = 3;
const int REQUISITO_BOMBARDERO = 5;

const int ENERGETICO = 4;
const int REQUISITO_ENERGETICO = 100;

const int LETRADO = 5;

const int MINERO = 6;

const int CANSADO = 7;
const int REQUISITO_CANSADO = 0;

const int CONSTRUCTOR = 8;
const int REQUISITO_CONSTRUCTOR = 7;

const int ARMADO = 9;
const int REQUISITO_ARMADO = 9;

const int EXTREMISTA = 10;
const int REQUISITO_EXTREMISTA = 5000;

class Objetivo {

    protected:

    string nombre_objetivo;
    string descripcion;
    int identificador;
    int requisito;

    public:

    Objetivo();
    int obtener_identificador();
    
    void mostrar_descripcion();
    
    virtual bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    virtual void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    ~Objetivo();

};

#endif // OBJETIVO_H_INCLUDED
