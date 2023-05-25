#ifndef MANSHELL_H
#define MANSHELL_H

#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MX_LN 80
#define B_SIZE PATH_MAX

char *srch_prt(char *fl);
void tokenize_command_line(char *ln, char **args);
void execute_in_child_process(char **args, char **envn, char *prog_nm);
void exec_cmd(char *ln, char *prog_nm, char **envp);

#endif
