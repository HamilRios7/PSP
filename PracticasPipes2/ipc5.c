#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int fd[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];
    pid_t pid , pid2;

    pipe(fd);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    

    pid = fork();

    if(pid!=0){
        pid2=fork();

    }
       if (pid == 0) {
        close(fd[1]);
        close(fd3[0]);
        
        int numero1, numero2,total;
        read(fd[0],&numero1, sizeof(numero1));
        read(fd[0],&numero2,sizeof(numero2));

        total=numero1+numero2;

        write(fd3[1],&total, sizeof(total));

        close(fd[0]); 
        close(fd3[1]);

    }else if(pid2 ==0 ){

        close(fd2[1]);
        close(fd4[0]);
        
        int numero1, numero2,total;
        read(fd2[0],&numero1, sizeof(numero1));
        read(fd2[0],&numero2,sizeof(numero2));

        total=numero1*numero2;

        write(fd4[1],&total, sizeof(total));

        close(fd2[0]); 
        close(fd4[1]);
    
    }else{
        close(fd[0]);
        close(fd2[0]);
        close(fd3[1]);
        close(fd4[1]);

        int numero1,numero2;
        int totalSum,totalMult;
        printf("Ingresa el numero 1 \n");
        scanf("%d", &numero1);
        printf("Ingresa el numero 2 \n");
        scanf("%d", &numero2);

        //escribo a hijo1
        write(fd[1],&numero1,sizeof(numero1));
        write(fd[1],&numero2,sizeof(numero2));


        //escribo a hijo2
        write(fd2[1],&numero1,sizeof(numero1));
        write(fd2[1],&numero2,sizeof(numero2));


        //leo de hijo1
        read(fd3[0],&totalSum,sizeof(totalSum));
        printf("La suma es %d \n" , totalSum );


        //leo hijo2
        read(fd4[0],&totalMult,sizeof(totalMult));
        printf("La multiplicacion es %d \n" , totalMult );

        wait(NULL);
        wait(NULL);
        close(fd[1]);
        close(fd2[1]);
        close(fd3[0]);
        close(fd4[0]);
    }

}
