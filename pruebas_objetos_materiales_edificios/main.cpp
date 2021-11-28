#include <iostream>

// #include "objeto.h"
//#include "edificio.h"
#include "mina.h"
#include "aserradero.h"

using namespace std;

int main(){
    //Edificio *edif;
    Objeto *edif = new Mina(100, 200, 300, 2); 
    Objeto *edif_2 = new Aserradero(100, 200, 300, 2); 
    //minita = new Mina(100, 200, 300, 2);
   //Objeto mina_1 = Mina(100, 200, 300, 2);
   //bjeto edif_1 = Edificio(100, 200, 300, 2) 
   //Edificio edif();
    cout << edif->obtener_nombre()<<endl;
    cout << edif_2->obtener_nombre()<<endl;

    cout << edif->obtener_cantidad_brindada()<<endl;
    cout << edif_2->obtener_cantidad_brindada()<<endl;

    return 0;
}  