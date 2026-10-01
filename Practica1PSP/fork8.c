#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 pid2 = fork();
 printf("CCC \n");
 }
 exit(0);
}

a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
que el pid del programa fork8 es el 1000 y los pids se generan de uno en uno en orden creciente.

  Proceso Padre PID=1000 => Proceso P1H PID=1001
                         => Proceso P2H PID=1002 
  
b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
AAA
BBB
CCC
CCC

No se puede producir otra salida, ya que primero ocurre el "AAA" que solo podra ser escrito por el Padre, luego ocurrira el hijo que hara print de "BBB" y por el ultimo , el padre y el segundo hijo que hace con fork dentro del else
, ambos haran un print de "CCC"  
  


c) Añade el código necesario para que el orden de ejecución sea tal que los respectivos procesos
padre sean los últimos que se ejecuten.


  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 pid2 = fork();
if(pid1=!0 && pid2=!0){
  
}  
 printf("CCC \n");
 }
 exit(0);
}
  
