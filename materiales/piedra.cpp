#include "piedra.h"

//Constructor de piedra don dos parametros
Piedra :: Piedra(): Material(cantidad_material){
        nombre_material = "piedra";
}


//Piedra saluda
void Piedra :: saludar(){
        cout << "Soy un paquete de" << cantidad_material << " piedras y me encuentro en"<<
        "el casillero consultado"<<endl;
}