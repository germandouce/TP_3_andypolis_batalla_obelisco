#ifndef VERTICE_H
#define VERTICE_H

class Vertice {
//ATRIBUTOS
private:
    int numero_vertice;
    int filas;
    int columnas;
    int posicion_x;
    int posicion_y;
    

//METODOS
public:
    //constructor sin parametros
    //pre:
    //post: inicializa el objeto sin parametros
    Vertice();

    //constructor con parametros(numero_vertice, fila, columna y coodernadas)
    //pre: 0 < numero_vertice < cantidad vertices, 0 < filas < cantidad de filas, 0 < columnas < cantidad de columnas
    // 0< posicion_x < filas , 0 < posicion_y < columnas.
    Vertice(int numero_vertice, int filas, int columnas, int posicion_x, int posicion_y);

    //pre:
    //post: devuelve el numero de vertice
    int obtener_vertice();

    //pre:
    //post: devuelve la cantidad de filas
    int obtener_fila();

    //pre:
    //post: devuelve la cantidad de columnas
    int obtener_columna();

    //pre:
    //post: devuelve la coordenada "x" que ocupa en la matriz
    int obtener_posicion_x();

    //pre:
    //post: devuelve la coordena "y" que ocupa en la matriz
    int obtener_posicion_y();
};
#endif //VERTICE_H
