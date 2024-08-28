// Tells the compiler to compile this file once
#pragma once
// Import used global libraries
#include <stdio.h>  // FILE, fopen, fclose, etc.
#include <string.h> // strtok, strcpy, etc.
#include <stdlib.h> // malloc, calloc, free, etc.
#include <stdbool.h>
// Import the header file of this module, because it has the constant definitions
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <time.h>

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

typedef struct process {
    pid_t pid;
    char *exec_name;
    time_t start_time;
    int exit_code;
} process;


// Declare functions

char **read_user_input();
void free_user_input(char **input);
void hello();
void isPrime(char* input);
