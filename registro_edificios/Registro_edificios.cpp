#include "Registro_edificios.h"

using namespace std;

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
    Nodo_R *actual;
    actual = primero;
    bool encontrado;
    int posicion;
    for ( posicion = 0; posicion < cantidad_edificios ; posicion++ ) {
        if (coordenada_x == actual->obtener_edificio()->obtener_fila() && coordenada_y == actual->obtener_edificio()->obtener_columna()) {
            return posicion;
        }
        else{
            encontrado = false;
        }
        actual = actual->obtener_siguiente();
    }
    if (encontrado == false){
        posicion = -1;
        cout << "No existe edificio en posicion ->> "<< "( " << coordenada_x << ", " << coordenada_y << " )" <<endl;
        cout << "Entonces no existe en el registro de edificios."<<endl;
    }

    delete actual;
    return  posicion;
}

Edificio* Registro_edificios::buscar_edificio_en_registro(int coordenada_x , int coordenada_y) {
    Nodo_R*aux = obtener_nodo(buscar_posicion(coordenada_x,coordenada_y));
    return aux -> obtener_edificio();
}

bool Registro_edificios::existe( int coordenada_x , int coordenada_y) {
    return (buscar_posicion(coordenada_x, coordenada_y) > 0);
}


void Registro_edificios::agregar(Edificio*edificio){
    Nodo_R*nuevo;
    string nombre_edificio = edificio->obtener_nombre();
    int piedra = edificio->obtener_cantidad_piedra();
    int madera = edificio->obtener_cantidad_madera();
    int metal = edificio->obtener_cantidad_metal();
    int limite_construccion = edificio->obtener_maximo_construir();
    int fila = edificio->obtener_fila();
    int columna = edificio ->obtener_columna();

    if (nombre_edificio == A) {
        nuevo = new Nodo_R(new Aserradero(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_aserraderos++;
    }

    else if (nombre_edificio == E) {
        nuevo = new Nodo_R(new Escuela(piedra, madera, metal, limite_construccion, fila, columna)) ;
        cantidad_escuelas++;
    }

    else if (nombre_edificio == F) {
        nuevo = new Nodo_R( new Fabrica(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_fabricas++;
    }

    else if (nombre_edificio == M) {
        nuevo = new Nodo_R(new Mina(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_minas++;
    }

    else if (nombre_edificio == G) {
        nuevo = new Nodo_R(new Mina_de_oro(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_minas_oro++;
    }

    else if (nombre_edificio == O) {
        nuevo = new Nodo_R(new Obelisco(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_obeliscos++;
    }

    else if (nombre_edificio == P) {
        nuevo = new Nodo_R( new Planta_electrica(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_plantas_electricas++;
    }
    if(primero == nullptr){
        primero = nuevo;
        ultimo = primero;
    }
    else{
        ultimo ->cambiar_siguiente(nuevo);
    }
    ultimo = nuevo;

    cantidad_edificios++;

}


void Registro_edificios::eliminar(int coordenada_x , int coordenada_y){
    if (existe(coordenada_x,coordenada_y)){
        Nodo_R *baja;
        int posicion_edificio_buscado = buscar_posicion(coordenada_x,coordenada_y);
        string nombre_edificio = buscar_edificio_en_registro(coordenada_x,coordenada_y)->obtener_nombre();
        if (posicion_edificio_buscado == 0) {
            baja = primero;
            primero = primero->obtener_siguiente();
        }
        else{
            Nodo_R* anterior = obtener_nodo(posicion_edificio_buscado - 1);
            baja = anterior->obtener_siguiente();
            cout<< "baja --> " << baja << endl;
            anterior->cambiar_siguiente(baja->obtener_siguiente());
        }
        actualizar_cantidad_tipo_edificio(nombre_edificio);
        cantidad_edificios--;
        cout<< "elimino baja -->" << baja << endl;
        delete baja;
    }
    else{
        cout << "No puede eliminarse un edificio que no existe en el registro." << endl;
    }
}

void Registro_edificios::actualizar_cantidad_tipo_edificio(string nombre_edificio){
    if (nombre_edificio == M)
        cantidad_minas--;
    else if (nombre_edificio == O)
        cantidad_obeliscos--;
    else if (nombre_edificio == P)
        cantidad_plantas_electricas--;
    else if (nombre_edificio == E)
        cantidad_escuelas--;
    else if (nombre_edificio == G)
        cantidad_minas_oro--;
    else if (nombre_edificio == F)
        cantidad_fabricas--;
    else if (nombre_edificio == A)
        cantidad_aserraderos--;
}


Registro_edificios::~Registro_edificios() {
    Nodo_R* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}


void Registro_edificios :: mostrar_registro_edificios() {
    Nodo_R *act;
    act = primero;
    if (cantidad_edificios == 0) {
        cout << "EL REGISTRO DE EDIFICIOS ESTA VACIO" << "\n\n";
    } else {
        cout << "\nREGISTRO DE EDIFICIOS GENERAL"<<endl;
        cout << "__________________________________________" << endl << endl;
        cout << "Cantidad Minas: " << obtener_cantidad_minas() << endl;
        cout << "Cantidad Minas de oro: " << obtener_cantidad_minas_oro() << endl;
        cout << "Cantidad Aserraderos: " << obtener_cantidad_aserraderos() << endl;
        cout << "Cantidad Fabricas: " << obtener_cantidad_fabricas() << endl;
        cout << "Cantidad Escuelas: " << obtener_cantidad_escuelas() << endl;
        cout << "Cantidad Obeliscos: " << obtener_cantidad_obeliscos() << endl;
        cout << "Cantidad Plantas electricas: " << obtener_cantidad_plantas_electricas() << endl << endl;

        cout << "REGISTRO DE EDIFICIOS DETALLADO"<<endl;
        cout << "__________________________________________" << endl<<endl;

        for (int posicion = 0; posicion < cantidad_edificios; posicion++){
            cout << "Nombre: " << act->obtener_edificio()->obtener_nombre() << endl;
            cout << "Diminutivo: " << act->obtener_edificio()->obtener_diminutivo() << endl;
            cout << "Cantidad de piedra: " << act->obtener_edificio()->obtener_cantidad_piedra() << endl;
            cout << "Cantidad de madera: " << act->obtener_edificio()->obtener_cantidad_madera() << endl;
            cout << "Cantidad de metal: " << act->obtener_edificio()->obtener_cantidad_metal() << endl;
            cout << "Cantidad limitte de construccion: " << act->obtener_edificio()->obtener_maximo_construir() << endl;
            cout << "Vida actual: " << act->obtener_edificio()->obtener_vida_actual() << endl;
            cout << "Ubicacion en mapa: " << "( " << act->obtener_edificio()->obtener_fila() << ", "<< act->obtener_edificio()->obtener_columna() << " )\n" << endl;
            act = act->obtener_siguiente();
        }
    }
    delete act;
}

bool Registro_edificios:: posicion_valida_a_consutar(int pos){
    return (pos < cantidad_edificios && pos >= 0);
}

Nodo_R* Registro_edificios::obtener_nodo(int pos) {
    if (posicion_valida_a_consutar(pos)){
        Nodo_R* aux = primero;
        for (int i = 0; i < pos; i++)
            aux = aux->obtener_siguiente();
        return aux;
    }
    else {
        cout<< "Posicion " << pos << " no valida. No existe esa cantidad de nodos en el registro (tomar en cuenta que se empiezan a contar desde posicion 0).\n" << endl;
        return nullptr;
    }
}
