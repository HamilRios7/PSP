#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int fd[2];
  
    pipe(fd);

    pid_t pid = fork();

    
    if (pid == 0) {
        close(fd[0]);
        time_t t;
        srand((unsigned) time(&t));
        int numeroCalculo1;
        int numeroCalculo2;
        for (int i = 0; i < 2; i++) {
            numeroCalculo1 = rand() % 50;
            numeroCalculo2 = rand() % 50;
        }

        write(fd[1], &numeroCalculo1, sizeof(numeroCalculo1));
        write(fd[1], &numeroCalculo2, sizeof(numeroCalculo2));
        printf("Ya los he mandado \n");
        close(fd[1]);
        printf("HIJO ha terminado \n");

    }
    else {
        close(fd[1]);
        
          int numeroCalculo1;
        int numeroCalculo2;
        sleep(3);
        read(fd[0], &numeroCalculo1, sizeof(numeroCalculo1));
        read(fd[0], &numeroCalculo2, sizeof(numeroCalculo2));
      

        printf("La suma es %d + %d = %d \n " , numeroCalculo1, numeroCalculo2, numeroCalculo1 + numeroCalculo2);
        printf("Resta es %d - %d = %d \n " ,numeroCalculo1, numeroCalculo2 , numeroCalculo1- numeroCalculo2);
        printf("La multiplicación es %d * %d = %d \n " , numeroCalculo1, numeroCalculo2 , numeroCalculo1* numeroCalculo2);
        printf("La división es %d / %d = %d \n " ,numeroCalculo1, numeroCalculo2 , numeroCalculo1/ numeroCalculo2);
   
        close(fd[1]); 
        wait(NULL);
        printf("PADRE ha terminado \n");

    }


}
