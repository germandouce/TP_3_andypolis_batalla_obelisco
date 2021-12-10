#include "constructor.h"

Constructor::Constructor(): Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Construir un edificio de cada tipo.";
    this -> identificador = CONSTRUCTOR;
   //  this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool Constructor::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios){
    // return (traer_resgistro_ == 9999999999999999999);
}