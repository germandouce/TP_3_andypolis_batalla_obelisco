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
    Registro_edificios* Registro_edificios = jug_turno-> devolver_resgitro_edificios();
    
    Casillero***mapa = juego-> devolver_mapa()->devolver_matriz();
    
    Diccionario * diccionario = juego->devolver_diccionario();
    
    switch (opcion) {
        case CONSTRUIR_EDIFICIO_X_NOMBRE:
            jug_turno->opcion_construir_edificio_x_nombre(diccionario,mapa);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            jug_turno->devolver_resgitro_edificios()->mostrar_registro_edificios();
            break;
        case DEMOLER_EDIFICIO_X_COORDENDA:
            //system("cls");
            break;
        case ATACAR_EDIFICIO_X_COORDENADA:
            // system("cls");
            //ATTACAR
            //Pasar coordenada. verificar su existencia en el mapa.
            //Spottear edificio en el mapa.
            //verificar que no sea nuestro
            //Ver tipo y estado de edificio para saber costo de destruccion.
            //Verificar en inventario cant bombas y energia.
            //Atacar (si lo desea el usuario--consultar).
            //Volver al menu.
            break;
        case REPARAR_EDIFICIO_X_COORDENADA :
            // system("cls");
            //REPARAR
            //Pasar coordenada. verificar su existencia en el mapa.
            //Spottear edificio en el mapa.
            //verificar que no sea nuestro
            //Ver estado de edificio.
            //Verificar en inventario materiales (al menos 25% de c/u requerido) y energia.
            //Reparar (si lo desea el usuario--consultar).
            //Volver al menu.
            break;
        case COMPRAR_BOMBAS:
           //  system("cls");
            //COMPRAR BOMBAS
            //Usuario ingresa cantidad deseada de bombas a comprar.
            //Verificar andycoins.
            //Informar situacion al usuario
            //Si se puede comprar preguntar antes de realizar accion.
            //Si el usuario acepta , realizar compra , informar balance final y volver al menu.
            //De lo contrario volver al menu (sin realizar compra).
            break;
        case CONSULTAR_COORDENADA:
           //  system("cls");
            //mapa -> consultar_casillero();
            break;
        case MOSTRAR_INVENTARIO:
            jug_turno -> devolver_inventario() -> mostrar_inventario();
            break;
        case MOSTRAR_OBJETIVOS:
           //system("cls");
            jug_turno -> mostrar_objetivos();
            //Podemos agregar una tecla que pregunte si desea volver
            //al menu (asa se le da el tiempo que necesite para ver su inventario).
        case RECOLECTAR_RECURSOS_PRODUCIDOS:
          //   system("cls");
            juego -> devolver_mapa() -> llover();
            //recolectar_recursos_producidos(vector_materiales, vector_edificios, vector_ubicaciones, posiciones_materiales);
            break;
        case MOVERSE_A_UNA_COORDENADA:
            juego -> devolver_mapa() -> moverse(inventario, jug_turno);
            break;
        case FINALIZAR_TURNO:
           //  system("cls");
            //FINALIZAR TURNO
            //Verifica energia usuario (si E == 0 finaliza turno y avisa al usuario).
            //Consulta antes de realizar accion.
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
            jug_turno->salir_del_juego();
            break;
    }
}

bool opcion_valida(int opcion) {
    return(opcion >= OPCION_MINIMA && opcion <= OPCION_MAXIMA);
}