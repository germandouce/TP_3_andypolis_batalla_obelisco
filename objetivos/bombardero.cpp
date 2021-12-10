#include "objetivo.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = "Bombardero";
    this -> descripcion =  "haber usado 5 bombas";
    this -> identificador = BOMBARDERO;
  //   this -> requisito = REQUISITO_BOMBARDERO;
}

bool comprobar_requisito(int cantidad_bombas_usadas) {
    return(cantidad_bombas_usadas == 5 );
}