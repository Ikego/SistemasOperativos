#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char** argv) {
    pid_t pid;
    

    int file = open("/home/miguel/Escritorio/archivo",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);
    if( file < 0)
    {
      printf("Error al abrir el archivo");
      return 1;
    }

  	pid = fork();

  	if(pid==0)
    {

	    sleep(3);
      write(file,"Escribio el hijo\n",17);
      
    } 
    else
    {
	    int status;
	    wait(&status);
      write(file,"Escribio el padre\n",18);
    }
	return 0;
}