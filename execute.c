#include "shell.h"

void execute(char **argv) {
  if (!argv[0]) {
    return; // Empty command
  }

  // Get PATH environment variable
  char *value = getenv("PATH");

  // Build linked list of paths in PATH
  head = linkpath(value);

  // Find the executable path
  char *pathname = _which(argv[0], head);

  if (!pathname) {
    printf("Error: '%s' command not found\n", argv[0]);
    return;
  }

  // Fork and execute the command
  pid_t pid = fork();

  if (pid == 0) {
    // Child process
    execve(pathname, argv, environ);
    exit(1); // If execve fails
  } else {
    // Parent process
    waitpid(pid, NULL, 0);
  }
}
