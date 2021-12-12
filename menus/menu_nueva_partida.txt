#include "menu_nueva_partida.h"
#include "menu_principal.h"
#include <iostream>

using namespace  std;

void presentar_menu_np() {

    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;
    cout << "1) Modificar edificio por nombre." << endl;
    cout << "2) Listar todos los edificios." << endl;
    cout << "3) Mostrar mapa." << endl;
    cout << "4) Comenzar partida." << endl;
    cout << "5) Guardar y salir." << endl;
    cout << END_COLOR;
}

void procesar_opcion_np(Juego* juego, int opcion) {

    switch (opcion) {
        case MODIFICAR_EDIFICIO_X_NOMBRE:
            juego -> devolver_diccionario() -> modificar_valores_edificios();
            cout<<"ENTER PARA VOLVER AL MENU"<<endl;
            cin.get();
            break;
        case LISTAR_TODOS_LOS_EDIFICIOS:
            system(CLR_SCREEN);
            juego -> devolver_diccionario() -> mostrar_todos_edificios();
            break;
        case MOSTRAR_MAPA:
            juego -> devolver_mapa() -> imprimir_mapa();
            break;
        case COMENZAR_PARTIDA:
            break;
        case GUARDAR_SALIR:
            //system("cls");
            break;
    }
}

bool opcion_valida_np(int opcion) {
    return(opcion >= OPCION_MINIMA_NP && opcion <= OPCION_MAXIMA_NP);
}