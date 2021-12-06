#include "grafo.h"

using namespace std;

int main() {

int cantidad_filas = 3;
int cantidad_columnas = 3;

int fila = 1;
int columna = 1;
int numero_vertice = 1;



Nodo Nodo(numero_vertice, cantidad_filas, cantidad_columnas, fila, columna);
	cout << Nodo.encontrar_tipo_nodo(fila, columna, cantidad_filas, cantidad_columnas) << endl;
	cout << Nodo.encontrar_tipo_nodo(2, 1,  3, 3) << endl;



/*
matriz_terrenos = new string* [3];
for(int h = 0; h < 3; h++){
	pmatriz_terrenos[h] = new string[3];
}
*/
string var_l = "L";
string var_t = "T";
string var_b = "B";
string var_m = "M";

string* p_terreno[6];
//string** terrenos = &p_terreno[0];
string** terrenos;
terrenos = p_terreno;

string terreno[6];
string terreno1[6];
string terreno2[6];
string terreno3[6];
string terreno4[6];
string terreno5[6];

terrenos[0] = terreno;
terrenos[1] = terreno1;
terrenos[2] = terreno2;
terrenos[3] = terreno3;
terrenos[4] = terreno4;
terrenos[5] = terreno5;

terreno[0] = var_l;
terreno[1] = var_b;
terreno[2] = var_b;
terreno[3] = var_b;
terreno[4] = var_b;
terreno[5] = var_l;

terreno1[0] = var_m;
terreno1[1] = var_l;
terreno1[2] = var_t;
terreno1[3] = var_m;
terreno1[4] = var_b;
terreno1[5] = var_l;

terreno2[0] = var_l;
terreno2[1] = var_b;
terreno2[2] = var_b;
terreno2[3] = var_b;
terreno2[4] = var_b;
terreno2[5] = var_m;

terreno3[0] = var_m;
terreno3[1] = var_b;
terreno3[2] = var_l;
terreno3[3] = var_t;
terreno3[4] = var_m;
terreno3[5] = var_l;

terreno4[0] = var_l;
terreno4[1] = var_b;
terreno4[2] = var_b;
terreno4[3] = var_b;
terreno4[4] = var_m;
terreno4[5] = var_m;

terreno5[0] = var_l;
terreno5[1] = var_l;
terreno5[2] = var_l;
terreno5[3] = var_b;
terreno5[4] = var_l;
terreno5[5] = var_l;

for (int i = 0; i < 6; i++){
	cout << endl;
	for (int j = 0; j < 6; j++){
		cout << terrenos[i][j] ;
	}
}


/*
matriz_terrenos[0][0] = &var_l;
matriz_terrenos[0][1] = &var_m;
matriz_terrenos[0][2] = &var_t;
matriz_terrenos[1][0] = &var_l;
matriz_terrenos[1][1] = &var_t;
matriz_terrenos[1][2] = &var_b;
matriz_terrenos[2][0] = &var_l;
matriz_terrenos[2][1] = &var_b;
matriz_terrenos[2][2] = &var_l;
*/

/*
Lista lista;

Lista* p_lista = &lista;

int num_nodo = 1;
for(int j = 1;j <= 6; j++){
	for(int i = 1;i <= 6; i++){

		lista.agregar(num_nodo, 6, 6, j, i);
		lista.devolver_nodo(num_nodo) -> cargar_vector_adyacentes();
		num_nodo++;
	}
}
*/


	/*
lista.agregar(1, 3, 3, 1, 1);
lista.devolver_nodo(1) -> cargar_vector_adyacentes();
lista.agregar(2, 3, 3, 1, 2);
lista.devolver_nodo(2) -> cargar_vector_adyacentes();
lista.agregar(3, 3, 3, 1, 3);
lista.devolver_nodo(3) -> cargar_vector_adyacentes();
lista.agregar(4, 3, 3, 2, 1);
lista.devolver_nodo(4) -> cargar_vector_adyacentes();
lista.agregar(5, 3, 3, 2, 2);
lista.devolver_nodo(5) -> cargar_vector_adyacentes();
lista.agregar(6, 3, 3, 2, 3);
lista.devolver_nodo(6) -> cargar_vector_adyacentes();
lista.agregar(7, 3, 3, 3, 1);
lista.devolver_nodo(7) -> cargar_vector_adyacentes();
lista.agregar(8, 3, 3, 3, 2);
lista.devolver_nodo(8) -> cargar_vector_adyacentes();
lista.agregar(9, 3, 3, 3, 3);
lista.devolver_nodo(9) -> cargar_vector_adyacentes();
*/
Grafo grafo(6,6);
//grafo.devolver_lista_vertices()->mostrar();
//lista.mostrar();



grafo.cargar_matriz_adyacencia(terrenos,6,6);
//grafo.mostrar_matriz_adyacencia();
grafo.calcular_camino_minimo_dijktra(2, 36);

}
