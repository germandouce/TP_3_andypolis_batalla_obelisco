#include "betun.h"

Betun::Betun(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> peso = PESO_BETUN;
	this -> tipo_casillero = BETUN;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> jugador1 = false;
	this -> jugador2 = false;
	this -> material = nullptr;
}

Betun::~Betun() {}