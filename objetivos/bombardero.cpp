#include "bombardero.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = "Bombardero";
    this -> descripcion =  "haber usado 5 bombas";
    this -> identificador = BOMBARDERO;
    this -> requisito = REQUISITO_BOMBARDERO;
}

bool Bombardero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios) {
    //return true;
}