#include ".\menu_nueva_partida.h"
#include ".\menu.h"
#include ".\juego.h"

int main() {

    bool archivo_ubicaciones_vacio = 1;
    bool archivo_ubicaciones_existe =1;


    if ( (archivo_ubicaciones_vacio || !archivo_ubicaciones_existe) ){
        
        menu_nueva_partida();

    }else{
        menu_principal();
    }
    
    return 0;
}
