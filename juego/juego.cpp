#include "juego.h"

Juego::Juego(){
    this -> mapa = 0;
    this -> diccionario_edificios = 0;
}

bool Juego::archivo_vacio(ifstream& archivo){
    return archivo.peek() == ifstream::traits_type::eof();
}


bool Juego::existe_archivo(ifstream& archivo,string nombre_archivo){
    archivo.open(nombre_archivo);
    return (archivo.is_open());
}

void Juego::instanciar_edificio(string nombre_edificio, Edificio* edificio){
    if ( nombre_edificio == "mina"){
        // edificio = new Mina();
    }
    else if ( nombre_edificio == "mina oro"){
        // edificio = new Mina_oro();

    }else if ( nombre_edificio == "aseeradero"){
        // edificio = new Aserradero();
    }
    else if ( nombre_edificio == "fabrica"){
        //edificio = new Fabrica();
    }
    else if ( nombre_edificio == "escuela"){
        //edificio = new Escuela();
    }
    else if ( nombre_edificio == "planta electrica"){
        //edificio = new Planta_electrica();
    }
    else{
        //edificio = new Edificio_desonocido()
    }
}


void Juego::instanciar_material(string nombre_material, Material * material){
    if ( nombre_material == "piedra"){
        material = new Piedra(100);
    }
    else if ( nombre_material == "madera"){
        material = new Metal(50);
    }
    else if ( nombre_material == "metal"){
        material = new Metal(50);
    }
    else if ( nombre_material == "andycoins"){
        material = new Metal(250);
    }
    else{
        //material = new Material_desconocido(1);
    }
}


void Juego::cargar_ubicaciones(ifstream& ubicaciones,Jugador * jug_1, Jugador * jug_2){

    string nombre_elemento;
    string espacio;
    string parentesis;
    string fila;
    string coma;
    string columna;

    Material * material;
    Jugador* jugador;
    Edificio * edificio;

    while (ubicaciones >> nombre_elemento){
        if (nombre_elemento == "1"){
            jugador = jug_1;
        }
        if (nombre_elemento == "2"){
            jugador = jug_2;
        }
        //VER ESTO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //leer_palabra_compuesta(archivo, nombre_edificio, OPCION_NUMEROS))
        //VER ESTO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ubicaciones >> espacio;
        ubicaciones >> parentesis;
        ubicaciones >> fila;
        ubicaciones >> coma;
        ubicaciones >> espacio;
        ubicaciones >> columna;
        ubicaciones >> parentesis;
        
        if (nombre_elemento == "piedra" || nombre_elemento == "madera" ||
        nombre_elemento == "metal" || nombre_elemento == "piedra"){
            
            instanciar_material(nombre_elemento, material);
            //mapa -> obtener_matriz_casilleros()[fila][columna] -> colocar_material(material);

        }else{

            instanciar_edificio(nombre_elemento, edificio);
            jugador->agregar_edificio_al_registro_(edificio);
            //mapa -> obtener_matriz_casilleros()[fila][columna] -> agrgar_edificio(edificio);
        }
    }
}

bool Juego::cargar_mapa(){
    bool bien_cargado = false;
    //logica para cragar el mapa
    return bien_cargado;
}


void Juego::crear_juego(){

    //bool mapa_bien_cargado = cargar_mapa();
    
    
    Jugador *jug_1 = new Jugador();
    Jugador *jug_2 = new Jugador();

    ifstream archivo;
    if ( existe_archivo(archivo, ARCHIVO_UBICACIONES) ){
        if ( !archivo_vacio(archivo) ){
            cargar_ubicaciones(archivo, jug_1, jug_2);
        }
    }
    
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
