#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crear_proceso(struct Proceso *p, int pid, char *nombre_proceso,
                   status_t estado, struct Proceso *padre,
                   struct Proceso *primer_hijo, struct Proceso *hermano) {

  p->pid = pid;
  strcpy(p->nombre, nombre_proceso);
  p->estado = estado;
  p->padre = padre;
  p->primer_hijo = primer_hijo;
  p->hermano = hermano;
}

void esperar_proceso(struct Proceso *p, double actual_time) {
  // Verificamos que el proceso este en estado EJECUTANDO
  // Si no esta en estado RUNNING, no se puede cambiar a WAITING
  if (p->estado != EJECUTANDO) {
    printf("El proceso %s no se puede esperar porque no esta en estado "
           "EJECUTANDO\n",
           p->nombre_proceso);
    exit(1);
  } else {
    // Aquí va el código para matar el proceso
    // Por ejemplo, puedes usar la función free() para liberar la memoria
    // asignada al proceso
    kill(p->pid, SIGSTOP);
    p->estado = ESPERANDO;
    // p->iniciar_tiempo_espera = actual_time;
    // p->init_time = (int)actual_time;
  }

  // typedef enum { EJECUTANDO, LISTO, ESPERANDO, TERMINADO } status_t;
}

void matar_proceso(struct Proceso *p) {
  // Verificamos que el proceso este en estado EJECUTANDO
  // Si no esta en estado RUNNING, no se puede cambiar a TERMINADO
  if (p->estado != EJECUTANDO) {
    printf("El proceso %s no se puede matar porque no esta en estado "
           "EJECUTANDO\n",
           p->nombre_proceso);
    exit(1);
  } else {

    kill(p->pid, SIGKILL); // Matamos el proceso con la SYSCALL SIGKILL
    p->estado = TERMINADO;
    free(p); // Liberamos la memoria asignada al proceso, OJOO QUIZAS SEA BUENO
             // NO LIBERAR LA MEMORIA ACA
    // Y LIBERARLA EN QUEUE, ejecutar_queu
  }
}

// Pausar un proceso
void pause_process(pid_t pid) { kill(pid, SIGSTOP); }

// Reanudar un proceso
void resume_process(pid_t pid) { kill(pid, SIGCONT); }

void print_process(struct Proceso *p) {
  printf("PID: %d\nNombre: %s\nEstado: %d\n\n", p->pid, p->nombre_proceso,
         p->estado);
}