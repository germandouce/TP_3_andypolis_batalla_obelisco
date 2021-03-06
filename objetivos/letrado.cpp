#include "letrado.h"

Letrado::Letrado(): Objetivo() {
    this -> nombre_objetivo = LETRADO;
    this -> descripcion = "Haber construido el maximo posible de escuelas";
}

bool Letrado::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
   if (diccionario->buscar_edificio("escuela")->obtener_maximo_construir() == registro_edificios->obtener_cantidad_escuelas()) {
       cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
       return true;
   }
   else{
       cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
       return false;
   }
}

void Letrado::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    int faltan = diccionario->buscar_edificio("escuela")->obtener_maximo_construir() - registro_edificios->obtener_cantidad_escuelas();
    cout<<"Te falta construir "<<faltan<<" escuelas para cumplir este objetivo\n"<<endl;
}