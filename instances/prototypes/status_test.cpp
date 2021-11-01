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
  /**
   * @return this returns the number of argments given, (less 1)
   * @note when used via system() the return value can be divided by 256 to get
   * the actual value of the number returned by main.
   *
   * Checking if processor is available...Ok
   * Executing command DIR...
   * The value returned was: 0.
   * The value returned was: 1.
   * The value returned was: 2.
   *
   * Hence we can setup an impromptu return coding scheme where:
   * 0 can mean false and
   * 1 can mean true
   *
   * However, if we do the opposite and
   * 0 can mean there were ZERO errors, (hence a successful run) and
   * another other value can be used to indicate an error, (as -1 causes
   * system() to returh 0xFF00).
   *
   *
   */
  return 0;
}