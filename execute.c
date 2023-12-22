#include "shell.h"

/**
 * execute_command - Executes a command in the shell
 * @user_input: Input to be executed
 * Return: 1 on success, -1 on failure
 */
int execute_command(char *user_input)
{
	int status;	/* Status of child process */
	int execution;	/* Execution of execve */
	char *path, **arguments;	/* Path of command and arguments */
	pid_t process_id;	/* child Process ID */

	arguments = splitter(user_input);	/* Split user input into arguments */
	if (arguments == NULL)	/* If splitter fails */
		return (-1);
	if (user_input[0] == '/' || user_input[0] == '.')
		path = strdup(user_input);
	else
		path = get_executable_path(arguments[0]);	/* Get path of command */
	if (path == NULL)
	{
		free_memory(arguments, path);
		return (-1);
	}
	process_id = fork();	/* Create child process */
	if (process_id < 0)
	{
		free_memory(arguments, path);
		return (-1);
	}
	else if (process_id == 0)
	{
		execution = execve(path, arguments, environ);	/* Execute command */
		if (execution < 0)	/* If execve fails */
		{
			free_memory(arguments, path);
			return (-1);
		}
		exit(1);
	}
	else
	{
		wait(&status);	/* Wait for child process to finish */
		free_memory(arguments, path);
	}
	return (1);
}
