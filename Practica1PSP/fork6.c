#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1,pid2,pid_hijo ,pid_padre, pid_propio;
  

  pid1 = fork();
  if(pid1!=0){
    pid2=fork();
  }

  
  if (pid1 == 0 )  //Nos encontramos en Proceso hijo P2
  {        
    
    sleep(10);
     
    printf("Desperte\n"  );
    
     
    
    
  }
   else if  (pid2 == 0)   //Nos encontramos en Proceso hijo p3
  { 
      pid_propio=getpid();
      pid_padre=getppid();
      printf("Soy Proceso P3 Mi PID=%d , y mi PPID=%d \n" ,pid_propio, pid_padre );
      sleep(1);
  
          
   
       
  }else {
       pid_hijo = wait(NULL); //espera la finalización del proceso hijo
       pid_hijo = wait(NULL); 
        
   
    pid_propio = getpid();
    printf("Soy padre ,Mi PID es:%d y mis hijso terminaron\n" , pid_propio);
   
  
  }
   exit(0);
}
