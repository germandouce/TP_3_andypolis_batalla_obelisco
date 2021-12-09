#include "menu_principal.h"
#include "menu_nueva_partida.h"
#include <iostream>
//incluir esta fucion siempre.
int elegir_opcion(){
    int opcion;
    std::cout<<"\nIngrese una opcion del menu: ";
    std::cin>> opcion;
    return opcion;
}
//funcionan ambos faltan llenarlos con los metodos segun opcion
int main() {
    presentar_menu();
    int opcion = elegir_opcion();
    if (opcion_valida(opcion))
        procesar_opcion(opcion);
    std::cout<<std::endl;
    presentar_menu_np();
    int opcion_nueva = elegir_opcion();
    if (opcion_valida_np(opcion_nueva))
        procesar_opcion_np(opcion_nueva);
    return 0;
}
