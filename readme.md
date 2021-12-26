# Tp Andypolis: La batalla por el obelisco

## General

Parte 3 de 3 del trabajo práctico "Andypolis" de la materia Algoritmos y Programación II de FIUBA.
En esta tecera etapa se agrega agregan funcionalidades al programa para convertirlo en un juego que se gana construyendo un 
obelisco o cumpliendo objetivos secundarios. Para ello se incorporan 2 jugadores que tienen un inventario de materiales cada uno 
listado comun de edificos esturado en un diccionario que esta implementado como un ABB. También se agrega un grafo
para que los mismos se muevan por el mapa siguiendo el camino de menor peso (implementado mediante el algoritmo de Dijstra) y recolectando materiales que llueven en el mapa cada 2 turnos. 
Para información mas detallada leer el arhivo  "Andypolis la batalla por el obelisco v1.6.pdf".

## Partes previas
Para ver el código correspondiente a la parte 1 de 3 del trbajo práctico dirigirse a:
[Tp Andypolis: La constucción](https://github.com/germandus/Tp-Andypolis-la-construccion)

## Compilación y ejecución

El comando para compilar es el siguiente: 

g++ Casilleros/*.cpp grafo/*.cpp Inventario/*.cpp juego/*.cpp materiales/*.cpp objetivos/*.cpp registro_edificios/*.cpp  *.cpp -o andypolis -Wall -Werror -Wconversion

Luego de generado el ejecutable (en este 'andypolis.exe') ejecutarlo como cualquier otro programa de extensión .exe

