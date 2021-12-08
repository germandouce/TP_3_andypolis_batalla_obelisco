#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "mina";
    this->diminutivo = "M";
    this->brinda = 15;
    this->vida_actual = 2;
    this->vida_maxima = 2;
}

void Mina::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " piedras y me encuentro en el casillero consultado." << endl;
}

string Mina::obtener_material_brindado(){
    return "piedra";
}