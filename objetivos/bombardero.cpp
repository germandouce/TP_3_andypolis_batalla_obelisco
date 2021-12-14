#include "bombardero.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = BOMBARDERO;
    this -> descripcion =  "Haber usado 5 bombas";
}

bool Bombardero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios,
Diccionario *diccionario, int energia) {
    return inventario ->devolver_bombas_usadas() == REQUISITO_BOMBARDERO;
    return true;
}

void Bombardero :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<< "Te faltan usar " << REQUISITO_BOMBARDERO - inventario->devolver_bombas_usadas();
    cout <<" bombas para completar este objetivo";
}