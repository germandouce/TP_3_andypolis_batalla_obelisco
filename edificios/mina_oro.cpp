#include "mina_oro.h"

Mina_oro::Mina_oro(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "mina de oro";
    this->diminutivo = "G";
    this->brinda = 50;
    this->vida_actual = 2;
    this->vida_maxima = 2;
}

int Mina_oro::obtener_cantidad_brindada(){
    return brinda;
}

void Mina_oro::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " Andycoins" << endl;
}

string Mina_oro::obtener_elemento_brindado(){
    return "andycoin";
}