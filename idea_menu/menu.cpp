#include <iostream>
#include "menu.h"
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}


#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

void mostrar_bienvenida() {
    system("cls");
    cout << "Bienvenido al sistema de construccion de edificios de Andypolis." << endl;
    cout << "El siguiente menu lo guiara a traves de las operaciones disponibles." << endl;
    cout << "Debe ingresar los numeros correspondientes a las operaciones requeridas." << endl;
}

void menu_principal(Jugador* jug_turno, Jugador* jug_secundario) {

    bool repite = true;
    int opcion_elegida;

    const char *titulo = "MENU";
    const char *sub_titulo = "Puede elegir una de las siguiente opciones: ";
    const char *opciones[] = {" Construir edificio por nombre.", " Listar los edificios construidos."," Demoler un edificio por coordenada.",
                              " Atacar un edificio por coordenada.", " Reparar un edificio por coordenada.",
                              " Comprar bombas.",
                              " Consultar coordenada.", " Mostrar inventario.", " Mostrar objetivos.",
                              " Recolectar recursos producidos.",
                              " Moverse a una coordenada.", " Finalizar turno.", " Guardar y salir."};
    int numero_opciones = OPCION_MAXIMA;

    do {
        opcion_elegida= menu(titulo, opciones, numero_opciones, sub_titulo);

        switch (opcion_elegida) {
            case 1:
                system("cls");
                cout << "hola 1" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //verificar_construccion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
                break;
            case 2:
                system("cls");
                cout << "hola 2" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //mostrar_edificios_construidos(vector_edificios, vector_ubicaciones);
                break;
            case 3:
                system("cls");
                cout << "hola 3" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //verificar_demolicion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
                break;
            case 4:
                system("cls");
                cout << "hola 4" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //ATTACAR
                //Pasar coordenada. verificar su existencia en el mapa.
                //Spottear edificio en el mapa.
                //verificar que no sea nuestro
                //Ver tipo y estado de edificio para saber costo de destruccion.
                //Verificar en inventario cant bombas y energía.
                //Atacar (si lo desea el usuario--consultar).
                //Volver al menú.
                break;
            case 5:
                system("cls");
                cout << "hola 5" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //REPARAR
                //Pasar coordenada. verificar su existencia en el mapa.
                //Spottear edificio en el mapa.
                //verificar que no sea nuestro
                //Ver estado de edificio.
                //Verificar en inventario materiales (al menos 25% de c/u requerido) y energía.
                //Reparar (si lo desea el usuario--consultar).
                //Volver al menú.
                break;
            case 6:
                system("cls");
                cout << "hola 6" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //COMPRAR BOMBAS
                //Usuario ingresa cantidad deseada de bombas a comprar.
                //Verificar andycoins.
                //Informar situación al usuario
                //Si se puede comprar preguntar antes de realizar accion.
                //Si el usuario acepta , realizar compra , informar balance final y volver al menu.
                //De lo contrario volver al menu (sin realizar compra).
                break;
            case 7:
                system("cls");
                cout << "hola 7" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //mapa -> consultar_casillero();
                break;
            case 8:
                system("cls");
                cout << "hola 8" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //mostrar_inventario(vector_materiales);
                break;
            case 9:
                system("cls");
                cout << "hola 9" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;

                //Mostrar_objetivos primarios y secudarios.
                //Podemos agregar una tecla que pregunte si desea volver
                //al menú (así se le da el tiempo que necesite para ver su inventario).
                break;
            case 10:
                system("cls");
                cout << "hola 10" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //recolectar_recursos_producidos(vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
                break;
            case 11:
                system("cls");
                cout << "hola 11" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //MOVERSE
                //Matchiar objetivo entero del jugador con ese numero de objetivo en el vector de strings
                //de juego.h y dsps imprimirlo
                //Pedir destino.
                //Verificar caminos mínimos(tener en cuenta que sólo se permiten movimientos aledaños).
                //Verificar energía usuario.
                //Consultar al usuario si desea realizar dicha acción.
                //Marcar camino realizado por el usuario.
                //Volver al menú.
                break;
            case 12:
                system("cls");
                cout << "hola 12" << endl;
                cout << "ENTER PARA VOLVER A MENU" << endl;
                //FINALIZAR TURNO
                //Verifica energía usuario (si E == 0 finaliza turno y avisa al usuario).
                //Consulta antes de realizar acción.
                //Se guarda E no usada. Se le agregan 50 de Energia mientras >100 E. Si E > 100 se pierde la E sobrante.
                jug_turno->
                break;
            case 13:
                system("cls");
                //guardar_materiales(vector_materiales);
                //guardar_ubicaciones(vector_ubicaciones);
                //mapa -> borrar();
                //delete mapa;
                cout << "-Se han guardado exitosamente los cambios efectuados!" << endl;
                cout << "DOBLE ENTER PARA SALIR DEL PROGRAMA" << endl;
                repite = false;
                break;
        }
        cin.get();

    } while(repite);

    cin.get();
}

int menu(const char *titulo, const char *opciones[], int numero_opciones, const char *sub_titulo){
        int opcion_elegida = OPCION_MINIMA;
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