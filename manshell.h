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
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

#endif
