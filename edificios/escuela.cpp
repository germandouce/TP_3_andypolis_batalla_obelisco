#include "escuela.h"

Escuela::Escuela(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "escuela";
    this->diminutivo = "E";
    this->brinda = 0;
    this->vida_actual = 1;
    this->vida_maxima = 1;
}

int Escuela::obtener_cantidad_brindada(){
    return brinda;
}

void Escuela::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " <<brinda<<" andycoins y me encuentro en el casillero consultado" << endl;
}

string Escuela::obtener_elemento_brindado(){
    return "andycoin";
}