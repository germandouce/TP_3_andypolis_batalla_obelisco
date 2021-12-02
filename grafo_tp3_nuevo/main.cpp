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


char ** matriz_terrenos;
/*
matriz_terrenos = new char* [3];
for(int h = 0; h < 3; h++){
	pmatriz_terrenos[h] = new char[3];
}
*/
char var_l = 'L';
char var_t = 'T';
char var_b = 'B';
char var_m = 'M';

char* p_terreno[3];
//char** terrenos = &p_terreno[0];
char** terrenos;
terrenos = p_terreno;

char terreno[3];
char terreno1[3];
char terreno2[3];

terrenos[0] = terreno;
terrenos[1] = terreno1;
terrenos[2] = terreno2;

terreno[0] = var_l;
terreno1[1] = var_b;
terreno2[2] = var_m;

cout << terrenos[1][1] << endl;
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


Lista lista;
Grafo grafo;


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

lista.mostrar();

//grafo.cargar_matriz_adyacencia(matriz_terrenos,3,3);
//grafo.mostrar_matriz_adyacencia();

}
