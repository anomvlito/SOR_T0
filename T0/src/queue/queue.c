#include "queue.h"
#include "../proceso/proceso.h"

struct queue *crear_queue() {
  struct queue *q = calloc(1, sizeof(struct queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

void encolar(struct queue *q, struct process *p) {
  if (q->size == 0) { // Si la cola esta vacia se agrega el proceso y se
                      // actualiza la cabeza y la cola
    q->head = p;
    q->tail = p;
    q->size++;
    return;
  } else { // Si la cola no esta vacia se agrega el proceso al final de la cola
           // y se actualiza la cola
    q->tail->next = p;
    q->tail = p;
    q->size++;
  }
}

void encolar_si_necesario(struct queue *q, struct process *p) {
  if (p->estado != TERMINADO) {
    encolar(q, p);
  } else {
    // nota si el proceso ya termino no se agrega a la cola ojo, con lo que
    // pueda pasar con los hijos
    matar_proceso(p);
    free(p);
    q->size--;
  }
}

void ejecutar_queue(struct queue *q, bool *shell_abierta) {
  while (*shell_abierta && q->size > 0) {
    struct process *p = q->head;

    // Verificar el estado del proceso antes de reanudarlo
    if (p->estado == ESPERANDO) {
      resume_process(p->pid);
      p->estado = EJECUTANDO;
    }

    // Esperar el tiempo asignado
    usleep(tiempo_de_espera);

    // Pausar el proceso
    pause_process(p->pid);
    p->estado = ESPERANDO;

    // Verificar si el proceso terminó
    int status;
    pid_t result = waitpid(p->pid, &status, WNOHANG);
    if (result == 0) {
      // Si no ha terminado, reenviarlo al final de la cola
      q->head = p->next; // Avanzar al siguiente en la cola
      encolar_si_necesario(q, p);
    } else if (result == p->pid) {
      // Si terminó, eliminarlo de la cola
      q->head = p->next; // Avanzar al siguiente en la cola
      matar_proceso(p);  // Liberar recursos del proceso
      free(p);           // Liberar la memoria del proceso
      q->size--;         // Reducir el tamaño de la cola
    }
  }
}

void liberar_queue(struct queue *q) { free(q); }