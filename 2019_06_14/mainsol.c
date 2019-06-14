#include "solucion.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  int x = 20;
  pid_t pid;

  pid = fork();

  if(pid == 0){
   printf("Soy el hijo \n");
   
   printf("  calculo fibonacci\n");
   x = fibonacci(x);
   printf("  guardo el valor calculado en archivo 'X'");
   guardarEntero("archivo",x);
   printf("  fibonacci: %d\n",x);
  }
  else{
   int status;
   wait(&status);
   printf("soy el padre \n");
   printf("  espero a que termine mi hijo\n");
   printf("  leo el valor que calculo mi hijo del archivo 'X'\n");
   printf("  multiplico por 100 e imprimo por pantalla el resultado: ");
   int respuesta = leerEntero("archivo") * 100;
   printf("%d\n",respuesta);
  }

  return 0;
}
