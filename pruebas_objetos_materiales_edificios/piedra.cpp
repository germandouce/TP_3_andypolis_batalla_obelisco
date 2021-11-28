#include "piedra.h"

Piedra::Piedra(int cantidad_material):Material(cantidad_material){
    this->nombre = "piedra";
    this->diminutivo = "S";
}

string Piedra::obtener_nombre(){
    return nombre;
}

int Piedra::obtener_cantidad(){
    return cantidad_material;
}

int Piedra::obtener_cantidad_brindada(){
    return 0;
}
// void Piedra::mostrar_mensaje(){
//     cout << " Soy una " << nombre << " brindo : " << " de piedra y me encuentro en el casillero consultado . " << endl;
// }