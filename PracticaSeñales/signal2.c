#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int segundos = 0;

void manejar_alarma(int sig) {
    segundos += 5;
    printf("Han transcurrido %d segundos\n", segundos);
    alarm(5); 
}

int main() {
    signal(SIGALRM, manejar_alarma);
    alarm(5); 

   while(1){
    pause(); 
   }

    return 0;
}
