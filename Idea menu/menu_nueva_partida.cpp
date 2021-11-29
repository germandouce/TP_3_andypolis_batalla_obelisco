#include "menu_nueva_partida.h"
#include "menu.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

void gotoxy(int x, int y);

void mostrar_mensaje_nueva_partida() {
    system("cls");
    cout << "Bienvenido al sistema de construccion de edificios de Andypolis." << endl;
    cout << "Nueva Partida." << endl;//puede ser mejor el mensaje
    cout << "El siguiente menu lo guiara a traves de las operaciones disponibles." << endl;
    cout << "Debe ingresar los numeros correspondientes a las operaciones requeridas." << endl;
}

void menu_nueva_partida() {

    bool repite = true;
    int opcion_elegida;

    const char *titulo = "MENU";
    const char *sub_titulo = "Puede elegir una de las siguiente opciones: ";
    const char *opciones[] = {" Modificar edificio por nombre.", " Listar todos los edificios."," Mostrar mapa.",
                              " Comenzar partida.", " Guardar y salir."};
    int numero_opciones = OPCION_MAXIMA_NP;

    do {
        opcion_elegida= menu_np(titulo, opciones, numero_opciones, sub_titulo);

        switch (opcion_elegida) {
            case 1:
                system("cls");
                cout << "hola 1" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                break;
            case 2:
                system("cls");
                cout << "hola 2" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                break;
            case 3:
                system("cls");
                cout << "hola 3" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                break;
            case 4:
                system("cls");
                cout << "hola 4" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                break;
            case 5:
                system("cls");
                cout << "-Se han guardado exitosamente los cambios efectuados!" << endl;
                cout << "DOBLE ENTER PARA SALIR DEL PROGRAMA" << endl;
                repite = false;
                break;
        }
        cin.get();

    } while(repite);

    cin.get();
}
int menu_np(const char *titulo, const char *opciones[], int numero_opciones, const char *sub_titulo){
    int opcion_elegida = OPCION_MINIMA_NP;
    int tecla;
    bool repite = true;

    do {
        system("cls");

        gotoxy(5, 5 + opcion_elegida); cout << "-->";

        gotoxy(15, 2); cout << titulo;

        gotoxy(10, 4); cout << sub_titulo;

        for (int i = 0; i < numero_opciones; i++) {
            gotoxy(10, 6 + i); cout << i + 1 << ") " << opciones[i];
        }

        do {
            tecla = getch();
        } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

        switch (tecla) {
            case TECLA_ARRIBA:
                opcion_elegida--;

                if (opcion_elegida < 1) {
                    opcion_elegida = numero_opciones;
                }
                break;

            case TECLA_ABAJO:
                opcion_elegida++;

                if (opcion_elegida > numero_opciones) {
                    opcion_elegida = 1;
                }
                break;

            case ENTER:
                repite = false;
                break;
        }

    } while (repite);

    return opcion_elegida;
}
