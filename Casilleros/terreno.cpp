#include "terreno.h"

Terreno::Terreno(int fila, int columna) {
    this -> fila = fila;
	this -> columna = columna;
	this -> peso = PESO_TERRENO;
	this -> tipo_casillero = TERRENO;
	this -> ocupado = false;
	this -> iluminado = false;
	this -> jugador1 = false;
	this -> jugador2 = false;
	this -> edificio = nullptr;
}

Terreno::~Terreno() {}