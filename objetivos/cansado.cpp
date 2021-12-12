#include "cansado.h"

Cansado::Cansado() : Objetivo() {
    this -> nombre_objetivo = CANSADO;
    this -> descripcion = "Terminar un turno con 0 de energia.";
    this -> identificador = CANSADO;
  //   this -> requisito = REQUISITO_CANSADO;
}

bool Cansado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
  return (energia == REQUISITO_CANSADO);
}

void Cansado::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
  cout<<"deberias consumir "<< energia <<" de energia para completar este  objetivo";
}