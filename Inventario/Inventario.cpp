#include "Inventario.h"
#include <fstream>
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


void Inventario::procesar_archivo_materiales(){
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(archivo_materiales.is_open()){

        string nombre;
        string cantidad;

        while(archivo_materiales >> nombre){
            archivo_materiales >> cantidad;

            if (nombre == "Madera" || nombre == "madera")//verificar como está en archivo
                cant_madera = cant_madera + stoi(cantidad);
            else if (nombre == "Piedra" || nombre == "piedra")
                cant_piedra = cant_piedra + stoi(cantidad);
            else if (nombre == "Metal" || nombre == "metal")
                cant_metal = cant_metal + stoi(cantidad);
            else if (nombre == "Bombas" || nombre == "bombas")
                cant_bombas = cant_bombas + stoi(cantidad);
            else if (nombre == "Andycoins" || nombre == "andycoins")
                cant_andycoins = cant_andycoins + stoi(cantidad);

            cantidad_elementos++;
        }

        archivo_materiales.close();
    }
    else{
        cout << "\nNo se encuentra archivo materiales.\n" << endl;
        cout << "Se creará un archivo materiales.txt con todas las cantidades en 0." << endl;
        crear_archivo_faltante();
        cantidad_elementos = 5;
    }
}

void Inventario::crear_archivo_faltante(){
    ofstream file;
    file.open("C:\\Users\\FacuNano\\Desktop\\Inventario\\materiales.txt");
    file << "Madera 0" << endl;
    file << "Piedra 0" << endl;
    file << "Metal 0" << endl;
    file << "Andycoins 0" << endl;
    file << "Bombas 0" << endl;
    file.close();
}

void Inventario::cambiar_cantidad_elemento(std::string nombre_elemento, int cantidad_sumar_o_restar) {
    //verificar formato de nombres en archivo
    int cantidad_actualizada;
    if (nombre_elemento == "Madera" || nombre_elemento == "madera"){
        if (cantidad_sumar_o_restar < 0 &&  cant_madera < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar << " madera. Las cantidades no pueden estar en negativo." << endl;
        }
        else{
            cantidad_actualizada = cant_madera + cantidad_sumar_o_restar;
            cant_madera = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Piedra" || nombre_elemento == "piedra"){
        if (cantidad_sumar_o_restar < 0 &&  cant_piedra < cantidad_sumar_o_restar *(-1) ){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar << " piedra. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_piedra + cantidad_sumar_o_restar;
            cant_piedra = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Metal" || nombre_elemento == "metal"){
        if (cantidad_sumar_o_restar < 0  && cant_metal < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar << " metal. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_metal + cantidad_sumar_o_restar;
            cant_metal = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Bombas" || nombre_elemento == "bombas"){
        if (cantidad_sumar_o_restar < 0  && cant_bombas < cantidad_sumar_o_restar*(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar << " bombas. Las cantidades no pueden estar en negativo." << endl;
        }
        else {
            cantidad_actualizada = cant_bombas + cantidad_sumar_o_restar;
            cant_bombas = cantidad_actualizada;
        }
    }

    else if (nombre_elemento == "Andycoins" || nombre_elemento == "andycoins"){
        if (cantidad_sumar_o_restar < 0  && cant_andycoins < cantidad_sumar_o_restar *(-1)){
            cout<< "No se puede restarle " << cantidad_sumar_o_restar << " andycoins. Las cantidades no pueden estar en negativo." << endl;
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

