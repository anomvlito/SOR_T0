#include "manager.h"
#include "proceso.h"

/*
 * Splits a string "str" by a separator "sep", returns an array with the
 * resulting strings. Equivalent to Python's str.split(sep).
 */
static char **split_by_sep(char *str, char *sep) {
  char **new_str = calloc(MAX_SPLIT, sizeof(char *));
  int index = 0, len;

  char *token = strtok(str, sep);
  while (token != NULL) {
    new_str[index] = calloc(BUFFER_SIZE, sizeof(char));
    strcpy(new_str[index++], token);
    token = strtok(NULL, sep);
  }

  // Remove dangling Windows (\r) and Unix (\n) newlines
  len = strlen(new_str[index - 1]);
  if (len > 1 && new_str[index - 1][len - 2] == '\r')
    new_str[index - 1][len - 2] = '\0';
  else if (len && new_str[index - 1][len - 1] == '\n')
    new_str[index - 1][len - 1] = '\0';
  return new_str;
}

/*
 * Reads a line fo user input and returns it as an array of strings
 */
char **read_user_input() {
  char *input = calloc(BUFFER_SIZE, sizeof(char));
  fgets(input, BUFFER_SIZE, stdin);
  char **split_input = split_by_sep(input, " ");
  free(input);
  return split_input;
}

/*
 * Frees user input obtained by the read_user_input function
 */
void free_user_input(char **input) {
  for (int i = 0; i < MAX_SPLIT; i++) {
    free(input[i]);
  }
  free(input);
}

void hello() {
  // https://www.geeksforgeeks.org/fork-system-call/
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork fail");
    exit(1);
  } else if (pid == 0) {
    printf("Hello World!\n");
  }
  // else {
  //   printf("Hello World p0!\n");
  // }
}

// https://www.geeksforgeeks.org/c-program-to-check-whether-a-number-is-prime-or-not/
void isPrime(char *input) {
  pid_t pid = fork();

  if (pid == 0) {
    // If number is less than or equal to 1, it is not prime
    int N = atoi(input);
    bool result = true;
    if (N <= 1) {
      result = false;
    }

    // Check for divisors from 2 to N/2
    for (int i = 2; i < N / 2; i++) {
      // If N is divisible by any number in this range, it
      // is not prime
      if (N % i == 0) {
        result = false;
      }
    }
    // If no divisors are found, it is prime
    if (result == true) {
      printf("%s is prime\n", input);
    } else {
      printf("%s is not prime\n", input);
    }
  } else
}

// comentario de discussions :
// En el comando lrlist, no tienen que crear un proceso hijo solo tiene que
// imprimir los procesos que se están ejecutando o terminaron de ejecutar para
// ello puedes usar array o linked list o cualquier estructura que manejes. Al
// final ese comando es del programa principal lrsh.

// creo que lo mejor es que los procesos se guarden en una lista enlazada del
// struct del queue de la cola con prioiridad, y que se vayan agregando a la
// lista de procesos en ejecución algunos procesos van a tomar más de 1 segundo.

void lrlist(struct process *process_list) {
  struct process *current = process_list;

  while (current != NULL) {
    // Imprimir información del proceso actual
    // se entrega un operador ternario para imprimir el estado del proceso
    printf("PID del proceso es: %d\n Nombre: %s \n Tiempo de ejecución: %ld "
           "segundos \n Estado: %s\n",
           current->pid, current->nombre_proceso,
           time(NULL) - current->tiempo_inicio,
           current->estado == FINISHED ? "Terminado" : "En ejecución")

        // Si el proceso actual tiene hijos, llamamos  con cuidado
        // recursivamente a lrlist para ir recorriendo a sus hijos
        if (current->primer_hijo != NULL) {
      lrlist(current->primer_hijo);
    }

    // Pasar al siguiente proceso en el mismo nivel
    current = current->siguiente_hermano;
  }
}

// cuando id de fork es -1 es porque no se pudo crear el proceso hijo
// cuando id de fork es 0 es porque es el proceso hijo
// cuando id de fork es > 0 es porque es el proceso padre
