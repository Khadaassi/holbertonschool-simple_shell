#include "shell.h"
/**
 * splitter - Splits a string into tokens
 * @input: The string to be split
 * Return: An array of strings
 */
char **splitter(char *input)
{
	char *token;
	char **arguments = NULL;
	int arg_count = 0;
	arguments = calloc(10, sizeof(char *));
	if (arguments == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	token = strtok(input, " \t\n");
	if (token == NULL)
	{
		free(arguments);
		return (NULL);
	}
	while (token != NULL)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	arguments[arg_count] = NULL;
	return (arguments);
}
