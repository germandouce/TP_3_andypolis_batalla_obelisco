#include "bombardero.h"

Bombardero::Bombardero() : Objetivo() {
    this -> nombre_objetivo = "Bombardero";
    this -> descripcion =  "Haber usado 5 bombas";
    this -> identificador = BOMBARDERO;
    this -> requisito = REQUISITO_BOMBARDERO;
}

bool Bombardero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios,
Diccionario *diccionario, int energia) {
    //return inventario -> obtener_cantidad_de_bombas_usadas() == REQUISITO_BOMBARDERO;
}

void Bombardero :: mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    // cout<< "Te faltan comprar " << REQUISITO_BOMBARDERO - inventario -> obtener_cantidad_de_bombas_usadas()
    // <<" bombas para completar este objetivo";
}