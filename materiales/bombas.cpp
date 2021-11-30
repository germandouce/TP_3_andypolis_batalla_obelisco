#include <iostream>
#include "bombas.h"

//Constructor de paquete de bombas sin parametros
Bombas :: Bombas() : Material(cantidad_material){
        nombre_material = "bombas";
}

//Piedra saluda
void Bombas :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " maderas "<<
        "y me encuentro en el casillero consultado"<<endl;
}