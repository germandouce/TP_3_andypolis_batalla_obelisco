#include "comprar_andypolis.h"

Comprar_andypolis::Comprar_andypolis() : Objetivo() {
    this -> nombre_objetivo = COMPRAR_ANDYPOLIS;
    this -> descripcion = "Haber juntado 100000 Andycoins a lo largo de la partida.";
}

bool Comprar_andypolis::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
	if (inventario->devolver_cant_acumulada_andycoins()  >= REQUISITO_COMPRAR_ANDYPOLIS)
        return true;
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Comprar_andypolis::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
	cout<< "Te falta obtener "<< REQUISITO_COMPRAR_ANDYPOLIS - (inventario->devolver_cant_acumulada_andycoins())<<endl;
}