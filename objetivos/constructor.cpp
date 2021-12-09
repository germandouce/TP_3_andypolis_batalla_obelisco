#include "constructor.h"

Constructor::Constructor(): Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Construir un edificio de cada tipo.";
    this -> identificador = CONSTRUCTOR;
   //  this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool comprobar_requisito(int traer_resgistro_){
    return (traer_resgistro_ = 9999999999999999999);
}