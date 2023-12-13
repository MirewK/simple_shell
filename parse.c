#include "shell.h"

char **parse_args(char *buff) {
  char **argv = malloc(sizeof(char *) * MAX_ARGS);
  int argc = 0;
  char *token = strtok(buff, " \t\n");

  while (token != NULL) {
    if (*token == '"' || *token == '\'') {
      // Handle quoted arguments
      char quote = *token;
      token++;
      char *arg = malloc(strlen(token) + 1);
      int i = 0;
      while (*token != quote && *token != '\0') {
        arg[i++] = *token++;
      }
      arg[i] = '\0';
      argv[argc++] = arg;
    } else {
      // Handle non-quoted arguments
      argv[argc++] = token;
    }
    token = strtok(NULL, " \t\n");
  }

  argv[argc] = NULL;
  return argv;
}
