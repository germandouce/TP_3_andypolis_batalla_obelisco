#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"

class Casillero_transitable: public Casillero {
	
	protected:

	Material* material;

	public:
	
	// Constructor sin parámetros.
    //pre: -
    //post: -
	Casillero_transitable();

	void construir_edificio(Edificio* edificio) {}

	void colocar_material(Material* material) {
		this -> material = material;
	}
	
	void mostrar() {
		if (!ocupado) {
			cout << SUCESS_COLOR << "-Soy un casillero transitable y me encuentro vacio." << END_COLOR << endl;
		}
		else {
			cout << SUCESS_COLOR << "-Soy un casillero transitable y no me encuentro vacio." << END_COLOR << endl;
			material -> saludar();
	    }
		cout << endl;
	}

	void imprimir_casillero() {

		string material_contenido = "   ";

		if (material != nullptr) {
			material_contenido = " " + material -> obtener_diminutivo() + " ";
		}

		cout << obtener_color() << NEGRO << material_contenido << END_COLOR;
	}

	int obtener_cantidad_contenida() {
		if (material == nullptr) {
			return 0;
		}
		else {
			return material -> obtener_cantidad();
		}
	}

	string obtener_nombre_contenido() {
		
		string nombre_material;
		
		if (material == nullptr) {
			nombre_material = "";
		}
		else {
			nombre_material = material -> obtener_nombre();
		}
		
		return nombre_material;
	}

	string obtener_color() {

		string color;

		if (tipo_casillero == CAMINO) {
			color = C_CAMINO;
		}

		if (tipo_casillero == MUELLE) {
			color = C_MUELLE;
		}

		if (tipo_casillero == BETUN) {
			color = C_BETUN;
		}

		return color;
	}

	~Casillero_transitable() {}
};

#endif // CASILLERO_TRANSITABLE_H