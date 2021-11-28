#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Objeto {

    protected:
    
    string nombre;
    string diminutivo;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un objeto con su nombre
    Objeto();
    
    //pre: -
    //post: Devuelve el nombre del objeto.
    //¡¡¡ ---- ESTE SI!!!!!!!!! PARA DECIR QUE HAY EN EL CASILLERO!!!!
    virtual string obtener_nombre() = 0;

    //¡¡¡ ---- ESTE SI!!!!!!!!! PARA MOSTRAR MAPA POR PANTALLA!!!!
    // PRE: 
    // POS: Devuelve el diminutivo del objeto
    // virtual string obtener_diminutivo() = 0;

    //ESTE METODO NO SERIA NECESARIO AQUI!!!!!
    virtual int obtener_cantidad_brindada() = 0;

    //CREO Q TAMPOCO SERIA SERIA NECESARIO !!!! 
    virtual int obtener_cantidad() = 0;
    // //pre: -
    // //post: Devuelve la cantidad del objeto.
    // //virtual int obtener_cantidad();

    
    ~Objeto();
}; 

#endif // OBJETO_H