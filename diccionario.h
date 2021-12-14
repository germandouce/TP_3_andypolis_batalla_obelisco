#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "nodo_dict.h"
#include <fstream>
#include <string>
#include "Inventario/Inventario.h"

using namespace std;

class Diccionario {
    
    private:
    
    Nodo_dict* origen;

    public:

    //Constructor de dicionario
    Diccionario();

    //Destructor de diccionario
    ~Diccionario();

    // PRE: Recibe un edificio
    // POST: Inserta un edificio en el diccionario
    void agregar_edificio(Edificio* edificio);

    // PRE : Recibe un id entre 2 valores limites, si son edificios,
    // entre 1 y 7 si son materiales, entre ??? y ???
    // POST: devuelve true si el id se esta en el diccionario
    Edificio* buscar_edificio(string nombre_edificio);

    Edificio* instanciar_edificio(string nombre_edificio, int fila, int columna);

    void mostrar_todos_edificios();

    void modificar_valores_edificios();

    void guardar_edificios(ofstream &archivo);

    private:

    // PRE: Recibe un nodo y el edificio a insertar
    // POST: Ingresa el nodo en su posicion correspondiente
    Nodo_dict* agregar_edificio(Nodo_dict* nodo, Edificio* edificio);

    //PRE: Recibe id y un nodo
    //POST: Devuelve true si el id esta en el diccionacio
    Nodo_dict* buscar_edificio(Nodo_dict* nodo, string clave);

    void guardar_edificios(ofstream &archivo, Nodo_dict* nodo);

    void mostrar_todos_edificios(Nodo_dict* nodo);

    Edificio* instanciar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite, int fila, int columna);

    // PRE: -
    // POST: Borra todos los nodos del diccionario
    void borrar_todo();

    // PRE: Recibe el nodo
    // POST: Borra los nodos derechos e izquierdos en cuestion
    void borrar_todo(Nodo_dict* nodo);
};

#endif //DICCIONARIO_H