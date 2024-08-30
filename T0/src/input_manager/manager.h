// Tells the compiler to compile this file once
#pragma once
// Import used global libraries
#include <stdbool.h>
#include <stdio.h>  // FILE, fopen, fclose, etc.
#include <stdlib.h> // malloc, calloc, free, etc.
#include <string.h> // strtok, strcpy, etc.

// Import the header file of this module, because it has the constant
// definitions
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// Define compile-time constants
#define MAX_SPLIT 255
#define BUFFER_SIZE 4096

// Declare functions

char **read_user_input();
void free_user_input(char **input);
void hello();
void isPrime(char *input);
void lrlist(struct process *process_list);
