#include "manshell.h"

/**
 * main - The main function of the program. Reads commands from the user and
 * executes them.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments passed to the program.
 * @envp: envroment variable.
 * Return: EXIT_SUCCESS on successful completion of the program.
 *
 */

int main(int argc __attribute__((unused)), char **argv, char **envp)
{
	int loper = 1;
	char *lne = NULL;
	size_t lenth = 0;
	ssize_t rd_num;

	if (isatty(STDIN_FILENO))
	{
	while (loper)
	{
		printf("Manshell($) ");
		fflush(stdout);
		rd_num = getline(&lne, &lenth, stdin);
		if (rd_num == -1)
		{
			free(lne);
			loper = 0;
		}
		else
		{
			exec_cmd(lne, argv[0], envp);
		}
	}
	}
	else
	{
		while ((rd_num = getline(&lne, &lenth, stdin)) != -1)
			exec_cmd(lne, argv[0], envp);
	}

	free(lne);
	return (EXIT_SUCCESS);
}
