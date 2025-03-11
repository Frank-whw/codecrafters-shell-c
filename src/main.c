#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  printf("$ ");

  // Wait for user input
  char input[100];
  while (true)
  {
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    printf("%s: command not found", input);
  }

  return 0;
}
