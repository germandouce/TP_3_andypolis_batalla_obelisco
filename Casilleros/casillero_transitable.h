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

	~Casillero_transitable();

	void construir_edificio(Edificio* edificio);

	void colocar_material(Material* material);
	
	Edificio* obtener_edificio();

	Material* obtener_material();

	void mostrar();

	void imprimir_casillero();

	int obtener_cantidad_contenida();

	string obtener_nombre_contenido();

	string obtener_color();
};

#endif // CASILLERO_TRANSITABLE_H