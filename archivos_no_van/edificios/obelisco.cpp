#include "obelisco.h"

Obelisco::Obelisco(int piedra, int madera, int metal, int maximo) : Edificio(piedra, madera, metal, maximo){
    this->nombre = "obelisco";
    this->diminutivo = "O";
    this->brinda = 0;
}

void Obelisco::mostrar_mensaje(){
    cout << "Soy un " << nombre << " ,no brindo materiales y me encuentro en el casillero consultado" << endl;
}

string Obelisco::obtener_material_brindado(){
    return "-";
}