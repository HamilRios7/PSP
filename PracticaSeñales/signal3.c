#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


void manejar_sigint(int sig) {
    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora);



    FILE *fichero = fopen("salidas.txt", "a"); 
   fprintf(fichero,"Señal SIGINT recibida a las %s" , fecha);
   fclose(fichero);
}

int main() {
     signal(SIGINT, manejar_sigint);
    while(1){

    pause();
    }
    return 0;
}
