#include "casillero.h"

Casillero::Casillero() {}

int Casillero::obtener_fila() {
	return fila;
}

int Casillero::obtener_columna() {
	return columna;
}

void Casillero::ocupar_casillero() {
	ocupado = true;
}

void Casillero::desocupar_casillero() {
	ocupado = false;
}

string Casillero::obtener_tipo_casillero() {
	return tipo_casillero;
}

bool Casillero::esta_ocupado() {
	return ocupado;
}

bool Casillero::hay_jugador1() {
	return jugador1;
}

void Casillero::ocupar_jugador1() {
	jugador1 = true;
}

void Casillero::desocupar_jugador1() {
	jugador1 = false;
}

bool Casillero::hay_jugador2() {
	return jugador2;
}

void Casillero::ocupar_jugador2() {
	jugador2 = true;
}

void Casillero::desocupar_jugador2() {
	jugador2 = false;
}

void Casillero::iluminar_casillero() {
	iluminado = true;
}

void Casillero::desiluminar_casillero() {
	iluminado = false;
}

bool Casillero::esta_iluminado() {
	return iluminado;
}