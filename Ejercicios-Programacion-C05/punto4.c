#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;
    

  	pid = fork();

  	if(pid==0)
    {

	  sleep(3);
	  char *myargs[2];
	  myargs[0] = strdup("/bin/ls");
	  myargs[1] = strdup("-l");
	  myargs[2] = NULL;
	  //execl(myargs[0],myargs);
	  //execle(myargs[0],myargs);
	  //execlp(myargs[0],myargs);
	  execv(myargs[0],myargs);
	  //execvp(myargs[0],myargs);
	  //execvpe(myargs[0],myargs);

      
    } 
    else
    {
	  int status;
	  wait(&status);
      printf("\nEscribio el padre\n");
    }
	return 0;
}