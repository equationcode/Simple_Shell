#include "manshell.h"

/**
 * main - driver function.
 *
 * Return: 0.
 */

int main(void)
{
	char **arg;
	int looper = 1, interact = isatty(STDIN_FILENO);
	char *ln = NULL;
	size_t n = 0;

	while (looper)
	{
		if (interact)
		{
		printf("ManShell($) ");
		fflush(stdout);
		}
		rd_cmdline(&ln, &n, &arg);
		cmd_exec(arg);
		if (!interact)
			looper = 0;
	}

	free(ln);
	free(arg);
	return (0);
}
