#include "manshell.h"

/**
 * main - driver function
 *
 * Return: 0.
 */

int main()
{
	char *argv[2] = {NULL, NULL};
	int looper = 1;
	pid_t la_pid;
	int status;
	char *cmd_ptr = NULL;
	size_t cmd_length = 0;
	ssize_t cmd_read;

	while (looper)
	{
		if (isatty(STDIN_FILENO))
			printf("ManShell($) ");
		cmd_read = getline(&cmd_ptr, &cmd_length, stdin);
		if (cmd_read == -1)
		{
			free(cmd_ptr);
			exit(EXIT_FAILURE);
		}
		if (cmd_ptr[cmd_length - 1] == '\n')
			cmd_ptr[cmd_length - 1] = '\0';
		argv[0] = cmd_ptr;
		la_pid = fork();
		if (la_pid == -1)
			exit(EXIT_FAILURE);
		if (la_pid == 0)
		{
			if (execve(cmd_ptr, argv, NULL) == -1)
			{
				printf("%s: No such file or directory\n", cmd_ptr);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
		free(cmd_ptr);
	}
	return (0);
}
