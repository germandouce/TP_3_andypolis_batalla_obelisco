#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y) : Edificio(piedra, madera, metal, maximo, pos_x,pos_y) {
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 25;
    this->vida_actual = 1;
    this->vida_maxima = 1;
    this->posicion_x = pos_x;
    this->posicion_y = pos_y;
}

void Escuela::mostrar_mensaje(){
    cout << "Soy una " << nombre << " brindo " << brinda << " andycoins y me encuentro en el casillero consultado" << endl;
}

string Escuela::obtener_material_brindado() {
    return "andycoins";
}