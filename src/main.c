#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
  // Flush after every printf
  setbuf(stdout, NULL);
  while (true)
  {
    // Uncomment this block to pass the first stage
    printf("$ ");

    // Wait for user input
    char input[100];

    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    if (strcmp(input, "exit 0") == 0)
    {
      return 0;
    }
    printf("%s: command not found\n", input);
  }

  return 0;
}
