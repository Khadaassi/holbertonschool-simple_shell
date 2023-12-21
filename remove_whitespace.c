#include "shell.h"

/**
 * remove_whitespace - Remove leading and trailing whitespace
 * @input: Input string
 * Return: String with removed whitespace
 */
char *remove_whitespace(char *input)
{
	char *cleaned_input = input;

	while (*cleaned_input == ' ' || *cleaned_input == '\t')
		cleaned_input++;

	if (*cleaned_input == '\n' || *cleaned_input == '\0')
		return (NULL);

	return (cleaned_input);
}
