#include "bombardero.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = BOMBARDERO;
    this -> descripcion =  "Haber usado 5 bombas";
}

bool Bombardero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios,
Diccionario *diccionario, int energia) {
    if (inventario ->devolver_bombas_usadas() == REQUISITO_BOMBARDERO)
        return true;
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Bombardero :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<< "Te faltan usar " << REQUISITO_BOMBARDERO - inventario->devolver_bombas_usadas();
    cout <<" bombas para completar este objetivo";
}