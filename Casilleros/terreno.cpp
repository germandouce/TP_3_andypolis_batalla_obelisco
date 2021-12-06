#include "terreno.h"

Terreno::Terreno(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> tipo_casillero = TERRENO;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> edificio = nullptr;
}

Terreno::~Terreno() {}