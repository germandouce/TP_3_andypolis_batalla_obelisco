#ifndef OBJETIVO_H_INCLUDED
#define OBJETIVO_H_INCLUDED

#include <iostream>
#include <string>

#include  "../diccionario.h"

using namespace std;

const int CANTIDAD_OBJETIVOS = 3;
const int MINIMO_OBJETIVO = 0;
const int MAXIMO_OBJETIVO = 9;
const int OBELISCO_CONSTRUIDO = 1;

const string COMPRAR_ANDYPOLIS = "Comprar andypolis";
const int REQUISITO_COMPRAR_ANDYPOLIS = 100000;

const string EDAD_PIEDRA = "Edad de piedra";
const int REQUISITO_EDAD_PIEDRA = 50000;

const string BOMBARDERO = "Bombardero";
const int REQUISITO_BOMBARDERO = 5;

const string ENERGETICO = "Energetico";
const int REQUISITO_ENERGETICO = 100;

const string LETRADO = "Letrado";

const string MINERO = "Minero";

const string CANSADO = "Cansado";
const int REQUISITO_CANSADO = 0;

const string CONSTRUCTOR = "Constructor";

const string ARMADO = "Armado";
const int REQUISITO_ARMADO = 10;

const string EXTREMISTA = "Extremista";
const int REQUISITO_EXTREMISTA = 500;

class Objetivo {

    protected:

    string nombre_objetivo;
    string descripcion;

    public:

    Objetivo();
    
    void mostrar_descripcion();
    
    void mostrar_nombre_objetivo();

    virtual bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    virtual void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    virtual ~Objetivo();
};

#endif // OBJETIVO_H_INCLUDED
