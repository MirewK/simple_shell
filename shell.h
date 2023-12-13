#ifndef SHELL_H
#define SHELL_H

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
