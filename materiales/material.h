#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Material {

    protected:
 
    string nombre_material;
    const  char* diminutivo;
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
    
    // Constructor con 1 parámetros.
    //pre: -
    //post: Instancia un Material "standard"
    Material(int cantidad_material);

    //Saluda
    //PRE: -
    //POST: Cada material saluda.
    virtual void saludar() = 0;

    //pre: -
    //post: Devuelve el nombre del Material.
    string obtener_nombre();
    
    //Obtener diminutivo
    //PRE: -
    //POST: Devuelve el diminutivo del material
    const char* obtener_diminutivo();

    //pre: -
    //post: Devuelve la cantidad del Material.
    int obtener_cantidad();

    //pre: -
    //post: Suma el cantidad a la 'cantidad_material'.
    void sumar_cantidad(int cantidad);

    //pre: -
    //post: Resta cantidad a la 'cantidad_material'.
    void restar_cantidad(int cantidad);
    
};

#endif // MATERIAL_H_INCLUDED