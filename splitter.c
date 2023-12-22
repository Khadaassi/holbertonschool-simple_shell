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

	/*Allocate memory for the arguments array*/
	arguments = calloc(10, sizeof(char *));
	if (arguments == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	/*Tokenize the input string using strtok*/
	token = strtok(input, " \t\n");
	if (token == NULL)
	{
		free(arguments);
		return (NULL);
	}
	/*Loop through the tokens and store them in the arguments array*/
	while (token != NULL)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}

	/*Set the last element of the arguments array to NULL*/
	arguments[arg_count] = NULL;
	return (arguments);
}
