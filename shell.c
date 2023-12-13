#include "shell.h"

ssize_t len = 0;
char *buff = NULL, *value = NULL, *pathname = NULL;
size_t size = 0;
list_path *head = NULL;

int main(void) {
  signal(SIGINT, sig_handler);
  while (len != EOF) {
    if (_isatty()) {
      printf("simple_shell> ");
    }
    len = getline(&buff, &size, stdin);
    if (len == EOF) {
      break;
    }
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

int _isatty(void) {
  return isatty(STDIN_FILENO);
}
