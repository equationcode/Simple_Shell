#include "manshell.h"

/**
 * main - driver function.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments passed.
 * @envp: The environment variables.
 *
 * Return: 0.
 */

int main(int argc, char **argv, char **envp)
{
	char **arg;
	int looper = 1, interact = isatty(STDIN_FILENO);
	char *ln = NULL;
	size_t n = 0;

	(void)argc;

	while (looper)
	{
		if (interact)
		{
			printf("ManShell($) ");
			fflush(stdout);
		}
		rd_cmdline(&ln, &n, &arg);
		cmd_exec(arg, argv[0], envp);
		if (!interact)
			looper = 0;
	}

	free(ln);
	free(arg);
	return (0);
}
