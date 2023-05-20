#ifndef MANSHELL_H
#define MANSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>

char read_cmd_line(void);
void print(void);
int cmd_arg(int argc, char *argv[]);

#endif
