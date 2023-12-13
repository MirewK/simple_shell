#include <stdio.h>
#include <stdlib.h>
#include "shell.h"


/* Main function */
int main(void)
{
    char *line; /* Buffer for the input line */
    char **args; /* Array of arguments */
    int status; /* Status of the execution */

    do {
        write("> simple_shell> "); /* Display the prompt */
        line = read_line(); /* Read the input line */
        args = split_line(line); /* Split the line into arguments */
        status = execute(args); /* Execute the arguments */

        free(line); /* Free the allocated memory */
        free(args);
    } while (status); /* Loop until status is zero */

    return 0;
}
