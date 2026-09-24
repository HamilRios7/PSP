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

Ambos ejecutaran el printf después del fork, y luego dependiendo de que procesa sea, uno hara printf de hijo o de padre
c) ¿cuántas veces aparece cada mensaje y qué partes de la salida pueden aparecer en distinto
orden?
El printf de inicio solo aparecera una vez por el padre
El printf despues del fork, saldrá dos veces por padre e hijo
El hijo printf solo aparecerá una vez
El padre printf solo aparecerá una vez
