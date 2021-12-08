#include "objetivo.h"

Objetivo::Objetivo(){
    this -> nombre_objetivo = "";
    this -> descripcion = "";
    this -> identificador = COMPRAR_ANDYPOLIS;
    this -> requisito = REQUISITO_COMPRAR_ANDYPOLIS;
}

Objetivo::~Objetivo(){

}

int Objetivo::obtener_identificador(){
    return this -> identificador;
}

void Objetivo::mostrar_descripcion(){
    cout << descripcion<< endl;
}





