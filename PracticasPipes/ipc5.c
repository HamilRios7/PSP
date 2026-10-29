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
       
        close(fd[0]); 
        close(fd2[1]); 
        char letra;
        int DNI;
        printf("Ingresa solo el numero del DNI: ");
        scanf("%d", &DNI);
        if( DNI > 99999999 || DNI < 10000000 ){
            printf("Error. Ese no puede ser tu numero de DNI");
            exit(0);
        }

        write(fd[1], &DNI , sizeof(DNI));
        //Aqui lee lo que llega
        read(fd2[0], &letra , sizeof(letra));
         printf("Tu DNI es %d \n" , DNI);
         printf("Y su letra es la %c \n" , letra);

        close(fd[1]); 
        close(fd2[0]);

    }else {

         close(fd[1]); 
        close(fd2[0]);
        
        int DNI;
        read(fd[0], &DNI , sizeof(DNI));

        int calculo;
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
     
        int resto =DNI % 23;
        char letraDni = letra[resto];
        

        write(fd2[1], &letraDni, sizeof(letraDni));


        wait(NULL);   
        close(fd[0]); 
        close(fd2[1]);
    
    }

}
