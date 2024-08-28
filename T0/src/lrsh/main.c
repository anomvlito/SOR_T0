#include "../input_manager/manager.h"

static bool string_equals(char *string1, char *string2) {
  return !strcmp(string1, string2);
}

int main(int argc, char const *argv[])
{
  char** input = read_user_input();

  if (string_equals(input[0], "hello")) {
    hello();
  }

  else if (string_equals(input[0], "sum")) {

  }

  else if (string_equals(input[0], "is_prime")) {
    isPrime(input[1]);
  }
  
  else if (string_equals(input[0], "irexcec")) {

  }
  
  else if (string_equals(input[0], "irlist")) {

  }

  free_user_input(input);
}

