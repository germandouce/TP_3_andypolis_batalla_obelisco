Cada carpeta posee su propio main para ser probada por separado. EXCEPTO JUEGO.H cuyo main esta solo
para detectar errores gruesos que saltan con extensiones de VSC.
Por otro lado, los archivos que se encuentran dispersos en la carpeta actual 
SI COMPILAN CON EL SIGUIENTE COMANDO: 

g++ edificios/*.cpp materiales/*.cpp casilleros/*.cpp grafo/*.cpp *.cpp -o main -Werror -Wconversion -Wall

Muchas gracias :) !