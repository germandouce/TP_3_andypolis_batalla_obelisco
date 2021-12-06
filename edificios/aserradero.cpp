#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "aserradero";
    this->diminutivo = "A";
    this->brinda = 25;
    this->vida_actual = 1;
    this->vida_maxima = 1;
}

void Aserradero::mostrar_mensaje(){
    cout << "Soy un " << nombre << " brindo " << brinda << " maderas y me encuentro en el casillero consultado" << endl;
}

string Aserradero::obtener_material_brindado(){
    return "madera";
}