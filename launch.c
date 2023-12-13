#include "shell.h"

void execute(char **argv) {
  if (!argv[0]) {
    return; // Empty command
  }

  value = _getenv("PATH");
  head = linkpath(value);
  pathname = _which(argv[0], head);

  if (!pathname) {
    printf("Error: '%s' command not found\n", argv[0]);
    return;
  }

  pid_t pid = fork();

  if (pid == 0) {
    execve(pathname, argv, environ);
    exit(1); // If execve fails
  } else {
    waitpid(pid, NULL, 0);
  }
}
