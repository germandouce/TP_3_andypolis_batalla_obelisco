#include "lago.h"

Lago::Lago(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = LAGO;
	this -> ocupado = false;
}

Lago::~Lago() {}