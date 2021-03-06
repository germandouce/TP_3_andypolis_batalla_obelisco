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
    else if (edificio -> obtener_nombre() > nodo -> devolver_clave()) {
        nodo -> colocar_nodo_derecho(agregar_edificio(nodo -> devolver_nodo_derecho(), edificio), nodo);
    }
    else {
        nodo -> colocar_nodo_izquierdo(agregar_edificio(nodo -> devolver_nodo_izquierdo(), edificio), nodo);
    }

    return nodo;
}

Edificio* Diccionario::buscar_edificio(string nombre_edificio) {
    
    Nodo_dict* nodo = buscar_edificio(this -> origen, nombre_edificio);

    if (nodo != nullptr) {
        return nodo -> devolver_edificio();
    }
    cout << ERROR_COLOR << "El Edificio ingresado no existe." << END_COLOR << endl;
    return nullptr;
}

Nodo_dict* Diccionario::buscar_edificio(Nodo_dict* nodo, string clave) {

    if (nodo == nullptr || nodo -> devolver_clave() == clave)
        return nodo;

    if (clave > nodo -> devolver_clave())
        return buscar_edificio(nodo -> devolver_nodo_derecho(), clave);

    return buscar_edificio(nodo -> devolver_nodo_izquierdo(), clave);
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

Edificio* Diccionario::instanciar_edificio(string nombre_edificio, int piedra, int madera, int metal, int limite_construccion, 
int fila, int columna) {

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
		edificio = new Mina_de_oro(piedra, madera, metal, limite_construccion, fila, columna);
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

void Diccionario::modificar_valores_edificios() {

    string nombre_edificio;

    system(CLR_SCREEN);
    cout << ENTER_COLOR << "Ingrese el nombre del Edificio que desea modificar: " << END_COLOR << endl;
    cin >> nombre_edificio;

    Edificio* edificio = buscar_edificio(nombre_edificio);

    if (edificio != nullptr) {
        edificio -> modificar_cantidades_edificio();
    }
}

void Diccionario::guardar_edificios(ofstream &archivo) {
    guardar_edificios(archivo, origen);
}

void Diccionario::guardar_edificios(ofstream &archivo, Nodo_dict* nodo) {

    if (nodo != nullptr) {
        Edificio* edificio = nodo -> devolver_edificio();

        archivo << edificio -> obtener_nombre() << " ";
        archivo << edificio -> obtener_cantidad_piedra() << " ";
        archivo << edificio -> obtener_cantidad_madera() << " ";
        archivo << edificio -> obtener_cantidad_metal() << " ";
        archivo << edificio -> obtener_maximo_construir() << endl;

        guardar_edificios(archivo, nodo -> devolver_nodo_derecho());
        guardar_edificios(archivo, nodo -> devolver_nodo_izquierdo());
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