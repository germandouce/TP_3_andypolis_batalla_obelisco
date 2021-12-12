#include "letrado.h"

Letrado::Letrado(): Objetivo() {
    this -> nombre_objetivo = LETRADO;
    this -> descripcion = "Haber construido el maximo posible de escuelas";
}

bool Letrado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
   return diccionario->buscar_edificio("escuela")->obtener_maximo_construir() == registro_edificios->obtener_cantidad_escuelas();
}

void Letrado::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    int faltan = diccionario->buscar_edificio("escuela")->obtener_maximo_construir() - registro_edificios->obtener_cantidad_escuelas();
    cout<<"Te falta construir "<<faltan<<" escuelas para cumplir este objetivo";
}