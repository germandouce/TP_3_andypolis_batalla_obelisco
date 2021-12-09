#include "Inventario.h"
#include <iostream>

using namespace std;

Inventario::Inventario(){
    cantidad_elementos = 0;
    cant_madera = 0;
    cant_piedra = 0;
    cant_metal = 0;
    cant_andycoins = 0;
    cant_bombas = 0;
}

int Inventario::devolver_cant_madera(){
    return cant_madera;
}

int Inventario::devolver_cant_piedra(){
    return cant_piedra;
}

int Inventario::devolver_cant_metal(){
    return cant_metal;
}

int Inventario::devolver_cant_andycoins(){
    return cant_andycoins;
}

int Inventario::devolver_cant_bombas(){
    return cant_bombas;
}

void Inventario::mostrar_inventario() {
    if (cantidad_elementos == 0){
        cout<< "INVENTARIO VACIO" << endl;
        cout << "__________________________________________" << endl << endl;
        cout << "Cantidad madera: " << devolver_cant_madera() << endl;
        cout << "Cantiidad piedra: " << devolver_cant_piedra() << endl;
        cout << "Cantidad metal: " << devolver_cant_metal() << endl;
        cout << "Cantidad andycoins: " << devolver_cant_andycoins() << endl;
        cout << "Cantidad bombas: " << devolver_cant_bombas() << endl;
    }
    else{
        cout << "INVENTARIO" << endl;
        cout << "__________________________________________" << endl << endl;
        cout << "Cantidad madera: " << devolver_cant_madera() << endl;
        cout << "Cantiidad piedra: " << devolver_cant_piedra() << endl;
        cout << "Cantidad metal: " << devolver_cant_metal() << endl;
        cout << "Cantidad andycoins: " << devolver_cant_andycoins() << endl;
        cout << "Cantidad bombas: " << devolver_cant_bombas() << endl;
    }
    cout << endl;
}

void Inventario::cambiar_cantidad_elemento(std::string nombre_elemento, int cantidad_sumar_o_restar) {
    int cantidad_actualizada;
    if (nombre_elemento == "Madera" || nombre_elemento == "madera"){
        if (cantidad_sumar_o_restar < 0 &&  cant_madera < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar *(-1) << " a la cantidad actual de madera. Las cantidades no pueden estar en negativo." << endl;
        }
        else{
            cantidad_actualizada = cant_madera + cantidad_sumar_o_restar;
            cant_madera = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Piedra" || nombre_elemento == "piedra"){
        if (cantidad_sumar_o_restar < 0 &&  cant_piedra < cantidad_sumar_o_restar *(-1) ){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar *(-1) << " a la cantidad actual de piedra. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_piedra + cantidad_sumar_o_restar;
            cant_piedra = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Metal" || nombre_elemento == "metal"){
        if (cantidad_sumar_o_restar < 0  && cant_metal < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar *(-1) << " a la cantidad actual de metal. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_metal + cantidad_sumar_o_restar;
            cant_metal = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Bombas" || nombre_elemento == "bombas"){
        if (cantidad_sumar_o_restar < 0  && cant_bombas < cantidad_sumar_o_restar*(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar *(-1) << " a la cantidad actual de bombas. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_bombas + cantidad_sumar_o_restar;
            cant_bombas = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Andycoins" || nombre_elemento == "andycoins"){
        if (cantidad_sumar_o_restar < 0  && cant_andycoins < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar *(-1) << " a la cantidad actual de andycoins. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_andycoins + cantidad_sumar_o_restar;
            cant_andycoins = cantidad_actualizada;
        }
    }

    else{
        cout<< "No se encuentra " << nombre_elemento << " en el inventario."<< endl;
    }

    cout<< endl;
}

void Inventario::actualizar_largo_de_inventario(){
    cantidad_elementos = cantidad_elementos+1;
}

Inventario::~Inventario(){
}

