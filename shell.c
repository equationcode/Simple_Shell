/*#include "manshell.h"

**
 * main - prompt the user.
 *
 * Return: 0.
 *
int main(int ac, char **av)
{

        int looper = 1;
	pid_t la_pid;
	int status;
	char *cmd_ptr = NULL;
        size_t cmd_length = 0;
	ssize_t cmd_read;

        while (looper)
        {
		if (isatty(STDIN_FILENO))
			print();
		cmd_read = getline(&cmd_ptr, &cmd_length, stdin);
        	if (cmd_read == -1)
        	{
                	free(cmd_ptr);
                	exit(EXIT_FAILURE);
        	}
        	while (cmd_ptr[looper])
        	{
                	if (feof(stdin))
                        	break;
                	if (cmd_ptr[looper] == '\n')
                        	cmd_ptr[looper] = 0;
                	looper++;
        	}
                av[0] = cmd_ptr;
                la_pid = fork();
                if (la_pid == -1)
		{
			exit(EXIT_FAILURE);
		}
                if (la_pid == 0)
		{
			if ((execve(cmd_ptr, av, NULL)) == -1)
				printf("%s\n: No such file or directory", cmd_ptr);
			status = cmd_arg(ac, av);
			if (status < 0)
			{
				printf("%d\n: No such file or directory", status);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
		free(cmd_ptr);
        }
	return (0);
}
*/
