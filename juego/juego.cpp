#include "juego.h"

Juego::Juego(){
    this -> mapa = 0;
    this -> diccionario_edificios = 0;
}


void Juego::cargar_ubicaciones(Jugador * jug_1, Jugador * jug_2){
     
    string nombre_elemento;
    string cantidad_elemento;
    int fila;
    int columna;
    Material * material;
    Jugador* jugador;
    Edificio * edificio;
    //logica para abrir y leer
    if (nombre_elemento == "1"){
        jugador = jug_1;
        
    }
    if (nombre_elemento == "2"){
        jugador = jug_1;
    }

    if ( nombre_elemento == "piedra"){
        material = new Piedra( stoi(cantidad_elemento) );
    }
    else if ( nombre_elemento == "metal"){
        material = new Metal(stoi(cantidad_elemento));
    }

    //bla bla bla
    
    //si esta en el vector de materiales....
    if (nombre_elemento == "materiales"){
        //mapa -> agregar_material(
    }else
    //si no es un edificio
    {
        //mapa -> agregar_edific(
    }
    jugador->agregar_edificio_al_registro_(edificio)

    


bool Juego::cargar_mapa(){
    bool bien_cargado = false;
    //logica para cragar el mapa
    return bien_cargado;
}


void Juego::crear_juego(){

    bool mapa_bien_cargado = cargar_mapa();
    //bool edificios_bien_cargado = 
    bool ubicaciones_bien_cargado = cargar_ubicaciones();

    Jugador *jug_1 = new Jugador();
    Jugador *jug_2 = new Jugador();
    
    Jugador * jugador;

    
    // Jugador * jugador;
    // for (int i = 1; i <3 ; i++){
    //     if (i = 0){
    //         jugador = jug_1;
    //     }
    //     else{
    //         jugador = jug_1;
    //     }   
    //asignar_objetivos(jugador);
    //jugador -> setear_numero_jugador(i);
    
    
    


}

int Juego:: generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);
}

void Juego::asignar_objetivos(Jugador *jugador){
    srand( (unsigned)time(0) );
    
    int objetivo;
    
    for(int i = 0; i < 3; i++){
        objetivo = generar_numero_random(1,10);
        jugador -> asignar_objetivo(objetivo, i );
    }

}
