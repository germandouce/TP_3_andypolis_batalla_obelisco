#include "objetivo.h"

Objetivo::Objetivo() {
    this -> nombre_objetivo = "";
    this -> descripcion = "";
    this -> identificador = COMPRAR_ANDYPOLIS;
    // this -> requisito = REQUISITO_COMPRAR_ANDYPOLIS;
}

Objetivo::~Objetivo() {}

void Objetivo::mostrar_nombre_objetivo(){
    cout<< nombre_objetivo<<": ";
}

int Objetivo::obtener_identificador(){
    return identificador;
}

void Objetivo::mostrar_descripcion(){
    cout << descripcion<< endl;
}