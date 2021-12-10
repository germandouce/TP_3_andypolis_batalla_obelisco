#include "cansado.h"

Cansado::Cansado() : Objetivo() {
    this -> nombre_objetivo = "Cansado";
    this -> descripcion = "Terminar un turno con 0 de energia.";
    this -> identificador = CANSADO;
  //   this -> requisito = REQUISITO_CANSADO;
}

bool Cansado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios) {
	//return true;
}