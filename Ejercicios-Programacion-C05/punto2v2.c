#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char** argv) {
    pid_t pid;
    

    int file = open("/home/miguel/Escritorio/archivov2",O_RDWR | O_CREAT |O_APPEND, S_IRUSR | S_IWUSR);
    if( file < 0)
    {
      printf("Error al abrir el archivo\n");
      return 1;
    }

  	pid = fork();

  	if(pid==0)
    {
	    for(int i = 0; i < 1000000;i++)
      {
        write(file,"1",1);
      }
      
      
    } 
    else
    {
	    for(int i = 0; i < 1000000; i++)
      {
        write(file,"0",1);
      }
      
    }
	return 0;
}