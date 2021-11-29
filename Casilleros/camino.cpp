#include "camino.h"

Camino::Camino(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = CAMINO;
	this -> ocupado = false;
	this -> material = Material();
}

Camino::~Camino() {}