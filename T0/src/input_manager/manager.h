// Tells the compiler to compile this file once
#pragma once

// Define compile-time constants
#define MAX_SPLIT 255
#define BUFFER_SIZE 4096


// typedef struct lrsh {             
//   bool consola_activa;
//   Proceso *procesos;                        
// } Lrsh;

// typedef struct proceso {             
//   bool activo;
//   proceso *proceso_padre;                                  
//   proceso *proceso_hijo;                                        
// } Proceso;



// Declare functions

char **read_user_input();
void free_user_input(char **input);
void hello(char *string1);