#include "planta_electrica.h"
#include "obelisco.h"
#include "mina.h"
#include "mina_oro.h"
#include "fabrica.h"
#include "escuela.h"
#include "aserradero.h"
#include "Registro_edificios.h"

int main(){
    Edificio * edificio_1;
    Edificio * edificio_2;
    Edificio * edificio_3;
    Edificio * edificio_4;
    Edificio * edificio_5;
    Edificio * edificio_6;
    Edificio * edificio_7;
    Edificio * edificio_8;
    edificio_1 = new Escuela(100, 200, 150, 1,0,5);
    edificio_2= new Obelisco(100, 180, 200, 1,3,0);
    edificio_3 = new Escuela(90,90,200,1,0,6);
    edificio_4 = new Mina(80,90,100,2,4,9);
    edificio_5 = new Mina_oro(100,60,20,1,8,2);
    edificio_6 = new Fabrica(70,80,50,3,5,0);
    edificio_7 = new Aserradero(70,40,100,3,4,7);
    edificio_8 = new Planta_electrica(50, 200, 45, 2 , 3, 9);
    Registro_edificios* registroEdificios_1 = new Registro_edificios();
    registroEdificios_1->agregar(edificio_1);
    registroEdificios_1->agregar(edificio_2);
    registroEdificios_1->agregar(edificio_3);
    cout<<"\nagrego edificios" << endl;
    cout<< "cantidad de obeliscos : " << registroEdificios_1->obtener_cantidad_obeliscos()<<endl;
    registroEdificios_1->mostrar_registro_edificios();
    cout<< "\nposicion edificio de coordenadas (0,5) en el registro ->> " << registroEdificios_1->buscar_posicion(0,5) << endl;
    registroEdificios_1->eliminar(3,0); //ARREGLAR METODOD ELIMINAR
    cout << "\nelimina obelisco posicion (3,0)\n" << endl;
    cout<<registroEdificios_1->existe(3,0)<< " --> deberia tirarme 0 (false) porque el edificio en esa posicion ya se elimino\n"<< endl;
    registroEdificios_1->mostrar_registro_edificios();
    cout << registroEdificios_1->posicion_valida_a_consutar(2) << " --> deberia tirarme 0 (false) porque en el registro se empieza a contar desde 0 . Hay solo 2 edificios en posiciones 0 y 1."<< endl;
    cout << "\ncantidad edificios: " << registroEdificios_1->obtener_cantidad_edificios() << endl << endl;
    cout << registroEdificios_1->obtener_nodo(9) << " --> deberia devolverme mensaje que niega accion y solo devuelve nullptr\n" << endl;
    cout << registroEdificios_1->obtener_nodo(1)<< " --> no deberia devolverme mensaje. solo la direccion del nodo." << endl << endl;
    registroEdificios_1->agregar(edificio_4);
    registroEdificios_1->agregar(edificio_5);
    registroEdificios_1->agregar(edificio_6);
    registroEdificios_1->agregar(edificio_7);
    registroEdificios_1->agregar(edificio_8);
    cout<<"\nagrego edificios." << endl;
    registroEdificios_1->mostrar_registro_edificios();
    registroEdificios_1->eliminar(4,7);
    cout << "\nelimino aserradero en (4,7) " << endl;
    registroEdificios_1->mostrar_registro_edificios();
    registroEdificios_1->eliminar(10,10);
    cout << "No deberia dejarme eliminar un edificio que no existe en el registro" << endl;
    registroEdificios_1->~Registro_edificios();
    delete edificio_1;
    delete edificio_2;
    delete edificio_3;
    delete edificio_4;
    delete edificio_5;
    delete edificio_6;
    delete edificio_7;
    delete edificio_8;
    string op;
    cout<<"cualquier tecla + ENTER para salir."<<endl;
    cin >> op;
    return 0;
}