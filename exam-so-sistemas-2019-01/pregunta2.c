#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile float v;
puerta puertaP;
 
int loops;

void *worker(void *arg) {
	cerrar_puerta(puertaP);
    int y = 350;
    int z = 25;
    sleep(2);
    v =(float) z / y;
    abrir_puerta(puertaP);
    return NULL;
}

void *worker2(void *arg){
	cerrar_puerta(puertaP);
	int x = 1250;
	v = (float) x * v; 
	abrir_puerta(puertaP);
	return NULL;
}

int main(int argc, char *argv[]) {
   
    crear_puerta(puertaP);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("El resultado x*(z/y) es : %f\n", v);
    destruir_puerta(puertaP);
    return 0;
}
