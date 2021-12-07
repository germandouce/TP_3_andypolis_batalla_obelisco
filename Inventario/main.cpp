#include "Inventario.h"
#include <iostream>
#include <fstream>

//PRE: recive los inventarios de amabos jugadores en default.
//POS: procesa el archivo txt materiales.
// caso en que el archivo existe : carga/ actualiza las cantidades de cada elemento en el inventario y devuelve true.
// caso constrario: avisa no existencia del archivo
// elimina los inventarios y devueve false.
bool procesar_archivo_materiales(Inventario*inventario_jugador_1,Inventario* inventario_jugador_2);

bool procesar_archivo_materiales(Inventario*inventario_jugador_1,Inventario* inventario_jugador_2){
    bool inventarios_actualizados;
    std::fstream archivo_materiales(PATH_MATERIALES, std::ios::in);

    if(archivo_materiales.is_open()){

        std::string nombre;
        std::string cantidad_1;
        std::string cantidad_2;

        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad_1;
            archivo_materiales >> cantidad_2;

            if (nombre == "Madera" || nombre == "madera"){
                inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
                inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            }
            else if (nombre == "Piedra" || nombre == "piedra"){
                inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
                inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            }
            else if (nombre == "Metal" || nombre == "metal"){
                inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
                inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            }
            else if (nombre == "Bombas" || nombre == "bombas"){
                inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
                inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            }
            else if (nombre == "Andycoins" || nombre == "andycoins"){
                inventario_jugador_1->cambiar_cantidad_elemento(nombre,stoi(cantidad_1));
                inventario_jugador_2->cambiar_cantidad_elemento(nombre,stoi(cantidad_2));
            }
            inventario_jugador_1->actualizar_cantidad_elementos();
            inventario_jugador_2->actualizar_cantidad_elementos();
        }

        archivo_materiales.close();
        inventarios_actualizados = true;
    }
    else{
        std::cout << "\nNo se encuentra archivo materiales.\n" << std::endl;
        delete inventario_jugador_1;
        delete inventario_jugador_2;
        inventarios_actualizados = false;
    }
    return inventarios_actualizados;
}

int main() {
    Inventario* inventario_jugador_1 = new Inventario();
    Inventario* inventario_jugador_2 = new Inventario();
    if (procesar_archivo_materiales(inventario_jugador_1, inventario_jugador_2)){
        std::cout<<"JUGADOR 1:" << std::endl;
        inventario_jugador_1->mostrar_inventario();
        std::cout<<"JUGADOR 2:" << std::endl;
        inventario_jugador_2->mostrar_inventario();
    }
    else{
        std::cout<< "\nSe eliminaron inventarios de cada jugador.\n" << std::endl;
    }
    //ahora borro los inventarios sólo por la memoria(no hacerlo en esta instancia en el TP).
    delete inventario_jugador_1;
    delete inventario_jugador_2;

    return 0;
}
