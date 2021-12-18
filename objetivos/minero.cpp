#include "minero.h"

Minero::Minero(): Objetivo() {
    this -> nombre_objetivo = MINERO;
    this -> descripcion = "Haber construido una mina de cada tipo.";
}
bool Minero::comprobar_requisito(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    if(registro_edificios->al_menos_una_mina() && registro_edificios->al_menos_una_mina_oro()) {
        cout << SUCESS_COLOR << "COMPLETADO" << END_COLOR << endl;
        return true;
    }
    else{
        cout << ERROR_COLOR << "NO COMPLETADO" << END_COLOR << endl;
        return false;
    }
}

void Minero::mostrar_progreso(Inventario* inventario, Registro_edificios* registro_edificios, 
Diccionario *diccionario, int energia){
    cout<<"Te falta construir: "<<endl;
    if (!registro_edificios->al_menos_una_mina()){
        cout<<"\tuna mina"<<endl;
    }
    if (!registro_edificios->al_menos_una_mina_oro()){
        cout<<"\tuna mina de oro\n"<<endl;
    }
}
