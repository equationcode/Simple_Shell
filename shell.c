#include "manshell.h"

/**
 * main - driver function.
 *
 * Return: 0.
 */

int main(void)
{
	char **arg;
	int looper = 1;
	char *ln = NULL;
	size_t n = 0;

	while (looper)
	{
		printf("ManShell($) ");
		fflush(stdout);

		rd_cmdline(&ln, &n, &arg);
		cmd_exec(arg);
	}

	free(ln);
	free(arg);
	return (0);
}
