#include "shell.h"
/**
 * free_memory - frees memory of arguments and path
 * @arguments: arguments of command
 * @path: path of command to be executed
 * Return: void
 */
void free_memory(char **arguments, char *path)
{
	free(arguments);
	free(path);
}
