#ifndef MENUS_MENU_PRINCIPAL_H
#define MENUS_MENU_PRINCIPAL_H

#include "..\juego\juego.h"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 13;

const int CONSTRUIR_EDIFICIO_X_NOMBRE = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_EDIFICIO_X_COORDENDA = 3;
const int ATACAR_EDIFICIO_X_COORDENADA = 4;
const int REPARAR_EDIFICIO_X_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 10;
const int MOVERSE_A_UNA_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_Y_SALIR = 13;

//pre: -
//post: Imprime menu en pantalla
void presentar_menu();

//pre: Se debe verificar que la opcion elegida sea valida
//post: Procesa opcion elegida y la ejecuta
void procesar_opcion(int opcion, Juego* juego,Jugador * jug_turno, Jugador * jug_secundario);

//pre: -
//post: Verifica que la opcion elegida sea valida para ejecutar
bool opcion_valida(int opcion);


#endif //MENUS_MENU_PRINCIPAL_H
