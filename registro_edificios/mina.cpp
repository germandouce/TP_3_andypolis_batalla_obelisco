#include "mina.h"

Mina::Mina(int piedra, int madera, int metal, int maximo,  int fila, int columna) : 
Edificio(piedra, madera, metal, maximo, fila, columna){
    this->nombre = "mina";
    this->diminutivo = "M";
    this->brinda = 15;
    this->vida_actual = 2;
    this->vida_maxima = 2;
    this->fila = fila;
    this->columna = columna;
}

void Mina::mostrar_mensaje(){
    cout << " Soy una " << nombre << " brindo " << brinda << " piedras y me encuentro en el casillero consultado." << endl;
}

string Mina::obtener_material_brindado(){
    return "piedra";
}