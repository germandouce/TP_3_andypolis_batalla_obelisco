#ifndef MENU_H
#define MENU_H

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 13;

//pre: -
//post: Imprime un mensaje de bienvenida.
void mostrar_bienvenida();

void gotoxy(int x, int y);

void menu_principal(Jugador* jug_turno, Jugador* jug_secundario);

int menu(const char *titulo, const char *opciones[], int numero_opciones, const char *sub_titulo);
#endif // MENU_H