#include "fabrica.h"

Fabrica::Fabrica(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "fabrica";
    this->diminutivo = "F";
    this->brinda = 40;
    this->vida_actual = 2;
    this->vida_maxima = 2;
}

int Fabrica::obtener_cantidad_brindada(){
    return brinda;
}

void Fabrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo : " << brinda << " metales y me encuentro en el casillero consultado." << endl;
}

string Fabrica::obtener_elemento_brindado(){
    return "metal";
}