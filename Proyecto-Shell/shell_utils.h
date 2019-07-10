
#ifndef __SHELL__
#define __SHELL__
int showHelp(char* SHELL,int size,int out,char filename[]);
int pauseOperation();
void echo(char stream_command[],int size,int out,char filename[]);
void dir(char* directory,char defaultDir[],int out,char filename[]);
int otherCommands(char* stream_command,int size,int out,char filename[]);
#endif