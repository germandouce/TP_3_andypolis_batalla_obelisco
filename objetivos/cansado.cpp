#include "cansado.h"

Cansado::Cansado() : Objetivo() {
    this -> nombre_objetivo = CANSADO;
    this -> descripcion = "Terminar un turno con 0 de energia.";
}

bool Cansado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
  if(energia == REQUISITO_CANSADO){
      cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
      return true;
  }
  else{
      cout << ERROR_COLOR << "COMPLETADO" << END_COLOR << endl;
      return false;
  }
}

void Cansado::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
  cout<<"deberias consumir "<< energia <<" de energia para completar este objetivo\n"<<endl;
}