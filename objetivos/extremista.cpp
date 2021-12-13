#include "extremista.h"

Extremista::Extremista() : Objetivo() {
    this -> nombre_objetivo = EXTREMISTA;
    this -> descripcion = "Haber comprado 500 bombas en una partida.";
}

bool Extremista::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    //return inventario->devolver_cant_acumuladas_bombas() == REQUISITO_EXTREMISTA ;
    return true;
}

void Extremista::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    // cout<< "Te falta obetener "<< REQUISITO_ENERGETICO - inventario->devolver_cant_acumuladas_bombas()
    // <<" bombas para cumplir este objetivo"<<endl;
    cout<< "Te falta obetener "<< REQUISITO_ENERGETICO - 2<<endl;
    cout <<" FUNCION JOSE\n"<<endl;
}