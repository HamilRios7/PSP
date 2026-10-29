#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
int main() {
    const char *fifo = "canal_num";
    const char *fifo2 = "canal_num";
    time_t t;
    int numero1;
    srand((unsigned) time(&t));
    numero1=rand() % 10; 

    // Crear FIFO si no existe
    mkfifo(fifo, 0666);
    mkfifo(fifo2, 0666);

    
    

    // Abrir FIFO para escritura (bloquea hasta que el lector abra)
    int fd = open(fifo, O_WRONLY);
   

    // Escribir el número en la FIFO
    if (write(fd, &numero1 ,sizeof(numero1)) == -1) {
        printf("escritor: error al escribir");
    } else {
        printf(" Número %d enviado al lector.\n", numero1);
    }

    //abrir fifo lecutra
    fd = open(fifo2, O_RDONLY);
   

    int solucionFact;
    // leer el número en la FIFO
    if (read(fd, &solucionFact ,sizeof(solucionFact)) == -1) {
        printf("escritor: error al escribir");
    } else {
        printf("El factorial es %d.\n", solucionFact);
    }


    close(fd);
   
    return 0;
}
