#ifndef OBJETIVO_H_INCLUDED
#define OBJETIVO_H_INCLUDED

#include <iostream>
#include <string>

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
const int REQUISITO_LETRADO = 5;

const int MINERO = 6;
const int REQUISITO_MINERO = 2;

const int CANSADO = 7;
const int REQUISITO_CANSADO = 7;

const int CONSTRUCTOR = 8;
const int REQUISITO_CONSTRUCTOR = 8;

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
    virtual bool comprobar_requisito() = 0;
    ~Objetivo();
};

class Comprar_andypolis: public Objetivo {
    public:
    Comprar_andypolis();
    bool comprobar_requisito();
};

class Edad_piedra: public Objetivo {
    public:
    Edad_piedra();
    bool comprobar_requisito();
};

class Bombardero: public Objetivo {
    public:
    Bombardero();
    bool comprobar_requisito();
};

class Energetico: public Objetivo {
    public:
    Energetico();
    bool comprobar_requisito();
};

class Letrado: public Objetivo {
    public:
    Letrado();
    bool comprobar_requisito(int maximos_escuelas);
    bool comprobar_requisito();
};

class Minero: public Objetivo {
    public:
    Minero();
    bool comprobar_requisito(int cantidad_minas, int cantidad_minas_oro);
    bool comprobar_requisito();
};

class Cansado: public Objetivo {
    public:
    Cansado();
    bool comprobar_requisito();

};

class Constructor: public Objetivo {
    public:
    Constructor();
    bool comprobar_requisitoint (int cant_mina, int cant_);
};

class Armado: public Objetivo {
    public:
    Armado();
    bool comprobar_requisito(int cantidad_bombas_actuales);
};

class Extremista: public Objetivo {
    public:
    Extremista();
    bool comprobar_requisito(int cantidad_bombas_totales);
};

#endif // OBJETIVO_H_INCLUDED