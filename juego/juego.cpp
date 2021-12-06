#include "juego.h"

Juego::Juego(){
    this -> mapa = new Mapa();
    //this -> diccionario_edificios = 0;
}

bool Juego::archivo_vacio(ifstream& archivo){
    return ( archivo.peek() == ifstream::traits_type::eof() );
}


bool Juego::existe_archivo(ifstream& archivo,string nombre_archivo){
    archivo.open(nombre_archivo);
    return (archivo.is_open());
}

void Juego::instanciar_edificio(string nombre_edificio, Edificio* edificio){
    if ( nombre_edificio == "mina"){
        edificio = new Mina(0,0,0,0);
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
        material = new Madera(50);
    }
    else if ( nombre_material == "metal"){
        material = new Metal(50);
    }
    else if ( nombre_material == "andycoins"){
        material = new Andycoins(250);
    }
    else{
        //material = new Material_desconocido(1);
    }
}


void Juego::cargar_ubicaciones(ifstream& ubicaciones,Jugador * jug_1, Jugador * jug_2){

    string nombre_elemento;
    string fila;
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

        ubicaciones >> fila;   
        fila = limpiar_string(fila, POSICION_INICIAL_FILA, TOPE_CADENA_FILA);

        ubicaciones >> columna;
        columna = limpiar_string(columna, POSICION_INICIAL_COLUMNA, TOPE_CADENA_COLUMNA);
        
        if (nombre_elemento == "piedra" || nombre_elemento == "madera" ||
        nombre_elemento == "metal" || nombre_elemento == "andycoins"){
            
            instanciar_material(nombre_elemento, material);
            //mapa -> obtener_matriz_casilleros()[fila][columna] -> colocar_material(material);

        }else{

            instanciar_edificio(nombre_elemento, edificio);
            jugador->agregar_edificio_al_registro_(edificio);
            //mapa -> obtener_matriz_casilleros()[fila][columna] -> agrgar_edificio(edificio);
        }
    }
    ubicaciones.close();
}

int Juego::limpiar_string(string cadena, int posicion_inicial, char str_tope) {

	string numero;
	string cifra;

	numero = cadena[posicion_inicial];

	while (cadena[posicion_inicial + 1] != str_tope) {
	    
		posicion_inicial++;
	    
		if (ASCII_NUM_CERO <= cadena[posicion_inicial] && cadena[posicion_inicial] <= ASCII_NUM_NUEVE) {
	    	cifra = cadena[posicion_inicial];
	    	numero = numero + cifra;
	    }
	}
	return stoi(numero);
}

// bool Juego::cargar_mapa(){
//     bool bien_cargado = false;
//     //logica para cragar el mapa
//     return bien_cargado;
// }

bool Juego::es_archivo_legible(ifstream& archivo, string nombre_archivo){
    
    bool archivo_legible = false;
    
    if ( existe_archivo(archivo, nombre_archivo) ){
        if ( !archivo_vacio(archivo) ){
            //cargar_ubicaciones(archivo, jug_1, jug_2);
            archivo_legible = true; 
        }else{
        archivo.close();
        }   
    }
    return archivo_legible;
}


void Juego::crear_juego(Jugador * jug_1, Jugador * jug_2){

    Jugador * jugador;
    for (int i = 1; i <3 ; i++){
        if (i = 0){
            jugador = jug_1;
        }
        else{
            jugador = jug_1;
        }   
        asignar_objetivos(jugador);
        jugador -> setear_numero_jugador(i);
    }
}


void Juego::turnos(){
    
    (int i = 1; i <3 ; i++){
        if (i = 1){
            jugador = jug_1;
        }
        else{
            jugador = jug_2;
        }   
        asignar_objetivos(jugador);
        jugador -> setear_numero_jugador(i);
    }


}

int Juego::generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);
}

void Juego::asignar_objetivos(Jugador *jugador){
    srand( (unsigned)time(0) );
    
    int objetivo;

    int vector_objetivos_jug_1[3];
    int vector_objetivos_jug_2[3];

    for(int i = 0; i < 3; i++){

        objetivo = generar_numero_random(1,10);



        jugador -> asignar_objetivo(objetivo, i );
    }

}
