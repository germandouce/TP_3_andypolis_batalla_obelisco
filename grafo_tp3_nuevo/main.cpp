#include "grafo.h"

using namespace std;

int main() {

Lista vertices;
vertices.agregar_vertices(4, 2, 2);
cout << vertices.devolver_nodo(1)-> obtener_vertice() -> obtener_numero_vertice() << endl;
cout << vertices.devolver_nodo(2)-> obtener_vertice() -> obtener_numero_vertice() << endl;
for (int i = 1; i <= 4; i++){
    cout << vertices.devolver_nodo(i)-> obtener_vertice() -> obtener_numero_vertice() << endl;
}

}
