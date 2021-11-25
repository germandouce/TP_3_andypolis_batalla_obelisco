#include <iostream>
#include "menu.h"

void mostrar_bienvenida() {
    system(CLR_SCREEN);
    cout << SUCESS_COLOR;
    cout << "Bienvenido al sistema de construccion de edificios de Andypolis." << endl;
    cout << "El siguiente menu lo guiara a traves de las operaciones disponibles." << endl;
    cout << "Debe ingresar los numeros correspondientes a las operaciones requeridas." << endl;
    cout << END_COLOR << endl; 
}

void mostrar_menu() {
    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;
    cout << "1. Construir edificio por nombre." << endl;
    cout << "2. Listar los edificios construidos." << endl;
    cout << "3. Demoler un edificio por coordenada." << endl;
    cout << "4. Atacar un edificio por coordenada." << endl;
    cout << "5. Reparar un edificio por coordenada." << endl;
    cout << "6. Comprar bombas." << endl;
    cout << "7. Consultar coordenada." << endl;
    cout << "8. Mostrar inventario." << endl;
    cout << "9. Mostrar objetivos." << endl;
    cout << "10. Recolectar recursos producidos." << endl;
    cout << "11. Moverse a una coordenada." << endl;
    cout << "12. Finalizar turno." << endl;
    cout << "13. Guardar y salir." << endl;
    cout << END_COLOR;
}

void procesar_opcion(int opcion_elegida, Mapa* &mapa, Vector<Material> &vector_materiales, Vector<Edificio> &vector_edificios, Vector<Ubicacion> &vector_ubicaciones) {

    int posiciones_materiales[MATERIALES_UTILIZADOS_EDIFICIOS];
    cargar_posicion_material_edificios(vector_materiales, posiciones_materiales);

    switch (opcion_elegida) {
        case 1:
            system(CLR_SCREEN);
            verificar_construccion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            cout << endl;
            break;
        case 2:
            system(CLR_SCREEN);
            mostrar_edificios_construidos(vector_edificios, vector_ubicaciones);
            break;
        case 3:
            system(CLR_SCREEN);
            verificar_demolicion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            cout << endl;
            break;
        case 4:
            system(CLR_SCREEN);
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
            system(CLR_SCREEN);
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
            system(CLR_SCREEN);
            //COMPRAR BOMBAS
            //Usuario ingresa cantidad deseada de bombas a comprar.
            //Verificar andycoins.
            //Informar situación al usuario
            //Si se puede comprar preguntar antes de realizar accion.
            //Si el usuario acepta , realizar compra , informar balance final y volver al menu.
            //De lo contrario volver al menu (sin realizar compra).
            break;
        case 7:
            system(CLR_SCREEN);
            mapa -> consultar_casillero();
            break;
        case 8:
            system(CLR_SCREEN);
            mostrar_inventario(vector_materiales);
            break;
        case 9:
            system(CLR_SCREEN);
            //Mostrar_objetivos primarios y secudarios.
            //Podemos agregar una tecla que pregunte si desea volver 
            //al menú (así se le da el tiempo que necesite para ver su inventario).
            break;
        case 10:
            system(CLR_SCREEN);
            recolectar_recursos_producidos(vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            cout << endl;
            break;
        case 11:
            system(CLR_SCREEN);
            //MOVERSE
            //Pedir destino.
            //Verificar caminos mínimos(tener en cuenta que sólo se permiten movimientos aledaños).
            //Verificar energía usuario.
            //Consultar al usuario si desea realizar dicha acción.
            //Marcar camino realizado por el usuario.
            //Volver al menú.
            break;
        case 12:
            system(CLR_SCREEN);
            //FINALIZAR TURNO
            //Verifica energía usuario (si E == 0 finaliza turno y avisa al usuario).
            //Consulta antes de realizar acción.
            //Se guarda E no usada. Se le agregan 50 de Energia mientras >100 E. Si E > 100 se pierde la E sobrante.
            break;
        case 13:
            system(CLR_SCREEN);
            guardar_materiales(vector_materiales);
            guardar_ubicaciones(vector_ubicaciones);
            mapa -> borrar();
            delete mapa;
            cout << SUCESS_COLOR << "-Se han guardado exitosamente los cambios efectuados!" << END_COLOR << endl;
    }
}

bool es_opcion_valida(int opcion_elegida) {
    return (opcion_elegida >= OPCION_MINIMA && opcion_elegida <= OPCION_MAXIMA);
}