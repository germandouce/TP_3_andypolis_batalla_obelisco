#include "casillero_construible.h"

Casillero_construible::Casillero_construible() : Casillero() {}

Casillero_construible::~Casillero_construible() {
    delete edificio;
}

void Casillero_construible::construir_edificio(Edificio* edificio) {
    this -> edificio = edificio;
}

void Casillero_construible::colocar_material(Material* material) {}

Edificio* Casillero_construible::obtener_edificio() {
    return edificio;
}

Material* Casillero_construible::obtener_material() {
    return nullptr;
}

void Casillero_construible::mostrar() {
    
    if (!esta_ocupado()) {
        cout << SUCESS_COLOR << "-Soy un casillero construible y me encuentro vacio." << END_COLOR << endl;
    }
    else {
        cout << SUCESS_COLOR << "-Soy un casillero construible y no me encuentro vacio." << END_COLOR << endl;
        
        if (hay_jugador1()) {
            cout << SUCESS_COLOR << "-Soy el Jugador 1 y me encuentro en el casillero consultado." << END_COLOR << endl;
        }
        else if (hay_jugador2()) {
            cout << SUCESS_COLOR << "-Soy el Jugador 2 y me encuentro en el casillero consultado." << END_COLOR << endl;
        }
        else {
            edificio -> mostrar_mensaje();
        }
    }
    cout << endl;
}

void Casillero_construible::imprimir_casillero() {

    string contenido = "   ";

    if (edificio != nullptr) {
        contenido = " " + edificio -> obtener_diminutivo() + " ";
    }

    if (hay_jugador1()) {
        contenido = " " + JUGADOR1 + " ";
    }

    if (hay_jugador2()) {
        contenido = " " + JUGADOR2 + " ";
    }
    
    cout << obtener_color() << NEGRO << contenido << END_COLOR;
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

    string color = C_TERRENO;

    if (esta_iluminado()) {
        color = ILUMINADO;  
    }

    return color;
}