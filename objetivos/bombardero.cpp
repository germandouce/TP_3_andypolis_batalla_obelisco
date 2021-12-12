#include "bombardero.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = BOMBARDERO;
    this -> descripcion =  "Haber usado 5 bombas";
}

bool Bombardero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios,
Diccionario *diccionario, int energia) {
    return inventario ->devolver_cant_anterior_bombas() == REQUISITO_BOMBARDERO;
}

void Bombardero :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<< "Te faltan comprar " << REQUISITO_BOMBARDERO - inventario->devolver_cant_anterior_bombas()
    <<" bombas para completar este objetivo";
}