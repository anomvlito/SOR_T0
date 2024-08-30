#include "process.h"
#include <stdio.h>
#include <string.h>

void crear_proceso(struct Proceso *p, char *nombre_proceso, status_t estado,
                   int tiempo_inicio, int tiempo_espera, int tiempo_retorno) {
  strcpy(p->nombre_proceso, nombre_proceso);
  p->estado = estado;
  p->tiempo_inicio = tiempo_inicio;
  p->tiempo_espera = tiempo_espera;
  p->tiempo_retorno = tiempo_retorno;
}

void matar_proceso(struct Process *p) { free(p); }