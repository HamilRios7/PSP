#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    
    int limite=5;

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);

        int recibido;
        for(int i=0 ; i<=limite;i++)
        {
            read(fd[0],&recibido, sizeof(recibido));          
            sleep(1);
            printf("HIJO: He recibido %d\n", recibido);
        }     

        close(fd[0]);
    }
    else {
        // PADRE: solo escribe
        close(fd[0]);
        int numero=20;
        for(int i=0 ; i<=limite;i++)
        {
            
            write(fd[1],&numero, sizeof(numero));
            printf("PADRE: He enviado %d\n", numero);
            sleep(2);
            numero+=10;
    
        }       
        
      

        close(fd[1]);
    }


} 