#include "objetivo.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = "Bombardero";
    this -> descripcion =  "haber usado 5 bombas";
    this -> identificador = BOMBARDERO;
    this -> requisito = REQUISITO_BOMBARDERO;
}

bool comprobar_requisito(int cantidad_minas, int cantidad_minas_oro){

}