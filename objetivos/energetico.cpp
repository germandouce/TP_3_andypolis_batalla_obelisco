#include "energetico.h"

Energetico::Energetico(): Objetivo() {
    this -> nombre_objetivo = "Energetico";
    this -> descripcion = "Terminar un turno con 100 de energia.";
    this -> identificador = ENERGETICO;
   //  this -> requisito = REQUISITO_ENERGETICO;
}

bool comprobar_requisito(int energia){
    return( energia == 100);
}