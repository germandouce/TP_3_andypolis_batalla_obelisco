#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis() : Objetivo() {
    this -> nombre_objetivo = "Comprar Andypolis";
    this -> descripcion = "Haber juntado 100000 Andycoins a lo largo de la partida.";
    this -> identificador = COMPRAR_ANDYPOLIS;
  //   this -> requisito = REQUISITO_COMPRAR_ANDYPOLIS;
}

bool Comprar_andypolis::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
	//return (ineventario->cantidad_acumulada_andycoins() == REQUISITO_COMPRAR_ANDYPOLIS);
}

void Comprar_andypolis::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
	//cout<< "Te falta obtener " REQUISITO_COMPRAR_ANDYPOLIS - (ineventario->cantidad_acumulada_andycoins());
}