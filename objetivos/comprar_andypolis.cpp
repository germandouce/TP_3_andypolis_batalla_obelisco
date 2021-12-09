#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis() : Objetivo() {
    this -> nombre_objetivo = "Comprar Andypolis";
    this -> descripcion = "Haber juntado 100000 Andycoins a lo largo de la partida.";
    this -> identificador = COMPRAR_ANDYPOLIS;
  //   this -> requisito = REQUISITO_COMPRAR_ANDYPOLIS;
}

bool comprobar_requisito(int cantidad_andycoins_acumulados){
    return ( cantidad_andycoins_acumulados == 100000);
}