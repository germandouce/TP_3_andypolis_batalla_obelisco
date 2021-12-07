#include "muelle.h"

Muelle::Muelle(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = MUELLE;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> material = nullptr;
}

Muelle::~Muelle() {}