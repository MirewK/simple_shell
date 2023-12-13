#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/*
 * File: shell.h
 *
 * Desc: Header file containing prototypes for all functions
 */
/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int execute(char **args);

#endif
