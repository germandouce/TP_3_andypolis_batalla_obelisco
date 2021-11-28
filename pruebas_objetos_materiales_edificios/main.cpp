#include <iostream>

// #include "objeto.h"
#include "edificio.h"
#include "mina.h"
#include "aserradero.h"
#include "piedra.h"
#include "material.h"


using namespace std;

int main(){
    //Edificio *edif;
    Objeto *mina_objeto = new Mina(100, 200, 300, 2); 
    Objeto *aserradero_objeto = new Aserradero(100, 200, 300, 2); 

    Objeto* piedrita = new  Piedra (10);

    cout << mina_objeto->obtener_nombre()<<endl;
    cout << aserradero_objeto->obtener_nombre()<<endl;

    cout << mina_objeto->obtener_cantidad_brindada()<<endl;
    cout << aserradero_objeto->obtener_cantidad_brindada()<<endl;

    cout<<"hay: "<<piedrita ->obtener_cantidad()<<" "<<piedrita->obtener_nombre() <<endl;
    
    cout <<piedrita->obtener_nombre() <<" brinda: " << piedrita ->obtener_cantidad_brindada()<<endl;
    cout <<"Hay " <<aserradero_objeto ->obtener_cantidad()<< " "<<aserradero_objeto ->obtener_nombre()<<endl;


    Edificio * edificiote = new Edificio(100, 100, 100, 4);
    cout << edificiote -> obtener_nombre()<< " brinda "<<edificiote -> obtener_cantidad_brindada()<< endl;

    Edificio * mina_edificio = new Mina(100, 100, 100, 4);
    cout << mina_edificio -> obtener_nombre()<< " brinda "<<mina_edificio -> obtener_cantidad_brindada()<< endl;

    return 0;
}  