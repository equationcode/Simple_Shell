#include "manshell.h"

/**
 * srch_prt - function that searches for specified file in the directories.
 * @fl: The name of the file to search
 *
 * Return: A pointer to a string containing the path of the file if found,
 * or NULL if not found.
 */
char *srch_prt(char *fl)
{
	char *pth = getenv("PATH");
	char *n = pth;
	char *strt;
	char *bff = malloc(B_SIZE);

	if (bff == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (*n != '\0')
	{
		strt = n;
		while (*n != ':' && *n != '\0')
			n++;
		if (n - strt + strlen(fl) + 2 > B_SIZE)
			continue;
		strncpy(bff, strt, n - strt);
		bff[n - strt] = '/';
		strcpy(bff + (n - strt) + 1, fl);
		if (access(bff, X_OK) == 0)
			return (bff);
		if (*n == ':')
			n++;
	}

	free(bff);
	return (NULL);
}
