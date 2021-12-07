#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <iostream>

using namespace std;


const int PRIMER_POSICION = 1;
const int PRIMER_FILA = 1;
const int PRIMER_COLUMNA = 1;

class Vertice {
//ATRIBUTOS
private:
    int numero_vertice;
    int cantidad_filas;
    int cantidad_columnas;
    int fila;
    int columna;
    

//METODOS
public:
    //constructor sin parametros
    //pre:
    //post: inicializa el objeto sin parametros
    Vertice();

    //constructor con parametros(numero_vertice, fila, columna y coodernadas)
    //pre: 0 < numero_vertice < cantidad vertices, 0 < cantidad_filas < cantidad de cantidad_filas, 0 < cantidad_columnas < cantidad de cantidad_columnas
    // 0< fila < cantidad_filas , 0 < columna < cantidad_columnas.
    Vertice(int numero_vertice, int cantidad_filas, int cantidad_columnas, int fila, int columna);

    //pre:
    //post: devuelve el numero de vertice
    int obtener_numero_vertice();

    //pre:
    //post: devuelve la cantidad de cantidad_filas
    int obtener_cantidad_filas();

    //pre:
    //post: devuelve la cantidad de cantidad_columnas
    int obtener_cantidad_columnas();

    //pre:
    //post: devuelve la coordenada "x" que ocupa en la matriz
    int obtener_fila();

    //pre:
    //post: devuelve la coordena "y" que ocupa en la matriz
    int obtener_columna();
};
#endif //VERTICE_H
