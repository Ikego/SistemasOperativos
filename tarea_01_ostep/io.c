#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    FILE* fp;
    int c;

    if (argc != 2) {
        fprintf(stderr, "usage: leerArchivoAlreves  <string>\n");
        exit(1);
    }
    if (access(argv[1], F_OK) != -1) {
        // file exists
        fp = fopen(argv[1], "r");
        int count = -2;
        fseek(fp, count, SEEK_END);
        while (ftell(fp) > 0) {
            c = fgetc(fp);
            printf("%c", c);
            fseek(fp, --count, SEEK_END);
        }
        c = fgetc(fp);
        printf("%c", c);
        printf("%s", "\n");
    }
    else {
        // file doesn't exist
        printf("El archivo no existe");
    }
    fclose(fp);
    return (0);
}
