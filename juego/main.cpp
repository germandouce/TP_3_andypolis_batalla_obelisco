#include ".\menu_nueva_partida.h"
#include ".\menu.h"
#include ".\juego.h"

int main() {

    Juego *juego = new Juego();

    Jugador *jug_1 = new Jugador();
    Jugador *jug_2 = new Jugador();
    
    ifstream archivo;

    bool mapa_bien_cargado = false;
    bool diccionario_edificios_bien_cargado = false;
    bool inventario_bien_cargado = false;

    if (juego -> es_archivo_legible(archivo, ARCHIVO_MAPA) ){
        //mapa->cargar_mapa(archivo,ARCHIVO_MAPA)
        mapa_bien_cargado = true;
    }

    if (juego -> es_archivo_legible(archivo, ARCHIVO_EDIFICIOS) ){
        //registro_edificios->cargar_edificios(archivo, jug_1, jug_2);
        bool diccionario_edificios_bien_cargado = true;
    }

    if (juego -> es_archivo_legible(archivo, ARCHIVO_MATERIALES) ){
        //registro_edificios->cargar_edificios(archivo, jug_1, jug_2);
        bool inventario_bien_cargado = true;
    }

    bool nueva_partida = false;
  
    nueva_partida = !( juego -> es_archivo_legible(archivo, ARCHIVO_UBICACIONES) );
    
    if (mapa_bien_cargado || diccionario_edificios_bien_cargado || inventario_bien_cargado) {
    
        if (nueva_partida ){
            menu_nueva_partida();
        }else{
            juego -> cargar_ubicaciones(archivo, jug_1, jug_2);
        }
        
        juego->crear_juego(jug_1, jug_2);
        menu_principal();

    }
    else{
        cout<<"No se pudo abrir uno de sus archivos";
    }


    
    return 0;
}
