#include "energetico.h"

Energetico::Energetico(): Objetivo() {
    this -> nombre_objetivo = ENERGETICO;
    this -> descripcion = "Terminar un turno con 100 de energia.";
}

bool Energetico::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return (energia == REQUISITO_ENERGETICO);
}

void Energetico::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te falta recuperar "<<REQUISITO_ENERGETICO - energia <<" de energia para cumplir este objetivo\n"<<endl;
}