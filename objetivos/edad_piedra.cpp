#include "edad_piedra.h"

Edad_piedra::Edad_piedra() : Objetivo() {
    this -> nombre_objetivo = "Edad de piedra";
    this -> descripcion = "Tener en el inventario 50000 piedras";
    this -> identificador = EDAD_PIEDRA;
   //  this -> requisito = REQUISITO_EDAD_PIEDRA;
}

bool comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios){
    //return (cantidad_piedras_en_inventario == 5000);
}