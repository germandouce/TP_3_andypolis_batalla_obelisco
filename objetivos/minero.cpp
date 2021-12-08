#include "objetivo.h"

Minero::Minero(): Objetivo() {
    this -> nombre_objetivo = "Minero";
    this -> descripcion = "Haber construido una mina de cada tipo.";
    this -> identificador = MINERO;
    this -> requisito = REQUISITO_MINERO;
}
bool comprobar_requisito(int cantidad_minas, int cantidad_minas_oro){

}

