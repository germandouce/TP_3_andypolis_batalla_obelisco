#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y) : Edificio(piedra, madera, metal, maximo, pos_x, pos_y){
    this->nombre = "mina";
    this->diminutivo = "M";
    this->brinda = 15;
    this->vida_actual = 2;
    this->vida_maxima = 2;
    this->posicion_x = pos_x;
    this->posicion_y = pos_y;
}

void Mina::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " piedras y me encuentro en el casillero consultado." << endl;
}

string Mina::obtener_material_brindado(){
    return "piedra";
}