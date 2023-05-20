/*#include "manshell.h"

**
 * cmd_arg - handle command line argument.
 * @argc: number of argument.
 * @argv: array of argument.
 *
 * Return: Nothing.
 *

int cmd_arg(int argc, char *argv[])
{
        int index;

        while ((index = getopt(argc, argv, "h")) != -1)
        {
                switch (index)
                {
                        case 'h':
                                printf("Usage: %s [options] command\n", argv[0]);
                                printf("Options:\n");
                                printf("  -h, --help    Print this help message\n");
                                break;
                        default:
                                printf("Unknown option: %c\n", optopt);
                                break;
                }
        }

        if (optind < argc)
        {
                return execve(argv[optind], argv + optind, NULL);
        }
        else
        {
                printf("No command specified\n");
                return -1;
        }
}
*/
