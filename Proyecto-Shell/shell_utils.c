#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int showHelp(char* HELP,int size,int out,char filename[])
{
    char PATH_MAN[size];
    strcpy(PATH_MAN,HELP);
    strcat(PATH_MAN,".help");
    __pid_t rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Failed to create process child\n");
        return -1;
    }else if (rc == 0)
    {
        if(out == 0)
        {
            close(STDOUT_FILENO);
            open(filename,O_CREAT|O_WRONLY|O_TRUNC,0666);
        }
        char *myargs[4];
        myargs[0] = strdup("more");
        myargs[1] = strdup("-6");
        myargs[2] = strdup(PATH_MAN);
        myargs[3] = NULL;
        execvp(myargs[0],myargs);
    }else
    {   
        int status_code;
        __pid_t rc_wait = wait(&status_code);
        if(status_code != 0)
        {
            fprintf(stderr,"An Errror ocurred until read manual page\n   ");
            return -1;
        } 
    }
    
    return 0;

}

int otherCommands(char* stream_command,int size,int out,char filename[])
{
    __pid_t rc = fork();
    if (rc < 0)
    {
        fprintf(stderr,"Failed to create process child\n");
        return -1;
    }
    else if ( rc == 0)
    {
        if(out == 0)
        {
            close(STDOUT_FILENO);
            open(filename,O_CREAT|O_WRONLY|O_TRUNC,0666);
        }
        int first = 1;
        int gotted = 0;
        int wasCreated = 0;
        char buffer[512];
        strcpy(buffer,"/bin/");
        char buffer2[512];
        strcpy(buffer2,"");
        for(int i = 0 ; i < size; i++)
        {
            

            if(first == 1)
            {
                if('\t' == stream_command[i] || ' ' == stream_command[i])
                {
                    if(gotted == 1)
                    {
                        first = 0;
                    }
                }
                else if('\0' == stream_command[i])
                {
                    break;
                }
                else if (gotted == 1)
                {
                    strncat(buffer,&stream_command[i],1);
                }
                else
                {
                    strncat(buffer,&stream_command[i],1);
                    gotted = 1;
                }
            }
            else if('\0' == stream_command[i])
            {
                break;
            }
            else
            {
                if('\t' != stream_command[i] || ' ' != stream_command[i])
                {
                    wasCreated = 1;
                }
                strncat(buffer2,&stream_command[i],1);
            }
        }
        if(wasCreated == 1)
        {
            char *myargs[2];
            myargs[0] = strdup(buffer);
            myargs[1] = strdup(buffer2);
            myargs[2] = NULL;
            execv(myargs[0],myargs);
            
        }else
        {
            char *myargs[2];
            myargs[0] = strdup(buffer);
            myargs[1] = NULL;
            execv(myargs[0],myargs);
        }
    }
    else
    {
        int status_code;
        __pid_t rc_wait = wait(&status_code);
        if(status_code != 0)
        {
            fprintf(stderr,"Failed to create a new process");
            return -1;
        } 
    }
}

int pauseOperation()
{
    int back  = 1;
    printf("Press Enter to continue ... \n");
    int firstChar = 10;
    int newChar;
    while (back)
    {
        newChar = getchar();
        if(firstChar == 10 && newChar == 10)
        {
            back = 0;
        }
        else
        {
            firstChar = newChar;
        }
    }

    return 0;
}

void echo(char stream_command[],int size,int out,char filename[])
{

     __pid_t rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Failed to create process child\n");
        exit(EXIT_FAILURE);
    }else if (rc == 0)
    {
        if (out == 0)
        {
            close(STDOUT_FILENO);
            open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
        }
        int enter = 1;
        for (int i = 4; i < size; i++)
        {
            if ('\t' == stream_command[i] || ' ' == stream_command[i])
            {
                if (enter)
                {
                    printf(" ");
                    enter = 0;
                }
            }
            else if ('\0' == stream_command[i])
            {
                break;
            }
            else
            {
                printf("%c", stream_command[i]);
                enter = 1;
            }
        }
        printf("\n");
        exit(0);
    }else
    {
        int status_code;
        __pid_t rc_wait = wait(&status_code);
        if(status_code != 0)
        {
            fprintf(stderr,"An Errror ocurred to display echo");
        }        
    }
}    
    

void dir(char* directory,char defaultDir[],int out,char filename[])
{
     __pid_t rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Failed to create process child\n");
        exit(EXIT_FAILURE);
    }else if (rc == 0)
    {
        if (out == 0)
        {
            close(STDOUT_FILENO);
            open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
        }
        DIR *dp;
            struct dirent *ep;

            if(directory == NULL)
            {
                dp = opendir(defaultDir);
            }else{
                dp = opendir(directory);
            }
            if(dp != NULL)
            {
                ep = readdir(dp);
                while (ep = readdir(dp))
                {
                    printf("%s\n",ep->d_name);
                }
                printf("\n");
                (void) closedir(dp);                
            }else
            {
                exit(EXIT_FAILURE);
            }
            exit(0);
    }else
    {
        int status_code;
        __pid_t rc_wait = wait(&status_code);
        if(status_code != 0)
        {
            fprintf(stderr,"Can't open directory or directory does not exist\n");
        }        
    }
}
