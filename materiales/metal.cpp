#include <iostream>
#include "metal.h"

//Constructor de Metal don dos parametros
Metal :: Metal() : Material(cantidad_material){
        nombre_material = "metal";
}


//metal saluda
void Metal :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " metale "<<
        "y me encuentro en el casillero consultado"<<endl;
}