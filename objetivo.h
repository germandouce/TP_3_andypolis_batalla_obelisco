#ifndef OBJETIVO_H_INCLUDED
#define OBJETIVO_H_INCLUDED

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

const int MINERO = 6;
const int REQUISITO_MINERO = 2;

const int CANSADO = 7;
const int CONSTRUCTOR = 8;
const int ARMARDO = 9;
const int EXTREMISTA = 10;

class Objetivo {

    private:

    string nombre_objetivo;
    string descripcion;
    int identificador;
    int requisito;

    public:

    Objetivo();
    int obtener_identificador();
    virtual bool comprobar_requisito() = 0;
}

class Comprar_andypolis: public Objetivo {
    public:
    Comprar_andypolis();
}

class Edad_piedra: public Objetivo {
    public:
    Edad_piedra();
}

class Bombardero: public Objetivo {
    public:
    Bombardero();
}

class Energetico: public Objetivo {
    public:
    Comprar_andypolis();
}

class Letrado: public Objetivo {
    public:
    Letrado(int maximos_escuelas);
}

class Minero: public Objetivo {
    public:
    Minero();
}

class Cansado: public Objetivo {
    public:
    Cansado();
}

class Constructor: public Objetivo {
    public:
    Constructor();
}

class Armado: public Objetivo {
    public:
    Armado();
}

class Extremista: public Objetivo {
    public:
    Extremista();
}

#endif // OBJETIVO_H_INCLUDED