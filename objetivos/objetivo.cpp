#include "objetivo.h"

Objetivo::Objetivo() {
    this -> nombre_objetivo = "";
    this -> descripcion = "";
}

Objetivo::~Objetivo() {}

void Objetivo::mostrar_nombre_objetivo(){
    cout<< nombre_objetivo<<": ";
}

void Objetivo::mostrar_descripcion(){
    cout << descripcion<< endl;
}