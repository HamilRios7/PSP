#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo = "canal_num";
    
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

   int fd2 = open(fifo, O_WRONLY);

   write(fd2,&numero,sizeof(numero));

    close(fd);
    close(fd2);

    return 0;
}
