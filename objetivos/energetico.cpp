#include "energetico.h"

Energetico::Energetico(): Objetivo() {
    this -> nombre_objetivo = "Energetico";
    this -> descripcion = "Terminar un turno con 100 de energia.";
    this -> identificador = ENERGETICO;
   //  this -> requisito = REQUISITO_ENERGETICO;
}

bool Energetico::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return true;
}