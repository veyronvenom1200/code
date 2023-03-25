// /* system example : DIR */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <limits.h>
#include <unistd.h>
#include <string.h>

int main ()
{
  int i;
  FILE *file;
  char cwd[PATH_MAX], final[20];
  printf ("Checking if processor is available...");
  if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
  printf ("Executing command DIR...\n");
  i=system ("ipconfig getifaddr en0 >> text.txt");

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", strcat(cwd, "/text.txt"));
   } else {
       perror("getcwd() error");
       return 1;
   }
  file = fopen("text.txt", "r");
  printf ("The value returned was: %d.\n",i);
  if (file) {
    fscanf(file, "%[^\n]", final);
    fclose(file);
}

printf("Final: %s\n", final);
  return 0;
}