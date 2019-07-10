1.[punto1.c](punto1.c) la variable tendrá el valor de 100 en el hijo(la misma que el padre)  y si los dos modifican el valor de la variable lo que sucederá es que,en este caso cada uno modificará el valor de 100 independientemente del otro.

2.[punto2.c](punto2.c) o [punto2v2.c](punto2v2.c) los dos pueden acceder al archivo y si los dos están escribiendo en él al mismo tiempo puede llegar a intercalarse lo que tiene que escribir el uno con el otro sino se está sobrescribiendo el archivo; si se está sobrescribiendo, dejará escrito lo que hiciera el último en terminarse.

3.[punto3.c](punto3.c) sí, haciendo uso de un sleep(n).
 
4.[punto4.c](punto4.c) hay varias variantes del exec para poder realizarla dependiendo de los datos que se tengan.

5.[punto5.c](punto5.c) el wait retorna el ID de un dead children. Mientras el hijo no hiciera ningun fork() entonces el wait() en él no esperará por nada y se seguirá ejecutando común y corriente.

6.[punto6.c](punto6.c) waitpid() puede ser util cuando se necesita hacer una espera más detallada respecto a un hijo/s especifico/s y además que provee otras opciones que el wait() no.

7.[punto7.c](punto7.c) si el hijo cierra el standard output y después trata de hacer un printf() no imprimirá nada pues ha cerrado su propia salida standard.
