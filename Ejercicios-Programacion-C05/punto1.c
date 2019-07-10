#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;
    
    int x = 100;

  	pid = fork();

  	if(pid==0)
    {

	    sleep(3);
    	printf("Soy el hijo y mi identificador es %d\n",(int) getpid());  
  	  printf("X del hijo es: %d\n",x);
      x = x - 5;
      printf("Nueva X del hijo es: %d\n",x);
      
    } 
    else
    {
	    int status;
	    wait(&status);
    	printf("Soy el padre,y mi identificador es %d y el de mi hijo es %d\n",(int)getpid(),pid);
  	  printf("X del padre es: %d\n",x );
      x = x + 3;
      printf("Nueva X del padre es:%d\n",x);
    }
	return 0;
}
