#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2, pid3 ;
 pid1=fork();

 if(pid1==0){
   
    pid2=fork();

 }
if(pid2==0 && pid1==0){
  
    pid3=fork();
   
}



   if(pid3==0 && pid2==0 && pid1==0){

        printf("Mi pid es =%d y mi ppid es =%d y la suma es =%d\n" ,getpid(), getppid(),getpid()+getppid());

    }else if(pid2==0 && pid1==0){

        wait(NULL);
       printf("Mi pid es =%d y mi ppid es =%d y la suma es =%d\n" ,getpid(), getppid(),getpid()+getppid());

    }else if( pid1==0){

        wait(NULL);
       printf("Mi pid es =%d y mi ppid es =%d y la suma es =%d\n" ,getpid(), getppid(),getpid()+getppid());

    }else {
        wait(NULL);
        printf("Mi pid es =%d y mi ppid es =%d y la suma es =%d\n" ,getpid(), getppid(),getpid()+getppid());
    }



 exit(0);
}
