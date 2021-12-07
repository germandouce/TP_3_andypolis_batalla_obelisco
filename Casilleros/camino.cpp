#include "camino.h"

Camino::Camino(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = CAMINO;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> material = nullptr;
}

Camino::~Camino() {}