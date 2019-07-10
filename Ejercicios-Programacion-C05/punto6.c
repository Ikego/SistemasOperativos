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
      pid = fork();
      int status2;
      waitpid(pid,&status2,0);
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
	    waitpid(pid,&status,0);
    	printf("\nSoy el padre,y mi identificador es %d y el de mi hijo es %d\n",(int)getpid(),pid);
    }
	return 0;
}