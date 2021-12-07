#include "casillero_inaccesible.h"

Casillero_inaccesible::Casillero_inaccesible() : Casillero() {}

Casillero_inaccesible::~Casillero_inaccesible() {}

void Casillero_inaccesible::construir_edificio(Edificio* edificio) {}

void Casillero_inaccesible::colocar_material(Material* material) {}

void Casillero_inaccesible::mostrar() {
    cout << SUCESS_COLOR << "-Soy un casillero inaccesible y me encuentro vacio." << END_COLOR << endl;
    cout << endl;
}

void Casillero_inaccesible::imprimir_casillero() {
    cout << obtener_color() << NEGRO << "   " << END_COLOR;
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