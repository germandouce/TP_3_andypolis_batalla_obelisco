#include "bombas.h"

//Constructor de paquete de bombas sin parametros
Bombas :: Bombas(int cantidad_material) : Material(cantidad_material){
        nombre_material = "bombas";
        diminutivo = "B";
}

//Piedra saluda
void Bombas :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " bombas "<<
        "y me encuentro en el casillero consultado"<<endl;
}