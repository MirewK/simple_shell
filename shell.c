#include "shell.h"

ssize_t len = 0;
char *buff = NULL, *value, *pathname;
size_t size = 0;
list_path *head = '\0';

void main(void) {
  signal(SIGINT, sig_handler);
  while (len != EOF) {
    _isatty();
    len = getline(&buff, &size, stdin);
    _EOF(len, buff);
    execute(parse_args(buff));
  }
  free_list(head);
  free(buff);
  return 0;
}

void sig_handler(int sig_num) {
  if (sig_num == SIGINT) {
    printf("\n");
    fflush(stdout);
  }
}

void _isatty(void) {
  // Check if input is coming from a terminal
  if (isatty(STDIN_FILENO)) {
    printf("simple_shell> ");
  }
}
