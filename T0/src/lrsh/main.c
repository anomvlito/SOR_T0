#include <stdio.h>
#include <stdlib.h>

#include "../input_manager/manager.h"
#include "../proceso/proceso.h"

static bool string_equals(char *string1, char *string2) {
  return !strcmp(string1, string2);
}

int main(int argc, char const *argv[]) {

  /* Construcción de las estructuras */


  while (algo != NULL) {

    char **input = read_user_input();


    if (string_equals(input[0], "hello")) {
    hello();
  }

  else if (string_equals(input[0], "sum")) {

  }

  else if (string_equals(input[0], "is_prime")) {
    isPrime(input[1]);
  }

  else if (string_equals(input[0], "irexcec")) {

    int argc = atoi(input[1]);  

    char **argv = malloc(sizeof(char *) * (argc + 2)); // + 1 para tambien guardar el nombre del path + un NULL al final
    argv[0] = input[4];
    for (int j = 0; j < 3; ++j)
    {
      argv[j + 1] = input[6 + j];
    }
    argv[argc + 1] = NULL;

  }

  else if (string_equals(input[0], "irlist")) {
    irlist();
  }

  free_user_input(input);



   
  }
  

  
}
