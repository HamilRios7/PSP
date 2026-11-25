#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>



int veces = 0;
int intervalo = 0;
int terminada = 0;

void manejar_alarma(int sig) {

    time_t hora;
    char *fecha ;
    time(&hora);
    fecha = ctime(&hora);

    printf("Señal de alarma recibida a las %s",fecha);

    veces--;
    if (veces > 0) {
        alarm(intervalo);
    } else {
        terminada = 1;
    }
}

int main() {
    printf("¿Cuántas veces sonará la alarma?:\n");
    scanf("%d", &veces);

    printf("¿Cada cuántos segundos se repetirá la alarma?:\n");
    scanf("%d", &intervalo);

    if (veces > 0 && intervalo > 0) {
        signal(SIGALRM, manejar_alarma);
        printf("Alarma activada\n");
        alarm(intervalo);

        while (terminada==0) {
            pause();
        }

        printf("Alarma desactivada\n");
    }

    return 0;
}
