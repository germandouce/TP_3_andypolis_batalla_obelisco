#include ".\idea menu\menu_nueva_partida.h"
#include "menu.h"
#include "juego.h"

int main() {

    Juego *juego = new Juego();
    
    Jugador *jug_1 = new Jugador();
    Jugador *jug_2 = new Jugador();

    juego -> crear_juego(jug_1, jug_2);

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

        int turno = 1;
        
        if (nueva_partida ){
            int ingreso;
            menu_nueva_partida();
            cout<<"Desea ser jugador 1 o 2 ? (ingrese 1 o 2)"<<endl;
            cin >> ingreso;
            jug_1 -> pedir_coordenadas();
            jug_2 -> pedir_coordenadas();

        }else{
            juego -> cargar_ubicaciones(archivo, jug_1, jug_2);
        }

        Jugador* jug_turno;
        Jugador* jug_secundario;
        
        bool alguien_gano = false;
        bool sin_energia = false;
        bool alguien_quiere_salir = false;

        while (!alguien_gano && !alguien_quiere_salir){
        
            if ( turno%2 ){ // turnos impares puese si el resto es 0 == false
                jug_turno = jug_1;
                jug_secundario = jug_2;
            }
            else{ //turnos pares
                jug_turno = jug_2;
                jug_secundario = jug_1;
            } 
        
            while( !alguien_gano && !sin_energia && !alguien_quiere_salir ){

                //menu_principal(Jugador* jug_turno, Jugador *jug_secundario);
            
                sin_energia = jug_turno ->sin_energia();
                alguien_gano = jug_turno->gano();
                alguien_quiere_salir = jug_turno ->quiere_salir_del_juego();
            }
            turno ++;
        }
    }else{
        cout<<"No se pudieron abrir uno o varios archivos ";
    
    }  

    return 0;
}
