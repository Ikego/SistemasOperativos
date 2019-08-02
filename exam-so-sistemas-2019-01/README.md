# Examen Sistemas Operativos

## Pregunta 1
para tomar el tiempo 
definimos una variable t que toma el tiempo actual y antes de finalizar se imprime el tiempo actual menos la variable T, esto con una funcion que esta en [common.h](common.h)
[threads.c](threads.c) es quien usa las puertas fuera del for
[threadsDentroFor.c](threadsDentroFor.c) es quien usa las puertas dentro del for
## Pregunta 2

Para distinguir que debe hacer un hilo de otro se crean dos worker y se cierra la puerta cuando se entra a ejecutar las funciones worker y se abre cuando se termina
Quien resuelve esto es [pregunta2.c](pregunta2.c)

## Pregunta 3
