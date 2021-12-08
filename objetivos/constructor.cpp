#include "objetivo.h"

Constructor::Constructor(): Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Construir un edificio de cada tipo.";
    this -> identificador = CONSTRUCTOR;
    this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool comprobar_requisito(int cantidad_minas, int cantidad_minas_oro){

}