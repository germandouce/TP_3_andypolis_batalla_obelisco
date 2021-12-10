#include "extremista.h"

Extremista::Extremista() : Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Haber comprado 500 bombas en una partida.";
    this -> identificador = EXTREMISTA;
   //  this -> requisito = REQUISITO_EXTREMISTA;
}

bool Extremista::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios){
    // return (bombas_compradas == 500);
   // return true
}