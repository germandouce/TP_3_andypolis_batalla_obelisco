#include "menu_principal.h"
#include <iostream>

using namespace  std;

void presentar_menu() {
    cout << ENTER_COLOR << "Puede elegir una de las siguiente opciones: " << END_COLOR << endl;
    cout << endl;
    cout << SUCESS_COLOR;
    cout << "1) Construir edificio por nombre." << endl;
    cout << "2) Listar los edificios construidos." << endl;
    cout << "3) Demoler un edificio por coordenada." << endl;
    cout << "4) Atacar un edificio por coordenada." << endl;
    cout << "5) Reparar un edificio por coordenada." << endl;
    cout << "6) Comprar bombas." << endl;
    cout << "7) Consultar coordenada." << endl;
    cout << "8) Mostrar inventario." << endl;
    cout << "9) Mostrar objetivos." << endl;
    cout << "10) Recolectar recursos producidos." << endl;
    cout << "11) Moverse a una coordenada." << endl;
    cout << "12) Finalizar turno." << endl;
    cout << "13) Guardar y salir." << endl;
    cout << END_COLOR;
}

void procesar_opcion(int opcion, Juego* juego, Jugador* jug_turno, Jugador* jug_secundario) {

    //system(CLR_SCREEN);
    Inventario* inventario = jug_turno -> devolver_inventario();

    switch (opcion) {
        case CONSTRUIR_EDIFICIO_X_NOMBRE:
            // system("cls");
            cout << "hola 1" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //verificar_construccion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            // system("cls");
            cout << "hola 2" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //mostrar_edificios_construidos(vector_edificios, vector_ubicaciones);
            break;
        case DEMOLER_EDIFICIO_X_COORDENDA:
           //  system("cls");
            cout << "hola 3" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //verificar_demolicion(mapa, vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            break;
        case ATACAR_EDIFICIO_X_COORDENADA:
            // system("cls");
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
        case REPARAR_EDIFICIO_X_COORDENADA :
            // system("cls");
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
        case COMPRAR_BOMBAS:
           //  system("cls");
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
        case CONSULTAR_COORDENADA:
           //  system("cls");
            cout << "hola 7" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //mapa -> consultar_casillero();
            break;
        case MOSTRAR_INVENTARIO:
           //  system("cls");
            cout << "hola 8" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //mostrar_inventario(vector_materiales);
            break;
        case MOSTRAR_OBJETIVOS:
           //  system("cls");
            cout << "hola 9" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //Mostrar_objetivos primarios y secudarios.
            //Podemos agregar una tecla que pregunte si desea volver
            //al menú (así se le da el tiempo que necesite para ver su inventario).
            break;
        case RECOLECTAR_RECURSOS_PRODUCIDOS:
          //   system("cls");
            cout << "hola 10" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //recolectar_recursos_producidos(vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            break;
        case MOVERSE_A_UNA_COORDENADA:
            juego -> devolver_mapa() -> moverse(inventario, jug_turno);
            break;
        case FINALIZAR_TURNO:
           //  system("cls");
            cout << "hola 12" << endl;
            cout << "ENTER PARA VOLVER A MENU" << endl;
            //FINALIZAR TURNO
            //Verifica energía usuario (si E == 0 finaliza turno y avisa al usuario).
            //Consulta antes de realizar acción.
            //Se guarda E no usada. Se le agregan 50 de Energia mientras >100 E. Si E > 100 se pierde la E sobrante.
            jug_turno->terminar_truno();
            jug_secundario->iniciar_turno();
            break;
        case GUARDAR_Y_SALIR:
           //  system("cls");
            //guardar_materiales(vector_materiales);
            //guardar_ubicaciones(vector_ubicaciones);
            //mapa -> borrar();
            //delete mapa;
            cout << "-Se han guardado exitosamente los cambios efectuados!" << endl;
            cout << "DOBLE ENTER PARA SALIR DEL PROGRAMA" << endl;
            jug_turno->salir_del_juego();
            break;
    }
}

bool opcion_valida(int opcion) {
    return(opcion >= OPCION_MINIMA && opcion <= OPCION_MAXIMA);
}
