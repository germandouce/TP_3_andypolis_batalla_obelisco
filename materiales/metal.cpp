#include "metal.h"

Metal :: Metal(int cantidad_material) : Material(cantidad_material){
        nombre_material = "metal";
        diminutivo = "I";
}

void Metal :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " metales "<<
        "y me encuentro en el casillero consultado"<<endl;
}