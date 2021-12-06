#include "Inventario.h"
#include <iostream>

int main() {
    Inventario Inventario_1;
    std::cout << "ANTES DE PROCESAR ARCHIVO. DEBERIA MOSTRARME EL INVENTARIO DEFAULT.\n"<< std::endl;
    Inventario_1.mostrar_inventario();
    Inventario_1.procesar_archivo_materiales();
    std::cout << "LUEGO DE PROCESAR ARCHIVO. NO ME DERÍA MOSTRAR EL INVENTARIO DEFAULT\n(EN ESTE CASO SE QUE EXISTE EL ARCHIVO)\n"<< std::endl;
    Inventario_1.mostrar_inventario();
    Inventario_1.cambiar_cantidad_elemento("bombas", 90);
    std::cout << "suma bombas"<<std::endl;
    Inventario_1.cambiar_cantidad_elemento("metal", 80);
    std::cout << "suma metal\n"<<std::endl;
    Inventario_1.mostrar_inventario();
    Inventario_1.cambiar_cantidad_elemento("casa", 100);
    Inventario_1.cambiar_cantidad_elemento("metal", -1000);
    Inventario_1.cambiar_cantidad_elemento("piedra", 30);
    std::cout << "suma piedra"<<std::endl;
    Inventario_1.cambiar_cantidad_elemento("bombas", -40);
    std::cout << "resta bombas\n"<<std::endl;
    Inventario_1.mostrar_inventario();
    std::string opcion;
    std::cout<< "Para salir presionar cualquier tecla."<<std::endl;
    std::cin >> opcion;
    return 0;
}
