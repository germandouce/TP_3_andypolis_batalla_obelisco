#include "objetivo.h"

Objetivo::Objetivo() {
    this -> nombre_objetivo = "";
    this -> descripcion = "";
}

Objetivo::~Objetivo() {}

void Objetivo::mostrar_nombre_objetivo(){
    cout<< SUCESS_COLOR << "--> " << nombre_objetivo<<": " << END_COLOR;
}

void Objetivo::mostrar_descripcion(){
    cout << SUCESS_COLOR << descripcion<< END_COLOR << endl;
}