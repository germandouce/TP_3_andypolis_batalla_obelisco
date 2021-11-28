#include "piedra.h"

Piedra::Piedra(int cantidad_material):Material(cantidad_material){
    this->nombre = "piedra";
    this->diminutivo = "S";
}

string Piedra::obtener_nombre(){
    return nombre;
}

string Piedra::obtener_diminutivo(){
    return diminutivo;
}

int Piedra::obtener_cantidad(){
    return cantidad_material;
}

void Piedra::saludar(){
    cout<< " Soy un conjunto de " << cantidad_material <<" "<< nombre << "s y me encuentro en el casillero consultado" << endl;
}