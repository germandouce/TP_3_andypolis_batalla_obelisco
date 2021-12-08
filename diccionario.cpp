#include "diccionario.h"

Diccionario::Diccionario() {
    this -> origen = nullptr;
}

void Diccionario::agregar_edificio(Edificio* edificio) {
    this -> origen = agregar_edificio(this -> origen, edificio);
}

Nodo_dict* Diccionario::agregar_edificio(Nodo_dict* nodo, Edificio* edificio) {
    
    if (nodo == nullptr) {
        nodo = new Nodo_dict(edificio);
    }
    else if (edificio -> obtener_diminutivo()[0] > nodo -> devolver_id()) {
        nodo -> colocar_nodo_derecho(agregar_edificio(nodo -> devolver_nodo_derecho(), edificio), nodo);
    }
    else {
        nodo -> colocar_nodo_izquierdo(agregar_edificio(nodo -> devolver_nodo_izquierdo(), edificio), nodo);
    }

    return nodo;
}

Edificio* Diccionario::buscar_edificio(string nombre_edificio) {
    
    int id = asociar_nombre_id(nombre_edificio);
    
    Nodo_dict* nodo = buscar(this -> origen, id);

    if (nodo != nullptr) {
        return nodo -> devolver_edificio();
    }

    return nullptr;
}

int Diccionario::asociar_nombre_id(string nombre_edificio) {

    int id = -1;

    if (nombre_edificio == A) {
        id = ASCII_A;
    }

    if (nombre_edificio == E) {
        id = ASCII_E;
    }

    if (nombre_edificio == F) {
        id = ASCII_F;
    }

    if (nombre_edificio == G) {
        id = ASCII_G;
    }

    if (nombre_edificio == M) {
        id = ASCII_M;
    }

    if (nombre_edificio == O) {
        id = ASCII_O;
    }

    if (nombre_edificio == P) {
        id = ASCII_P;
    }

    return id;
}

Nodo_dict* Diccionario::buscar(Nodo_dict* nodo, int id) {

    if (nodo == nullptr || nodo -> devolver_id() == id)
        return nodo;

    if (id > nodo -> devolver_id())
        return buscar(nodo -> devolver_nodo_derecho(), id);

    return buscar(nodo -> devolver_nodo_izquierdo(), id);
}

Edificio* Diccionario::instanciar_edificio(string nombre_edificio, int fila, int columna) {

    Edificio* edificio = buscar_edificio(nombre_edificio);

    int piedra = edificio -> obtener_cantidad_piedra();
    int madera = edificio -> obtener_cantidad_madera();
    int metal = edificio -> obtener_cantidad_metal();
    int limite_construccion = edificio -> obtener_maximo_construir();

    edificio = instanciar_edificio(nombre_edificio, piedra, madera, metal, limite_construccion, fila, columna);

    return edificio;
}

Edificio* Diccionario::instanciar_edificio(string nombre_edificio, int piedra, int madera, int metal, 
int limite_construccion,int fila, int columna){

    Edificio* edificio;

    if (nombre_edificio == A) {
		edificio = new Aserradero(piedra, madera, metal, limite_construccion, fila, columna);
	}

	if (nombre_edificio == E) {
		edificio = new Escuela(piedra, madera, metal, limite_construccion,fila, columna);
	}

	if (nombre_edificio == F) {
		edificio = new Fabrica(piedra, madera, metal, limite_construccion, fila, columna);
	}

	if (nombre_edificio == M) {
		edificio = new Mina(piedra, madera, metal, limite_construccion, fila, columna);
	}

	if (nombre_edificio == G) {
		edificio = new Mina_oro(piedra, madera, metal, limite_construccion, fila, columna);
	}

	if (nombre_edificio == O) {
		edificio = new Obelisco(piedra, madera, metal, limite_construccion, fila, columna);
	}

	if (nombre_edificio == P) {
		edificio = new Planta_electrica(piedra, madera, metal, limite_construccion, fila, columna);
	}

    return edificio;
}

void Diccionario::mostrar_todos_edificios() {
    mostrar_todos_edificios(origen);
}

void Diccionario::mostrar_todos_edificios(Nodo_dict* nodo) {

    if (nodo != nullptr) {
        nodo -> devolver_edificio() -> mostrar_toda_informacion();
        
        mostrar_todos_edificios(nodo -> devolver_nodo_derecho());
        mostrar_todos_edificios(nodo -> devolver_nodo_izquierdo());
    }
}

void Diccionario::borrar_todo(Nodo_dict* nodo) {
    
    if (nodo == NULL) {
        return;
    }
    
    this -> borrar_todo(nodo -> devolver_nodo_izquierdo());
    this -> borrar_todo(nodo -> devolver_nodo_derecho());
    delete nodo;
}

void Diccionario::borrar_todo() {
    this -> borrar_todo(this -> origen);
}

Diccionario::~Diccionario() {
    this -> borrar_todo();
}