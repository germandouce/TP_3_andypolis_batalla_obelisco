#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible: public Casillero {
	
	public:

	// Constructor sin parámetros.
    //pre: -
    //post: -
	Casillero_inaccesible();

	void construir_edificio(Edificio* edificio) {}

	void colocar_material(Material* material) {}
	
	void mostrar() {
		cout << SUCESS_COLOR << "-Soy un casillero inaccesible y me encuentro vacio." << END_COLOR << endl;
		cout << endl;
	}

	void imprimir_casillero() {
		cout << obtener_color() << NEGRO << "   " << END_COLOR;
	}

	int obtener_cantidad_contenida() {
		return 0;
	}

	string obtener_nombre_contenido() {
		return "";
	}

	string obtener_color() {
		return C_LAGO;
	}

	~Casillero_inaccesible() {}
};

#endif // CASILLERO_INACCESIBLE_H