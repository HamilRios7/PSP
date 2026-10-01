#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2, pid3;
 pid1=fork();
 if(pid1!=0){
    pid2=fork();
 }
if(pid2==0 && pid1!=0){
    pid3=fork();
}

if(pid1!=0 && pid2!=0){

    wait(NULL);
    wait(NULL);
    printf("Mi pid es =%d y soy el padre \n" ,getpid());

}else if(getpid()%2==0){
    wait(NULL);
    printf("Mi PID es=%d  y mi PPID es=%d   \n" ,getpid(), getppid());

}else if(getpid()%2!=0){
wait(NULL);
printf("Mi PID es=%d   \n" ,getpid());

}


 exit(0);
}


a) ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta
Proceso Padre => Proceso P1
              =Proceso P2 => Proceso P3

Se ejecutará el Proceso P1 primero, al ser el primero creado y saltarse los if para crear a los otros procesos, despues se ejecutara el P3 ya que P2 tendrá que esperar a que se ejecute su proceso hijo que es P3. 
Una vez terminado P3 , se ejecutará P2, y una vez que P2 y P1 terminen, el proceso Padre se ejecutará

Siempre se ejecutará de esta manera , debido a que cuando se crea el P1, este salta todos los if que crean los otros hijos y va directo a los if de ejecucion, mientras aun se crean los otros procesos.  De la misma manera, 
solo podra ejecutarse despues el P3 porque aunque sea el ultimo en crearse porque Padre y P2 esperaran a sus hijos a terminar.

