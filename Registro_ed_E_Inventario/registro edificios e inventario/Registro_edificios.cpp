#include "Registro_edificios.h"
#include "Nodo_listas.h"

Registro_edificios::Registro_edificios(){
    ultimo = nullptr;
    primero =  nullptr;
    cantidad_edificios = 0;
    cantidad_minas = 0;
    cantidad_aserraderos = 0;
    cantidad_fabricas = 0;
    cantidad_escuelas = 0;
    cantidad_obeliscos = 0;
    cantidad_plantas_electricas = 0;
    cantidad_minas_oro = 0;
}

int Registro_edificios::obtener_cantidad_edificios(){
    return cantidad_edificios;
}

int Registro_edificios::obtener_cantidad_minas(){
    return cantidad_minas;
}

int Registro_edificios::obtener_cantidad_aserraderos(){
    return cantidad_aserraderos;
}

int Registro_edificios::obtener_cantidad_fabricas(){
    return cantidad_fabricas;
}

int Registro_edificios::obtener_cantidad_escuelas(){
    return cantidad_escuelas;
}

int Registro_edificios::obtener_cantidad_obeliscos(){
    return cantidad_obeliscos;
}

int Registro_edificios::obtener_cantidad_plantas_electricas(){
    return cantidad_plantas_electricas;
}

int Registro_edificios::obtener_cantidad_minas_oro(){
    return cantidad_minas_oro;
}

int Registro_edificios :: buscar_posicion(int coordenada_x , int coordenada_y){
    Nodo_l *actual = new Nodo_l();
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
    delete actual;
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
    Nodo_l*nuevo = new Nodo_l();

    if(primero == nullptr){
        primero = nuevo;
        ultimo = primero;
    }
    else{
        ultimo ->cambiar_siguiente(nuevo);
    }
    ultimo = nuevo;

    contar(ultimo);

    cantidad_edificios++;
}

void Registro_edificios::contar(Nodo_l*nodo){//verificar como estan escritos los nombres en el archivo
    if (nodo->obtener_edificio()->obtener_nombre() == "Mina")
        cantidad_minas++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Mina oro")
        cantidad_minas_oro++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Aserradero")
        cantidad_aserraderos++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Fabrica")
        cantidad_fabricas++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Escuela")
        cantidad_escuelas++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Obelisco")
        cantidad_obeliscos++;
    else if (nodo->obtener_edificio()->obtener_nombre() == "Planta electrica")
        cantidad_plantas_electricas++;
}

void Registro_edificios::eliminar(int coordenada_x , int coordenada_y){
    Nodo_l* baja = primero;
    int posicion_edificio_buscado = buscar_posicion(coordenada_x,coordenada_y);
    if (primero->obtener_edificio() == buscar_edificio_en_registro(coordenada_x, coordenada_y)) {
        primero = baja->obtener_siguiente();
    }
    else{
        baja = obtener_nodo(posicion_edificio_buscado);
        Nodo_l *anterior = obtener_nodo(posicion_edificio_buscado- 1);
        anterior->cambiar_siguiente(baja->obtener_siguiente());
        }
    cantidad_edificios--;
    delete baja;
}


Registro_edificios::~Registro_edificios() {
    Nodo_l* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}


void Registro_edificios :: mostrar_registro_edificios(Edificio edificio) {
    Nodo_l *act = new Nodo_l();
    act = primero;
    if (cantidad_edificios == 0) {
        cout << "EL REGISTRO DE EDIFICIOS ESTÁ VACIO" << "\n\n";
    } else {
        cout << "REGISTRO DE EDIFICIOS GENERAL" << "\n" << endl;
        cout << "__________________________________________" << endl << endl;
        cout << "Cantidad Minas: " << obtener_cantidad_minas() << endl;
        cout << "Cantidad Minas de oro: " << obtener_cantidad_minas_oro() << endl;
        cout << "Cantidad Aserraderos: " << obtener_cantidad_aserraderos() << endl;
        cout << "Cantidad Fabricas: " << obtener_cantidad_fabricas() << endl;
        cout << "Cantidad Escuelas: " << obtener_cantidad_escuelas() << endl;
        cout << "Cantidad Obeliscos: " << obtener_cantidad_obeliscos() << endl;
        cout << "Cantidad Plantas electricas: " << obtener_cantidad_plantas_electricas() << endl << endl;

        cout << "REGISTRO DE EDIFICIOS DETALLADO" << "\n" << endl;
        cout << "__________________________________________" << endl << endl;

        for (int i = 0; i < cantidad_edificios; i++) {
            cout << "Nombre: " << act->obtener_edificio()->obtener_nombre() << endl;
            cout << "Diminutivo: " << act->obtener_edificio()->obtener_diminutivo() << endl;
            cout << "Cantidad de piedra: " << act->obtener_edificio()->obtener_cantidad_piedra() << endl;
            cout << "Cantidad de madera: " << act->obtener_edificio()->obtener_cantidad_madera() << endl;
            cout << "Cantidad de metal: " << act->obtener_edificio()->obtener_cantidad_metal() << endl;
            cout << "Cantidad limitte de construccion: " << act->obtener_edificio()->obtener_maximo_construir() << endl;
            cout << "Edificio en pie? " << act->obtener_edificio()->edificio_en_pie() << endl << endl;
            act = act->obtener_siguiente();
        }
    }
    delete act;
}

Nodo_l* Registro_edificios::obtener_nodo(int pos) {
    Nodo_l* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}
