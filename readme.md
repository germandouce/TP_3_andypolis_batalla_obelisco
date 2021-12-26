# Tp Andypolis: La batalla por el obelisco

## Creditos
Este trabajo práctico fue realizado por un equipo de 4 personas:
[Jorge](https://github.com/blaufoxj), [Nicolas Centurión](https://github.com/NicolasCenturion), [Jose](https://github.com/Jsf-MK-ian) y [Germán Douce](https://github.com/germandus)

## General

Parte 3 de 3 del trabajo práctico "Andypolis" de la materia Algoritmos y Programación II de FIUBA.
En esta tecera etapa se agregan funcionalidades al programa para convertirlo en un juego que se gana construyendo un 
obelisco o cumpliendo otros objetivos secundarios que el juego muestra a cada jugador. Para ello se incorporan 2 jugadores que tienen un inventario de materiales cada uno y un listado común de edificos estructurado en un diccionario que esta implementado como un ABB. También se agrega un grafo para que los mismos se muevan por el mapa siguiendo el camino de menor peso (implementado mediante el algoritmo de Dijstra) y recolectando materiales que llueven en el mapa cada 2 turnos. 
Para información mas detallada leer el archivo  "Andypolis la batalla por el obelisco v1.6.pdf".

## Partes previas
Para ver el código correspondiente a la parte 2 de 3 del trbajo práctico dirigirse a:
[Tp Andypolis: La constucción](https://github.com/germandus/Tp-Andypolis-la-construccion)

## Compilación y ejecución

El comando para compilar es el siguiente: 

g++ Casilleros/*.cpp grafo/*.cpp Inventario/*.cpp juego/*.cpp materiales/*.cpp objetivos/*.cpp registro_edificios/*.cpp  *.cpp -o andypolis -Wall -Werror -Wconversion

Luego de generado el ejecutable (en este 'andypolis.exe') ejecutarlo como cualquier otro programa de extensión .exe

