#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

/*
* read_line-function to read a line 
* split_line- split multiple lines
*@int bufsize = BUFSIZE -Size of the buffer
*  @int position -Position in the buffer
*   @char **tokens - Array of tokens
 *   @char *token -Pointer to a token 
* @char *line = NULL-Pointer to the line
 *   @size_t bufsize -Size of the buffe
  *  @ssize_t nread -Number of characters read
*/
/* Function to read a line from stdin */
char *read_line(void)
{
    char *line = NULL; /* Pointer to the line */
    size_t bufsize = 0; /* Size of the buffer */
    ssize_t nread; /* Number of characters read */

    nread = getline(&line, &bufsize, stdin); /* Get the line from stdin */
    if (nread == -1) /* Check for errors */
    {
        if (feof(stdin)) /* End of file */
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else /* Some other error */
        {
            perror("read_line");
            exit(EXIT_FAILURE);
        }
    }
    return line; /* Return the line */
}

/* Function to split a line into tokens */
char **split_line(char *line)
{
    int bufsize = BUFSIZE; /* Size of the buffer */
    int position = 0; /* Position in the buffer */
    char **tokens = malloc(bufsize * sizeof(char *)); /* Array of tokens */
    char *token; /* Pointer to a token */

    if (!tokens) /* Check for memory allocation errors */
    {
        perror("split_line");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM); /* Get the first token */
    while (token != NULL) /* Loop until no more tokens */
    {
        tokens[position] = token; /* Store the token in the array */
        position++;

        if (position >= bufsize) /* Check if the buffer is full */
        {
            bufsize += BUFSIZE; /* Increase the buffer size */
            tokens = realloc(tokens, bufsize * sizeof(char *)); /* Reallocate memory */
            if (!tokens) /* Check for memory allocation errors */
            {
                perror("split_line");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIM); /* Get the next token */
    }
    tokens[position] = NULL; /* Terminate the array with a NULL pointer */
    return tokens; /* Return the array of tokens */
}
