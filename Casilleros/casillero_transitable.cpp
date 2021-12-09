#include "casillero_transitable.h"

Casillero_transitable::Casillero_transitable() : Casillero() {}

Casillero_transitable::~Casillero_transitable() {}

void Casillero_transitable::construir_edificio(Edificio* edificio) {}

void Casillero_transitable::colocar_material(Material* material) {
    this -> material = material;
}

void Casillero_transitable::mostrar() {
    if (!ocupado) {
        cout << SUCESS_COLOR << "-Soy un casillero transitable y me encuentro vacio." << END_COLOR << endl;
    }
    else {
        cout << SUCESS_COLOR << "-Soy un casillero transitable y no me encuentro vacio." << END_COLOR << endl;
        material -> saludar();
    }
    cout << endl;
}

void Casillero_transitable::imprimir_casillero() {

    string contenido = "   ";

    if (material != nullptr) {
        contenido = " " + material -> obtener_diminutivo() + " ";
    }

    if (jugador1) {
        contenido = " " + JUGADOR1 + " ";
    }

    if (jugador2) {
        contenido = " " + JUGADOR2 + " ";
    }
    
    cout << obtener_color() << NEGRO << contenido << END_COLOR;
}

int Casillero_transitable::obtener_cantidad_contenida() {
    if (material == nullptr) {
        return 0;
    }
    else {
        return material -> obtener_cantidad();
    }
}

string Casillero_transitable::obtener_nombre_contenido() {
    
    string nombre_material;
    
    if (material == nullptr) {
        nombre_material = "";
    }
    else {
        nombre_material = material -> obtener_nombre();
    }
    
    return nombre_material;
}

string Casillero_transitable::obtener_color() {

    string color;

    if (tipo_casillero == CAMINO) {
        color = C_CAMINO;
    }

    if (tipo_casillero == MUELLE) {
        color = C_MUELLE;
    }

    if (tipo_casillero == BETUN) {
        color = C_BETUN;
    }

    if (esta_iluminado()) {
        color = ILUMINADO;
    }

    return color;
}