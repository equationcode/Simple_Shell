#include "manshell.h"

/**
 * exec_cmd - Executes the given command line.
 * @ln: The command line to execute.
 * @prog_nm: The name of the program.
 */
void exec_cmd(char *ln, char *prog_nm, char **envp)
{
	char *args[MX_LN / 2 + 1];
	pid_t mypid;
	int stats;

	tokenize_command_line(ln, args);

	if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	mypid = fork();
	if (mypid == 0)
		execute_in_child_process(args, envp, prog_nm);
	else if (mypid > 0)
		wait(&stats);
	else
		perror("fork"), exit(EXIT_FAILURE);
}
