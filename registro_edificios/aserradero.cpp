#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y) : Edificio(piedra, madera, metal, maximo, pos_x, pos_y){
    this->nombre = "aserradero";
    this->diminutivo = "A";
    this->brinda = 25;
    this->vida_actual = 1;
    this->vida_maxima = 1;
    this->posicion_x = pos_x;
    this->posicion_y = pos_y;
}

void Aserradero::mostrar_mensaje(){
    cout << "Soy un " << nombre << " brindo " << brinda << " maderas y me encuentro en el casillero consultado" << endl;
}

string Aserradero::obtener_material_brindado(){
    return "madera";
}