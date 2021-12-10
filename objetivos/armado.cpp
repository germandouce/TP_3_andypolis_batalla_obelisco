#include "armado.h"

Armado::Armado() : Objetivo() {
    this -> nombre_objetivo = "Constructor";
    this -> descripcion = "Tener 10 bombas en el inventario.";
    this -> identificador = CONSTRUCTOR;
    this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool Armado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios) {
    return true;
}