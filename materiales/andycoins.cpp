#include <iostream>
#include "andycoins.h"

//Constructor de piedra don dos parametros
Andycoins :: Andycoins() : Material(cantidad_material){
        nombre_material = "andycoins";
}

//Piedra saluda
void Andycoins :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " andycoins y"
        <<"me encuentro en el casillero consultado"<<endl;
}