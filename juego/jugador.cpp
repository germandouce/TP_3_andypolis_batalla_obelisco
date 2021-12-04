#include "jugador.h"


Jugador::Jugador(){

    this -> numero_jugador = 0;

    // this -> Vector<Material>* inventario;
    // this -> Vector<Objetivo>* objetivos;
    // this -> Vector<Edificio>* edificios;
    this -> objetivos_secundarios_cumplidos;
    this -> energia = 50;
    this -> andycoins_acumulados = 0;
    //this -> bombas_usadas;
    this -> bombas_compradas = 0;
}

void Jugador::setear_numero_jugador(int numero_jugador){
    this -> numero_jugador = numero_jugador;
}

void Jugador::asignar_objetivos(int numero_random){
    this -> vector_obejtivos
}




// Jugador::Jugador(Vector<Material>* inventario){
    
// }



// void Jugador::verificar_objetivos(int escuelas_construidas, int cantidad_minas, int distintos_edificios) {

//     for (int i = 0; i < objetivos.obtener_largo(); i++) {
        
//         Objetivo objetivo = objetivos[i];
//         int identificador = objetivo.obtener_identificador();

//         switch identificador {
//             case COMPRAR_ANDYPOLIS:
            
//                 if (objetivo.comprobar_requisito(andycoins_acumulados)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case EDAD_PIEDRA:

//                 if (objetivo.comprobar_requisito(inventario[PIEDRA])) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case BOMBARDERO:

//                 if (objetivo.comprobar_requisito(bombas_usadas)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case ENERGETICO:

//                 if (objetivo.comprobar_requisito(energia)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case LETRADO:

//                 if (objetivo.comprobar_requisito(escuelas_construidas)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case MINERO:

//                 if (objetivo.comprobar_requisito(cantidad_minas)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case CANSADO:

//                 if (objetivo.comprobar_requisito(energia)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case CONSTRUCTOR:

//                 if (objetivo.comprobar_requisito(distintos_edificios)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case ARMARDO:

//                 if (objetivo.comprobar_requisito(inventario[BOMBAS])) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;

//             case EXTREMISTA:

//                 if (objetivo.comprobar_requisito(bombas_compradas)) {
//                     objetivos_secundarios_cumplidos++;
//                 }
//                 break;  
//             }
//     }
// }
