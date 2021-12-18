#include "armado.h"

Armado::Armado() : Objetivo() {
    this -> nombre_objetivo = ARMADO;
    this -> descripcion = "Tener 10 bombas en el inventario.";
}

bool Armado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
    if (inventario->devolver_cant_bombas() >= REQUISITO_ARMADO) {
        cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
        return true;
    }
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Armado :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    int cant_bombas_invt = inventario -> devolver_cant_bombas();
    if (cant_bombas_invt < REQUISITO_ARMADO){
        cout << "Te falta sumar " << REQUISITO_ARMADO - cant_bombas_invt
             <<" en tu innventario para completar este objetivo\n";
    }
}