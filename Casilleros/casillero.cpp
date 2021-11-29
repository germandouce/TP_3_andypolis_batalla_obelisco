#include "casillero.h"

Casillero::Casillero() {}

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