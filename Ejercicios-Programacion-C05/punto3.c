#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    pid_t pid;

  	pid = fork();

  	if(pid==0)
    {

	    
    	printf("Hello \n");  
  	       
    } 
    else
    {
	    sleep(10);
    	printf("Goodbye\n");
  	  
    }
	return 0;
}