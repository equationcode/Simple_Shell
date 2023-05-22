#include "manshell.h"

/**
 * rd_cmdline - Reads a command line from the user
 * and tokenizes it into arguments.
 *
 * @ln: Pointer to a buffer to store the command line.
 * @n: Pointer to the size of the buffer.
 * @arg: Pointer to an array of pointers to store
 * the arguments.
 *
 * Return: Nothing.
 */

void rd_cmdline(char **ln, size_t *n, char ***arg)
{
	int indx = 0;
	char *tok;
	int max_args = 4096;

	if (getline(ln, n, stdin) == -1)
	{
		printf("\n");
		exit(0);
	}

	*arg = malloc(max_args * sizeof(char *));
	tok = strtok(*ln, " \n");
	while (tok != NULL)
	{
		(*arg)[indx++] = tok;
		tok = strtok(NULL, " \n");
	}
	(*arg)[indx] = NULL;
}
