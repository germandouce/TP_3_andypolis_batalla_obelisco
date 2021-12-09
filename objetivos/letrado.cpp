#include "objetivo.h"

Letrado::Letrado(): Letrado() {
    this -> nombre_objetivo = "Letrado";
    this -> descripcion = "Haber construido el maximo posible de escuelas";
    this -> identificador = LETRADO;
   //  this -> requisito = REQUISITO_LETRADO;
}

bool comprobar_requisito(int cantidad_escuelas_construidas, int cantidad_max_escuelas){
    return (cantidad_escuelas_construidas == cantidad_max_escuelas);
}