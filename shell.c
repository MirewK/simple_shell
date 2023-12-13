#include "shell.h"

ssize_t len = 0;
char *buff = NULL;
size_t size = 0;
list_path *head = NULL;

int main(void) {
  /* Register signal handler for SIGINT */
  signal(SIGINT, sig_handler);

  while ((len = getline(&buff, &size, stdin)) != EOF) {
    /* Check if input is coming from a terminal */
    if (_isatty()) {
      printf("simple_shell> ");
    }

    /* Parse arguments */
    char **argv = parse_args(buff);

    /* Execute command */
    execute(argv);

    /* Release allocated memory */
    free_list(head);
    free(buff);
  }

  return 0;
}
