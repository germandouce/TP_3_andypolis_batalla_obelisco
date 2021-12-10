#include "objetivo.h"

Armado::Armado() : Objetivo() {
    this -> nombre_objetivo = "Constructor";
    this -> descripcion = "Tener 10 bombas en el inventario.";
    this -> identificador = CONSTRUCTOR;
    this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool comprobar_requisito(int cantidad_bombas_actuales) {
    return (cantidad_bombas_actuales == REQUISITO_ARMADO);
}