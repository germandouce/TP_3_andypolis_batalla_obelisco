#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int maximo):Edificio(piedra, madera, metal, maximo){
    this->nombre = "mina";
    this->diminutivo = "M";
    this->brinda = 15;
}

string Mina::obtener_nombre(){
    return nombre;
}

int Mina::obtener_cantidad_brindada(){
    return brinda;
}

int Mina::obtener_cantidad(){
    return 1;
}

void Mina::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo : " << brinda << " de piedra y me encuentro en el casillero consultado . " << endl;
}