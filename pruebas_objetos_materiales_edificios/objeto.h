#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

const string S = "piedra";
const string W = "madera";
const string I = "metal";
const string VACIO = "";

const int PRODUCCION_MINA = 15;
const int PRODUCCION_ASERRADERO = 25;
const int PRODUCCION_FABRICA = 40;

const int SIN_MATERIAL = 0;
const int MATERIAL_CONTENIDO_POR_CASILLERO = 1;

const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const int BOMBAS = 3;

class Objeto {

    protected:
    
    string nombre;
    string diminutivo;
    // int cantidad_objeto;
    // int cantidad_piedra;
    // int canitdad_madera;
    // int cantidad_metal;
    // int brinda;
    // int maximo_construir;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un objeto con su nombre
    Objeto();

    // Constructor de objeto con parámetros.
    //pre: -
    //post: Instancia un objeto según los valores ingresados.
    // Objeto(string nombre, int cantidad_objeto, string diminutivo);
    
    //pre: -
    //post: Devuelve el nombre del objeto.
    virtual string obtener_nombre() = 0;

    
    // PRE: 
    // POS: Devuelve el diminutivo del objeto
    // virtual string obtener_diminutivo() = 0;

    virtual int obtener_cantidad_brindada() = 0;

    // //pre: -
    // //post: Devuelve la cantidad del objeto.
    // //virtual int obtener_cantidad();

    // //pre: -
    // //post: Imprime en pantalla los atributos del Material.
    // void mostrar_material();

    // //pre: El costo debe ser mayor ó igual a cero.
    // //post: Suma el 'costo' a la 'cantidad_material'.
    // void sumar_costo(int costo);

    // //pre: El costo debe ser mayor ó igual a cero.
    // //post: Resta el 'costo' a la 'cantidad_material'.
    // void restar_costo(int costo);

    // //pre: El Material debe ser una instancia "vacía", con sus atributos nulos.
    // //post: Genera una unidad de un material de forma aleatoria entre los posibles materiales que pueden llover.
    // //      Devuelve un número asociado al material llovido.
    // int llover_material_aleatorio();

    // //pre: -
    // //post: Imprime en pantalla información del Material.
    // void mostrar_informacion();
    
    ~Objeto();

    private:

    //pre: -
    //post: Devuelve el nombre de un material según el número ingresado asociado.
    string obtener_tipo_material(int tipo_material);
}; 

#endif // OBJETO_H