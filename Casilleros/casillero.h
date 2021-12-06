#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <string>
#include "../colores.h"
#include ".././edificios./edificio.h"
#include ".././materiales./material.h"

const string CONSTRUIBLE = "construible";
const string TRANSITABLE = "transitable";
const string INACCESIBLE = "inaccesible";

const string TERRENO = "T";
const string LAGO = "L";
const string CAMINO = "C";
const string MUELLE = "M";
const string BETUN = "B";

class Casillero {
	
	protected:

	int fila;
	int columna;
	string tipo_casillero;
	bool ocupado; 

	public:

	// Constructor sin parámetros. No se puede instanciar.
	//pre: -
	//post: -
	Casillero();

	//pre: -
	//post: Devuelve la fila del Casillero.
	int obtener_fila();

	//pre: -
	//post: Devuelve la columna del Casillero.
	int obtener_columna();

	//pre: -
	//post: Devuelve el tipo de casillero del Casillero.
	string obtener_tipo_casillero();

	//pre: -
	//post: Devuelve True si está ocupado y False si no lo está.
	bool esta_ocupado();

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void ocupar_casillero();

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void desocupar_casillero();

	//pre: -
	//post: Construye el Edificio en el Casillero si este es construible.
	//		Sino, imprime un mensaje.
	virtual void construir_edificio(Edificio* edificio) = 0;

	//pre: -
	//post: Coloca el Material en el Casillero si este es transitable.
	//		Sino, imprime un mensaje.
	virtual void colocar_material(Material* material) = 0;

	//pre: -
	//post: Muestra información sobre el Casillero y sobre lo que contiene.
	virtual void mostrar() = 0;

	//pre: -
	//post: Imprime el Casillero.
	virtual void imprimir_casillero() = 0;

	//pre: -
	//post: Devuelve 1 si el Casillero contiene algo, ó 0 si no contiene nada.
	virtual int obtener_cantidad_contenida() = 0;

	//pre: -
	//post: Devuelve el nombre de lo que contiene el Casillero.
	virtual string obtener_nombre_contenido() = 0;

	//pre: -
	//post: Devuelve el color del Casillero.
	virtual string obtener_color() = 0;

	// Destructor.
	//pre: -
	//post: -
	virtual ~Casillero() {}
};

#endif // CASILLERO_H