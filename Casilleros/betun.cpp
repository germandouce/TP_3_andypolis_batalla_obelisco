#include "betun.h"

Betun::Betun(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = BETUN;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> material = nullptr;
}

Betun::~Betun() {}