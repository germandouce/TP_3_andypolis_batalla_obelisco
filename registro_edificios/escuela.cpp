#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int maximo,  int fila, int columna) : Edificio(piedra, madera, metal, maximo, fila,columna) {
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 25;
    this->vida_actual = 1;
    this->vida_maxima = 1;
    this->fila = fila;
    this->fila = fila;
}

void Escuela::mostrar_mensaje(){
    cout << "Soy una " << nombre << " brindo " << brinda << " andycoins y me encuentro en el casillero consultado" << endl;
}

string Escuela::obtener_material_brindado() {
    return "andycoins";
}