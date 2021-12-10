#include "camino.h"

Camino::Camino(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> peso = PESO_CAMINO;
	this -> tipo_casillero = CAMINO;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> jugador1 = false;
	this -> jugador2 = false;
	this -> material = nullptr;
}

Camino::~Camino() {}