#include "Registro_edificios.h"
#include "Nodo_listas.h"

Registro_edificios::Registro_edificios(){
    ultimo = nullptr;
    primero =  nullptr;
    cantidad_edificios = 0;
}

int Registro_edificios::obtener_cantidad_edificios(){
    return cantidad_edificios;
}

int Registro_edificios :: buscar_posicion(int coordenada_x , int coordenada_y){
    Nodo_Reg_ed *actual = new Nodo_Reg_ed();
    actual = primero;
    bool encontrado = false;
    int posicion = 0;
    while ( posicion < cantidad_edificios || encontrado) {
        if (coordenada_x == actual->obtener_edificio()->obtener_coordenada_x() &&
            coordenada_y == actual->obtener_edificio()->obtener_coordenada_y()) {
            encontrado = true;
        }
        actual = actual->obtener_siguiente();
        posicion++;
    }
    return  posicion;
}

Edificio* Registro_edificios::buscar_edificio_en_registro(int coordenada_x , int coordenada_y) {
    if (existe(coordenada_x,coordenada_y)){
        return obtener_nodo(buscar_posicion(coordenada_x,coordenada_y))->obtener_edificio();
    }
    else {
        cout<< "NO EXISTE EDIFICIO EN LA UBICACION CONSULTADA."<< endl;
        return nullptr;
    }
}

bool Registro_edificios::existe( int coordenada_x , int coordenada_y) {
    return (buscar_posicion(coordenada_x, coordenada_y) > 0);
}

void Registro_edificios::agregar() {
    Nodo_Reg_ed*nuevo = new Nodo_Reg_ed();
    Nodo_Reg_ed*siguiente = primero;
    nuevo ->obtener_edificio();

    if(primero == nullptr){
        primero = nuevo;
        ultimo = primero;
    }
    else {
        ultimo = nuevo;
        int posicion_ultimo_x = ultimo->obtener_edificio()->obtener_coordenada_x();
        int posicion_ultimo_y = ultimo->obtener_edificio()->obtener_coordenada_y();
        Nodo_Reg_ed* anterior = obtener_nodo(buscar_posicion(posicion_ultimo_x-1,posicion_ultimo_y-1));
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad_edificios++;
}

void Registro_edificios::eliminar(int coordenada_x , int coordenada_y){
    Nodo_Reg_ed* baja = primero;
    Edificio*edificio_buscado;
    edificio_buscado = buscar_edificio_en_registro(coordenada_x,coordenada_y);
    int posicion_ed_buscado = buscar_posicion(edificio_buscado->obtener_coordenada_x(),edificio_buscado->obtener_coordenada_y());
    if (primero->obtener_edificio() == edificio_buscado){
        primero = baja->obtener_siguiente();
    }
    else{
        baja = baja->obtener_siguiente();
        Nodo_Reg_ed*anterior = obtener_nodo(posicion_ed_buscado-1);
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad_edificios--;
    delete baja;
}


Registro_edificios::~Registro_edificios() {
    Nodo_Reg_ed* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}


void Registro_edificios :: mostrar_registro_edificios(Edificio edificio) {
    Nodo_Reg_ed *act = new Nodo_Reg_ed;
    act = primero;
    if (cantidad_edificios == 0) {
        cout << "EL REGISTRO DE EDIFICIOS ESTÁ VACIO" << "\n\n";
    } else {
        cout << "REGISTRO DE EDIFICIOS" << "\n" << endl;
        cout << "__________________________________________" << endl << endl;

        for (int i = 0; i < cantidad_edificios; i++) {
            cout << "Nombre: " << act->obtener_edificio()->obtener_nombre() << endl;
            cout << "Diminutivo: " << act->obtener_edificio()->obtener_diminutivo() << endl;
            cout << "Cantidad de piedra: " << act->obtener_edificio()->obtener_cantidad_piedra() << endl;
            cout << "Cantidad de madera: " << act->obtener_edificio()->obtener_cantidad_madera() << endl;
            cout << "Cantidad de metal: " << act->obtener_edificio()->obtener_cantidad_metal() << endl;
            cout << "Cantidad limitte de construccion: " << act->obtener_edificio()->obtener_maximo_construir() << endl;
            cout << "Edificio en pie? " << act->obtener_edificio()->edificio_en_pie() << endl;
            act = act->obtener_siguiente();
        }
    }
}

Nodo_Reg_ed* Registro_edificios::obtener_nodo(int pos) {
    Nodo_Reg_ed* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}
