#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo, pid_padre, pid_propio;
  

  pid = fork();

  
  if (pid == 0 )  //Nos encontramos en Proceso hijo 
  {        
    printf("Hamil \n");	
    
      pid_hijo = getpid();
     
    
     
    //sleep(30); 
  }
  else    //Nos encontramos en Proceso padre 
  { 
   pid_hijo = wait(NULL); //espera la finalización del proceso hijo
   
   
        pid_propio = getpid();
   printf("Mi PID es:%d\n" , pid_propio);
   printf("Mi hijo tenia el PID:%d\n" , pid_hijo);
  
          
   
       
  }
   exit(0);
}
