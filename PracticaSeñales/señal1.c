#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>




void manejar_sigint(int sig) {
    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora);


     printf("Fin del proceso %d : %s \n",getpid() ,fecha);
   
}

int main() {
   
    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora);

    printf("Inicio del proceso %d : %s \n",getpid(),fecha);

    signal(SIGINT, manejar_sigint);

    pause();

    return 0;
}
