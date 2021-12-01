#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 25;
    this->vida_actual = 1;
    this->vida_maxima = 1;
}

void Escuela::mostrar_mensaje(){
    cout << "Soy una " << nombre << " brindo " <<brinda<<" andycoins y me encuentro en el casillero consultado" << endl;
}

string Escuela::obtener_material_brindado(){
    return "andycoin";
}