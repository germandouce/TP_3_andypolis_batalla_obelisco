#include "edad_piedra.h"

Edad_piedra::Edad_piedra() : Objetivo() {
    this -> nombre_objetivo = EDAD_PIEDRA;
    this -> descripcion = "Tener en el inventario 50000 piedras";
}

bool Edad_piedra::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    if(inventario->devolver_cant_piedra() >= REQUISITO_EDAD_PIEDRA)
        return true;
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Edad_piedra::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te faltan obetener "<< REQUISITO_EDAD_PIEDRA - inventario->devolver_cant_piedra() 
    <<" piedras para cumplir este objetivo\n"<<endl;
}