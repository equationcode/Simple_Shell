#include "manshell.h"

/**
 * tokenize_command_line - Tokenizes the given command line into an array of
 * arguments.
 * @ln: The command line to tokenize.
 * @args: The array to store the tokenized arguments.
 */
void tokenize_command_line(char *ln, char **args)
{
	int i;
	char *tok;

	ln[strcspn(ln, "\n")] = '\0';

	tok = strtok(ln, " ");
	i = 0;
	while (tok != NULL)
	{
		args[i++] = tok;
		tok = strtok(NULL, " ");
	}
	args[i] = NULL;
}
