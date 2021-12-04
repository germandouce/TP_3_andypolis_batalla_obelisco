#include "edificio.h"

Edificio::Edificio(){
    this-> nombre = "edificio";
<<<<<<< HEAD
    this-> diminutivo = "";
    this-> cantidad_piedra = 0;
    this-> cantidad_madera = 0;
=======
    this-> diminutivo = "-";
    this-> cantidad_piedra = 0;
    this-> canitdad_madera = 0;
>>>>>>> release
    this-> cantidad_metal = 0;
    // this-> cantidad_edificios = 0;
    this-> brinda = 0;
    this-> maximo_construir = 0;
    this->vida_actual =0;
    this->vida_maxima =0;
}

Edificio::Edificio( int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir){
<<<<<<< HEAD
    this-> nombre = "";
    this-> diminutivo = "Ed";
    this-> cantidad_piedra = cantidad_piedra;
    this-> cantidad_madera = cantidad_madera;
=======
    this-> nombre = "-`";
    this-> diminutivo = "-";
    this-> cantidad_piedra = cantidad_piedra;
    this-> canitdad_madera = cantidad_madera;
>>>>>>> release
    this-> cantidad_metal = cantidad_metal;
    // this-> cantidad_edificios = 0;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this->vida_actual =0;
    this->vida_maxima =0;
} 

string Edificio::obtener_nombre(){
    return nombre;
}

<<<<<<< HEAD
string Edificio::obtener_diminutivo(){
=======
const char* Edificio::obtener_diminutivo(){
>>>>>>> release
    return diminutivo;
}

int Edificio::obtener_cantidad_piedra(){
    return cantidad_piedra;
}

int Edificio::obtener_cantidad_madera(){
<<<<<<< HEAD
    return cantidad_madera;
=======
    return canitdad_madera;
>>>>>>> release
}

int Edificio::obtener_cantidad_metal(){
    return cantidad_metal;
}

int Edificio::obtener_cantidad_brindada(){
    return brinda;
}

// int Edificio::obtener_cantidad_construidos(){
//     return cantidad_edificios;
// }

int Edificio::obtener_maximo_construir(){
    return maximo_construir;
}

int Edificio::obtener_mitad_madera(){
<<<<<<< HEAD
    return cantidad_madera/2;
=======
    return canitdad_madera/2;
>>>>>>> release
}

int Edificio::obtener_mitad_piedra(){
    return cantidad_piedra/2;
}

int Edificio::obtener_mitad_metal(){
    return cantidad_metal/2;
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

void Edificio:: daniar(){
    vida_actual--;
}

<<<<<<< HEAD
bool Edificio:: edificio_en_pie() {
    return (vida_actual > 0);
}

void Edificio::reparar() {
    if (vida_actual == vida_maxima) {
        cout << "El edificio no requiere reparacion" << endl;
    }
    else {
        vida_actual++;
        cout << "Se reparo el edificio "<< nombre <<" correctamente";
    }
}

void Edificio::mostrar_toda_informacion() {

    cout << ENTER_COLOR;
    cout << "Se requieren los siguientes materiales para construir un/a '" << nombre << "': ";
    cout << END_COLOR << endl;

    cout << SUCESS_COLOR;
    cout << "-" << cantidad_piedra << " unidades de piedra." << endl;
    cout << "-" << cantidad_madera << " unidades de madera." << endl;
    cout << "-" << cantidad_metal << " unidades de metal." << endl;
    cout << endl;
    
    if (diminutivo != "O") {
        cout << "-Produce " << brinda << " de " << obtener_material_brindado() << " cuando se recolecta." << endl;
    }
    
    cout << SUCESS_COLOR << "-Construidos: " << "???" << "/";
    cout << obtener_maximo_construir() << "." << endl;
    cout << END_COLOR << endl;
}

Edificio::~Edificio() {}
=======
bool Edificio:: edificio_en_pie(){
    return (vida_actual > 0);
}

void Edificio::reparar(){
    if (vida_actual == vida_maxima){
        cout <<"El edificio no requiere reparacion"<<endl;
    }
    else{
        vida_actual++;
        cout<<"Se reparo el edificio "<<nombre<<" corretamente";
    }
}

int Edificio::obtener_posicion_x(){
    return posicion_x;
}

int Edificio::obtener_posicion_y(){
    return posicion_y;
}

Edificio::~Edificio(){}

>>>>>>> release
