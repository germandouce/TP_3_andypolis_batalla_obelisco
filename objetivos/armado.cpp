#include "armado.h"

Armado::Armado() : Objetivo() {
    this -> nombre_objetivo = CONSTRUCTOR;
    this -> descripcion = "Tener 10 bombas en el inventario.";
    this -> identificador = CONSTRUCTOR;
    this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool Armado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia) {
    return inventario->devolver_cant_bombas() == REQUISITO_ARMADO;
}

void Armado :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout << "Te falta sumar " << REQUISITO_ARMADO - inventario -> devolver_cant_bombas()
    <<" en tu innventario para completar este objetivo";

}