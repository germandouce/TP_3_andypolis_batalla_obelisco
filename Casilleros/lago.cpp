#include "lago.h"

Lago::Lago(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> peso = PESO_LAGO;
	this -> tipo_casillero = LAGO;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> jugador1 = false;
	this -> jugador2 = false;
}

Lago::~Lago() {}