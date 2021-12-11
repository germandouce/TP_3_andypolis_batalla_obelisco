#include "./menus/menu_nueva_partida.h"
#include "./menus/menu_principal.h"
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

    bool nueva_partida = true;
    int archivos_cargados = 0;

    juego -> leer_archivos(mapa, archivos_cargados, nueva_partida, jug_1, jug_2);

    if (archivos_cargados == CONTINUAR_PARTIDA) {
        
        bool alguien_gano = false;
        bool quiere_salir = false;
        bool quiere_terminar_turno = false;
        bool sin_energia = false;
        
        if (nueva_partida) {

            int opcion_elegida;
            
            system(CLR_SCREEN);
            while (opcion_elegida != COMENZAR_PARTIDA) {

                presentar_menu_np();

                cin >> opcion_elegida;
                cin.clear();
                cin.ignore(100, '\n');

                while (!opcion_valida_np(opcion_elegida)) {
                    cout << ERROR_COLOR << "Opcion no valida. Eliga nuevamente." << END_COLOR << endl;
                    cin >> opcion_elegida;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                procesar_opcion_np(juego, opcion_elegida);
            }

            juego -> posicionar_jugadores(jug_1, jug_2, mapa);
        }

        Jugador* jug_turno;
        Jugador* jug_secundario;        

        jug_turno = jug_2;
        jug_secundario = jug_1;

        int turnos_sin_llover = 0;
        mapa->llover();
        while (!alguien_gano && !quiere_salir){
            
            alguien_gano = false;
            quiere_salir = false;
            quiere_terminar_turno = false;
            sin_energia = false;
        
            if (jug_1 -> es_su_turno()) { 
                jug_turno = jug_1;
                jug_secundario = jug_2;
            }
            else {
                jug_turno = jug_2;
                jug_secundario = jug_1;
            } 

            cout <<"TURNO DEL JUGADOR "<< jug_turno-> devolver_numero_jugador() <<endl;
            
            
            turnos_sin_llover++;
            if (turnos_sin_llover == (2 + 1)){
                mapa -> llover();
                turnos_sin_llover = 0;
            }

            //comienzo de turno
            while (!alguien_gano && !sin_energia && !quiere_terminar_turno && !quiere_salir) {
                
                int opcion;

                //system(CLR_SCREEN);
                mapa -> imprimir_mapa();
                presentar_menu();

                cin >> opcion;
                cin.clear();
                cin.ignore(100, '\n');

                while (!opcion_valida(opcion)) {
                    cout << "Opcion no valida. Eliga nuevamente." << endl;
                    cin >> opcion;
                    cin.clear();
                    cin.ignore(100, '\n');
                }

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
