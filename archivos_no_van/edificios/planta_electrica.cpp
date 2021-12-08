#include "planta_electrica.h"

Planta_electrica::Planta_electrica(int piedra, int madera, int metal, int maximo) : Edificio( piedra, madera, metal, maximo){
    this->nombre = "planta electrica";
    this->diminutivo = "P";
    this->brinda = 15;
    this->vida_actual = 1;
    this->vida_maxima = 1;
}

void Planta_electrica::mostrar_mensaje(){
    cout << " Soy una " << nombre << "brindo " <<brinda<<" de energia y me encuentro en el casillero consultado"<< endl;
}

string Planta_electrica::obtener_material_brindado(){
    return "energia";
}