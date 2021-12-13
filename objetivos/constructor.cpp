#include "constructor.h"

Constructor::Constructor(): Objetivo() {
    this -> nombre_objetivo = CONSTRUCTOR;
    this -> descripcion = "Construir un edificio de cada tipo.";
}

bool Constructor::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return registro_edificios->al_menos_uno_de_cada_tipo();
}

void Constructor::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te faltan construir al menos 1 edificio de cada uno de los siguientes tipos: "<<endl;
    if (registro_edificios->al_menos_una_planta_electrica()){
        cout<<"\tPlanta electrica"<<endl;
    }
    if (registro_edificios->al_menos_una_mina()){
        cout<<"\tAserradero"<<endl;
    }
    if (registro_edificios->al_menos_una_fabrica()){
        cout<<"\tEscuela"<<endl;
    }
    if (registro_edificios->al_menos_una_escuela() ){
        cout<<"\tFabrica"<<endl;
    }
    if (registro_edificios->al_menos_un_aserradero() ){
        cout<<"\tMina"<<endl;
    }
    if (registro_edificios->al_menos_una_mina_oro() ){
        cout<<"\tMina oro\n"<<endl;
    }
}