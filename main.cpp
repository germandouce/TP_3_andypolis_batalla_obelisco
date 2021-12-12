#include "./menus/menu_nueva_partida.h"
#include "./menus/menu_principal.h"
#include <iostream>

using namespace std;

int main() {
    
    srand((unsigned)time(NULL)); // Semilla para generar números aleatorios.
    Juego* juego = new Juego();
    juego -> cargar_objetivos();
    juego -> crear_juego();

    bool nueva_partida = true;
    int archivos_cargados = 0;

    juego -> leer_archivos(archivos_cargados, nueva_partida);

    if (archivos_cargados == CONTINUAR_PARTIDA) {     
        if (nueva_partida) {
            juego -> elegir_opcion_menu_np();
        }

        juego -> llover();
        juego -> jugar_partida();
    }
    else {
        cout << "No se pudieron abrir uno o varios archivos." << endl;;
    }  

    delete juego;
    return 0;
}