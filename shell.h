#ifndef SHELL_H_
#define SHELL_H_
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
extern char **environ;
/* execute_commands.c */
int execute_command(char *input);
char *get_executable_path(char *executablename);
char **splitter(char *input);
char *remove_whitespace(char *input);
void free_allocated_memory(char **args, char *path);
#endif
