# Tarea_01_ostep

## Integrantes:
* Miguel Reyes - 1729688
* David Gaona - 1729009
* Diego Hernandez - 1726042

## [mem.c](mem.c)
## [threads.c](threads.c)
Para arreglar el problema que se tenía en threads.c sin modificar, el cual era que se tenia una variable global a la cual los threads 
debian aumentarle en uno el valor n veces pero al pedirsele un número muy grande ocurrian inconsistencias en esto. Para resolverlo


## [io.c](io.c)
el metodo de dar el contenido de un archivo al revés, contiene dos parámetros el primero que es la invocación del metodo y el segundo que es el nombre del archivo, si en la terminal de linux se escribe menos o más de 2 argumentos sale un error indicando cómo llamar la función. En caso de que el usuario haya llamado bien la función el primer paso es comprobar que el archivo exista en caso de que no exista sale un error indicando que el archivo no existe, paso siguiente es abrir el archivo en modo de sólo lectura y utilizar el metodo fseek para colocarme en la posición final del archivo -2, después hacemos un ciclo desde la posición en la que estamos hasta que la posición llegue a uno, en estos ciclos hacemos lo siguiente: obtenemos el carácter de  la posición actual en la que estamos y lo mostramos en pantalla y decrementamos el contador para poder pararnos en la posición anterior a la que estamos. Y al final cuando la posición en la que estemos sea igual a 0 mostramos este último carácter cerramos la lectura del archivo y retornamos que todo salió bien con 0.
