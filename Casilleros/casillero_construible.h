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

	~Casillero_construible();

	Edificio* obtener_edificio();

	Material* obtener_material();

	void construir_edificio(Edificio* edificio);

	void colocar_material(Material* material);
	
	void mostrar();

	void imprimir_casillero();

	int obtener_cantidad_contenida();

	string obtener_nombre_contenido();

	string obtener_color();
};

#endif // CASILLERO_CONSTRUIBLE_H