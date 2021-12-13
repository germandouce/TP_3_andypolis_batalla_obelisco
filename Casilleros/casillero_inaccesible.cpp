#include "casillero_inaccesible.h"

Casillero_inaccesible::Casillero_inaccesible() : Casillero() {}

Casillero_inaccesible::~Casillero_inaccesible() {}

void Casillero_inaccesible::construir_edificio(Edificio* edificio) {}

void Casillero_inaccesible::colocar_material(Material* material) {}

Edificio* Casillero_inaccesible::obtener_edificio() {
    return nullptr;
}

Material* Casillero_inaccesible::obtener_material() {
    return nullptr;
}

void Casillero_inaccesible::mostrar() {

    if (!esta_ocupado_jugador()) {
        cout << SUCESS_COLOR << "-Soy un casillero inaccesible y me encuentro vacio." << END_COLOR << endl;
    }
    else {
        cout << SUCESS_COLOR << "-Soy un casillero inaccesible y no me encuentro vacio." << END_COLOR << endl;

        if (hay_jugador1()) {
            cout << SUCESS_COLOR << "-Soy el Jugador 1 y me encuentro en el casillero consultado." << END_COLOR << endl;
        }
        else if (hay_jugador2()) {
            cout << SUCESS_COLOR << "-Soy el Jugador 2 y me encuentro en el casillero consultado." << END_COLOR << endl;
        }
    }
    cout << endl;
}

void Casillero_inaccesible::imprimir_casillero() {

    string contenido = "   ";

    if (hay_jugador1()) {
        contenido = " " + JUGADOR1 + " ";
    }

    if (hay_jugador2()) {
        contenido = " " + JUGADOR2 + " ";
    }

    cout << obtener_color() << NEGRO << contenido << END_COLOR;
}

int Casillero_inaccesible::obtener_cantidad_contenida() {
    return 0;
}

string Casillero_inaccesible::obtener_nombre_contenido() {
    return "";
}

string Casillero_inaccesible::obtener_color() {
    
    string color = C_LAGO;

    if (esta_iluminado()) {
        color = ILUMINADO;
    }
    
    return color;
}