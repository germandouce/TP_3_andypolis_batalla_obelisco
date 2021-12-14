#include "edificio.h"

Edificio::Edificio() {
    this-> nombre = "edificio";
    this-> diminutivo = "";
    this-> cantidad_piedra = 0;
    this-> cantidad_madera = 0;
    this-> cantidad_metal = 0;
    this-> brinda = 0;
    this-> maximo_construir = 0;
    this->vida_actual =0;
    this->vida_maxima =0;
    this->fila=0;
    this->columna=0;
}

Edificio::Edificio(int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_construir, int fila, int columna) {
    this-> nombre = "";
    this-> diminutivo = "Ed";
    this-> cantidad_piedra = cantidad_piedra;
    this-> cantidad_madera = cantidad_madera;
    this-> cantidad_metal = cantidad_metal;
    this-> brinda = 0;
    this-> maximo_construir = maximo_construir;
    this->vida_actual =0;
    this->vida_maxima =0;
} 

string Edificio::obtener_nombre(){
    return nombre;
}

string Edificio::obtener_diminutivo(){
    return diminutivo;
}

int Edificio::obtener_cantidad_piedra(){
    return cantidad_piedra;
}

int Edificio::obtener_cantidad_madera(){
    return cantidad_madera;
}

int Edificio::obtener_cantidad_metal(){
    return cantidad_metal;
}

int Edificio::obtener_cantidad_brindada(){
    return brinda;
}

int Edificio::obtener_maximo_construir(){
    return maximo_construir;
}

int Edificio::obtener_mitad_madera(){
    return cantidad_madera/2;
}

int Edificio::obtener_mitad_piedra(){
    return cantidad_piedra/2;
}

int Edificio::obtener_mitad_metal(){
    return cantidad_metal/2;
}

int Edificio::obtener_vida_actual(){
    return vida_actual;
}

void Edificio:: daniar(){
    vida_actual--;
}

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

    cout << ENTER_COLOR << "Se requieren los siguientes materiales para construir un/a '" << nombre << "': " << END_COLOR;
    cout << SUCESS_COLOR << endl;
    cout << "-" << cantidad_piedra << " unidades de piedra." << endl;
    cout << "-" << cantidad_madera << " unidades de madera." << endl;
    cout << "-" << cantidad_metal << " unidades de metal." << endl;
    cout << endl;
    
    if (diminutivo != "O") {
        cout << "-Produce " << brinda << " de " << obtener_material_brindado() << " cuando se recolecta." << endl;
    }

    cout << "-Se pueden construir un maximo de " << maximo_construir << "." << END_COLOR << endl;
    cout << endl;
}

void Edificio::asignar_fila(int fila) {
    this -> fila = fila;
}

void Edificio::asignar_columna(int columna) {
    this -> columna = columna;
}

int Edificio::obtener_fila() {
    return fila;
}

int Edificio::obtener_columna() {
    return columna;
}


void Edificio::modificar_cantidad_piedra(){
        int nueva_cantidad_piedra;
    
        cout << SUCESS_COLOR << "El costo anterior de piedra es de " << cantidad_piedra << "." << END_COLOR << endl;
        cout << endl;
        cout << ENTER_COLOR << "Ingrese el nuevo costo de piedra deseado: " << END_COLOR << endl;
        
        cin >> nueva_cantidad_piedra;
        if (verificacion_cantidades(nueva_cantidad_piedra)){
            cantidad_piedra = nueva_cantidad_piedra;
        }
          else{
              cout << "La cantidad ingresada no es valida." << endl;
              cout << "El intervalo valido es: (" << MAX_MATERIAL <<" ," << MIN_MATERIAL <<" )" << endl;
          }
        
        cantidad_piedra = nueva_cantidad_piedra;

}

void Edificio::modificar_cantidad_madera(){
        int nueva_cantidad_madera;
    
        cout << SUCESS_COLOR << "El costo anterior de madera es de " << cantidad_madera << "." << END_COLOR << endl;
        cout << endl;
        cout << ENTER_COLOR << "Ingrese el nuevo costo de madera deseado: " << END_COLOR << endl;
        
        cin >> nueva_cantidad_madera;
        if (verificacion_cantidades(nueva_cantidad_madera)){
            cantidad_madera = nueva_cantidad_madera;
        }
          else{
              cout << "La cantidad ingresada no es valida." << endl;
              cout << "El intervalo valido es: (" << MAX_MATERIAL <<" ," << MIN_MATERIAL <<" )" << endl;
          }
        
        cantidad_madera = nueva_cantidad_madera;

}

void Edificio::modificar_cantidad_metal(){
        int nueva_cantidad_metal;
    
        cout << SUCESS_COLOR << "El costo anterior de metal es de " << cantidad_metal << "." << END_COLOR << endl;
        cout << endl;
        cout << ENTER_COLOR << "Ingrese el nuevo costo de metal deseado: " << END_COLOR << endl;
        
        cin >> nueva_cantidad_metal;
        if (verificacion_cantidades(nueva_cantidad_metal)){
            cantidad_metal = nueva_cantidad_metal;
        }
          else{
              cout << "La cantidad ingresada no es valida." << endl;
              cout << "El intervalo valido es: (" << MAX_MATERIAL <<" ," << MIN_MATERIAL <<" )" << endl;
          }
        
        cantidad_metal = nueva_cantidad_metal;

}

bool Edificio::verificacion_cantidades(int cantidad_verificar){
    return (MAX_MATERIAL > cantidad_verificar && cantidad_verificar > MIN_MATERIAL);

}

void Edificio::modificar_cantidades_edificio() {
    
    system(CLR_SCREEN);

    if (diminutivo != OBELISCO) {
        
        modificar_cantidad_piedra();
        modificar_cantidad_madera();
        modificar_cantidad_metal();

        cout << SUCESS_COLOR << "Se han modificado los valores correctamente!" << END_COLOR << endl;
        cout << endl;
    }
    else {
        cout << ERROR_COLOR << "El obelisco no es un edificio modificable." << END_COLOR << endl;
        cout << endl;
    }
}

int Edificio::restar_vida(int vida_sacada){
	return (vida_actual -= vida_sacada);
}

Edificio::~Edificio() {}