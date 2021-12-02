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
			edificio -> mostrar_mensaje();
		}
		cout << endl;
	}

	void imprimir_casillero() {

		string edificio_contenido = "   ";

		if (edificio != nullptr) {
			edificio_contenido = " " + edificio -> obtener_diminutivo() + " ";
		}
		
		cout << obtener_color() << NEGRO << edificio_contenido << END_COLOR;
	}

	int obtener_cantidad_contenida() {
		
		int existe_edificio = 1;

		if (edificio == nullptr) {
			existe_edificio = 0;
		}

		return existe_edificio;
	}

	string obtener_nombre_contenido() {
		
		string nombre_edificio;
		
		if (edificio == nullptr) {
			nombre_edificio = "";
		}
		else {
			nombre_edificio = edificio -> obtener_nombre();
		}
		
		return nombre_edificio;
	}

	string obtener_color() {
		return C_TERRENO;
	}

	~Casillero_construible() {}

};

#endif // CASILLERO_CONSTRUIBLE_H