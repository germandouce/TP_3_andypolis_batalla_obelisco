#include "fabrica.h"

Fabrica::Fabrica(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "fabrica";
    this->diminutivo = "F";
    this->brinda = 40;
    this->vida_actual = 2;
    this->vida_maxima = 2;
}

void Fabrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " metales y me encuentro en el casillero consultado." << endl;
}

string Fabrica::obtener_material_brindado(){
    return "metal";
}