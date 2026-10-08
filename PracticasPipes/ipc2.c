#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int main(){

int fd[2];
    
    time_t t;
    int numero1;
    srand((unsigned) time(&t));  

    char operador='+';
    pipe(fd);
    pid_t pid=fork();







    if(pid==0){
        int numeroSumar=0;
        int sumados=0;
        char operador;
        close(fd[1]);
        while(read(fd[0],&numeroSumar,sizeof(numeroSumar))){

            printf("Numero introducido %d \n",numeroSumar);
            sumados +=numeroSumar;

        }
        printf("Sumatorio %d",sumados);

    }else{

        

        close(fd[0]);
        for(int i =0 ; i<=2;i++){
            numero1=rand() % 50; 
            write(fd[1],&numero1,sizeof(numero1)); 
        }
       
         write(fd[1],&operador,sizeof(operador)); 
        close(fd[1]);
        wait(NULL);
        printf("He terminado soy padre \n");

    }



}
