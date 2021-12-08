#include <iostream>
#include "menu.h"
#include "ctime"

using namespace std;

int main() {

    srand((unsigned)time(NULL)); // Semilla para generar números aleatorios.
    
    Mapa* mapa = new Mapa();
    
    int opcion_elegida;

    if (!(mapa -> se_cargo_terreno() && mapa -> se_cargo_diccionario())) {
        return 0;
    }
    
    mostrar_bienvenida();

    do {
        mostrar_menu();
        cin >> opcion_elegida;
        cin.clear();
        cin.ignore(100, '\n');

        while (!es_opcion_valida(opcion_elegida)) {
            system(CLR_SCREEN);
            cout << ERROR_COLOR << "La opcion elegida es invalida. Intente de nuevo." << END_COLOR << endl;
            cout << endl;
            mostrar_menu();
            cin >> opcion_elegida;
            cin.clear();
            cin.ignore(100, '\n');
        }

        procesar_opcion(opcion_elegida, mapa);
        
    } while (opcion_elegida != 10);

    return 0;
}