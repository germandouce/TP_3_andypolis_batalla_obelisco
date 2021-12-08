#ifndef UNTITLED_MENU_NUEVA_PARTIDA_H
#define UNTITLED_MENU_NUEVA_PARTIDA_H
#include "menu.h"

const int OPCION_MINIMA_NP = 1;
const int OPCION_MAXIMA_NP = 5;

//pre: -
//post: Imprime un mensaje de nueva partida.
void mostrar_mensaje_nueva_partida();

void gotoxy(int x, int y);

void menu_nueva_partida();

int menu_np(const char *titulo, const char *opciones[], int numero_opciones, const char *sub_titulo);

#endif //UNTITLED_MENU_NUEVA_PARTIDA_H
