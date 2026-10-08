#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int main(){
    int fd[2];
    pipe(fd);
    time_t hora;
    char *fecha;
    time(&hora);
    fecha=ctime(&hora);    

    pid_t pid=fork();


    if(pid==0){
        char d [20];
         close(fd[1]);    
         read (fd[0],d,20);
         sleep(1);
         printf("Me ha enviado : %s \n",d);
        close(fd[0]);   
          printf("He terminado soy hijo \n");


    }else{

        
        close(fd[0]);
        write(fd[1],fecha,20);
        printf("He enviado un mensaje a hijo \n");
        close(fd[1]);
        wait(NULL);
        printf("He terminado soy padre \n");

    }



}
