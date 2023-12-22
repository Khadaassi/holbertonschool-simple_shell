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

	/*Check if arguments count is not equal to 1*/
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE); // Return failure
	}
	/*Loop to continuously read input*/ 
	while (1)
	{
		/*Display the shell prompt if input is from terminal*/
		if (isatty(STDIN_FILENO))
			printf("$ ");
		/*Read input from stdin*/
		read_chars = getline(&input, &len, stdin);
		/*If end of file or an error occurs, break out of loop*/
		if (read_chars == -1)
			break;
		/*If input is only whitespace, continue*/
		cleaned_input = remove_whitespace(input);
		if (cleaned_input == NULL)
			continue;
		/*If input is exit, break out of loop*/
		if (strcmp(cleaned_input, "exit\n") == 0)
			break;
		/*Execute the command and store the result*/
		execution_result = execute_command(cleaned_input);

		/*If execution result is -1, print error*/
		if (execution_result == -1)
			perror(argv[0]);
	}
	/*Free allocated memory*/
	free(input);
	return (0); // Return success
}
