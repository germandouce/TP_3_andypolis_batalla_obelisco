
#include "piedra.h"
#include "metal.h"
#include "madera.h"
#include "bombas.h"
#include "andycoins.h"

int main(){
    Material * material;
    Material * mate;
    material = new Madera(10);
    mate = new Andycoins(10);
    cout<<mate->obtener_diminutivo()<<endl;
    mate->sumar_cantidad(100);
    mate->saludar();
}