#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
*launch- function to launch the program
*@pid_t pid - Process 
*@int status - Status of the execution
*/

/* Function to launch a program with the given arguments */
int launch(char **args)
{
    pid_t pid; /* Process ID */
    int status; /* Status of the execution */

    pid = fork(); /* Create a child process */
    if (pid == 0) /* Child process */
    {
        if (execve(args[0], args, NULL) == -1) /* Execute the program */
        {
            perror("launch"); /* Print an error message if execution fails */
        }
        exit(EXIT_FAILURE); /* Exit with failure status */
    }
    else if (pid < 0) /* Forking error */
    {
        perror("launch"); /* Print an error message if forking fails */
    }
    else /* Parent process */
    {
        do {
            waitpid(pid, &status, WUNTRACED); /* Wait for the child process to end */
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); /* Check the status */
    }
    return 1; /* Return 1 to continue the loop */
}

/* Function to execute the arguments */
int execute(char **args)
{
    if (args[0] == NULL) /* No arguments */
    {
        return 1; /* Return 1 to continue the loop */
    }

    return launch(args); /* Launch the program with the arguments */
}
