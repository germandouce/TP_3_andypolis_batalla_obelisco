#include "extremista.h"

Extremista::Extremista() : Objetivo() {
    this -> nombre_objetivo = EXTREMISTA;
    this -> descripcion = "Haber comprado 500 bombas en una partida.";
}

bool Extremista::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    if (inventario->devolver_cant_bombas_compradas() == REQUISITO_EXTREMISTA) {
        cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
        return true;
    }
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Extremista::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<< "Te falta obetener "<< REQUISITO_ENERGETICO - inventario->devolver_cant_bombas_compradas()
    <<" bombas para cumplir este objetivo.\n"<<endl;
}