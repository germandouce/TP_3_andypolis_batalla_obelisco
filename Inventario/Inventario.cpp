#include "Inventario.h"
#include <iostream>

using namespace std;

Inventario::Inventario(){ 
    cantidad_elementos = 0;
    cant_madera = 0;
    cant_piedra = 0;
    cant_metal = 0;
    cant_andycoins = cant_anterior_andycoins = 0;
    cant_bombas = cant_anterior_bombas = 0;

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

int Inventario::devolver_cant_anterior_andycoins(){
    return cant_anterior_andycoins;
}

int Inventario::devolver_cant_anterior_bombas(){
    return cant_anterior_bombas;
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

bool Inventario::cambio_cantidad_madera_valida( int cantidad_consultada){
    return(cant_madera > cantidad_consultada *(-1));
}

bool Inventario::cambio_cantidad_piedra_valida( int cantidad_consultada){
    return(cant_piedra > cantidad_consultada*(-1) );
}

bool Inventario::cambio_cantidad_metal_valida( int cantidad_consultada){
    return(cant_metal > cantidad_consultada *(-1));
}

bool Inventario::cambio_cantidad_andycoins_valida( int cantidad_consultada){
    return(cant_andycoins > cantidad_consultada*(-1));
}

bool Inventario::cambio_cantidad_bombas_valida( int cantidad_consultada){
    return(cant_bombas > cantidad_consultada*(-1));
}


void Inventario::cambio_cantidad_madera(int cantidad){
    if (cantidad < 0 && !cambio_cantidad_madera_valida(cantidad)){
        cout<< "No se puede restarle " << cantidad *(-1) << " a la cantidad actual de madera. Las cantidades no pueden estar en negativo." << endl;
    }
    else{
        int cantidad_actualizada = cant_madera + cantidad;
        cant_madera = cantidad_actualizada;
    }
}
void Inventario::cambio_cantidad_piedra(int cantidad){
    if (cantidad < 0 &&!cambio_cantidad_piedra_valida(cantidad)){
        cout<< "No se puede restarle " << cantidad *(-1) << " a la cantidad actual de piedra. Las cantidades no pueden estar en negativo." << endl;
    }
    else{
        int cantidad_actualizada = cant_piedra + cantidad;
        cant_piedra = cantidad_actualizada;
    }
}
void Inventario::cambio_cantidad_metal(int cantidad){
    if (cantidad < 0 && !cambio_cantidad_metal_valida(cantidad)){
        cout<< "No se puede restarle " << cantidad *(-1) << " a la cantidad actual de metal. Las cantidades no pueden estar en negativo." << endl;
    }
    else{
        int cantidad_actualizada = cant_metal + cantidad;
        cant_metal = cantidad_actualizada;
    }
}

void Inventario::cambio_cantidad_bombas(int cantidad){
    if (cantidad < 0 &&!cambio_cantidad_bombas_valida(cantidad)){
        cout<< "No se puede restarle " << cantidad *(-1) << " a la cantidad actual de bombas. Las cantidades no pueden estar en negativo." << endl;
    }
    else{
        int cantidad_actualizada = cant_bombas + cantidad;
        cant_bombas = cantidad_actualizada;
    }
}

void Inventario::cambio_cantidad_andycoins(int cantidad){
    if (cantidad < 0 &&!cambio_cantidad_andycoins_valida(cantidad)){
        cout<< "No se puede restarle " << cantidad *(-1) << " a la cantidad actual de andycoins. Las cantidades no pueden estar en negativo." << endl;
    }
    else{
        int cantidad_actualizada = cant_andycoins + cantidad;
        cant_andycoins = cantidad_actualizada;
    }
}

void Inventario::cambiar_cantidad_elemento(string nombre_elemento, int cantidad_sumar_o_restar) {
    if (nombre_elemento == I_MADERA) {
        cambio_cantidad_madera(cantidad_sumar_o_restar);
    }

    else if (nombre_elemento == I_PIEDRA){
        cambio_cantidad_piedra(cantidad_sumar_o_restar);
    }

    else if (nombre_elemento == I_METAL){
        cambio_cantidad_metal(cantidad_sumar_o_restar);
    }

    else if (nombre_elemento == I_BOMBAS) {
      cambio_cantidad_bombas(cantidad_sumar_o_restar);
    }

    else if (nombre_elemento == I_ANDYCOINS) {
        cambio_cantidad_andycoins(cantidad_sumar_o_restar);
    }

    else{
        cout<< "No se encuentra " << nombre_elemento << " en el inventario."<< endl;
    }

    cout<< endl;
}

void Inventario::actualizar_largo_de_inventario(){
    cantidad_elementos = cantidad_elementos+1;
}

void Inventario::consultar_porcentaje_material(string nombre_material ,int numero_porcentaje,Registro_edificios*registro_edificios,int fila , int columna){
    float porcentaje_usar = numero_porcentaje/100;
    if (porcentaje_concultado_valido(porcentaje_usar)){
        if (nombre_material == I_MADERA){
            if (porcentaje_de_madera_existente(porcentaje_usar,registro_edificios,fila,columna))
                cout << "Contas con la cantidad de madera necesaria."<<endl;
            else{
                cout << "No contas con la cantidad de madera necesaria."<<endl;
                }
            }
        else if (nombre_material == I_PIEDRA){
            if (porcentaje_de_piedra_existente(porcentaje_usar,registro_edificios, fila, columna))
                cout << "Contas con la cantidad de piedra necesaria."<<endl;
            else{
                cout << "No contas con la cantidad de piedra necesaria."<<endl;
                }
            }
        else if (nombre_material == I_METAL){
            if (porcentaje_de_metal_existente(porcentaje_usar,registro_edificios, fila, columna))
                cout << "Contas con la cantidad de metal necesaria."<<endl;
            else{
                cout << "No contas con la cantidad de metal necesario."<<endl;
                }
            }
    }else{
        cout << "Porcentaje consultado no valido." << endl;
         }
}

bool Inventario::porcentaje_de_madera_existente(float porcentaje_usar, Registro_edificios*registro_edificios, int fila, int columna){
    float cantidad_madera_requerida = registro_edificios->buscar_edificio_en_registro(fila,columna)->obtener_cantidad_madera()*porcentaje_usar;
    return ((float)cant_madera >= cantidad_madera_requerida);
}

bool Inventario::porcentaje_de_piedra_existente(float porcentaje_usar, Registro_edificios*registro_edificios, int fila, int columna){
    float cantidad_piedra_requerida = registro_edificios->buscar_edificio_en_registro(fila,columna)->obtener_cantidad_piedra()*porcentaje_usar;
    return ((float)cant_piedra >= cantidad_piedra_requerida);
}

bool Inventario::porcentaje_de_metal_existente(float porcentaje_usar, Registro_edificios*registro_edificios, int fila, int columna){
    float cantidad_metal_requerido =registro_edificios->buscar_edificio_en_registro(fila,columna)->obtener_cantidad_metal()*porcentaje_usar;
    return ((float)cant_metal >= cantidad_metal_requerido);
}

bool Inventario::porcentaje_concultado_valido(float porcentaje_consultado){
    return(porcentaje_consultado > 0);
}

bool Inventario:: hay_madera_suficiente(int cantidad_necesaria){
    return (cant_madera >= cantidad_necesaria);
}

bool Inventario:: hay_metal_suficiente(int cantidad_necesaria){
    return (cant_metal >= cantidad_necesaria);
}

bool Inventario:: hay_piedra_suficiente(int cantidad_necesaria){
    return (cant_piedra >= cantidad_necesaria);

}
void Inventario:: actualizar_cant_anterior_elemento(string elemento){
    else if (elemento == I_BOMBAS) {
        cant_anterior_bombas = cant_bombas;
    }
    else if (elemento == I_ANDYCOINS) {
        cant_anterior_andycoins = cant_andycoins;
    }
    else{
        cout<< "No se encuentra " << nombre_elemento << " en el inventario."<< endl;
    }
}


Inventario::~Inventario(){
}