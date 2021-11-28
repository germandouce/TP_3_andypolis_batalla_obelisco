#include "aserradero.h"

Aserradero::Aserradero(int piedra, int madera, int metal, int maximo):Edificio(piedra, madera, metal, maximo){
    this->nombre = "aserradero";
    this->diminutivo = "A";
    this->brinda = 40;
}

string Aserradero::obtener_nombre(){
    return nombre;
}

string Aserradero::obtener_diminutivo(){
    return diminutivo;
}

int Aserradero::obtener_cantidad_brindada(){
    return brinda;
}

int Aserradero::obtener_cantidad(){
    return 1;
}


void Aserradero::saludar(){
    cout << " Soy una " << nombre << " brindo " << brinda << " de piedra y me encuentro en el casillero consultado" << endl;
}