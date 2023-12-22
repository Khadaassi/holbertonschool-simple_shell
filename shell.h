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

/*Prototypes*/

char *get_executable_path(char *executablename);
char **splitter(char *input);
char *remove_whitespace(char *input);
/*In execute.c file */
void free_allocated_memory(char **args, char *path);
int execute_command(char *input);

#endif
