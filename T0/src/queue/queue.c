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

void ejecutar_queue(struct queue *q) {
  while (q->size > 0) {

    // Obtener el primer proceso de la cola
    struct process *p = q->head;

    // Reanudar el proceso
    resume_process(p->pid);

    // Esperar el tiempo asignado
    usleep(tiempo_de_espera);

    // Pausar el proceso
    pause_process(p->pid);

    // Verificar si el proceso terminó
    int status;
    pid_t result = waitpid(p->pid, &status, WNOHANG);
    if (result == 0) {
      // Si no ha terminado, reenviarlo al final de la cola
      encolar(q, p);
    } else if (result == p->pid) {
      // Si terminó, liberar recursos
      matar_proceso(p);
      // free(p);
    }
  }
}

void liberar_queue(struct queue *q) { free(q); }