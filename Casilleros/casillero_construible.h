#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "casillero.h"

class Casillero_construible: public Casillero {
	
	protected:

	Edificio* edificio;

	public:

	// Constructor sin parámetros.
    //pre: -
    //post: -
	Casillero_construible();

	//pre: -
	//post: Actualiza el edificio con el 'edificio' ingresado.
	void asignar_edificio(Edificio edificio);

	void construir_edificio(Edificio* edificio) {
		this -> edificio = edificio;
	}

	void colocar_material(Material* material) {}
	
	void mostrar() {
		if (!ocupado) {
			cout << SUCESS_COLOR << "-Soy un casillero construible y me encuentro vacio." << END_COLOR << endl;
		}
		else {
			cout << SUCESS_COLOR << "-Soy un casillero construible y no me encuentro vacio." << END_COLOR << endl;
			edificio -> mostrar_informacion();
		}
		cout << endl;
	}

	void imprimir_casillero() {

		string edificio_contenido = "   ";

		if (edificio -> obtener_nombre() == M) {
			edificio_contenido = " M ";
		}

		if (edificio -> obtener_nombre() == A) {
			edificio_contenido = " A ";
		}

		if (edificio -> obtener_nombre() == F) {
			edificio_contenido = " F ";
		}

		if (edificio -> obtener_nombre() == E) {
			edificio_contenido = " E ";
		}

		if (edificio -> obtener_nombre() == O) {
			edificio_contenido = " O ";
		}

		if (edificio -> obtener_nombre() == P) {
			edificio_contenido = " P ";
		}

		cout << obtener_color() << NEGRO << edificio_contenido << END_COLOR;
		
	}

	int obtener_cantidad_contenida() {
		
		int existe_edificio = 0;

		if (edificio -> obtener_nombre() != "") {
			existe_edificio = 1;
		}

		return existe_edificio;
	}

	string obtener_nombre_contenido() {
		return edificio -> obtener_nombre();
	}

	string obtener_color() {
		return C_TERRENO;
	}

	~Casillero_construible() {}

};

#endif // CASILLERO_CONSTRUIBLE_H