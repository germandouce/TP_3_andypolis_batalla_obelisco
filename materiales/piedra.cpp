#include "piedra.h"

Piedra :: Piedra(int cantidad_material): Material(cantidad_material){
        nombre_material = "piedra";
        diminutivo = "S";
}

void Piedra :: saludar(){
        cout << "Soy un paquete de " << cantidad_material << " piedras y me encuentro en "<<
        "el casillero consultado"<<endl;
}