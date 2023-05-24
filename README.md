Here is a README file for the simple_shell program written in C language:
Simple Shell
This is a simple shell program written in C language. It reads a command line from the user and tokenizes it into arguments. The command is then executed by creating a new process using fork() and execve().
Usage
To use this program, compile it using a C compiler and run the resulting executable. You will be prompted with ManShell($) where you can enter your command. The command will be executed and the output will be displayed.
Functions
The program contains the following functions:
rd_cmdline: Reads a command line from the user and tokenizes it into arguments.
cmd_exec: Executes a command by creating a new process using fork() and execve().

