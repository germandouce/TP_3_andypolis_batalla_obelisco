#include "piedra.h"

//Constructor de piedra don dos parametros
Piedra :: Piedra(int cantidad_material): Material() {
        nombre_material = "piedra";
        this -> cantidad_material = cantidad_material;
}


//Piedra saluda
void Piedra :: saludar(){
        cout << "Soy un paquete de" << cantidad_material << " piedras y me encuentro en"<<
        "el casillero consultado"<<endl;
}