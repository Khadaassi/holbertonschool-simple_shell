#include "shell.h"

/**
 * free_memory - frees memory
 * @arguments: arguments
 * @path: path of command
 * Return: void
 */
void free_memory(char **arguments, char *path)
{
	free(arguments);
	free(path);
}

/**
 * execute_command - Executes a command
 * @user_input: Input to be executed
 * Return: 1 on success, -1 on failure
 */
int execute_command(char *user_input)
{
	int status, execution;
	char *path, **arguments;
	pid_t process_id;

	arguments = splitter(user_input);
	if (arguments == NULL)
		return (-1);
	
	if (user_input[0] == '/' || user_input[0] == '.')
		path = strdup(user_input);
	else
		path = get_executable_path(arguments[0]);
	
	if (path == NULL)
	{
		free_memory(arguments, path);
		return (-1);
	}

	process_id = fork();

	if (process_id < 0)
	{
		free_memory(arguments, path);
		return (-1);
	}
	else if (process_id == 0)
	{
		execution = execve(path, arguments, environ);
		
		if (execution < 0)
		{
			free_memory(arguments, path);
			return (-1);
		}
		
		exit(1);
	}
	else
	{
		wait(&status);
		free_memory(arguments, path);
	}

	return (1);
}
