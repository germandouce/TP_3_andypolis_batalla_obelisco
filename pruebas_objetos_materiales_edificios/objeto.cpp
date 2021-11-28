#include "objeto.h"

Objeto::Objeto(){
    this-> nombre = "objeto";
    this-> diminutivo = "";
    // this-> cantidad_objeto =1;
    // this-> cantidad_piedra = 0;
    // this-> canitdad_madera = 0;
    // this-> cantidad_metal = 0;
    // this-> brinda = 0;
    // this-> maximo_construir = 0;
}

Objeto :: ~Objeto(){

}
// Objeto::Objeto(string nombre, int cantidad_objeto, string diminutivo){
//     this-> nombre = "objeto";
//     this-> cantidad_objeto =1;
//     this-> diminutivo = "";
//     this-> cantidad_piedra = 0;
//     this-> canitdad_madera = 0;
//     this-> cantidad_metal = 0;
//     this-> brinda = 0;
//     this-> maximo_construir = 0;
// }


// int Edificio::obtener_cantidad_piedra(){
//     return cantidad_piedra;
// }
// int Edificio::obtener_cantidad_madera(){
//     return canitdad_madera;
// }
// int Edificio::obtener_cantidad_metal(){
//     return cantidad_metal;
// }

// int Edificio::obtener_cantidad_construidos(){
//     return cantidad_edificios;
// }

// int Edificio::obtener_maximo_construir(){
//     return maximo_construir;
// }

// int Edificio::obtener_mitad_madera(){
//     return canitdad_madera/2;
// }

// int Edificio::obtener_mitad_piedra(){
//     return cantidad_piedra/2;
// }

// int Edificio::obtener_mitad_metal(){
//     return cantidad_metal/2;
// }

// int Edificio::obtener_cuantos_puedo_construir(){
//     int restantes = maximo_construir - cantidad_edificios ;
//     return restantes;
// }

// void Edificio::sumar_cantidad(){
//     cantidad_edificios++ ;
// }

// void Edificio::restar_cantidad(){
//     cantidad_edificios-- ;
// }

// Edificio::~Edificio(){}