#include "casillero_construible.h"

Casillero_construible::Casillero_construible() : Casillero() {}

Casillero_construible::~Casillero_construible() {}

void Casillero_construible::construir_edificio(Edificio* edificio) {
    this -> edificio = edificio;
}

void Casillero_construible::colocar_material(Material* material) {}

void Casillero_construible::mostrar() {
    if (!ocupado) {
        cout << SUCESS_COLOR << "-Soy un casillero construible y me encuentro vacio." << END_COLOR << endl;
    }
    else {
        cout << SUCESS_COLOR << "-Soy un casillero construible y no me encuentro vacio." << END_COLOR << endl;
        edificio -> mostrar_mensaje();
    }
    cout << endl;
}

void Casillero_construible::imprimir_casillero() {

    string edificio_contenido = "   ";

    if (edificio != nullptr) {
        edificio_contenido = " " + edificio -> obtener_diminutivo() + " ";
    }
    
    cout << obtener_color() << NEGRO << edificio_contenido << END_COLOR;
}

int Casillero_construible::obtener_cantidad_contenida() {
    
    int existe_edificio = 1;

    if (edificio == nullptr) {
        existe_edificio = 0;
    }

    return existe_edificio;
}

string Casillero_construible::obtener_nombre_contenido() {
    
    string nombre_edificio;
    
    if (edificio == nullptr) {
        nombre_edificio = "";
    }
    else {
        nombre_edificio = edificio -> obtener_nombre();
    }
    
    return nombre_edificio;
}

string Casillero_construible::obtener_color() {
    return C_TERRENO;
}