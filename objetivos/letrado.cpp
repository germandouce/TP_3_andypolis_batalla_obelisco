#include "letrado.h"

Letrado::Letrado(): Objetivo() {
    this -> nombre_objetivo = "Letrado";
    this -> descripcion = "Haber construido el maximo posible de escuelas";
    this -> identificador = LETRADO;
   //  this -> requisito = REQUISITO_LETRADO;
}

bool Letrado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios){
    return true;
}