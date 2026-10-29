#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int fd[2];
    int fd2[2];
  
    pipe(fd);
    pipe(fd2);

    pid_t pid = fork();


       if (pid == 0) {
       
        int fact;
        read(fd[0], &fact , sizeof(fact));
        if(fact==0){
            fact=1;
        }else{
            for (int i = fact - 1; i>0;i--){
                fact = fact * i;
            }
        }
        printf("HIJO ha calculado y mandado al pipe2 \n");
        write(fd2[1], &fact , sizeof(fact) );
        
        close(fd[0]); 
        close(fd2[1]);
        printf("HIJO ha terminado \n");

    }
    else {
        time_t t;
        srand((unsigned) time(&t));
        int numRandom = rand() % 10;
        int factLeido;
        write(fd[1], &numRandom , sizeof(numRandom) );
        printf("El proceso padre genera el numero %d en el pipe1 \n" , numRandom);

       
        printf("Padre lee el pipe2 \n");
        read(fd2[0], &factLeido, sizeof(factLeido));

        printf("El factorial calculado por el proceso hijo: %d != %d \n" , numRandom , factLeido);
        close(fd[1]); 
        close(fd2[0]);
        
        wait(NULL);
        printf("PADRE ha terminado \n");

    }

}
