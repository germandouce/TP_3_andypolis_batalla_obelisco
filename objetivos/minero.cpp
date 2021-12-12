#include "minero.h"

Minero::Minero(): Objetivo() {
    this -> nombre_objetivo = MINERO;
    this -> descripcion = "Haber construido una mina de cada tipo.";
    this -> identificador = MINERO;
}
bool Minero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    return (registro_edificios->al_menos_una_mina() && registro_edificios->al_menos_una_mina_oro() );
}

void Minero::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te falta construir: "<<endl;
    if (!registro_edificios->al_menos_una_mina()){
        cout<<"una mina";
    }
    if (!registro_edificios->al_menos_una_mina_oro()){
        cout<<"una mina de oro";
    }
}
