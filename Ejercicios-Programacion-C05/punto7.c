#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char** argv) {
    pid_t pid;
    

  	pid = fork();

  	if(pid==0)
    {
      printf("Hijo de pid: %d, cerrando standard output...\n",(int)getpid());
      close(STDOUT_FILENO);
      printf("Hijo tratando de escribir despues de cerrar");
      
    }
    else
    {
      printf("Soy el padre y mi hijo hara una locura me identifico con el pid: %d\n",(int)getpid());
	    int status;
	    waitpid(pid,&status,0);
    	printf("\nSoy el padre,y mi identificador es %d y el de mi hijo es %d\n",(int)getpid(),pid);
    }
	return 0;
}