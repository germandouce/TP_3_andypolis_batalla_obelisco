#include "madera.h"

Madera :: Madera(int cantidad_material) : Material(cantidad_material){
        nombre_material = "madera";
        diminutivo = "W";
}

void Madera :: saludar(){
        cout << "Soy un paquete de "<<cantidad_material << " maderas "<<
        "y me encuentro en el casillero consultado"<<endl;
}