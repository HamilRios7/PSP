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
        close(fd[0]);
        close(fd3[1]);

        int numero ;
        int numeroComparar, total=0;

        read(fd3[0],&numero, sizeof(numero));
        numeroComparar=numero;
        total +=numero;

        for(int i=0 ; i <9 ; i++){
           
            read(fd3[0],&numero, sizeof(numero));
            total +=numero;
            if(numeroComparar<numero){
                numeroComparar=numero;
            }
            
        }
        total=total/10;
      
       
        write(fd[1],&total, sizeof(total));
        write(fd[1],&numeroComparar, sizeof(numeroComparar));

        close(fd[1]); 
        close(fd3[0]);

    }else if(pid2 ==0 ){

        close(fd2[0]);
        close(fd4[1]);
        
        int contadorApro=0, contadorSusp=0, numero;
         for(int i=0 ; i <10 ; i++){
           
            read(fd4[0],&numero, sizeof(numero));
            
            if(numero>=5){
                contadorApro++;
            }
            
        }
        contadorSusp=10-contadorApro;

        write(fd2[1],&contadorApro, sizeof(contadorApro));
        write(fd2[1],&contadorSusp, sizeof(contadorSusp));

        close(fd2[1]); 
        close(fd4[0]);
    
    }else{
        close(fd[1]);
        close(fd2[1]);
        close(fd3[0]);
        close(fd4[0]);

        int numero1,numero2;
        int totalSum,totalMult;
        for(int i=0 ; i <10 ; i++){
            printf("Ingresa las notas \n");
            scanf("%d", &numero1);
            write(fd3[1],&numero1,sizeof(numero1));
            write(fd4[1],&numero1,sizeof(numero1));
        }
       
        int notaMed,notaMax;
        //leo a hijo1
        read(fd[0],&notaMed,sizeof(notaMed));
        read(fd[0],&notaMax,sizeof(notaMax));
         printf("La nota maxima es %d  y la nota media es %d\n" , notaMax, notaMed );


         int aprobados, suspensos;
        //leo a hijo2
    
        read(fd2[0],&aprobados,sizeof(aprobados));
        read(fd2[0],&suspensos,sizeof(suspensos));
        printf("El numero de aprobados son %d  y el numero de suspensos son %d\n" , aprobados, suspensos );

        wait(NULL);
        wait(NULL);

        close(fd[0]);
        close(fd2[0]);
        close(fd3[1]);
        close(fd4[1]);
    }

}
