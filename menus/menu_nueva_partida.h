#ifndef MENUS_MENU_NUEVA_PARTIDA_H
#define MENUS_MENU_NUEVA_PARTIDA_H

const int OPCION_MINIMA_NP = 0;
const int OPCION_MAXIMA_NP = 5;

const int MODIFICAR_EDIFICIO_X_NOMBRE = 1;
const int LISTAR_TODOS_LOS_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_SALIR = 5;

//pre: -
//post: Imprime menu en pantalla
void presentar_menu_np();

//pre: Se debe verificar que la opcion elegida sea valida
//post: Procesa opcion elegida y la ejecuta
void procesar_opcion_np(int opcion);

//pre: -
//post: Verifica que la opcion elegida sea valida para ejecutar
bool opcion_valida_np(int opcion);

//pre: El valor ingresado debe ser de tipo entero.
//post: Pide ingresar un valor entero para asignarno a la opcion y retorna la misma.
int elegir_opcion();
#endif //MENUS_MENU_NUEVA_PARTIDA_H
