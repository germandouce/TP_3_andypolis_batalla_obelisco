#include "objetivo.h"

Objetivo::Objetivo() {}

Comprar_andypolis::Comprar_andypolis() : Objetivo() {
    this -> nombre_objetivo = "Comprar Andypolis";
    this -> descripcion = "";
    this -> identificador = COMPRAR_ANDYPOLIS;
    this -> requisito = REQUISITO_COMPRAR_ANDYPOLIS;
}

