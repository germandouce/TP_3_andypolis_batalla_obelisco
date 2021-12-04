
#include "planta_electrica.h"
#include "obelisco.h"
#include "mina.h"
#include "mina_oro.h"
#include "fabrica.h"
#include "escuela.h"
#include "aserradero.h"


int main(){
    Edificio * edificio;
    Edificio * edif;
    edificio = new Escuela(100, 200, 150, 1);
    edif = new Obelisco(100, 180, 200, 1);
    cout<<edif->obtener_diminutivo()<<endl;
    edif->mostrar_mensaje();
    cout << edif->obtener_material_brindado() <<endl;
    cout << edif->obtener_cantidad_brindada() <<endl;
}