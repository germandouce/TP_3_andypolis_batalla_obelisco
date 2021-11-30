#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include <string>

using namespace std;

const string S = "piedra";
const string W = "madera";
const string I = "metal";
const string VACIO = "";


class Material {

    protected:
    
    string nombre_material;
    int cantidad_material;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un Material "vacío" con todos sus atributos nulos.
    Material();

    // Constructor con dos parámetros.
    //pre: -
    //post: Instancia un Material cualquiera sea el nombre y con la 
    //cantidad del mismo
    Material(string nombre_material, int cantidad_material);
    
    // Constructor con dos parámetros.
    //pre: -
    //post: Instancia un Material standard sea el nombre y con la 
    //cantidad del mismo
    Material(int cantidad_material);

    //Saluda
    //PRE: -
    //POST: Saluda. Todos saludan "igual" pero con distintos nombre y contenidos
    virtual void saludar() = 0;

    //pre: -
    //post: Devuelve el nombre del Material.
    string obtener_nombre();

    //pre: -
    //post: Devuelve la cantidad del Material.
    int obtener_cantidad();

    //pre: -
    //post: Imprime en pantalla los atributos del Material.
    void mostrar_material();

    //pre: El costo debe ser mayor ó igual a cero.
    //post: Suma el 'costo' a la 'cantidad_material'.
    void sumar_costo(int costo);

    //pre: El costo debe ser mayor ó igual a cero.
    //post: Resta el 'costo' a la 'cantidad_material'.
    void restar_costo(int costo);

    //pre: El Material debe ser una instancia "vacía", con sus atributos nulos.
    //post: Genera una unidad de un material de forma aleatoria entre los posibles materiales que pueden llover.
    //      Devuelve un número asociado al material llovido.
    int llover_material_aleatorio();

    //pre: -
    //post: Imprime en pantalla información del Material.
    void mostrar_informacion();
    
    private:

    //pre: -
    //post: Devuelve el nombre de un material según el número ingresado asociado.
    string obtener_tipo_material(int tipo_material);
};

#endif // MATERIAL_H_INCLUDED