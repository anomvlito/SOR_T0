
#include <stdio.h>
#include <stdlib.h>
#include "../input_manager/manager.h"

int main(int argc, char const *argv[])
{
  char** input = read_user_input();
  hello(input[0]);
  //printf("%s\n", input[0]);
  free_user_input(input);
}

