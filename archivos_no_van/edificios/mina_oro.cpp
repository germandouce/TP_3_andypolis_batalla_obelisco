#include "mina_oro.h"

Mina_oro::Mina_oro(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "mina de oro";
    this->diminutivo = "G";
    this->brinda = 50;
    this->vida_actual = 2;
    this->vida_maxima = 2;
}

void Mina_oro::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " andycoins" << endl;
}

string Mina_oro::obtener_material_brindado(){
    return "andycoins";
}