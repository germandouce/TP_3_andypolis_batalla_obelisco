#include <iostream>
#include "madera.h"

//Constructor de piedra don dos parametros
Madera :: Madera() : Material(cantidad_material){
        nombre_material = "madera";
}

//Piedra saluda
void Madera :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " maderas "<<
        "y me encuentro en el casillero consultado"<<endl;
}