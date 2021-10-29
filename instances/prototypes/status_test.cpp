/* system example : DIR */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* system, NULL, EXIT_FAILURE */

int main() {
  int i0, i1, i2;
  printf("Checking if processor is available...");
  if (system(NULL))
    puts("Ok");
  else
    exit(EXIT_FAILURE);
  printf("Executing command DIR...\n");
  i0 = system("build/status_main");
  printf("The value returned was: %d.\n", i0 / 256);
  i1 = system("build/status_main 1");
  printf("The value returned was: %d.\n", i1 / 256);
  i2 = system("build/status_main 1 2");
  printf("The value returned was: %d.\n", i2 / 256);
  return 0;
}