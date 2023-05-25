#include "manshell.h"

/**
 * execute_in_child_process - function that executes a given command
 * @args: The array of arguments representing the command to execute.
 * @envn: The environment for the new process image.
 * @prog_nm: The name of the program.
 */
void execute_in_child_process(char **args, char **envn, char *prog_nm)
{
	char *pth;

	if (strchr(args[0], '/') != NULL)
	{
		execve(args[0], args, envn);
	}
	else
	{
		pth = srch_prt(args[0]);
		if (pth != NULL)
		{
			execve(pth, args, envn);
			free(pth);
		}
	}
	printf("%s: No such file or directory\n", prog_nm);
	exit(EXIT_FAILURE);
}
