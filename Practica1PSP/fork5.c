#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1,pid2,pid_hijo ,pid_padre, pid_propio;
  

  pid1 = fork();

   if(pid1==0){
    pid2=fork();
  }
  
  if (pid1 == 0 && pid2!=0)  //Nos encontramos en Proceso hijo P2
  {       //Especificamos el if para que solo pueda entrar p2 y 
          //no entre p3 ya que tambien tiene la variable p1 igual 0
    
      wait(NULL); 
      pid_propio = getpid();
      pid_padre=getppid();
      printf("SOY PROCESO P2 \n" );
      printf("Mi PID=%d , y mi PPID=%d \n" ,pid_propio,pid_padre );
     
     
    
    
  }
   else if  (pid2 == 0 && pid1==0)   //Nos encontramos en Proceso P3
     //Especificamos en el if el valor de las variables para que solo entre p3 a este if
  
  { 
     
      pid_propio = getpid();
      pid_padre=getppid();
      printf("Soy proceso P3\n");
      printf("Mi PID=%d , y mi PPID=%d \n" ,pid_propio,pid_padre );
      
  
          
   
       
  }else { //estamos en proceso padre
       wait(NULL); 
        
        
   
    pid_propio = getpid();
    printf("Soy proceso P1\n" );
    printf("Mi PID es:%d y el de mi hijo es : %d\n" , pid_propio,pid1);
   
  
  }
   exit(0);
}
