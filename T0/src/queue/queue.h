#include <stdio.h>
#include <stdlib.h>

#include "../input_manager/manager.h"
#include "../proceso/proceso.h"

#define tiempo_de_espera 1000000 // 1 segundo en microsegundos

// definimos un queue de procesos que se comporte como fifo pero le asigne un
// tiempo determinado al proceso cada vez que llegue a la cola el tiempo de
// ejecución de cada proceso es de {tiempo_de_espera } segundos, si se demora
// más que eso pasa al final de la cola y se le da la oportunidad de ejecutar al
// siguiente proceso en la cola, si hay solo un proceso en la cola se deja que
// este termine su ejecución

struct queue {
  struct process *head;
  struct process *tail;
  int size;
};

// aca van las declaraciones de las funciones de queue.c
void encolar(struct queue *q, struct process *p);

void ejecutar_queue(struct queue *q);

void liberar_queue(struct queue *q);