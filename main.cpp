#include ".\menus\menu_nueva_partida.h"
#include ".\menus\menu_principal.h"
#include <iostream>

using namespace std;

int main() {
    
    srand((unsigned)time(NULL)); // Semilla para generar números aleatorios.

    Juego *juego = new Juego();

    juego -> cargar_objetivos();
    
    juego -> crear_juego();

    Mapa* mapa;

    Jugador* jug_1 = juego-> devolver_jugador_1();
    Jugador* jug_2 = juego -> devolver_jugador_2();

    ifstream archivo;

    bool mapa_bien_cargado = false;
    bool nueva_partida = true;
    bool diccionario_edificios_bien_cargado = false;
    bool inventario_bien_cargado = true;

    if (juego -> es_archivo_legible(archivo, ARCHIVO_MAPA)) {
        juego -> devolver_mapa() -> cargar_mapa(archivo);
        mapa = juego -> devolver_mapa();  
        mapa_bien_cargado = true;
    }

    if (juego -> es_archivo_legible(archivo, ARCHIVO_EDIFICIOS)) {
        juego -> cargar_diccionario(archivo);
        diccionario_edificios_bien_cargado = true;
    }

    if (juego -> es_archivo_legible(archivo, ARCHIVO_UBICACIONES)) {
        juego -> cargar_ubicaciones(archivo);
        nueva_partida = false;
    }

    if (!nueva_partida) {
        if (juego -> es_archivo_legible(archivo, ARCHIVO_MATERIALES)) {
            juego -> cargar_inventario(archivo);
            inventario_bien_cargado = true;
        }
    }

    if (mapa_bien_cargado && diccionario_edificios_bien_cargado && inventario_bien_cargado) {
        
        bool alguien_gano = false;
        bool quiere_salir = false;
        bool quiere_terminar_turno = false;
        bool sin_energia = false;
        
        if (nueva_partida) {
                
            int ingreso;
            int opcion_elegida;

            presentar_menu_np();

            cin >> opcion_elegida;
            cin.clear();
            cin.ignore(100, '\n');

            while (!opcion_valida_np(opcion_elegida)) {
                cout << "Opcion no valida. Eliga nuevamente." << endl;
                cin >> opcion_elegida;
                cin.clear();
                cin.ignore(100, '\n');
            }

            procesar_opcion_np(juego, opcion_elegida);
            
            cout << "Desea ser jugador 1 o 2 ? (ingrese 1 o 2): ";
            cin >> ingreso;
            cout << endl;

            jug_1 -> pedir_coordenadas();
            jug_2 -> pedir_coordenadas();

            int fila1 = jug_1 -> devolver_fila() - 1;
            int columna1 = jug_1 -> devolver_columna() - 1;

            int fila2 = jug_2 -> devolver_fila() - 1;
            int columna2 = jug_2 -> devolver_columna() - 1;
             
            mapa -> obtener_casillero(fila1, columna1) -> ocupar_jugador1();
            mapa -> obtener_casillero(fila2, columna2) -> ocupar_jugador2();

        }else{
            //juego -> cargar_ubicaciones(archivo);
        }

        cout << alguien_gano <<sin_energia <<quiere_salir <<quiere_terminar_turno <<endl;

        Jugador* jug_turno;
        Jugador* jug_secundario;        

        jug_turno = jug_2;
        jug_secundario = jug_1;

        while (!alguien_gano && !quiere_salir){
            
            alguien_gano = false;
            quiere_salir = false;
            quiere_terminar_turno = false;
            sin_energia = false;
        
            if ( jug_1->es_su_turno() ){ // turnos impares puese si el resto es 0 == false
                jug_turno = jug_1;
                jug_secundario = jug_2;
            }
            else{ //turnos pares
                jug_turno = jug_2;
                jug_secundario = jug_1;

            } 
            //sin_energia = false;
            cout <<"\nTURNO DE JUGADOR "<< jug_turno-> devolver_numero_jugador() <<endl;
            //cout << alguien_gano <<sin_energia <<quiere_salir <<quiere_terminar_turno <<endl;
            
            while( !alguien_gano && !sin_energia && !quiere_terminar_turno && !quiere_salir ){
                //cout <<"\nOLAAAA "<< jug_turno-> devolver_numero_jugador() <<endl;
                
                int opcion;

                //system(CLR_SCREEN);
                mapa -> imprimir_mapa();
                presentar_menu();

                cin >> opcion;
                while (!opcion_valida(opcion)){
                    cout<<"Opcion no valida. Eliga nuevamente." <<endl;
                    cin>>opcion;} // ahi estan los 2 hechos
                procesar_opcion(opcion ,juego, jug_turno, jug_secundario);
                
                sin_energia = jug_turno ->esta_sin_energia();
                alguien_gano = jug_turno ->gano();
                quiere_salir = jug_turno -> quiere_salir_del_juego();
                quiere_terminar_turno = ! ( jug_turno -> es_su_turno() );
            }
        } 
        cout<< "Has ganado "<< jug_turno -> devolver_numero_jugador() <<endl;
    }else{
        cout<<"No se pudieron abrir uno o varios archivos ";
    
    }  
    delete juego;
    delete jug_1;
    delete jug_2;

    return 0;
}