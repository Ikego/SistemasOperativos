#include "solucion.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
  int x = 20;
  pid_t pid;

  pid = fork();

  if(pid == 0){
   printf("fibonacci(%d)= ",x);
   x = fibonacci(x);
   printf("%d\n",x);
   guardarEntero("archivo",x);
  }
  else{
   int status;
   wait(&status);
   int respuesta = leerEntero("archivo") * 100;
   printf("la respuesta del padre es: %d\n",respuesta);
  }

  return 0;
}
