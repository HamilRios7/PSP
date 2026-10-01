#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 printf("AAA \n");
 } else printf("BBB \n");
 exit(0);
}


a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
que el pid del programa fork7 es el 1000 y los pids se generan de uno en uno en orden creciente.

ProcesoP1 PID=1000 -> Proceso Hijo PID=1001



  
b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
Saldría CCC
        AAA
        BBB

No podría producirse otra salida porque el fork ocurre cuando el proceso padre ya esta dentro del if, por lo que su if ya ocurrira antes de que el proceso hijo pueda hacer su else 


c) Modificar el código para que la salida por pantalla sea:
CCC
BBB
AAA


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 printf("BBB \n");
 } else{ 
 printf("AAA \n");
 }
 exit(0);
}
