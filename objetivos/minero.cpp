#include "minero.h"

Minero::Minero(): Objetivo() {
    this -> nombre_objetivo = "Minero";
    this -> descripcion = "Haber construido una mina de cada tipo.";
    this -> identificador = MINERO;
   //  this -> requisito = REQUISITO_MINERO;
}
bool Minero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return true;
}

void Minero::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    diccionario -> buscar_edificio("mina")->obtener_maximo_construir();
}
