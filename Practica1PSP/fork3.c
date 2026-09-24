printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}
printf("Fin\n");


a) ¿Cuántos procesos existen?

Existen 2 procesos

b) ¿ qué instrucciones ejecuta cada uno?
El printf de Inicio solo lo ejecutara el padre.
Ambos ejecutaran el printf "Después del fork", y luego dependiendo de que procesa sea, 
uno hara printf de "Soy el hijo" si es el proceso hijo y " Soy el  padre" si es el proceso padre.
 Despues el printf de Fin sera escrito por ambos procesos

c) ¿cuántas veces aparece cada mensaje y qué partes de la salida pueden aparecer en distinto
orden?
El printf de inicio solo aparecera una vez por el padre
El printf despues del fork, saldrá dos veces por padre e hijo
Los printf de soy el padre y soy el hijo apareceran en un orden aleatorio  cada vez que se ejecute el codigo
EL print de fin aparecera dos veces , por padre e hijo
