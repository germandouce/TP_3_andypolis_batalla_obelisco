#include "extremista.h"

Extremista::Extremista() : Objetivo() {
    this -> nombre_objetivo = EXTREMISTA;
    this -> descripcion = "Haber comprado 500 bombas en una partida.";
    this -> identificador = EXTREMISTA;
   //  this -> requisito = REQUISITO_EXTREMISTA;
}

bool Extremista::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return inventario->devolver_cant_anterior_bombas() == REQUISITO_EXTREMISTA ;
}

void Extremista::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<< "Te falta obetener "<< REQUISITO_ENERGETICO - inventario->devolver_cant_anterior_bombas()
    <<" bombas para cumplir este objetivo";
}