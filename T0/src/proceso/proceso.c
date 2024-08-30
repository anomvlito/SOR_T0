#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crear_proceso(struct Proceso *p, char *nombre_proceso, status_t estado,
                   int tiempo_inicio, int iniciar_tiempo_espera,
                   int tiempo_retorno, struct Proceso *procesos_hijos,
                   struct Proceso *proceso_padre,
                   struct Proceso *siguiente_hermano) {
  strcpy(p->nombre_proceso, nombre_proceso);
  p->estado = EJECUTANDO;
  p->tiempo_inicio = tiempo_inicio;
  p->iniciar_tiempo_espera = iniciar_tiempo_espera;
  p->tiempo_retorno = tiempo_retorno;
  p->procesos_hijos = procesos_hijos;
  p->proceso_padre = proceso_padre;
  p->siguiente_hermano = siguiente_hermano;
}

void wait_process(struct Process *p, double actual_time) {
  // Verificamos que el proceso este en estado RUNNING
  // Si no esta en estado RUNNING, no se puede cambiar a WAITING
  if (p->status != RUNNING) {
    printf(
        "El proceso %s no se puede esperar porque no esta en estado RUNNING\n",
        p->name);
    exit(1);
  } else {
    kill(p->pid, SIGSTOP);
    p->status = WAITING;
    p->iniciar_tiempo_espera = actual_time;
    p->init_time = actual_time;
    // p->init_time = (int)actual_time;  si necesitamos el tiempo con más
    // precision usamos  (int)actual_time;
  }
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
    p->estado = WAITING;
    p->star_time_wait = actual_time;
    p->tiempo_inicio = (int)actual_time;
  }
}

void matar_proceso(struct Proceso *p) { free(p); }

void print_process(struct Proceso *p) {
  printf("Nombre: %s\n", p->nombre_proceso);
  printf("Estado: %d\n", p->estado);
  printf("Tiempo de inicio: %d\n", p->tiempo_inicio);
  printf("Tiempo de espera: %d\n", p->iniciar_tiempo_espera);
  printf("Tiempo de retorno: %d\n", p->tiempo_retorno);
  printf("\n");
}