#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 256
#define MAX_ARGS 32

typedef struct list_path {
  char *path;
  struct list_path *next;
} list_path;

/* Function prototypes */
void sig_handler(int sig_num);
int _isatty(void);
char **parse_args(char *buff);
void execute(char **argv);
void free_list(list_path *head);

#endif /* _SHELL_H_ */
