#include "objetivo.h"

Extremista::Extremista() : Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Haber comprado 500 bombas en una partida.";
    this -> identificador = EXTREMISTA;
   //  this -> requisito = REQUISITO_EXTREMISTA;
}

bool Extremista::comprobar_requisito(int bombas_compradas){
    return (bombas_compradas == 500);
}