#ifndef OBJETIVO_H_INCLUDED
#define OBJETIVO_H_INCLUDED

#include <iostream>
#include <string>

#include  "../diccionario.h"

using namespace std;

const int COMPRAR_ANDYPOLIS = 1;
const string NOMBRE_COMPRAR_ANDYPOLIS = "Comprar andypolis";

const int EDAD_PIEDRA = 2;
const string NOMBRE_EDAD_PIEDRA = "Edad de piedra";

const int BOMBARDERO = 3;
const string NOMBRE_BOMBARDERO = "Bombardero";

const int ENERGETICO = 4;
const string NOMBRE_ENERGETICO = "Energetico";

const int LETRADO = 5;
const string NOMBRE_LETRADO = "Letrado";

const int MINERO = 6;
const string NOMBRE_MINERO = "Minero";

const int CANSADO = 7;
const string NOMBRE_CANSADO = "Cansado";

const int CONSTRUCTOR = 8;
const string NOMBRE_MINERO = "Constructor";

const int ARMADO = 9;
const string NOMBRE_ARMADO = "Armado";

const int EXTREMISTA = 10;
const string NOMBRE_MINERO = "Extremisra";

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
    
    void mostrar_nombre_objetivo();

    virtual bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    virtual void mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
    Diccionario *diccionario, int energia) = 0;
    
    ~Objetivo();

};

#endif // OBJETIVO_H_INCLUDED
