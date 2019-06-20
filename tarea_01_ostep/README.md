# Tarea_01_ostep

## Integrantes:
* Miguel Reyes - 1729688
* David Gaona - 1729009
* Diego Hernandez - 1726042

## [mem.c](mem.c)
Se deshabilitó la generación aleatoria de direcciones de memoria en el equipo. Esto con el fin de ver la virtualización de la memoria, de como cada proceso tiene su propia región de memoria, y que a pesar de que dos procesos accedan a una misma dirección de memoria, cada proceso solo accede a sus propias variables.
Para compilar el programa se hace con el comando:
```
gcc mem.c -o mem
```
Para correr el programa se hace con el comando: 
```
./mem n
```
donde n es un número entero.

## [threads.c](threads.c)
Para arreglar el problema que se tenía en threads.c sin modificar, el cual era que se tenía una variable global a la cual los threads 
debían aumentarle en uno el valor n veces pero al pedírsele un número muy grande ocurrían inconsistencias en esto. Para resolverlo se usó principalmente ```#include pthread.h```el cual nos permite crear puertas con metodos para bloquearlas, abrirlas y destruirlas; para que cuando un thread entre a hacer los incrementos, cierre la puerta y cualquier otro thread no pueda hacer esta operación hasta que el thread que cerro la puerta la vuelva a abrir y asi poder evitar estas inconsistencias ocurridas. Para poder hacer esto, se definió una puerta de manera global y cuando se verifica que todo es correcto se crea, después cuando un thread entra a operar el counter antes de hacerlo n veces cierra la puerta y cuando termina la abre, por último antes de finalizar el programa se destruye la puerta y se retorna 0 diciendo que todo salió bien.

Para compilar el programa se hace con el comando:
```
gcc thread.c -o thread -lpthread
```
Para correr el programa se hace con el comando:
```
./thread n
```
donde n es un número entero.

## [io.c](io.c)
El programa de dar el contenido de un archivo al revés; contiene dos parámetros, el primero que es la invocación del programa y el segundo que es el nombre del archivo, si en la terminal de linux se escribe menos o más de 2 argumentos sale un error indicando cómo llamar la función. En caso de que el usuario haya llamado bien la función el primer paso es comprobar que el archivo exista en caso de que no exista sale un error indicando que el archivo no existe, el paso siguiente es abrir el archivo en modo de solo lectura y utilizar el metodo fseek para colocarme en la posición final del archivo -2, después hacemos un ciclo desde la posición en la que estamos hasta que la posición llegue a uno, en estos ciclos hacemos lo siguiente: obtenemos el carácter de la posición actual en la que estamos y lo mostramos en pantalla y decrementamos el contador para poder pararnos en la posición anterior a la que estamos. Y al final cuando la posición en la que estemos sea igual a 0 mostramos este último carácter cerramos la lectura del archivo y retornamos que todo salió bien con 0.

Para compilar el programa se hace con el comando:
```
gcc io.c -o io
```
Para correr el programa se hace con el comando:
```
./io a
```
donde a es el nombre del archivo a invertir.

