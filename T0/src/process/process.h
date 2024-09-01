#pragma once
#include <stdio.h> // Para usar printf
#include <stdlib.h> // Para usar EXIT_SUCCESS y EXIT_FAILURE
#include <string.h> // Para usar strcpy
#include <unistd.h> // Para usar fork y execv
#include <sys/wait.h> // Para usar waitpid
#include <sys/types.h> // Para usar pid_t
#include <signal.h> // Para usar kill

typedef Process {
    pid_t pid;
    char name[32];
    int init_time;
    int exit_code;
    char** process_info;
};

void initialize_process(struct Process *p, char *name, int init_time, char** process_info);
