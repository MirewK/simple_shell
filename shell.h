#ifndef SHELL_H
#define SHELL_H

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int execute(char **args);

#endif
