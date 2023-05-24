#include "manshell.h"
/**
 * cmd_exec - Executes a command by creating a new
 * process using fork() and execve().
 *
 * @arg: Array of pointers to the arguments
 * of the command.
 * @prog_name: The name of the program.
 *
 * Return: Nothing.
 */

void cmd_exec(char **arg, char *prog_name)
{
	pid_t my_id;
	char *envp[] = {NULL};

	if (arg[0] == NULL)
		return;
	my_id = fork();
	if (my_id == 0)
	{
		execve(arg[0], arg, envp);
		printf("%s: No such file or directory\n", prog_name);
		exit(1);
	}
	else if (my_id > 0)
		wait(NULL);
	else
	{
		perror("fork");
		exit(1);
	}
}
