#include "constructor.h"

Constructor::Constructor(): Objetivo() {
    this -> nombre_objetivo = "Extremista";
    this -> descripcion = "Construir un edificio de cada tipo.";
    this -> identificador = CONSTRUCTOR;
   //  this -> requisito = REQUISITO_CONSTRUCTOR;
}

bool Constructor::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return registro_edificios->al_menos_uno_de_cada_tipo_construidos();
}

void Constructor::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te faltan construir al menos 1 edificio de cada uno de los siguientes tipos: "<<endl;
    if (! registro_edificios->obtener_cantidad_plantas_electricas()){
        cout<<"Planta electrica"<<endl;
    }
    if (! registro_edificios->obtener_cantidad_aserraderos()){
        cout<<"Aserradero"<<endl;
    }
    if (! registro_edificios->obtener_cantidad_escuelas()){
        cout<<"Escuela"<<endl;
    }
    if (! registro_edificios->obtener_cantidad_fabricas()){
        cout<<"Fabrica"<<endl;
    }
    if (! registro_edificios->obtener_cantidad_minas()){
        cout<<"Mina"<<endl;
    }
    if (! registro_edificios->obtener_cantidad_minas_oro() ){
        cout<<"Mina oro"<<endl;
    }
}