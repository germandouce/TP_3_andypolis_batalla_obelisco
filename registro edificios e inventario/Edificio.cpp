#include "Edificio.h"

Edificio::Edificio() {
    this->nombre = "nada";
    this->nombre = "edificio";
    this->diminutivo = "";
    this->cantidad_piedra = 0;
    this->canitdad_madera = 0;
    this->cantidad_metal = 0;
    int coordenada_x=0;
    int coordenada_y=0;
    //this-> cantidad_edificios = 0;
    // this-> cantidad_edificios = 0;
    this->brinda = 0;
    this->maximo_construir = 0;
    this->vida_actual = 0;
}

Edificio::Edificio( int cantidad_piedra, int cantidad_madera, int cantidad_metal,int coordenada_x, int coordenada_y,  int maximo_construir, int brinda , int vida_actual, int vida_maxima){

    this-> cantidad_piedra = cantidad_piedra;
    this-> canitdad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this -> coordenada_x = coordenada_x;
    this-> coordenada_y = coordenada_y;
    //this-> cantidad_edificios = 0;
    // this-> cantidad_edificios = 0;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this->vida_actual =0;
}

string Edificio::obtener_diminutivo() {
    string diminutivo;
    for (int i = 0 ; i<3;i++){
        diminutivo [i] = nombre[i];
        i++;
    }
    return  diminutivo;
}

int Edificio::obtener_cantidad_piedra() {
    return cantidad_piedra;
}

int Edificio::obtener_cantidad_madera() {
    return canitdad_madera;
}

int Edificio::obtener_cantidad_metal() {
    return cantidad_metal;
}


int Edificio::obtener_coordenada_x() {
    return coordenada_x;
}

int Edificio::obtener_coordenada_y() {
    return coordenada_y;
}

int Edificio::obtener_cantidad_brindada() {
    return brinda;
}

int Edificio::obtener_maximo_construir() {
    return maximo_construir;
}

int Edificio::obtener_mitad_metal() {
    return cantidad_metal / 2;
}

int Edificio::obtener_cuantos_puedo_construir() {
    return  maximo_construir;
}
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


void Edificio::daniar() {
    vida_actual--;
}
bool Edificio::edificio_en_pie() {
    return (vida_actual > 0);
}
void Edificio::reparar() {
    if (vida_actual == vida_maxima) {
        cout << "El edificio no requiere reparacion" << endl;
    } else {
        vida_actual++;
        cout << "Se reparo el edificio " << nombre << " corretamente";
    }
}
Edificio::~Edificio(){;
        }