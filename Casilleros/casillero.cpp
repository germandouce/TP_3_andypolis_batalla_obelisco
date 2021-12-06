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