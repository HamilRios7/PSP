#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];

    pipe(fd);
    pid_t pid = fork();



    if (pid == 0) {
        char entrada[10];
        int total = 0;
        int numero1;

        close(fd[1]);
        sleep(10);
        while (read(fd[0], entrada, sizeof(entrada)) ) {
            if (strcmp(entrada, "+") != 0) {
                numero1 = atoi(entrada);
                printf("El numero es %d\n", numero1);
                total += numero1;
            } else {
                printf("El operador es %s\n", entrada);
             
            }
        }

        printf("El total es %d\n", total);
        close(fd[0]);

    } else {
        close(fd[0]);
        char entrada[10];

        do {
            printf("Introduce los numeros (+ para terminar): \n");
            scanf("%c", entrada);

            write(fd[1], entrada, sizeof(entrada));

        } while (strcmp(entrada, "+") != 0);

        close(fd[1]);
        wait(NULL);

        printf("He terminado soy padre\n");
    }

    return 0;
}
