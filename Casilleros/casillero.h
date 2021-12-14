#ifndef CASILLERO_H
#define CASILLERO_H

#include <iostream>
#include <string>
#include "../colores.h"
#include "../registro_edificios/edificio.h"
#include "../materiales/material.h"

const string TERRENO = "T";
const string LAGO = "L";
const string CAMINO = "C";
const string MUELLE = "M";
const string BETUN = "B";

const int PESO_CAMINO = 4;
const int PESO_BETUN = 0;
const int PESO_LAGO = 2; 
const int PESO_MUELLE = 5; 
const int PESO_TERRENO = 25;

const int DIFERENCIA_LAGO = 3;
const int DIFERENCIA_MUELLE = 3;

const string JUGADOR1 = "J";
const string JUGADOR2 = "U";

class Casillero {
	
	protected:

	int fila;
	int columna;
	int peso;
	string tipo_casillero;
	bool ocupado;
	bool iluminado;
	bool jugador1;
	bool jugador2;

	public:

	// Constructor sin parametros. No se puede instanciar.
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
	//post: Devuelve el peso del Casillero.
	int obtener_peso_jugador1();

	int obtener_peso_jugador2();

	//pre: -
	//post: Devuelve el tipo de casillero del Casillero.
	string obtener_tipo_casillero();

	//pre: -
	//post: Devuelve True si esta ocupado y False si no lo esta.
	bool esta_ocupado();

	bool esta_ocupado_jugador();

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void ocupar_casillero();

	//pre: -
	//post: Actualiza el valor de 'esta_vacio'.
	void desocupar_casillero();

	//pre: -
	//post: Devuelve True si el Jugador 1 esta ubicado en el Casillero. Sino devuelve False.
	bool hay_jugador1();

	void ocupar_jugador1();

	void desocupar_jugador1();

	bool hay_jugador2();

	void ocupar_jugador2();

	void desocupar_jugador2();

	void iluminar_casillero();

	void desiluminar_casillero();

	bool esta_iluminado();

	//pre: -
	//post: Construye el Edificio en el Casillero si este es construible.
	//		Sino, imprime un mensaje.
	virtual void construir_edificio(Edificio* edificio) = 0;

	virtual Edificio* obtener_edificio() = 0;

	//pre: -
	//post: Coloca el Material en el Casillero si este es transitable.
	//		Sino, imprime un mensaje.
	virtual void colocar_material(Material* material) = 0;

	virtual Material* obtener_material() = 0;

	//pre: -
	//post: Muestra informacion sobre el Casillero y sobre lo que contiene.
	virtual void mostrar() = 0;

	//pre: -
	//post: Imprime el Casillero.
	virtual void imprimir_casillero() = 0;

	//pre: -
	//post: Devuelve 1 si el Casillero contiene algo, o 0 si no contiene nada.
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