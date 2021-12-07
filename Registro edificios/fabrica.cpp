#include "fabrica.h"

Fabrica::Fabrica(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y) : Edificio(piedra, madera, metal, maximo, pos_x, pos_y){
    this->nombre = "fabrica";
    this->diminutivo = "F";
    this->brinda = 40;
    this->vida_actual = 2;
    this->vida_maxima = 2;
    this->posicion_x= pos_x;
    this->posicion_y=pos_y;
}

void Fabrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " metales y me encuentro en el casillero consultado." << endl;
}

string Fabrica::obtener_material_brindado(){
    return "metal";
}