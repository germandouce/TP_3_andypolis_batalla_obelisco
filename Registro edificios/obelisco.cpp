#include "obelisco.h"

Obelisco::Obelisco(int piedra, int madera, int metal, int maximo,  int pos_x, int pos_y) : Edificio(piedra, madera, metal, maximo, pos_x, pos_y){
    this->nombre = "obelisco";
    this->diminutivo = "O";
    this->brinda = 0;
    this->posicion_x = pos_x;
    this->posicion_y = pos_y;
}

void Obelisco::mostrar_mensaje(){
    cout << "Soy un " << nombre << " ,no brindo materiales y me encuentro en el casillero consultado" << endl;
}

string Obelisco::obtener_material_brindado(){
    return "-";
}