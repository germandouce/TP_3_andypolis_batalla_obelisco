#include <iostream>
#include "lista.h"

Lista::Lista() {
    //No esta bueno usar null. Mejor 0 q es una cte
    primero = 0;
    cantidad = 0;
}

int Lista::Obtener_cantidad(){
    return cantidad;
}

bool Lista::vacia() {
    return (cantidad == 0);
}


void Lista::alta(Dato d, int pos) {
    //3 opciones: en la 1era pos, al final o en el medio.
    //Las opciones de insertar en el medio o al final son la misma
    //pero con la diferencia de que hayq preguntar si es el primero 
    //o no
    //Primero creo 1 nuevo nodo y guardo su direc.
    Nodo* nuevo = new Nodo(d);
    std::cout << "Pido memoria en: " << nuevo << std::endl;
    
    //Va a guardar la posicion del primero
    Nodo* siguiente = primero;

    //Si la poscion es la primera (lo quiero mandar adelante de todo)
    if (pos == 1) {
        //El ptr primero ahora apunta a nuevo
        primero = nuevo;
    }
    //si no...      
    else {
        //Necesito contar hasta la pos anterior a donde quiero colocar.
        //Obtenego el nodo de la pos anterior a la que me pasaron
        Nodo* anterior = obtener_nodo(pos - 1);
        
        //Me conviene tener un ptr al siguiente del que estaba en la pos
        //en la q quiero colocar.(el que ahora va a ser el anterior)
        //Siguiente sera el siguiente nodo al q estoy agregando
        siguiente = anterior->obtener_siguiente();
        
        // le agrego al anterior un siguiente que es el que quiero agregar
        anterior->cambiar_siguiente(nuevo);
    }
    //Por ultimo hago apuntar al que acabo de agregar al siguiente
    nuevo->cambiar_siguiente(siguiente);
    
    //Aumento en 1 la cantidad de nodos
    cantidad++;
    
    //1)Creo el nodo
    //2)creo un objeto de tipo nodo y lo llamo siguiente. Lo hago apuntar al primero
    //3)si la pos en la q agrego es la primera apunto el ptr primero al nuevo sino...
    //4) Gurado la pos del anterior
    //5) Guardo la posicion del siguiente
    //6) Hago apuntar al anterior al nuevo
    //7)Tanto si quiero agregar en la primera pos o no, le agrego
    //como siguiente al nuevo nodo el q fije como siguiente(al que antes era el primero si no entro al if,
    //o el q fijo como sig en el if si lo estoy agregando en el medio o al final)
}

void Lista::baja(int pos) {
    //No devuelvo nada xq la idea es solo sacarlo.
    //Dos casos, si doy de baja en la primera, o si doy de baja en la 
    //primera o la ultima
    
    //Creo un nodo que apunta inicialmente al primero
    Nodo* baja = primero;
    //Si es la primera
    if (pos == 1)
        //El primero, que lo guarde en baja, apunta al siguiente
        //Si esta solo ese elemento, obtener_siguiente me devuelve un null
        //obtengo la pos del sig al que bajo y apunto el ptro primero a el.
        primero = baja->obtener_siguiente();
    else {
        //Guardo el anterior
        Nodo* anterior = obtener_nodo(pos - 1);
        
        //El q quiero dar de baja sera el siguiente del anterior
        baja = anterior->obtener_siguiente();
        
        //Ahora hago el saltito y hago apuntar al anterior del q saco al siguiente
        //del que saco. 
        //Cambiar siguiente es un metodo de nodo que espera un puntero
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    //Bajo en 1 la cantidad de nodos
    cantidad--;
    
    //libero la mem del nodo baja
    std::cout << "Libero memoria en: " << baja << std::endl;
    delete baja;

    //1)Creo un objeto tipo nodo llamdo baja y lo hago apuntar al primero
    //2)Si la posicion es 1 hago apuntar el primero al siguiente del q bajo (q era el primero) sino
    //3) Guardo el anterior
    //4) Gurado en baja la direc del siguiente al anterior (lo identifico comparandolo con el anterior)
    //5) Hago el saltito y hago apuntar al anterior al siguiente del que estoy bajando
    //5)Sea cual sea el que bajo, bajo uno la cantidad y libero memoria

}

Dato Lista::consulta(int pos) {
    //Obtengo el nodo y lo guardo en aux
    Nodo* aux = obtener_nodo(pos);
    //Devuelvo el dato de ese nodo aux
    return aux->obtener_dato();
}

Lista::~Lista() {
    //Mientras no este vacia la lista llamo a baja
    while (! vacia())
        baja(1);
}

Nodo* Lista::obtener_nodo(int pos) {
    //Esta privado xq no me interesa que lo use el ususario!
    Nodo* aux = primero;
    //Salta de un nodo al otro hasta llegar al nodo que quiero
    for (int i = 1; i < pos; i++)
        //va menor xq quiero el anterior a la pos q mando
        aux = aux->obtener_siguiente();
    return aux;
}

// void Lista::mostrar() {
//     //las clase que impriman deben ser epsciales xa imprimir ??
//     //No va como primitiva de lista
//     //Apunto al primero
//     Nodo* aux = primero;
//     //Mientras tenga alguno numero al q apuntar
//     while (aux) {
//         //Obtengo el dato
//         //std::cout << aux->obtener_dato() << " - ";
//         //Me muevo al siguiente
//         aux = aux->obtener_siguiente();
//     }
// }
