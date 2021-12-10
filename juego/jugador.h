#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "..\vector.h"

#include "..\objetivos\armado.h"
#include "..\objetivos\bombardero.h"
#include "..\objetivos\cansado.h"
#include "..\objetivos\comprar_andypolis.h"
#include "..\objetivos\constructor.h"
#include "..\objetivos\edad_piedra.h"
#include "..\objetivos\energetico.h"
#include "..\objetivos\extremista.h"
#include "..\objetivos\letrado.h"
#include "..\objetivos\minero.h"

const int NUMERO_JUGADOR1 = 1;
const int NUMERO_JUGADOR2 = 2;

using namespace std;

class Jugador {

    private:    

    int numero_jugador;
    Vector<Objetivo>* objetivos;
    Inventario* inventario;
    Registro_edificios* registro_edificios;
    int objetivos_secundarios_cumplidos;
    int energia;
    int andycoins_acumulados;
    int bombas_usadas;
    int bombas_compradas;
    
    bool obelisco_construido;

    int fila;
    int columna;

    bool en_juego;
    bool su_turno;

    public:

    //Jugador(Vector<Material>* inventario);
    
    //Constructor de jugador
    Jugador();

    //Pedir coordenadas
    //PRE:-
    //POST: Pide las coordenadas en las q quiere ubicarse al jugador
    void pedir_coordenadas();
    
    //Asignar coordenadas
    //PRE:Recibe dos enteros con las coordenadas x e y respectivamente.
    //POST: Asigna al jugador en los atributos las coordenadas correspondientes.
    void asignar_coordenadas(int fila, int columna);

    //Devolver fila
    //PRE:-
    //POST: Devuelve un entero con la fila
    int devolver_fila();

    //Devolver columna
    //PRE:-
    //POST: Devuelve un entero con la columna
    int devolver_columna();

    //Setear numero jugador
    //PRE:Recibe un entero con el numero de jugador
    //POST:Modifica el atributo numero de jugador colocandole el numero que se pase por parametro
    void setear_numero_jugador(int numero_jugador);

    //Devolver numero jugador;
    //PRE: 
    //POST: Devuelve el numero de juagdor.
    int devolver_numero_jugador();

    //Asignar objetivos
    //PRE:
    //POST: Asigna 1 objetivo al jugador agregandolo a la lista de objetivos
    void asignar_objetivo(Objetivo* objetivo_a_asignar);

    //Cargar el inventario
    //PRE:
    //POST:-
    void agregar_material_a_inventario();

    //Cargar resgistro edificios
    //PRE:-
    //POST: Lee el archivo de edificios y va cargandolos en el registro
    void agregar_edificio_al_registro(Edificio* edificio);

    //Verificar objetivos
    //PRE:
    //POST: verifica si cumplio sus objetivos 
    void verificar_objetivos(int objetivo, int escuelas_construidas, int cantidad_minas, int distintos_edificios);

    //Gnao
    //PRE:-
    //POST:Verifica que si se construyo el obelisco o si se cumplieron 2 objetivos ppales
    bool gano();

    //Obtener energia
    //PRE:-
    //POST:Devuelve la cantidad de energia que tiene el jugador
    int obtener_energia();

    //Sin energia
    //PRE:-
    //POSR: Devuelve true si se quedo sin energia, false en caso constrario
    bool esta_sin_energia();

    //Iniciar turno
    //PRE:-
    //POST: cambia el valor de su turno a true
    void iniciar_turno();

    //termianr turno
    //PRE:-
    //POST: cambia el valor de su turno a false
    void terminar_truno();

    //es su turno
    //PRE:-
    //POST: Devuelve el valor de su_turno
    bool es_su_turno();

    //Salir del juego
    //PRE:-
    //POST: Coloca en false el atributo en_juego
    void salir_del_juego();

    //Quiere salir del juego
    //PRE:-
    //POST: Devuelve el valor del atributo en_juego
    bool quiere_salir_del_juego();

    //Sumar energia
    //PRE: Recibe un entero con la cantidad de enrgia a sumar
    //POST: Suma la cantidad de energia recibida por parametro al atributo energia.
    //Si se supera los 100 pts de energia suma hasta 100
    void sumar_energia(int energia);

    //PRE: Recibe un entero con la cantidad de enrgia a sumar
    //POST: 
    void esta_obelisco_construido();
    
    //Devolver resgitro edificios
    //PRE:-
    //POST:Devuelve un puntero al registro de edificios del jugador
    Registro_edificios* devolver_resgitro_edificios();

    //Devolver inventario
    //PRE:-
    //POST:Devuelve un puntero al inventario del jugador
    Inventario* devolver_inventario();
    
};

#endif // JUGADOR_H