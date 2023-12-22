#include "shell.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *input = NULL, *cleaned_input = NULL;
	int execution_result;
	size_t len = 0;
	ssize_t read_chars;
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		read_chars = getline(&input, &len, stdin);
		if (read_chars == -1)
			break;
		cleaned_input = remove_whitespace(input);
		if (cleaned_input == NULL)
			continue;
		if (strcmp(cleaned_input, "exit\n") == 0)
			break;
		execution_result = execute_command(cleaned_input);
		if (execution_result == -1)
			perror(argv[0]);
	}
	free(input);
	return (0);
}
