#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char** argv) {
    pid_t pid;
    

  	pid = fork();

  	if(pid==0)
    {
      pid = fork();
      int status2;
      wait(&status2);
      sleep(3);

      printf("\nEstoy contando: ");
      for(int i = 0 ;  i < 100;i++)
      {
        printf("%d",i);  
      }
    }
    else
    {
	    int status;
	    wait(&status);
    	printf("\nSoy el padre,y mi identificador es %d\n",(int)getpid());
    }
	return 0;
}
