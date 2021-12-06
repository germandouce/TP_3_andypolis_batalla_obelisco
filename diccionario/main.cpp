#include <fstream>

#include "diccionario.h"

using namespace std;

int main() {
    ifstream archivo("edificios.txt");
    string nombre_edificio;
    int cantidad_material, cantidad_madera, cantidad_piedra, cantidad_metal, maximo;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de materiales." << endl;
        return false;
    }
    else {
        string * edificio;
        Diccionario<string> *dict_edif ;
        while (archivo >> nombre_edificio) {
            archivo >> cantidad_piedra;
            archivo >> cantidad_madera;
            archivo >> cantidad_metal;
            archivo >> maximo;

            edificio = &nombre_edificio;
            cout<<*edificio<<endl;
            dict_edif ->agregar_dato(edificio);
            cout <<"hola";
            cout<<edificio<<endl;

    archivo.close();
    }
    }
}