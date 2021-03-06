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

int Registro_edificios :: buscar_posicion(int fila, int columna){
    Nodo_R *actual;
    actual = primero;
    bool encontrado;
    int posicion;
    for ( posicion = 0; posicion < cantidad_edificios ; posicion++ ) {
        if (fila == actual->obtener_edificio()->obtener_fila() && columna == actual->obtener_edificio()->obtener_columna()) {
            return posicion;
        }
        else{
            encontrado = false;
        }
        actual = actual->obtener_siguiente();
    }
    if (encontrado == false){
        posicion = -1;
    }

    delete actual;
    return  posicion;
}



Edificio* Registro_edificios::buscar_edificio_en_registro(int coordenada_x , int coordenada_y) {
    Nodo_R*aux = obtener_nodo(buscar_posicion(coordenada_x,coordenada_y));
    return aux -> obtener_edificio();
}

bool Registro_edificios::existe( int coordenada_x , int coordenada_y) {
    return (buscar_posicion(coordenada_x, coordenada_y) >= 0);
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

    if (nombre_edificio == A && cantidad_aserraderos < limite_construccion ) {
         nuevo = new Nodo_R(new Aserradero(piedra, madera, metal, limite_construccion, fila, columna));
         cantidad_aserraderos++;
     }

     else if (nombre_edificio == E && cantidad_escuelas < limite_construccion) {
         nuevo = new Nodo_R(new Escuela(piedra, madera, metal, limite_construccion, fila, columna)) ;
         cantidad_escuelas++;
     }

     else if (nombre_edificio == F && cantidad_fabricas < limite_construccion) {
         nuevo = new Nodo_R( new Fabrica(piedra, madera, metal, limite_construccion, fila, columna));
         cantidad_fabricas++;
     }

    else if (nombre_edificio == M && cantidad_minas < limite_construccion) {
         nuevo = new Nodo_R(new Mina(piedra, madera, metal, limite_construccion, fila, columna));
        cantidad_minas++;
     }

     else if (nombre_edificio == G && cantidad_minas_oro < limite_construccion) {
         nuevo = new Nodo_R(new Mina_de_oro(piedra, madera, metal, limite_construccion, fila, columna));
         cantidad_minas_oro++;
     }

     else if (nombre_edificio == O && cantidad_obeliscos < limite_construccion) {
         nuevo = new Nodo_R(new Obelisco(piedra, madera, metal, limite_construccion, fila, columna));
         cantidad_obeliscos++;
    }

     else if (nombre_edificio == P && cantidad_plantas_electricas < limite_construccion) {
         nuevo = new Nodo_R( new Planta_electrica(piedra, madera, metal, limite_construccion, fila, columna));
         cantidad_plantas_electricas++;
     }
     else{
       cout << ERROR_COLOR << "Pasa el limite de edificios a construir." << END_COLOR << endl;
     }
    nuevo = new Nodo_R(edificio);
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
            baja ->obtener_edificio();
            anterior->cambiar_siguiente(baja->obtener_siguiente());
        }
        actualizar_cantidad_tipo_edificio(nombre_edificio);
        cantidad_edificios--;
        delete baja;
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
        cout << ERROR_COLOR << "EL REGISTRO DE EDIFICIOS ESTA VACIO" << END_COLOR <<"\n\n";
    } else {
        cout << ENTER_COLOR<< "\nREGISTRO DE EDIFICIOS GENERAL" << endl;
        cout <<  "__________________________________________" <<END_COLOR<< endl << endl;
        cout << SUCESS_COLOR << "Cantidad Minas: " << obtener_cantidad_minas() << endl;
        cout << "Cantidad Minas de oro: " << obtener_cantidad_minas_oro() << endl;
        cout << "Cantidad Aserraderos: " << obtener_cantidad_aserraderos() << endl;
        cout << "Cantidad Fabricas: " << obtener_cantidad_fabricas() << endl;
        cout << "Cantidad Escuelas: " << obtener_cantidad_escuelas() << endl;
        cout << "Cantidad Obeliscos: " << obtener_cantidad_obeliscos() << endl;
        cout << "Cantidad Plantas electricas: " << obtener_cantidad_plantas_electricas() << END_COLOR << endl << endl;

        cout << ENTER_COLOR << "REGISTRO DE EDIFICIOS DETALLADO"<<endl;
        cout << "__________________________________________" << END_COLOR << endl<<endl;

        for (int posicion = 0; posicion < cantidad_edificios; posicion++){
            cout << SUCESS_COLOR << "Nombre: " << act->obtener_edificio()->obtener_nombre() << endl;
            cout << "Diminutivo: " << act->obtener_edificio()->obtener_diminutivo() << endl;
            cout << "Cantidad de piedra: " << act->obtener_edificio()->obtener_cantidad_piedra() << endl;
            cout << "Cantidad de madera: " << act->obtener_edificio()->obtener_cantidad_madera() << endl;
            cout << "Cantidad de metal: " << act->obtener_edificio()->obtener_cantidad_metal() << endl;
            cout << "Cantidad limite de construccion: " << act->obtener_edificio()->obtener_maximo_construir() << endl;
            cout << "Vida actual: " << act->obtener_edificio()->obtener_vida_actual() << endl;
            cout << "Ubicacion en mapa: " << "( " << act->obtener_edificio()->obtener_fila() << ", "<< act->obtener_edificio()->obtener_columna() << " )\n" << END_COLOR << endl;
            act = act->obtener_siguiente();
        }
    }
    delete act;
}

bool Registro_edificios:: posicion_valida_a_consultar(int pos){
    return (pos < cantidad_edificios && pos >= 0);
}

Nodo_R* Registro_edificios::obtener_nodo(int pos) {
    if (posicion_valida_a_consultar(pos)){
        Nodo_R* aux = primero;
        for (int i = 0; i < pos; i++)
            aux = aux->obtener_siguiente();
        return aux;
    }
    else {
        return nullptr;
    }
}

int Registro_edificios::obtener_edificios_construidos(string nombre_edificio) {
    
    int cantidad_construida;
    
    if (nombre_edificio == M) {
        cantidad_construida = obtener_cantidad_minas();
    }
    else if (nombre_edificio == O){
        cantidad_construida = obtener_cantidad_obeliscos();
    }
    else if (nombre_edificio == P){
        cantidad_construida = obtener_cantidad_plantas_electricas();
    }
    else if (nombre_edificio == E){
        cantidad_construida = obtener_cantidad_escuelas();
    }   
    else if (nombre_edificio == G){
        cantidad_construida = obtener_cantidad_minas_oro();
    }
    else if (nombre_edificio == F){
        cantidad_construida = obtener_cantidad_fabricas();
    }
    else if (nombre_edificio == A){
        cantidad_construida = obtener_cantidad_aserraderos();
    }
    else{
        cantidad_construida = NO_EXISTE;
    }
    
    return cantidad_construida;     
}

bool Registro_edificios::al_menos_un_obelisco(){
    return (obtener_cantidad_obeliscos() >= 1);
}

bool Registro_edificios::al_menos_una_mina(){
    return (obtener_cantidad_minas() >= 1);
}

bool Registro_edificios::al_menos_una_fabrica(){
    return (obtener_cantidad_fabricas() >=1);
}

bool Registro_edificios::al_menos_un_aserradero(){
    return (obtener_cantidad_aserraderos() >= 1);
}

bool Registro_edificios::al_menos_una_mina_oro(){
    return (obtener_cantidad_minas_oro() >= 1);
}

bool Registro_edificios::al_menos_una_planta_electrica(){
    return  (obtener_cantidad_plantas_electricas() >= 1);
}
bool Registro_edificios::al_menos_una_escuela(){
    return (obtener_cantidad_escuelas() >= 1);
}

bool Registro_edificios::al_menos_uno_de_cada_tipo(){
    return (al_menos_un_aserradero() && al_menos_un_obelisco() && al_menos_una_escuela()
    && al_menos_una_fabrica() && al_menos_una_mina_oro() && al_menos_una_mina() && al_menos_una_planta_electrica());
}

void Registro_edificios::guardar(ofstream& archivo) {

    Nodo_R* nodo = primero;

    for (int i = 0; i < cantidad_edificios; i++) {

        Edificio* edificio = nodo -> obtener_edificio();

        string nombre_edificio = edificio -> obtener_nombre();
        int fila = edificio -> obtener_fila();
        int columna = edificio -> obtener_columna();

        archivo << nombre_edificio << " (" << fila << ", " << columna << ")" << endl;

        nodo = nodo -> obtener_siguiente();
    }
}