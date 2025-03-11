#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// void substring(char *src, char *dest, int start, int len)
// {
//   int i;
//   for (i = 0; i < len && src[start + i] != '\0'; i++)
//   {
//     dest[i] = src[start + i];
//   }
//   dest[i] = '\0';
// }
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
    else if (strncmp(input, "echo", 4) == 0)
    {
      // char dest[100];
      // substring(input, dest, 5, strlen(input));
      // 蠢死我了，这边直接input+5就完了，真的巧 从来没想过
      printf("%s\n", input + 5);
    }
    else
      printf("%s: command not found\n", input);
  }

  return 0;
}
