#include <stdlib.h>
#include <sys/types.h>

// define el estado del proceso
// status_t es un tipo de dato que puede tomar 4 valores
// 0 se interpretara como RUNNING
// 1 se interpretara como READY
// 2 se interpretara como WAITING
// 3 se interpretara como FINISHED

typedef enum { RUNNING, READY, WAITING, FINISHED } status_t;

struct proceso {
  char nombre_proceso[32];
  pid_t pid;
  status_t estado;
  int tiempo_inicio;
  int tiempo_espera;
  int tiempo_retorno;
}

void crear_proceso(struct Proceso *p, char *nombre_proceso, status_t estado,
                   int tiempo_inicio, int tiempo_espera, int tiempo_retorno);

void matar_proceso(struct Proceso *p);

void print_process(struct Proceso *p);