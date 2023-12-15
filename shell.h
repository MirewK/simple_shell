#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
pid_t fork(void);
pid_t wait(int *wstatus);
int execve(const char *pathname, char *const argv[],char *const envp[]);
char *strtok(char *str, const char *delim);




#endif /* SHELL_H */
