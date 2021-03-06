#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>

#include "grafo/grafo.h"
#include "juego/jugador.h"

#include "materiales/piedra.h"
#include "materiales/madera.h"
#include "materiales/metal.h"
#include "materiales/andycoins.h"
#include "materiales/bombas.h"

#include "Casilleros/terreno.h"
#include "Casilleros/lago.h"
#include "Casilleros/camino.h"
#include "Casilleros/muelle.h"
#include "Casilleros/betun.h"

const int POSICION_INICIAL = 0;
const int ZERO = 0;

const int TIPOS_MATERIALES_LLUVIA = 3;
const int PIEDRA_LLOVIDA = 100;
const int MADERA_LLOVIDA = 50;
const int METAL_LLOVIDO = 50;
const int ANDYCOINS_LLOVIDO = 250;

const int CANT_MATERIALES = 4;
const int CANT_MAX_PIEDRA = 2;
const int CANT_MAX_MADERA = 4;
const int CANT_MAX_METAL = 3;
const int CANT_MAX_ANDYCOINS = 2;
const int CANT_MIN_PIEDRA = 1;
const int CANT_MIN_MADERA = 0;
const int CANT_MIN_METAL = 2;
const int CANT_MIN_ANDYCOINS = 0;

const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const int ANDYCOINS = 3;

const string S = "piedra";
const string W = "madera";
const string I = "metal";
const string B = "bombas";
const string C = "andycoins";

const char TOPE_CADENA_FILA = ',';
const char TOPE_CADENA_COLUMNA = ')';
const int ASCII_NUM_CERO = 48;
const int ASCII_NUM_NUEVE = 57;
const int POSICION_INICIAL_FILA = 1;
const int POSICION_INICIAL_COLUMNA = 0;

const int CANTIDAD_COORDENADAS = 2;
const int FILA = 0;
const int COLUMNA = 1;

const int NULA = -1;

using namespace std;

class Mapa {
	
	private:

	int filas;
	int columnas;
	
	Vector<Casillero> casilleros_lluvia;
	int transitables_disponibles;
	
	Casillero*** matriz;
	Grafo* grafo;

	public:

	// Constructor sin parámetros. Pensado para crear punteros a Mapa.
	//pre: -
    //post: Instancia un Mapa sin valor alguno.
	Mapa();

	~Mapa();

	//pre: -
    //post: Devuelve la cantidad de filas del Mapa.
	int obtener_filas();

	//pre: -
    //post: Devuelve la cantidad de columnas del Mapa.
	int obtener_columnas();

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Devuelve un puntero al Casillero ubicado en la fila y columna ingresadas.
	Casillero* obtener_casillero(int fila, int columna);

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Devuelve el tipo del Casillero ubicado en la fila y columna ingresadas.
	string obtener_tipo_casillero(int fila, int columna);

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Asigna el puntero a Casillero a la posición fila y columna ingresadas.
	void cargar_casillero(int fila, int columna, Casillero* casillero);

	void colocar_material(int fila, int columna, Material* material);

	void cargar_mapa(ifstream& mapa);

	void cargar_diccionario(ifstream &archivo);

	//pre: -
    //post: Imprime el Mapa.
	void imprimir_mapa();

	//pre:-
	//post: Muestra todos los edificios.
	void mostrar_todos_edificios();
	
	//pre:
	//post: Agrego aleatoriamente materiales en el mapa.
	void llover();

	//pre:-
	//post: Escribe los materiales llovidos en un txt.
	void guardar_lluvia(ofstream &archivo);

	//pre: -
    //post: Genera una lluvia de Materiales en el Mapa.
	void generar_lluvia_materiales();

	void cargar_casilleros_lluvia();

	//pre:-
	//post:Muestra el movimiento de un jugador desde un punto a otro del mapa.
	void moverse(Jugador* jugador);

	//pre:-
	//post:Informa si el movimiento es valido.
	bool es_movimiento_valido(int fila, int columna);

	//pre:-
	//post: Imprime el camino minimo.
	void imprimir_camino_recorrido(Lista* lista_vertices, Inventario* inventario, int origen, int destino, bool es_jugador2);

	void print_lento(unsigned int tiempo);
	
	//pre:-
	//post: Ocupa un casillero por un jugador.
	void ocupar_jugador(int fila, int columna, bool es_jugador2);

	//pre:-
	//post: Desocupa el casillero si habia un jugador.
	void desocupar_jugador(int fila, int columna, bool es_jugador2);

	//pre:-
	//post: Almacena los recursos por los que pasa el jugador.
	void recolectar_recursos(int fila, int columna, Inventario* inventario);

	//pre: -
    //post: Pide al usuario que ingrese una fila y una columna, y muestra información del Casillero
	//		correspondiente a dichas coordenadas.
	void consultar_casillero();

	void verificar_construccion();

	//pre: Los valores ingresados deben cumplir que: 0 <= fila < filas y 0 <= columna < columnas.
    //post: Construye el Edificio en la fila y columna ingresadas si esta no está ocupada.
	void construir_edificio(int fila, int columna, Edificio* edificio_a_construir);
	
	Casillero*** devolver_matriz();

	private:

	//pre: El 'tipo_casillero' es un tipo de Casillero válido.
    //post: Suma uno a los casilleros disponibles correspondientes al tipo ingresado.

	Casillero* crear_subcasillero(int fila, int columna, string tipo_casillero);
	
	//pre:
	//post:
	void asignar_atributos(int filas, int columnas);
	
	//pre:
	//post:
	void sumar_casillero_por_tipo(string tipo_casillero);

	//pre:
	//post: Lee palabra compuesta.
	string leer_palabra_compuesta(ifstream &archivo, string &nombre_edificio, int opcion);

	//pre:-
	//post: 
	bool verificar_tipo_caracter(string palabra, int tipo_caracter);

	//pre:-
	//post: Informa si es un numero.
	bool es_numero(string palabra);

	//pre: -
	//post: Llueve en un casillero
	Material* llover_material_aleatorio(int &material_llovido);

	//pre: -
	//post: Devuelve el tipo de material
	string obtener_tipo_material(int tipo_material);

	//pre: -
    //post: Verifica si puede llover más del 'material_llovido' y devuelve True.
	//		Devuelve False si no se pasa la verificación.
	bool puede_llover_mas(int &piedra_llovida, int &madera_llovida, int &metal_llovido, int &andycoins_llovido, int material_llovido);
	
	//pre: -
    //post: Pide coordenadas y actualiza los respectivos valores ingresados.
	void pedir_coordenadas(int &fila, int &columna);

	//pre: -
    //post: Pide una número y actualiza el valor de fila.
	void pedir_fila(int &fila);

	//pre: -
    //post: Pide una número y actualiza el valor de columna.
	void pedir_columna(int &columna);
};

#endif // MAPA_H_INCLUDED
