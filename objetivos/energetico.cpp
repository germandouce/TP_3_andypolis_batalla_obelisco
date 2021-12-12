#include "energetico.h"

Energetico::Energetico(): Objetivo() {
    this -> nombre_objetivo = ENERGETICO;
    this -> descripcion = "Terminar un turno con 100 de energia.";
    this -> identificador = ENERGETICO;
   //  this -> requisito = REQUISITO_ENERGETICO;
}

bool Energetico::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    energia == REQUISITO_ENERGETICO;
}

void Energetico::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te falta recuperar "<<REQUISITO_ENERGETICO - energia <<" de energia para cumplir este objetivo";
}