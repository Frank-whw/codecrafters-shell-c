#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
// void substring(char *src, char *dest, int start, int len)
// {
//   int i;
//   for (i = 0; i < len && src[start + i] != '\0'; i++)
//   {
//     dest[i] = src[start + i];
//   }
//   dest[i] = '\0';
// }

// Function to check if a file exists and is executable
bool isExecutable(char *path)
{
  return access(path, X_OK) == 0;
}
// Function to search for a command in the PATH
char *findPath(char *command)
{
  char *path_env = getenv("PATH");
  if (path_env == NULL)
  {
    return NULL;
  }
  char *path_copy = strdup(path_env);
  char *dir = strtok(path_copy, ":");
  static char full_path[1024];
  while (dir != NULL)
  {
    snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
    if (isExecutable(full_path))
    {
      free(path_copy);
      return full_path;
    }
    dir = strtok(NULL, ":");
  }
  free(path_copy);
  return NULL;
}

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
    char builtins[][16] = {"echo", "type", "exit"};
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
    else if (strncmp(input, "type", 4) == 0)
    {
      int hasFount = 0;
      for (int i = 0; i < sizeof(builtins) / 16; i++)
      {
        if (strcmp(input + 5, builtins[i]) == 0)
        {
          hasFount = 1;
          printf("%s is a shell builtin\n", input + 5);
        }
      }
      if (hasFount == 0)
      {
        char *path = findPath(input + 5);
        if (path)
        {
          hasFount = 1;
          printf("%s is %s\n", input + 5, path);
        }
        else
        {
          printf("%s: not found\n", input + 5);
        }
      }
      if (hasFount == 0)
        printf("%s: not found\n", input + 5);
    }
    else
      printf("%s: command not found\n", input);
  }

  return 0;
}
