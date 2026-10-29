#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo = "canal_num";
    const char *fifo2 = "canal_num";
    // Abrir FIFO para lectura (bloquea hasta que el escritor escriba)
    int fd = open(fifo, O_RDONLY);
    
    int numero;
    // Leer el número enviado
    if (read(fd, &numero, sizeof(numero)) == -1) {
        printf("lector: error al leer");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if(numero == 0){
            numero = 1;
    }else{
        for (int i = numero - 1; i>0;i--){
            numero = numero * i;
        }
    }

   fd = open(fifo2, O_WRONLY);

   write(fd,&numero,sizeof(numero));

    close(fd);
    
    return 0;
}
