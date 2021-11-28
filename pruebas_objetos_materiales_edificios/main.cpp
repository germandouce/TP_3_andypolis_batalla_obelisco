
// #include "objeto.h"
// #include "edificio.h"
#include "mina.h"
#include "aserradero.h"
#include "piedra.h"
// #include "material.h"


using namespace std;

int main(){
    //Edificio *edif;
    Objeto *mina_objeto = new Mina(100, 200, 300, 2); 
    Objeto *aserradero_objeto = new Aserradero(100, 200, 300, 2); 

    // Objeto *objetote = new Objeto()

    Objeto* piedrita = new  Piedra (10);

    cout << mina_objeto->obtener_nombre()<<endl;
    cout << aserradero_objeto->obtener_nombre()<<endl;

    cout << mina_objeto->obtener_cantidad()<<endl;
    cout << aserradero_objeto->obtener_cantidad()<<endl;

    Edificio * aserradero_edif = new Aserradero(100, 100, 100, 4);
    cout << aserradero_edif -> obtener_nombre()<< " brinda "<<aserradero_edif -> obtener_cantidad_brindada()<< endl;

    Edificio * mina_edificio = new Mina(100, 100, 100, 4);
    cout << mina_edificio -> obtener_nombre()<< " brinda "<<mina_edificio -> obtener_cantidad_brindada()<< endl;

    mina_objeto->saludar();
    aserradero_objeto->saludar();
    aserradero_edif->saludar();
    mina_edificio->saludar();
    piedrita->saludar();


    return 0;
}  