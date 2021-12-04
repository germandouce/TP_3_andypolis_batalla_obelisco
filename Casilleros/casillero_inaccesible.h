#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible: public Casillero {
	
	public:

	// Constructor sin parámetros.
    //pre: -
    //post: -
	Casillero_inaccesible();

	~Casillero_inaccesible();

	void construir_edificio(Edificio* edificio);

	void colocar_material(Material* material);
	
	void mostrar();

	void imprimir_casillero();

	int obtener_cantidad_contenida();

	string obtener_nombre_contenido();

	string obtener_color();
};

#endif // CASILLERO_INACCESIBLE_H