#include <iostream>
#include "lista.h"
#include <ctime>
// #include "casillero_transitable.h"

using namespace std;


int generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);

}

void consultar_material_a_colocar(int &cant_gen_piedras, int &cant_gen_maderas, int &cant_gen_metales, string &material_a_colocar ){
    if (cant_gen_piedras){
        material_a_colocar = "piedra";
        cant_gen_piedras --;

    } else if (cant_gen_maderas){
        material_a_colocar = "madera";
        cant_gen_maderas --;

    } else{
        material_a_colocar = "metal";
        cant_gen_metales --;
    }
}

void mostrar_alerta_materiales_no_colocados(int materiales_restantes, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales){
    cout <<endl<<"No se pudieron colocar los siguientes " <<materiales_restantes 
    << " materiales porque los casilleros transitables ya estan todos ocupados: "<<endl;
    if (cant_gen_piedras > 0){
        cout<<cant_gen_piedras <<" unidades de piedra"<<endl;
    }
    if (cant_gen_maderas > 0){
        cout<<cant_gen_maderas <<" unidades de madera" <<endl;
    }
    if (cant_gen_metales > 0){
        cout<<cant_gen_metales <<" unidades de metal " <<endl;
    }
}


void colocar_materiales_llovidos(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales, 
Lista *casilleros_habilitados){

    string material_a_colocar = "";
    int materiales_restantes = tot_materiales_gen;

    while (materiales_restantes >0 && 100 >0){

        consultar_material_a_colocar(cant_gen_piedras, cant_gen_maderas, cant_gen_metales, material_a_colocar);

        int pos_coordenada =  generar_numero_random( 0, casilleros_habilitados->Obtener_cantidad() - 1);
        
        //int fila =  obtener_casillero_vector_casilleros_lluvia(pos_coordenada) ->obtener_fila() ;
        //int columna =  obtener_casillero_vector_casilleros_lluvia(pos_coordenada) ->obtener_columna() ;
        
        int fila = casilleros_habilitados->consulta(pos_coordenada) -> obtener_fila();
        int columna = casilleros_habilitados->consulta(pos_coordenada) -> obtener_col();

        //mapa[fila][columna] -> agregar_material(material_a_colocar, 1);

        casilleros_habilitados ->baja(pos_coordenada);

        cout <<"1 unidad de " << material_a_colocar << " en " <<"("<< fila << ","  << columna <<")" << endl;

        //sacar_casillero(pos_coordenada);

        materiales_restantes --;
    }

    if ( materiales_restantes != 0 ){
        mostrar_alerta_materiales_no_colocados(materiales_restantes, cant_gen_piedras, cant_gen_maderas, cant_gen_metales);
    }

}



// Casillero_transitable* obtener_casillero_vector_casilleros_lluvia ( int pos) {
// 	return vector_casilleros_lluvia[pos];
// }


// void sacar_casillero(int posicion_numero_a_sacar){
    
//     if (total_casilleros > 1) {

//         //mando el q quiero elimnar a la ult pos y lo intercambio con ese
//         swap_casillero(total_casilleros - 1, posicion_numero_a_sacar);
        
//         Casillero_transitable **vector_aux_casilleros_lluvia = new Casillero_transitable*[total_casilleros - 1];

//         for(int i = 0; i < total_casilleros - 1; i++){
//             vector_aux_casilleros_lluvia[i] = vector_casilleros_lluvia[i];
//             //Como esta en la ult pos nunca lo copio!
//         }
        
//         delete vector_casilleros_lluvia[total_casilleros - 1];
//         delete[] vector_casilleros_lluvia;


//         vector_casilleros_lluvia = vector_aux_casilleros_lluvia;

//     }else{
//         delete vector_casilleros_lluvia[total_casilleros - 1];
//         delete[] vector_casilleros_lluvia;
//     }

//     total_casilleros --;
// }

// void swap_casillero(int posicion_1, int posicion_2){
//     Casillero_transitable *aux = vector_casilleros_lluvia[posicion_1];
//     vector_casilleros_lluvia[posicion_1] = vector_casilleros_lluvia[posicion_2]; //mando al final (pos_1) el quiero eliminar(pos_2)
//     vector_casilleros_lluvia[posicion_2] = aux; //el ultimo lo pongo en donde estaba el que quiero eliminar
// }

// void agregar_casillero_a_vector_casilleros_lluvia (Casillero_transitable *casillero, int tam_nuevo, int pos ) {
    
//     Casillero_transitable** vector_aux = new Casillero_transitable*[tam_nuevo];

//     for (int i = 0; i<pos; i++){
//         vector_aux[i] = vector_casilleros_lluvia[i];
//     }

//     vector_aux[pos] = casillero;

//     if (total_casilleros != 0){
//         delete [] vector_casilleros_lluvia;
//         }

//     total_casilleros = tam_nuevo;
//     vector_casilleros_lluvia = vector_aux;
// }

void cargar_vector_casilleros_lluvia_con_casileros_permitidos(Lista *casilleros_habilitados){
    
    int pos = 0;
    Casillero_transitable* casillero_aux;

    for ( int i = 0; i < 10; i++){
        for ( int j = 0; j < 10 ; j++){
            //if (mapa[i][j] -> obtener_nombre() =="C" && !( mapa[i][j] -> existe_material() ) ){    
                
                casillero_aux = new Casillero_transitable(1,2);
                casilleros_habilitados -> alta(casillero_aux, pos);
                //agregar_casillero_a_vector_casilleros_lluvia(casillero_aux,pos+1, pos);
                
                pos+=1;
            }
        }
    }

void ejecutar_lluvia(int tot_materiales_gen, int cant_gen_piedras, int cant_gen_maderas, int cant_gen_metales,
int cant_gen_andycoins){
    
    Lista *casilleros_habilitados;

    casilleros_habilitados = new Lista;
    
    cargar_vector_casilleros_lluvia_con_casileros_permitidos(casilleros_habilitados);

    colocar_materiales_llovidos(tot_materiales_gen, cant_gen_piedras, cant_gen_maderas, cant_gen_metales, casilleros_habilitados);
    
    // int total_cas = 100;

    // for ( int i = 0; i < total_cas; i++){
    //     delete vector_casilleros_lluvia[i];
    //     total_casilleros--;
    // }
    // if (total_cas !=0){
    //     delete [] vector_casilleros_lluvia;
    //     vector_casilleros_lluvia = nullptr;
    // }
}

void lluvia_recursos(){

    srand( (unsigned)time(0) );

    int cant_gen_piedras = generar_numero_random(1,2); 
    int cant_gen_maderas = generar_numero_random(0,3);
    int cant_gen_metales = generar_numero_random(2,4);
    int cant_gen_andycoins = generar_numero_random(0,1);

    int tot_materiales_gen = cant_gen_piedras + cant_gen_maderas + cant_gen_metales + cant_gen_andycoins;
    
        
    cout << "Han llovido en el mapa " << tot_materiales_gen << " conjuntos de materiales: " <<endl
    <<cant_gen_piedras <<" conjuntos de piedra"<<endl
    <<cant_gen_maderas <<" conjuntos de madera" <<endl
    <<cant_gen_metales <<" conjuntos de metal " <<endl<<endl
    <<cant_gen_metales <<" bolsas de andycoins " <<endl<<endl
    <<"en las siguientes posiciones: "<< endl;

    ejecutar_lluvia(tot_materiales_gen,cant_gen_piedras, cant_gen_maderas, cant_gen_metales, cant_gen_andycoins);

    cout <<endl;
}


int main(){

    lluvia_recursos();

    // Pila p;
    // p.alta(5);
    // p.alta(8);
    // p.alta(3);
    // cout << "El ultimo elemento es: " << p.consulta() << endl;
    // p.baja();
    // cout << "El ultimo elemento es: " << p.consulta() << endl;
    // p.alta(7);

    // while (! p.vacia())
    //     cout << p.baja() << endl;


    // return 0;

}
